#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_swedish.h"
#include "keymap_jp.h"


enum layers {
    DVORAK = 0,
    QWERTY,
    SYMBOLS,
    MOUSE,
    FN,
    SWITCH,
    LAST_LAYER,
};

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_172_255_255,
  HSV_86_255_128,
  HSV_27_255_255,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DVORAK] = LAYOUT_ergodox(
        // left
         KC_EQUAL   ,KC_1              ,KC_2          ,KC_3     ,KC_4      ,KC_5  ,KC_LEFT
        ,KC_DELETE  ,KC_QUOTE          ,KC_COMMA      ,KC_DOT   ,KC_P      ,KC_Y  ,OSL(SYMBOLS)
        ,KC_SLASH   ,KC_A              ,KC_O          ,KC_E     ,KC_U      ,KC_I
        ,KC_LSHIFT  ,LCTL_T(KC_COLON)  ,LALT_T(KC_Q)  ,KC_J     ,KC_K      ,KC_X  ,KC_LGUI
        ,XXXXXXX    ,XXXXXXX           ,KC_ESCAPE     ,KC_LEFT  ,KC_RIGHT

                   ,KC_APPLICATION  ,OSL(SWITCH)
                                    ,KC_HOME
        ,KC_SPACE  ,KC_BSPACE       ,KC_END

        // right
        ,KC_RIGHT      ,KC_6  ,KC_7   ,KC_8     ,KC_9          ,KC_0             ,KC_MINUS
        ,OSL(SYMBOLS)  ,KC_F  ,KC_G   ,KC_C     ,KC_R          ,KC_L             ,KC_BSLASH
                       ,KC_D  ,KC_H   ,KC_T     ,KC_N          ,LT(MOUSE, KC_S)  ,XXXXXXX
        ,KC_RGUI       ,KC_B  ,KC_M   ,KC_W     ,RALT_T(KC_V)  ,RCTL_T(KC_Z)     ,KC_RSHIFT
                              ,KC_UP  ,KC_DOWN  ,KC_ESCAPE     ,KC_APPLICATION   ,MO(SYMBOLS)

        ,OSL(FN)    ,KC_24
        ,KC_PGUP
        ,KC_PGDOWN  ,KC_TAB          ,KC_ENTER
    ),

    [QWERTY] = LAYOUT_ergodox(
        // left
         KC_EQUAL          ,KC_1          ,KC_2          ,KC_3     ,KC_4      ,KC_5  ,KC_LEFT
        ,KC_DELETE         ,KC_Q          ,KC_W          ,KC_E     ,KC_R      ,KC_T  ,OSL(SYMBOLS)
        ,LGUI_T(KC_SLASH)  ,KC_A          ,KC_S          ,KC_D     ,KC_F      ,KC_G
        ,KC_LSHIFT         ,LCTL_T(KC_Z)  ,LALT_T(KC_X)  ,KC_C     ,KC_V      ,KC_B  ,KC_LGUI
        ,XXXXXXX           ,XXXXXXX       ,KC_ESCAPE     ,KC_LEFT  ,KC_RIGHT

                   ,KC_APPLICATION  ,OSL(SWITCH)
                                    ,KC_HOME
        ,KC_SPACE  ,KC_BSPACE       ,KC_END

        // right
        ,KC_RIGHT      ,KC_6  ,KC_7   ,KC_8      ,KC_9            ,KC_0                  ,KC_MINUS
        ,OSL(SYMBOLS)  ,KC_Y  ,KC_U   ,KC_I      ,KC_O            ,KC_P                  ,KC_BSLASH
                       ,KC_H  ,KC_J   ,KC_K      ,KC_L            ,LT(MOUSE, KC_SCOLON)  ,RGUI_T(KC_QUOTE)
        ,KC_RGUI       ,KC_N  ,KC_M   ,KC_COMMA  ,RALT_T(KC_DOT)  ,RCTL_T(KC_SLASH)      ,KC_RSHIFT
                              ,KC_UP  ,KC_DOWN   ,KC_ESCAPE       ,KC_F24                ,MO(SYMBOLS)

        ,OSL(FN)    ,XXXXXXX
        ,KC_PGUP
        ,KC_PGDOWN  ,KC_TAB   ,KC_ENTER
    ),

    [SYMBOLS] = LAYOUT_ergodox(
        // left
         KC_ESCAPE ,KC_F1     ,KC_F2    ,KC_F3        ,KC_F4        ,KC_F5     ,XXXXXXX
        ,XXXXXXX   ,KC_EXLM   ,KC_AT    ,KC_LCBR      ,KC_RCBR      ,KC_PIPE   ,_______
        ,XXXXXXX   ,KC_HASH   ,KC_DLR   ,KC_LPRN      ,KC_RPRN      ,KC_GRAVE
        ,XXXXXXX   ,KC_PERC   ,KC_CIRC  ,KC_LBRACKET  ,KC_RBRACKET  ,KC_TILD   ,KC_LCTRL
        ,XXXXXXX   ,KC_EQUAL  ,_______  ,XXXXXXX      ,XXXXXXX

                  ,RGB_MOD  ,HSV_172_255_255
                            ,HSV_86_255_128
        ,RGB_VAD  ,RGB_VAI  ,HSV_27_255_255

        // right
        ,XXXXXXX ,KC_F6    ,KC_F7    ,KC_F8   ,KC_F9  ,KC_F10     ,KC_F11
        ,_______ ,KC_UP    ,KC_7     ,KC_8    ,KC_9   ,KC_ASTR    ,KC_F12
                 ,KC_DOWN  ,KC_4     ,KC_5    ,KC_6   ,XXXXXXX    ,XXXXXXX
        ,KC_RALT ,KC_AMPR  ,KC_1     ,KC_2    ,KC_3   ,KC_BSLASH  ,XXXXXXX
                           ,XXXXXXX  ,KC_DOT  ,KC_0   ,KC_EQUAL   ,_______

        ,RGB_TOG             ,RGB_SLD
        ,TOGGLE_LAYER_COLOR
        ,XXXXXXX             ,RGB_HUD  ,RGB_HUI
    ),

    [MOUSE] = LAYOUT_ergodox(
        // left
         XXXXXXX  ,XXXXXXX  ,XXXXXXX      ,XXXXXXX     ,XXXXXXX        ,XXXXXXX  ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX  ,KC_MS_WH_UP  ,KC_MS_UP    ,KC_MS_WH_DOWN  ,XXXXXXX  ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX  ,KC_MS_LEFT   ,KC_MS_DOWN  ,KC_MS_RIGHT    ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX      ,XXXXXXX     ,XXXXXXX        ,XXXXXXX  ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX      ,XXXXXXX     ,XXXXXXX

                     ,XXXXXXX     ,XXXXXXX
                                  ,XXXXXXX
        ,KC_MS_BTN1  ,KC_MS_BTN2  ,KC_MS_BTN3

        // right
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX          ,XXXXXXX              ,XXXXXXX              ,XXXXXXX  ,RESET
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX          ,XXXXXXX              ,XXXXXXX              ,XXXXXXX  ,XXXXXXX
                  ,XXXXXXX  ,XXXXXXX          ,XXXXXXX              ,XXXXXXX              ,_______  ,KC_MEDIA_PLAY_PAUSE
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX          ,KC_MEDIA_PREV_TRACK  ,KC_MEDIA_NEXT_TRACK  ,XXXXXXX  ,XXXXXXX
                            ,KC_AUDIO_VOL_UP  ,KC_AUDIO_VOL_DOWN    ,KC_AUDIO_MUTE        ,XXXXXXX  ,XXXXXXX

        ,XXXXXXX  ,XXXXXXX
        ,XXXXXXX
        ,XXXXXXX  ,KC_WWW_BACK  ,KC_WWW_FORWARD
    ),

    [FN] = LAYOUT_ergodox(
        // left
         XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX
        ,XXXXXXX  ,KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5    ,XXXXXXX
        ,XXXXXXX  ,KC_F6    ,KC_F7    ,KC_F8    ,KC_F9    ,KC_F10
        ,XXXXXXX  ,KC_F11   ,KC_F12   ,KC_F13   ,KC_F14   ,KC_F15   ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX

                  ,XXXXXXX  ,XXXXXXX
                            ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX

        // right
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX   ,XXXXXXX
        ,XXXXXXX  ,KC_F16   ,KC_F17   ,KC_F18   ,KC_F19   ,KC_F20    ,XXXXXXX
                  ,KC_F21   ,KC_F22   ,KC_F23   ,KC_F24   ,XXXXXXX   ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,KC_LALT  ,KC_RALT  ,KC_RCTRL  ,XXXXXXX
                            ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX   ,XXXXXXX

        ,_______  ,XXXXXXX
        ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX
    ),

    [SWITCH] = LAYOUT_ergodox(
        // left
         XXXXXXX  ,XXXXXXX     ,XXXXXXX     ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX     ,XXXXXXX     ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX
        ,XXXXXXX  ,DF(DVORAK)  ,DF(QWERTY)  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX     ,XXXXXXX     ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX     ,XXXXXXX     ,XXXXXXX  ,XXXXXXX

                  ,XXXXXXX  ,_______
                            ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX

        // right
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX     ,XXXXXXX     ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX     ,XXXXXXX     ,XXXXXXX
                  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,TO(QWERTY)  ,TO(DVORAK)  ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX     ,XXXXXXX     ,XXXXXXX
                            ,XXXXXXX  ,XXXXXXX  ,XXXXXXX     ,XXXXXXX     ,XXXXXXX

        ,XXXXXXX  ,XXXXXXX
        ,XXXXXXX
        ,XXXXXXX  ,XXXXXXX  ,XXXXXXX
    ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][LAST_LAYER] = {
    [SWITCH] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,205,155},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},

        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,205,155},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
    },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case SWITCH:
      set_layer_color(SWITCH);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_27_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(27,255,255);
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_3_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
