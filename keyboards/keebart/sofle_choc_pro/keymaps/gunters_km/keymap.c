// Gunters Sofle Choc Pro Keymap — portiert von Corne (Miryoku-Stil)
// ================================================================
//
// Aufbau (5 Layer + Base):
//   Layer 0  BASE   — QWERTY mit GACS Home Row Mods + Zahlenreihe
//   Layer 1  NAV    — Navigation (Pfeile, Home/End/PgUp/PgDn)
//   Layer 2  SYM    — Symbole beidseitig (oeffnend links, schliessend rechts)
//   Layer 3  NUM    — Taschenrechner (Numpad links, Modifier rechts)
//   Layer 4  FUN    — Funktionstasten F1-F12
//   Layer 5  EURKEY — Umlaute/Sonderzeichen via AltGr (Hold)
//
// Unterschiede zur Corne:
//   - Zahlenreihe oben (Reihe 0)
//   - 5 Daumentasten pro Seite (aeussere 2 unbelegt)
//   - Mitte-Tasten statt Encoder (Mute/Play auf BASE, LLCK auf anderen Layern)
//   - Keine Extra-Spalten (Vol/Mute/Play waren dort auf der Corne)
//
// Home Row Mods (GACS — von aussen nach innen):
//   Links:  A=GUI  S=Alt  D=Ctrl  F=Shift
//   Rechts: ;=GUI  L=Alt  K=Ctrl  J=Shift
//
// Thumb-Tasten (innere 3 von 5, alle LT — Tap + Hold):
//   Links:  Esc/NAV    Space/SYM    Tab/FUN
//   Rechts: Enter/NUM  Bsp/SYM      EURKEY(Hold)

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
#define SYM_SPC  LT(_SYM,  KC_SPC)
#define FUN_TAB  LT(_FUN,  KC_TAB)
#define NUM_ENT  LT(_NUM,  KC_ENT)
#define SYM_BSP  LT(_SYM,  KC_BSPC)

// -- EurKey-Umlaute (AltGr + Buchstabe) -------------------------------------
#define EU_AUML  RALT(KC_A)       // ae
#define EU_OUML  RALT(KC_O)       // oe
#define EU_UUML  RALT(KC_U)       // ue
#define EU_SZET  RALT(KC_S)       // ss
#define EU_EURO  RALT(KC_5)       // Euro
#define EU_BIGA  RALT(S(KC_A))    // Ae
#define EU_BIGO  RALT(S(KC_O))    // Oe
#define EU_BIGU  RALT(S(KC_U))    // Ue

// -- Sondertasten -----------------------------------------------------------
#define HY_KEY   HYPR(KC_NO)      // Hyper (Ctrl+Shift+Alt+GUI)
#define EUR_LY   MO(_EURKEY)      // EurKey-Layer (Hold)

// -- Layer-Namen -----------------------------------------------------------
enum layers {
  _BASE,
  _NAV,
  _SYM,
  _NUM,
  _FUN,
  _EURKEY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // ┌───────────────────────────────────────────────────────────────────────┐
  // │ BASE — QWERTY mit GACS Home Row Mods + Zahlenreihe                  │
  // │                                                                       │
  // │  `    1    2    3    4    5              6    7    8    9    0    -    │
  // │ Hyp   Q    W    E    R    T              Y    U    I    O    P   Del  │
  // │ Esc  A/G  S/A  D/C  F/S   G              H   J/S  K/C  L/A  ;/G  '  │
  // │ Sft   Z    X    C    V    B  Mute  Play  N    M    ,    .    /   Sft │
  // │            ·    Esc/NAV Spc/SYM Tab/FUN  Ent/NUM Bsp/SYM EUR  ·     │
  // └───────────────────────────────────────────────────────────────────────┘
  [_BASE] = LAYOUT_split_4x6_5(
  //,---------------------------------------------------------------.                  ,---------------------------------------------------------------.
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
       HY_KEY,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
       KC_ESC,    HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                                KC_H,    HM_J,    HM_K,    HM_L, HM_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------+------.  ,-------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,          KC_MPLY,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------+------|  |-------+--------+--------+--------+--------+--------+--------|
                          KC_NO,   KC_NO, NAV_ESC, SYM_SPC, FUN_TAB,          NUM_ENT, SYM_BSP,  EUR_LY,   KC_NO,   KC_NO
                      //`----------------------------------------------'  `----------------------------------------------'
  ),

  // ┌───────────────────────────────────────────────────────────────────────┐
  // │ NAV — Navigation (linker aeusserer Daumen haelt)                     │
  // │                                                                       │
  // │  ·    ·    ·    ·    ·    ·              ·    ·    ·    ·    ·    ·   │
  // │  ·    ·    ·    ·    ·    ·             ZAnf Wrt← Wrt→ ZEnd KillLn Redo│
  // │  ·   GUI  Alt  Ctrl Sft   ·             ←    ↓    ↑    →   WrtBs Undo│
  // │  ·    ·    ·    ·    ·    ·  LLCK LLCK Home PgDn PgUp End  WrtDl Find│
  // │            ·   ░░░░  ·    ·         Ent  Bsp  Del   ·    ·           │
  // └───────────────────────────────────────────────────────────────────────┘
  [_NAV] = LAYOUT_split_4x6_5(
  //,---------------------------------------------------------------.                  ,---------------------------------------------------------------.
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                    LGUI(KC_LEFT), LALT(KC_LEFT), LALT(KC_RGHT), LGUI(KC_RGHT), LCTL(KC_K), LGUI(S(KC_Z)),
  //|--------+--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
       KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                            KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, LALT(KC_BSPC), LGUI(KC_Z),
  //|--------+--------+--------+--------+--------+--------+--------+------.  ,-------+--------+--------+--------+--------+--------+--------|
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, QK_LLCK,          QK_LLCK, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, LALT(KC_DEL), LGUI(KC_F),
  //|--------+--------+--------+--------+--------+--------+--------+------|  |-------+--------+--------+--------+--------+--------+--------|
                          KC_NO,   KC_NO, KC_TRNS,   KC_NO,   KC_NO,            KC_ENT, KC_BSPC,  KC_DEL,   KC_NO,   KC_NO
                      //`----------------------------------------------'  `----------------------------------------------'
  ),

  // ┌───────────────────────────────────────────────────────────────────────┐
  // │ SYM — Symbole beidseitig (beide mittleren Daumen)                    │
  // │                                                                       │
  // │  ·    ·    ·    ·    ·    ·              ·    ·    ·    ·    ·    ·   │
  // │  ·    !    @    #    $    %              "    +    *    ^    '    ·   │
  // │  ·    <    [    {    (    &              ;    )    }    ]    >    ·   │
  // │  ·    ~    |    \    `    /  LLCK LLCK   '    -    :    \    |    ·   │
  // │            ·    -    =    _          _    =    -    ·    ·           │
  // └───────────────────────────────────────────────────────────────────────┘
  [_SYM] = LAYOUT_split_4x6_5(
  //,---------------------------------------------------------------.                  ,---------------------------------------------------------------.
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
       KC_NO, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                             KC_DQT, KC_PLUS, KC_ASTR, KC_CIRC, KC_QUOT,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
       KC_NO, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,                            KC_SCLN, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------+------.  ,-------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_TILD, KC_PIPE, KC_BSLS,  KC_GRV, KC_SLSH, QK_LLCK,          QK_LLCK, KC_QUOT, KC_MINS, KC_COLN, KC_BSLS, KC_PIPE,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------+------|  |-------+--------+--------+--------+--------+--------+--------|
                          KC_NO,   KC_NO, KC_MINS,  KC_EQL, KC_UNDS,          KC_UNDS,  KC_EQL, KC_MINS,   KC_NO,   KC_NO
                      //`----------------------------------------------'  `----------------------------------------------'
  ),

  // ┌───────────────────────────────────────────────────────────────────────┐
  // │ NUM — Taschenrechner (rechter innerer Daumen haelt)                  │
  // │                                                                       │
  // │  ·    ·    ·    ·    ·    ·              ·    ·    ·    ·    ·    ·   │
  // │  ·    /    7    8    9    -              ·    ·    ·    ·    ·    ·   │
  // │  ·    *    4    5    6    +              ·   Sft  Ctrl  Alt  GUI  ·   │
  // │  ·    ,    1    2    3    .  LLCK LLCK   ·    ·    ·    ·    ·    ·   │
  // │            ·   Bsp   0    =         ░░░░  ·    ·    ·    ·           │
  // └───────────────────────────────────────────────────────────────────────┘
  [_NUM] = LAYOUT_split_4x6_5(
  //,---------------------------------------------------------------.                  ,---------------------------------------------------------------.
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
       KC_NO, KC_SLSH,    KC_7,    KC_8,    KC_9, KC_MINS,                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
       KC_NO, KC_ASTR,    KC_4,    KC_5,    KC_6, KC_PLUS,                               KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------+------.  ,-------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_COMM,    KC_1,    KC_2,    KC_3,  KC_DOT, QK_LLCK,          QK_LLCK,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------+------|  |-------+--------+--------+--------+--------+--------+--------|
                          KC_NO,   KC_NO, KC_BSPC,    KC_0,  KC_EQL,          KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO
                      //`----------------------------------------------'  `----------------------------------------------'
  ),

  // ┌───────────────────────────────────────────────────────────────────────────┐
  // │ FUN — Funktionstasten + System (linker innerer Daumen haelt)            │
  // │                                                                           │
  // │  ·    ·    ·    ·    ·    ·              F12  F7   F8   F9  F16  F17     │
  // │  ·   ScBer ScVol ScTlb F14  F15          F11  F4   F5   F6  F18  F19   │
  // │  ·   GUI   Alt  Ctrl  Sft   ·            F10  F1   F2   F3  F20  F21   │
  // │  ·   Spc←  Spc→ MPrv  MNxt  ·  LLCK LLCK Vol- Vol+ Mute  ·    ·    ·   │
  // │            ·    ·    ·   ░░░░        ·   CpWd  ·    ·    ·             │
  // └───────────────────────────────────────────────────────────────────────────┘
  [_FUN] = LAYOUT_split_4x6_5(
  //,---------------------------------------------------------------.                  ,---------------------------------------------------------------.
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_F12,   KC_F7,   KC_F8,   KC_F9,  KC_F16,  KC_F17,
  //|--------+--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
       KC_NO, LGUI(S(KC_4)), LGUI(S(KC_3)), LGUI(S(KC_5)), KC_F14, KC_F15,              KC_F11,   KC_F4,   KC_F5,   KC_F6,  KC_F18,  KC_F19,
  //|--------+--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
       KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                              KC_F10,   KC_F1,   KC_F2,   KC_F3,  KC_F20,  KC_F21,
  //|--------+--------+--------+--------+--------+--------+--------+------.  ,-------+--------+--------+--------+--------+--------+--------|
       KC_NO, LCTL(KC_LEFT), LCTL(KC_RGHT), KC_MPRV, KC_MNXT, KC_NO, QK_LLCK, QK_LLCK, KC_VOLD, KC_VOLU, KC_MUTE,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------+------|  |-------+--------+--------+--------+--------+--------+--------|
                          KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,            KC_NO, CW_TOGG,   KC_NO,   KC_NO,   KC_NO
                      //`----------------------------------------------'  `----------------------------------------------'
  ),

  // ┌───────────────────────────────────────────────────────────────────────┐
  // │ EURKEY — Umlaute/Sonderzeichen (Hold, rechter aeusserer Daumen)      │
  // │                                                                       │
  // │  ·    ·    ·    ·    ·    ·              ·    ·    ·    ·    ·    ·   │
  // │  ·    Ae   ·    Euro ·    ·              ·    ue   ·    oe   ·    ·   │
  // │  ·    ae   ss   ·    ·    ·              ·    Ue   ·    Oe   ·    ·   │
  // │ Sft   ·    ·    ·    ·    ·  LLCK LLCK   ·    ·    ·    ·    ·   Sft │
  // │            ·    ·    ·    ·          ·    ·   ░░░░  ·    ·           │
  // └───────────────────────────────────────────────────────────────────────┘
  [_EURKEY] = LAYOUT_split_4x6_5(
  //,---------------------------------------------------------------.                  ,---------------------------------------------------------------.
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
       KC_NO, EU_BIGA,   KC_NO, EU_EURO,   KC_NO,   KC_NO,                               KC_NO, EU_UUML,   KC_NO, EU_OUML,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
       KC_NO, EU_AUML, EU_SZET,   KC_NO,   KC_NO,   KC_NO,                               KC_NO, EU_BIGU,   KC_NO, EU_BIGO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------+------.  ,-------+--------+--------+--------+--------+--------+--------|
    KC_LSFT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, QK_LLCK,          QK_LLCK,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------+------|  |-------+--------+--------+--------+--------+--------+--------|
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO, KC_TRNS,   KC_NO,   KC_NO
                      //`----------------------------------------------'  `----------------------------------------------'
  ),

};
