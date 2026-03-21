// Gunters Corne Keymap
// =====================
//
// Aufbau:
//   Layer 0  BASE   — QWERTY mit GACS Home Row Mods
//   Layer 1  NAV    — Navigation (Pfeile, Home/End/PgUp/PgDn)
//   Layer 2  SYM    — Symbole (Klammern, Sonderzeichen)
//   Layer 3  NUM    — Zahlen (Nummernblock-Layout links)
//
// Prinzip:
//   Linker Daumen hält Layer → Inhalt rechts, explizite Modifier links.
//   Rechter Daumen hält Layer → Inhalt links, explizite Modifier rechts.
//   CHORDAL_HOLD verhindert Fehlauslösungen der Home Row Mods
//   beim schnellen Tippen (Modifier nur bei gegenüberliegender Hand).
//
// Home Row Mods (GACS — von außen nach innen):
//   Links:  A=GUI  S=Alt  D=Ctrl  F=Shift
//   Rechts: ;=GUI  L=Alt  K=Ctrl  J=Shift
//
// Sondertasten:
//   Oben links: Hyper (Ctrl+Shift+Alt+GUI) — frei für Systemkürzel
//   Home links: Esc (latenzfrei, nicht dual-function)
//   Oben rechts: Delete
//   Extra-Spalten: Vol-  Vol+  Mute  Play/Pause (auf allen Layern)
//
// Thumb-Tasten:
//   Links:  NAV(hold) Space/SYM   Tab
//   Rechts: Enter     Bsp/NUM     AltGr (Right Alt, für EurKey → ä ö ü ß €)

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

// -- Thumb-Tasten -----------------------------------------------------------
#define SYM_SPC  LT(2, KC_SPC)
#define NUM_BSPC LT(3, KC_BSPC)

// -- Sondertasten -----------------------------------------------------------
#define HY_KEY   HYPR(KC_NO)   // Hyper (Ctrl+Shift+Alt+GUI) — frei für Systemkürzel

// -- Layer-Namen -----------------------------------------------------------
enum layers {
  _BASE,
  _NAV,
  _SYM,
  _NUM,
};

#ifdef LAYOUT_split_3x6_3_ex2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // ┌─────────────────────────────────────────────────────────────────────┐
  // │ BASE — QWERTY mit GACS Home Row Mods                              │
  // │                                                                     │
  // │ Hyp  Q    W    E    R    T   Vol- Vol+  Y    U    I    O    P  Del  │
  // │ Esc  A/G  S/A  D/C  F/S  G   Mute Play  H    J/S  K/C  L/A  ;/G ' │
  // │ Sft  Z    X    C    V    B              N    M    ,    .    /  Sft  │
  // │                NAV  Spc  Tab       Ent  Bsp  AltGr                  │
  // │                     /SYM                /NUM                        │
  // └─────────────────────────────────────────────────────────────────────┘
  [_BASE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       HY_KEY,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_VOLD,    KC_VOLU,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_ESC,    HM_A,    HM_S,    HM_D,    HM_F,    KC_G, KC_MUTE,    KC_MPLY,    KC_H,    HM_J,    HM_K,    HM_L, HM_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          MO(1), SYM_SPC,  KC_TAB,    KC_ENT, NUM_BSPC, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  // ┌─────────────────────────────────────────────────────────────────────┐
  // │ NAV — Navigation (linker Daumen hält)                              │
  // │                                                                     │
  // │ Links: explizite Modifier    Rechts: Pfeile, Seitennavigation      │
  // │                                                                     │
  // │  ·    ·    ·    ·    ·    ·   (V-) (V+)  ·    ·    ·    ·    ·   · │
  // │  ·   GUI  Alt  Ctrl Sft   ·  (Mut)(Ply)  ←    ↓    ↑    →    ·   · │
  // │  ·    ·    ·    ·    ·    ·              Home PgDn PgUp End   ·   · │
  // │                ░░░░  ·    ·         Ent  Bsp   ·                    │
  // └─────────────────────────────────────────────────────────────────────┘
  [_NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,    KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO, KC_TRNS,    KC_TRNS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_TRNS,   KC_NO,   KC_NO,     KC_ENT, KC_BSPC,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  // ┌─────────────────────────────────────────────────────────────────────┐
  // │ SYM — Symbole (linker Daumen hält Space)                           │
  // │                                                                     │
  // │ Links: explizite Modifier    Rechts: Symbole und Sonderzeichen     │
  // │                                                                     │
  // │  ·    ·    ·    ·    ·    ·   (V-) (V+)  *    {    }    <    >   `  │
  // │  ·   GUI  Alt  Ctrl Sft   ·  (Mut)(Ply)  =    (    )    ^    :   " │
  // │  ·    ·    ·    ·    ·    ·              +    [    ]    ,    \   |  │
  // │                 ·   ░░░░  ·         Ent   _    ·                    │
  // └─────────────────────────────────────────────────────────────────────┘
  [_SYM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,    KC_TRNS, KC_ASTR, KC_LCBR, KC_RCBR, KC_LABK, KC_RABK,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO, KC_TRNS,    KC_TRNS,  KC_EQL, KC_LPRN, KC_RPRN, KC_CIRC, KC_COLN,  KC_DQT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_PLUS, KC_LBRC, KC_RBRC, KC_COMM, KC_BSLS, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO, KC_TRNS,   KC_NO,     KC_ENT, KC_UNDS,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  // ┌─────────────────────────────────────────────────────────────────────┐
  // │ NUM — Zahlen (rechter Daumen hält Bsp)                             │
  // │                                                                     │
  // │ Links: Nummernblock-Layout   Rechts: explizite Modifier            │
  // │                                                                     │
  // │  ·    *    7    8    9    +   (V-) (V+)  ·    ·    ·    ·    ·   ·  │
  // │  ·    /    1    2    3    0  (Mut)(Ply)  ·   Sft  Ctrl Alt  GUI  ·  │
  // │  ·    ~    4    5    6    -              ·    ·    ·    ·    ·    ·  │
  // │                 ,    =    .          ·   ░░░░  ·                    │
  // └─────────────────────────────────────────────────────────────────────┘
  [_NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_NO, KC_ASTR,    KC_7,    KC_8,    KC_9, KC_PLUS, KC_TRNS,    KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_SLSH,    KC_1,    KC_2,    KC_3,    KC_0, KC_TRNS,    KC_TRNS,   KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
       KC_NO, KC_TILD,    KC_4,    KC_5,    KC_6, KC_MINS,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_COMM,  KC_EQL,  KC_DOT,      KC_NO, KC_TRNS,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

};

#else
// -- Fallback für Corne ohne Extra-Spalten (3x6_3) -------------------------
// Minimales QWERTY ohne Home Row Mods, als Sicherheitsnetz.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                                          KC_LGUI, NAV_ESC,  KC_SPC,     KC_ENT, NUM_BSPC, KC_RALT
  ),
  [_NAV] = LAYOUT_split_3x6_3(
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   KC_NO,   KC_NO,
                                          KC_TRNS,   KC_NO,   KC_NO,     KC_ENT, KC_BSPC,   KC_NO
  ),
  [_SYM] = LAYOUT_split_3x6_3(
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_ASTR, KC_LCBR, KC_RCBR, KC_LABK, KC_RABK,  KC_GRV,
       KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                        KC_EQL, KC_LPRN, KC_RPRN, KC_CIRC, KC_COLN,  KC_DQT,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_PLUS, KC_LBRC, KC_RBRC, KC_COMM, KC_BSLS, KC_PIPE,
                                            KC_NO, KC_TRNS,   KC_NO,     KC_ENT, KC_UNDS,   KC_NO
  ),
  [_NUM] = LAYOUT_split_3x6_3(
       KC_NO, KC_ASTR,    KC_7,    KC_8,    KC_9, KC_PLUS,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO, KC_SLSH,    KC_1,    KC_2,    KC_3,    KC_0,                         KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,   KC_NO,
       KC_NO, KC_TILD,    KC_4,    KC_5,    KC_6, KC_MINS,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                          KC_COMM,  KC_EQL,  KC_DOT,      KC_NO, KC_TRNS,   KC_NO
  ),
};
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), },
  [_NAV]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), },
  [_SYM]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), },
  [_NUM]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), },
};
#endif
