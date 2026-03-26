// Gunters Corne Keymap — Miryoku-Stil
// =====================================
//
// Aufbau (6 Layer + Base):
//   Layer 0  BASE   — QWERTY mit GACS Home Row Mods
//   Layer 1  NAV    — Navigation (Pfeile, Home/End/PgUp/PgDn)
//   Layer 2  SYM1   — Symbole rechts (Klammern schliessend, Operatoren)
//   Layer 3  SYM2   — Symbole links (Klammern oeffnend, Vim-Zeichen)
//   Layer 4  NUM    — Taschenrechner (Numpad links, Modifier rechts)
//   Layer 5  FUN    — Funktionstasten F1-F12
//   Layer 6  EURKEY — Umlaute/Sonderzeichen via AltGr (Toggle)
//
// Prinzip:
//   Linker Daumen haelt Layer -> Inhalt rechts, explizite Modifier links.
//   Rechter Daumen haelt Layer -> Inhalt links, explizite Modifier rechts.
//   CHORDAL_HOLD verhindert Fehlausloesungen der Home Row Mods.
//
// Home Row Mods (GACS — von aussen nach innen):
//   Links:  A=GUI  S=Alt  D=Ctrl  F=Shift
//   Rechts: ;=GUI  L=Alt  K=Ctrl  J=Shift
//
// Thumb-Tasten (alle LT — Tap + Hold):
//   Links:  Esc/NAV    Space/SYM1   Tab/FUN
//   Rechts: Enter/NUM  Bsp/SYM2     Del/EURKEY
//
// Extra-Spalten: Vol-  Vol+  Mute  Play/Pause (auf allen Layern transparent)
// 6. Spalte: Comfort-Tasten (Hyper, Esc, Del, Shift) — ausserhalb Miryoku-Raster

#include QMK_KEYBOARD_H

// -- Home Row Mods (GACS) --------------------------------------------------
#define HM_A    LGUI_T(KC_A)
#define HM_S    LALT_T(KC_S)
#define HM_D    LCTL_T(KC_D)
#define HM_F    LSFT_T(KC_F)
#define HM_J    RSFT_T(KC_J)
#define HM_K    RCTL_T(KC_K)
#define HM_L    LALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

// -- Thumb-Tasten (LT — Tap + Hold) ----------------------------------------
#define NAV_ESC  LT(_NAV,  KC_ESC)
#define SYM1_SPC LT(_SYM1, KC_SPC)
#define FUN_TAB  LT(_FUN,  KC_TAB)
#define NUM_ENT  LT(_NUM,  KC_ENT)
#define SYM2_BSP LT(_SYM2, KC_BSPC)

// -- EurKey-Umlaute (AltGr + Buchstabe) -------------------------------------
#define EU_AUML  RALT(KC_A)       // ä
#define EU_OUML  RALT(KC_O)       // ö
#define EU_UUML  RALT(KC_U)       // ü
#define EU_SZET  RALT(KC_S)       // ß
#define EU_EURO  RALT(KC_5)       // €
#define EU_BIGA  RALT(S(KC_A))    // Ä
#define EU_BIGO  RALT(S(KC_O))    // Ö
#define EU_BIGU  RALT(S(KC_U))    // Ü

// -- Sondertasten -----------------------------------------------------------
#define HY_KEY   HYPR(KC_NO)   // Hyper (Ctrl+Shift+Alt+GUI)
#define EUR_DEL  LT(_EURKEY, KC_DEL)  // Tap: Del, Hold: EurKey-Layer

// -- Layer-Namen -----------------------------------------------------------
enum layers {
  _BASE,
  _NAV,
  _SYM1,
  _SYM2,
  _NUM,
  _FUN,
  _EURKEY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // ┌─────────────────────────────────────────────────────────────────────┐
  // │ BASE — QWERTY mit GACS Home Row Mods                              │
  // │                                                                     │
  // │ Hyp  Q    W    E    R    T   Vol- Vol+  Y    U    I    O    P  Del  │
  // │ Esc  A/G  S/A  D/C  F/S  G   Mute Play  H    J/S  K/C  L/A  ;/G ' │
  // │ Sft  Z    X    C    V    B              N    M    ,    .    /  Sft  │
  // │               Esc/NAV Spc/SYM1 Tab/FUN  Ent/NUM Bsp/SYM2 Del/EUR  │
  // └─────────────────────────────────────────────────────────────────────┘
  [_BASE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       HY_KEY,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_VOLD,    KC_VOLU,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_ESC,    HM_A,    HM_S,    HM_D,    HM_F,    KC_G, KC_MUTE,    KC_MPLY,    KC_H,    HM_J,    HM_K,    HM_L, HM_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         NAV_ESC,SYM1_SPC, FUN_TAB,   NUM_ENT,SYM2_BSP, EUR_DEL
                                    //`--------------------------'  `--------------------------'
  ),

  // ┌─────────────────────────────────────────────────────────────────────┐
  // │ NAV — Navigation (linker aeusserer Daumen haelt)                   │
  // │                                                                     │
  // │  ·    ·    ·    ·    ·    ·   (V-) (V+) ZAnf  Wrt← Wrt→ ZEnd KillLn Redo │
  // │  ·   GUI  Alt  Ctrl Sft   ·  (Mut)(Ply)  ←    ↓    ↑    →   WrtBs Undo │
  // │  ·    ·    ·    ·    ·    ·              Home PgDn PgUp End  WrtDl Find │
  // │                ░░░░  ·    ·         Ent  Bsp  Del                   │
  // └─────────────────────────────────────────────────────────────────────┘
  [_NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,    KC_TRNS, LGUI(KC_LEFT), LALT(KC_LEFT), LALT(KC_RGHT), LGUI(KC_RGHT), LCTL(KC_K), LGUI(S(KC_Z)),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO, KC_TRNS,    KC_TRNS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, LALT(KC_BSPC), LGUI(KC_Z),
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, LALT(KC_DEL), LGUI(KC_F),
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_TRNS,   KC_NO,   KC_NO,     KC_ENT, KC_BSPC,  KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  // ┌─────────────────────────────────────────────────────────────────────┐
  // │ SYM1 — Symbole rechts (linker mittlerer Daumen haelt)              │
  // │                                                                     │
  // │ Klammern schliessend symmetrisch zu SYM2, Operatoren               │
  // │ Haeufige Zeichen auf Zeige-/Mittelfinger, = und _ auf Daumen      │
  // │                                                                     │
  // │  ·    ·    ·    ·    ·    ·   (V-) (V+)  "    +    *    ^    '   · │
  // │  ·   GUI  Alt  Ctrl Sft   ·  (Mut)(Ply)  ;    )    }    ]    >   · │
  // │  ·    ·    ·    ·    ·    ·              '    -    :    \    |   · │
  // │                 ·   ░░░░  ·          _    =    -                    │
  // └─────────────────────────────────────────────────────────────────────┘
  [_SYM1] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,    KC_TRNS,  KC_DQT, KC_PLUS, KC_ASTR, KC_CIRC, KC_QUOT,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO, KC_TRNS,    KC_TRNS, KC_SCLN, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_QUOT, KC_MINS, KC_COLN, KC_BSLS, KC_PIPE,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO, KC_TRNS,   KC_NO,   KC_UNDS,  KC_EQL, KC_MINS
                                      //`--------------------------'  `--------------------------'
  ),

  // ┌─────────────────────────────────────────────────────────────────────┐
  // │ SYM2 — Symbole links (rechter mittlerer Daumen haelt)              │
  // │                                                                     │
  // │ Klammern oeffnend symmetrisch zu SYM1, Vim-Zeichen                 │
  // │ = und _ auf Daumen (gespiegelt zu SYM1)                            │
  // │                                                                     │
  // │  ·    !    @    #    $    %   (V-) (V+)  ·    ·    ·    ·    ·   · │
  // │  ·    <    [    {    (    &   (Mut)(Ply)  ·   Sft  Ctrl Alt  GUI  · │
  // │  ·    ~    |    \    `    /              ·    ·    ·    ·    ·   · │
  // │                 -    =    _          ·   ░░░░  ·                    │
  // └─────────────────────────────────────────────────────────────────────┘
  [_SYM2] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_NO, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_TRNS,    KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, KC_TRNS,    KC_TRNS,   KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_TILD, KC_PIPE, KC_BSLS,  KC_GRV, KC_SLSH,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_MINS,  KC_EQL, KC_UNDS,      KC_NO, KC_TRNS,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  // ┌─────────────────────────────────────────────────────────────────────┐
  // │ NUM — Taschenrechner (rechter innerer Daumen haelt)                │
  // │                                                                     │
  // │ Numpad links, Modifier rechts. Daumen: Bsp, 0, =                  │
  // │                                                                     │
  // │  ·    /    7    8    9    -   (V-) (V+)  ·    ·    ·    ·    ·   · │
  // │  ·    *    4    5    6    +   (Mut)(Ply)  ·   Sft  Ctrl Alt  GUI  · │
  // │  ·    ,    1    2    3    .              ·    ·    ·    ·    ·   · │
  // │                Bsp   0    =         ░░░░  ·    ·                    │
  // └─────────────────────────────────────────────────────────────────────┘
  [_NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_NO, KC_SLSH,    KC_7,    KC_8,    KC_9, KC_MINS, KC_TRNS,    KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_ASTR,    KC_4,    KC_5,    KC_6, KC_PLUS, KC_TRNS,    KC_TRNS,   KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_COMM,    KC_1,    KC_2,    KC_3,  KC_DOT,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_BSPC,    KC_0,  KC_EQL,   KC_TRNS,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  // ┌─────────────────────────────────────────────────────────────────────────┐
  // │ FUN — Funktionstasten + System (linker innerer Daumen haelt)          │
  // │                                                                         │
  // │  ·   ScBer ScVol ScTlb  ·    ·  (V-)(V+) F12  F7   F8   F9  Bri+ MCtrl│
  // │  ·   GUI   Alt  Ctrl  Sft   ·  (Mut)(Ply) F11  F4   F5   F6   ·  Cmd+` │
  // │  ·   Spc←  Spc→ MPrv  MNxt  ·            F10  F1   F2   F3  Bri-  ·   │
  // │                  ·     ·   ░░░░       ·   CpWd  ·                       │
  // └─────────────────────────────────────────────────────────────────────────┘
  [_FUN] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_NO, LGUI(S(KC_4)), LGUI(S(KC_3)), LGUI(S(KC_5)), KC_NO, KC_NO, KC_TRNS,    KC_TRNS,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_BRIU, LCTL(KC_UP),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO, KC_TRNS,    KC_TRNS,  KC_F11,   KC_F4,   KC_F5,   KC_F6,   KC_NO, LGUI(KC_GRV),
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
       KC_NO, LCTL(KC_LEFT), LCTL(KC_RGHT), KC_MPRV, KC_MNXT, KC_NO,                       KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_BRID,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO,   KC_NO, KC_TRNS,      KC_NO,CW_TOGG,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  // ┌─────────────────────────────────────────────────────────────────────┐
  // │ EURKEY — Umlaute/Sonderzeichen (Hold, rechter aeusserer Daumen)    │
  // │                                                                     │
  // │ Rechten aeusseren Daumen halten, Umlaute tippen.                   │
  // │ Nicht belegte Tasten sind blockiert (KC_NO).                       │
  // │                                                                     │
  // │  ·    Ä    ·    €    ·    ·   (V-) (V+)  ·    ü    ·    ö    ·   · │
  // │  ·    ä    ß    ·    ·    ·   (Mut)(Ply)  ·    Ü    ·    Ö    ·   · │
  // │ Sft   ·    ·    ·    ·    ·              ·    ·    ·    ·    ·  Sft │
  // │                 ·    ·    ·          ·    ·   ░░░░                   │
  // │                                                                     │
  // │ Gleicher Finger fuer klein/gross: ä/Ä (Pinky), ü/Ü (Zeige), ö/Ö  │
  // │ (Ring). Shift auf Pinky-Reihe fuer ß→ẞ falls noetig.              │
  // └─────────────────────────────────────────────────────────────────────┘
  [_EURKEY] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_NO, EU_BIGA,   KC_NO, EU_EURO,   KC_NO,   KC_NO, KC_TRNS,    KC_TRNS,   KC_NO, EU_UUML,   KC_NO, EU_OUML,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_NO, EU_AUML, EU_SZET,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,    KC_TRNS,   KC_NO, EU_BIGU,   KC_NO, EU_BIGO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

};
