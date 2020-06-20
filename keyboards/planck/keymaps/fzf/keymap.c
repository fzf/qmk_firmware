/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _MOVE,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK
};

#define MOVE MO(_MOVE)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ESCTRL MT(MOD_LCTL, KC_ESC)
#define TG_INPT LGUI(LSFT(KC_9))

#define KC_MUP KC_MS_UP
#define KC_MDN KC_MS_DOWN
#define KC_MLFT KC_MS_LEFT
#define KC_MRGT KC_MS_RIGHT
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2
#define KC_MB3 KC_MS_BTN3
#define KC_MB4 KC_MS_BTN4
#define KC_MB5 KC_MS_BTN5
#define KC_MWUP KC_MS_WH_UP
#define KC_MWDN KC_MS_WH_DOWN

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Bksp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Esctrl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Move  |      |      | GUI  |Lower |    Space    |Raise |      |      |      |Move  |
 * `-----------------------------------------------------------------------------------'
 *
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    ESCTRL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    MOVE,    _______, _______, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, _______, _______, MOVE
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   /  |   [  |   {  |   }  |   ]  |Bksp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   ^  |   &  |   *  |  \   |   =  |Left  |Down  |Up    |Right |  _   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
 */

[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_SLSH, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_BSPC,
    KC_DEL,  KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_EQL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, KC_ENT ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |   1  |   2  |   3  |      |   ?  |   +  |  |   |   (  |   )  |Bksp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |   4  |   5  |   6  |      |      |      |      |      |  -   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   7  |   8  |   9  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   0  |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  _______, KC_1,    KC_2,    KC_3,    _______, KC_QUES, KC_PLUS, KC_PIPE, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, KC_RPRN, KC_ENT,
    _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_0,    _______, _______, _______, _______, _______, _______, _______, _______
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |Tab   |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |Bksp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Esctrl|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Move  |      |      | GUI  |Lower |    Space    |Raise |      |      |      |Move  |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    ESCTRL,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
    MOVE,    _______, _______, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, _______, _______, MOVE
),

/* Movement
 * ,-----------------------------------------------------------------------------------.
 * |      |MsBut2|Ms Up |MsBut1|MsWhUp|      | Home | PgDn | PgUp |  End |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Ms Lft|Ms Dn |Ms Rgt|MsWhDn|      | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
 */
[_MOVE] = LAYOUT_planck_grid(
    _______, _______, _______, KC_UP,   _______, KC_MWUP, KC_MB2,  _______, KC_MB1,  _______, _______, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MWDN, KC_MLFT, KC_MDN,  KC_MUP,  KC_MRGT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |Debug |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|Move  |Dvorak|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET,   _______, DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, TG_INPT,
    _______, _______, _______, QWERTY,  _______, _______, DVORAK,  _______, MOVE,    _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return false;
  }
}
