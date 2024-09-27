#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK_DH = 0,
    _QWERTY,
    _NAV,
    _SYM,
    _FUN,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FUN      MO(_FUN)

#define KC_MICM  KC_F20
#define KC_COMP  KC_RCTL

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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 *
 *   ,-----------------------------------------.                                            ,-----------------------------------------.
 *   | Tab  |   Q  |   W  |   F  |   P  |   B  |                                            |   J  |   L  |   U  |   Y  | ;  : | Bksp |
 *   |------+------+------+------+------+------|                                            |------+------+------+------+------+------|
 *   | Esc  |   A  |   R  |   S  |   T  |   G  |                                            |   M  |   N  |   E  |   I  |   O  | ' "  |
 *   |------+------+------+------+------+------+-------------.                ,-------------+------+------+------+------+------+------|
 *   |Compos|   Z  |   X  |   C  |   D  |   V  |      |      |                |      |      |   K  |   H  | ,  < | . >  | /  ? | \ |  |
 *   `--------------------+------+------+------+------+------|                |------+------+------+------+------+--------------------'
 *                        |      | Alt  | Ctrl | Shift| Super|                | Enter| Space| _NAV | _SYM |F-keys|
 *                        `----------------------------------'                `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B   ,                                   KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_SCLN,KC_BSPC,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
     KC_ESC ,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G   ,                                   KC_M   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_QUOT,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────┐  ┌───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_COMP,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V   ,XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,KC_K   ,KC_H   ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
  //└───────┴───────┴───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┴───────┴───────┘
                             XXXXXXX,KC_LALT,KC_LCTL,KC_LSFT,KC_LGUI,   KC_ENT ,KC_SPC ,NAV    ,SYM    ,FUN
  //                        └───────┴───────┴───────┴───────┴───────┘  └───────┴───────┴───────┴───────┴───────┘
    ),

/*
 * Base Layer: QWERTY
 *
 *   ,-----------------------------------------.                                            ,-----------------------------------------.
 *   | Tab  |   Q  |   W  |   E  |   R  |   T  |                                            |   Y  |   U  |   I  |   O  |   P  | Bksp |
 *   |------+------+------+------+------+------|                                            |------+------+------+------+------+------|
 *   | Esc  |   A  |   S  |   D  |   F  |   G  |                                            |   H  |   J  |   K  |   L  | ;  : | ' "  |
 *   |------+------+------+------+------+------+-------------.                ,-------------+------+------+------+------+------+------|
 *   |Compos|   Z  |   X  |   C  |   V  |   B  |      |      |                |      |      |   N  |   M  | ,  < | . >  | /  ? | \ |  |
 *   `--------------------+------+------+------+------+------|                |------+------+------+------+------+--------------------'
 *                        |      | Alt  | Ctrl | Shift| Super|                | Enter| Space| _NAV | _SYM |F-keys|
 *                        `----------------------------------'                `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                                   KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSPC,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
     KC_ESC ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                                   KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────┐  ┌───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_COMP,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
  //└───────┴───────┴───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┴───────┴───────┘
                             XXXXXXX,KC_LALT,KC_LCTL,KC_LSFT,KC_LGUI,   KC_ENT ,KC_SPC ,NAV    ,SYM    ,FUN
  //                        └───────┴───────┴───────┴───────┴───────┘  └───────┴───────┴───────┴───────┴───────┘
    ),

/*
 * Sym Layer: Symbols and numbers
 *
 *   ,-----------------------------------------.                                            ,-----------------------------------------.
 *   |   `  |   !  |   @  |   #  |   {  |   }  |                                            |   /  |   7  |   8  |   9  |   -  |      |
 *   |------+------+------+------+------+------|                                            |------+------+------+------+------+------|
 *   |   ~  |   $  |   %  |   ^  |   (  |   )  |                                            |   *  |   4  |   5  |   6  |   +  |  .   |
 *   |------+------+------+------+------+------+-------------.                ,-------------+------+------+------+------+------+------|
 *   |Compos|   &  |   <  |   >  |   [  |   ]  |      |      |                |      |      |   0  |   1  |   2  |   3  |   =  |  ,   |
 *   `--------------------+------+------+------+------+------|                |------+------+------+------+------+--------------------'
 *                        |      |      |      |      |      |                |      |      |      |      |      |
 *                        `----------------------------------'                `----------------------------------'
 */
    [_SYM] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_GRV ,KC_EXLM,KC_AT  ,KC_HASH,KC_LCBR,KC_RCBR,                                   KC_SLSH,KC_7   ,KC_8   ,KC_9   ,KC_MINS,_______,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
     KC_TILD,KC_DLR ,KC_PERC,KC_CIRC,KC_LPRN,KC_RPRN,                                   KC_ASTR,KC_4   ,KC_5   ,KC_6   ,KC_PLUS,KC_DOT ,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────┐  ┌───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_COMP,KC_AMPR,KC_LT  ,KC_GT  ,KC_LBRC,KC_RBRC,_______,_______,   _______,_______,KC_0   ,KC_1   ,KC_2   ,KC_3   ,KC_EQL ,KC_COMM,
  //└───────┴───────┴───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┴───────┴───────┘
                             _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
  //                        └───────┴───────┴───────┴───────┴───────┘  └───────┴───────┴───────┴───────┴───────┘
    ),

/*
 * Nav Layer: Media, navigation
 *
 *   ,-----------------------------------------.                                            ,-----------------------------------------.
 *   |MicMut| Vol+ | Bri+ |🖰 MClk|      |      |                                            | 🖰 ←  | 🖰 ↓  | 🖰 ↑  | 🖰 →  |ScrlUp|      |
 *   |------+------+------+------+------+------|                                            |------+------+------+------+------+------|
 *   |M Prev|M Play|M Next|🖰 RClk|🖰 LClk|      |                                            |   ←  |   ↓  |   ↑  |   →  |ScrlDn|      |
 *   |------+------+------+------+------+------+-------------.                ,-------------+------+------+------+------+------+------|
 *   | Mute | Vol- | Bri- |PrtScr|Insert|Delete|      |      |                |      |      | Home | PgDn | PgUp |  End |      |      |
 *   `--------------------+------+------+------+------+------|                |------+------+------+------+------+--------------------'
 *                        |      |      |      |      |      |                |      |      |      |      |      |
 *                        `----------------------------------'                `----------------------------------'
 */
    [_NAV] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_MICM,KC_VOLU,KC_BRIU,KC_BTN3,_______,_______,                                   KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,KC_WH_U,_______,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
     KC_MPRV,KC_MPLY,KC_MNXT,KC_BTN2,KC_BTN1,_______,                                   KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_WH_D,_______,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────┐  ┌───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_MUTE,KC_VOLD,KC_BRID,KC_PSCR,KC_INS ,KC_DEL ,_______,_______,   _______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,_______,
  //└───────┴───────┴───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┴───────┴───────┘
                             _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
  //                        └───────┴───────┴───────┴───────┴───────┘  └───────┴───────┴───────┴───────┴───────┘
    ),

/*
 * Function/adjust Layer: Function keys and adjustments
 *
 *   ,-----------------------------------------.                                            ,-----------------------------------------.
 *   |QWERTY|  F9  | F10  | F11  | F12  |      |                                            |      |      |      |      |      |      |
 *   |------+------+------+------+------+------|                                            |------+------+------+------+------+------|
 *   |COLEMA|  F5  |  F6  |  F7  |  F8  |      |                                            |      |      |      |      |      |      |
 *   |------+------+------+------+------+------+-------------.                ,-------------+------+------+------+------+------+------|
 *   |      |  F1  |  F2  |  F3  |  F4  |      |      |      |                |      |      |      |      |      |      |      |      |
 *   `--------------------+------+------+------+------+------|                |------+------+------+------+------+--------------------'
 *                        |      |      |      |      |      |                |      |      |      |      |      |
 *                        `----------------------------------'                `----------------------------------'
 */
    [_FUN] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
     QWERTY ,KC_F9  ,KC_F10 ,KC_F11, KC_F12 ,_______,                                   _______,_______,_______,_______,_______,_______,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
     COLEMAK,KC_F5  ,KC_F6  ,KC_F7 , KC_F8  ,_______,                                   _______,_______,_______,_______,_______,_______,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────┐  ┌───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,KC_F1  ,KC_F2  ,KC_F3 , KC_F4  ,_______,_______,_______,   _______,_______,_______,_______,_______,_______,_______,_______,
  //└───────┴───────┴───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┴───────┴───────┘
                             _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
  //                        └───────┴───────┴───────┴───────┴───────┘  └───────┴───────┴───────┴───────┴───────┘
    ),

};

#ifdef OLED_ENABLE
#include "oled.c"
#endif
