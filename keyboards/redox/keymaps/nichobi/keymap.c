#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK,
  _QWERTY,
  _SYM,
  _NAV
};

// Shortcut to make keymap more readable
#define SYM_L MO(_SYM)
#define NAV_L MO(_NAV)

#define KC_MICM KC_F20
#define KC_COMP KC_RCTL

#define COLEMAK DF(_COLEMAK)
#define QWERTY  DF(_QWERTY)

//#define KC_ALAS LALT_T(KC_PAST)
//#define KC_CTPL LCTL_T(KC_BSLS)

//#define KC_NAGR LT(_NAV, KC_GRV)
//#define KC_NAMI LT(_NAV, KC_MINS)

//#define KC_ADEN LT(_ADJ, KC_END)
//#define KC_ADPU LT(_ADJ, KC_PGUP)

// Force numlock
bool led_update_user(led_t led_state){
  if(!led_state.num_lock) tap_code(KC_NUM_LOCK);
  return true;
}

// Define key overrides
const key_override_t *key_overrides[] = (const key_override_t *[]){
  // Horizontal scrolling while holding shift
  &ko_make_basic(MOD_MASK_SHIFT, KC_WH_U, KC_WH_L),
  &ko_make_basic(MOD_MASK_SHIFT, KC_WH_D, KC_WH_R),
  NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  /* COLEMAK_DH
   *  ______________.------|‾‾‾‾‾‾|------.______                                            ______.------|‾‾‾‾‾‾|------.______________
   * |  ` ~  |   1  |   2  |   3  |   4  |   5  |-------.                          .-------|   6  |   7  |   8  |   9  |   0  | = +   |
   * |_______|______|------|‾‾‾‾‾‾|------|______| [ {   |                          | ] }   |______|------|‾‾‾‾‾‾|------|______|_______|
   * |  Tab  |   Q  |   W  |   F  |   P  |   B  |_______|                          |-------|   J  |   L  |   U  |   Y  | ; :  | - _   |
   * |_______|______|------|‾‾‾‾‾‾|------|______| Delete|                          |Backspc|______|------|‾‾‾‾‾‾|------|______|_______|
   * |  Esc  |   A  |   R  |   S  |   T  |   G  |       |                          |       |   M  |   N  |   E  |   I  |   O  | ' "   |
   * |_______|______|------|‾‾‾‾‾‾|------|______|_______'                          `-------|______|------|‾‾‾‾‾‾|------|______|_______|
   * | Compos|   Z  |   X  |   C  |   D  |   V  |,---------------,        .----------------'   K  |   H  | , <  | . >  | / ?  | \ |   |
   * |_______|______|------|‾‾‾‾‾‾|------|______/       /       /          \       \       \______|------|‾‾‾‾‾‾|------|______|_______|
   *  |QWERTY|      |      | Alt  |    ,-------/-------/-------/            \-------\-------\-------.    | _SYM |      |      |      |
   *  |______|______|------'‾‾‾‾‾‾    / Ctrl  / Shift / Super /              \ Enter \ Space \ _NAV  \    ‾‾‾‾‾‾'------|______|______|
   *                                 '-------/       /       /                \       \       \-------`
   *                                        '---------------'                  `--------------'
   */
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                                   KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_EQL ,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                  ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B   ,KC_LBRC,                   KC_RBRC,KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_SCLN,KC_MINS,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_ESC ,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G   ,KC_DEL ,                   KC_BSPC,KC_M   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_QUOT,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_COMP,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V   ,XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,KC_K   ,KC_H   ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
  //├───────┼───────┼───────┼───────┼──────┬┴──────┬┼───────┼───────┤  ├───────┼───────┼┬──────┴┬──────┼───────┼───────┼───────┼───────┤
     QWERTY ,XXXXXXX,XXXXXXX,KC_LALT,       KC_LCTL, KC_LSFT,KC_LGUI,   KC_ENT ,KC_SPC , NAV_L  ,       SYM_L  ,XXXXXXX,XXXXXXX,XXXXXXX
  //└───────┴───────┴───────┴───────┘      └───────┘└───────┴───────┘  └───────┴───────┘└───────┘      └───────┴───────┴───────┴───────┘
  ),

  [_QWERTY] = LAYOUT(
  /* QWERTY
   *  ______________.------|‾‾‾‾‾‾|------.______                                            ______.------|‾‾‾‾‾‾|------.______________
   * |  ` ~  |   1  |   2  |   3  |   4  |   5  |-------.                          .-------|   6  |   7  |   8  |   9  |   0  | = +   |
   * |_______|______|------|------|------|------| [ {   |                          | ] }   |______|------|‾‾‾‾‾‾|------|______|_______|
   * |  Tab  |   Q  |   W  |   E  |   R  |   T  |-------|                          |-------|   Y  |   U  |   I  |   O  |   P  | - _   |
   * |_______|______|------|------|------|------| Delete|                          |Backspc|______|------|‾‾‾‾‾‾|------|______|_______|
   * |  Esc  |   A  |   S  |   D  |   F  |   G  |       |                          |       |   H  |   J  |   K  |   L  | ; :  | ' "   |
   * |_______|______|------|------|------|------|-------'                          `-------|______|------|‾‾‾‾‾‾|------|______|_______|
   * | Compos|   Z  |   X  |   C  |   V  |   B  '----------------,        .----------------'   N  |   M  | , <  | . >  | / ?  | \ |   |
   * |_______|______|------|------|-------------/       /       /          \       \       \______|------|‾‾‾‾‾‾|------|______|_______|
   *  |COLEMK|      |      | Alt  |    ,-------/-------/-------/            \-------\-------\-------.    | _SYM |      |      |      |
   *  |______|______|------'‾‾‾‾‾‾'   / Ctrl  / Shift / Super /              \ Enter \ Space \ _NAV  \    ‾‾‾‾‾‾'------|______|______|
   *                                '-------/       /       /                \       \       \-------`
   *                                       '---------------'                  '--------------'
   */
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                                   KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_EQL ,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                  ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_LBRC,                   KC_RBRC,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_MINS,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_ESC ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_DEL ,                   KC_BSPC,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_COMP,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
  //├───────┼───────┼───────┼───────┼──────┬┴──────┬┼───────┼───────┤  ├───────┼───────┼┬──────┴┬──────┼───────┼───────┼───────┼───────┤
     COLEMAK,XXXXXXX,XXXXXXX,KC_LALT,       KC_LCTL, KC_LSFT,KC_LGUI,   KC_ENT ,KC_SPC , NAV_L  ,       SYM_L  ,XXXXXXX,XXXXXXX,XXXXXXX
  //└───────┴───────┴───────┴───────┘      └───────┘└───────┴───────┘  └───────┴───────┘└───────┘      └───────┴───────┴───────┴───────┘
  ),

  /* SYM
   *  ______________.------|‾‾‾‾‾‾|------.______                                            ______.------|‾‾‾‾‾‾|------.______________
   * |  F1   |  F2  |  F3  |  F4  |  F5  |  F6  |-------.                          .-------|  F7  |  F8  |  F9  |  F10 |  F11 |  F12  |
   * |_______|______|------|‾‾‾‾‾‾|------|______|       |                          |       |______|------|‾‾‾‾‾‾|------|______|_______|
   * |       |   !  |   @  |   {  |   }  |   |  |_______|                          |-------|   /  |   9  |   8  |   7  |   -  |       |
   * |_______|______|------|‾‾‾‾‾‾|------|______| Delete|                          |Backspc|______|------|‾‾‾‾‾‾|------|______|_______|
   * |       |   #  |   $  |   [  |   ]  |   `  |       |                          |       |   *  |   4  |   5  |   6  |   +  |       |
   * |_______|______|------|‾‾‾‾‾‾|------|______|_______'                          `-------|______|------|‾‾‾‾‾‾|------|______|_______|
   * | Compos|   %  |   ^  |   (  |   )  |   ~  |,---------------,        ,----------------'   0  |   1  |   2  |   3  |   =  |       |
   * |_______|______|------|‾‾‾‾‾‾|------|______/       /       /          \       \       \______|------|‾‾‾‾‾‾|------|______|_______|
   *  |QWERTY|      |      | Alt  |    ,-------/-------/-------/            \-------\-------\-------.    |      |   .  | Enter|      |
   *  |______|______|------'‾‾‾‾‾‾'   / Ctrl  / Shift / Super /              \ Enter \ Space \ _NAV  \   '‾‾‾‾‾‾'------|______|______|
   *                                 '-------/       /       /                \       \       \-------`
   *                                        '---------------'                  `--------------'
   */
  [_SYM] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                                   KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                  ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,KC_EXLM,KC_AT  ,KC_LCBR,KC_RCBR,KC_PIPE,_______,                   _______,KC_PSLS,KC_P7  ,KC_P8  ,KC_P9  ,KC_PMNS,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,KC_HASH,KC_DLR ,KC_LBRC,KC_RBRC,KC_GRV ,_______,                   _______,KC_PAST,KC_P4  ,KC_P5  ,KC_P6  ,KC_PPLS,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,KC_PERC,KC_CIRC,KC_LPRN,KC_RPRN,KC_TILD,_______,_______,   _______,_______,KC_P0  ,KC_P1  ,KC_P2  ,KC_P3  ,KC_PEQL,XXXXXXX,
  //├───────┼───────┼───────┼───────┼──────┬┴──────┬┼───────┼───────┤  ├───────┼───────┼─┬─────┴─┬─────┼───────┼───────┼───────┼───────┤
     _______,_______,_______,_______,       _______, _______,_______,   _______,_______,  _______,      _______,KC_PDOT,KC_PENT,XXXXXXX
  //└───────┴───────┴───────┴───────┘      └───────┘└───────┴───────┘  └───────┴───────┘ └───────┘     └───────┴───────┴───────┴───────┘
  ),

  /* NAV
   *  ______________.------|‾‾‾‾‾‾|------.______                                            ______.------|‾‾‾‾‾‾|------.______________
   * |       |      |      |      |      |      |-------.                          .-------|      |      |      |      |      |       |
   * |_______|______|------|‾‾‾‾‾‾|------|______|       |                          |       |______|------|‾‾‾‾‾‾|------|______|_______|
   * | MicMut| Vol+ | Bri+ |      |PrtScr|      |_______|                          |-------| ⬉ ←  | ⬉ ↓  | ⬉ ↑  | ⬉ →  |LClick|ScrlUp |
   * |_______|______|------|‾‾‾‾‾‾|------|______|       |                          |       |______|------|‾‾‾‾‾‾|------|______|_______|
   * |  Mute | Vol- | Bri- |      |Insert|      |       |                          |       |   ←  |   ↓  |   ↑  |   →  |RClick|ScrlDn |
   * |_______|______|------|‾‾‾‾‾‾|------|______|_______'                          `-------|______|------|‾‾‾‾‾‾|------|______|_______|
   * |       |      |      |      |      |      |,---------------,        .----------------' Home | PgDn | PgUp | End  |      |       |
   * |_______|______|------|‾‾‾‾‾‾|------|______/       /       /          \       \       \______|------|‾‾‾‾‾‾|------|______|_______|
   *  |      |      |      |      |    ,-------/-------/-------/            \-------\-------\-------.    |      |      |      |      |
   *  |______|______|------'‾‾‾‾‾‾'   /       /       /       /              \ Enter \ Space \ _NAV  \   '‾‾‾‾‾‾'------|______|______|
   *                                 '-------/       /       /                \       \       \-------`
   *                                        '---------------'                  `--------------'
   */
  [_NAV] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
     _______,_______,_______,_______,_______,_______,                                   _______,_______,_______,_______,_______,_______,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                  ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_MICM,KC_VOLU,KC_BRIU,XXXXXXX,KC_PSCR,XXXXXXX,_______,                   _______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,KC_BTN1,KC_WH_U,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_MUTE,KC_VOLD,KC_BRID,XXXXXXX,KC_INS ,XXXXXXX,_______,                   _______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_BTN2,KC_WH_D,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,_______,   _______,XXXXXXX,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,XXXXXXX,XXXXXXX,
  //├───────┼───────┼───────┼───────┼──────┬┴──────┬┼───────┼───────┤  ├───────┼───────┼─┬─────┴─┬─────┼───────┼───────┼───────┼───────┤
     XXXXXXX,XXXXXXX,XXXXXXX,_______,       _______, _______,_______,   _______,_______,  _______,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX
  //└───────┴───────┴───────┴───────┘      └───────┘└───────┴───────┘  └───────┴───────┘ └───────┘     └───────┴───────┴───────┴───────┘
  ),

  //[_ADJ] = LAYOUT(
  ////┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //   KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6                                                KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  ////├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //   XXXXXXX ,RESET   ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                          RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  ////├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  ////├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  ////├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
  //   XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,     _______ ,    _______ ,_______ ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  ////└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  //)

};
