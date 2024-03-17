// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    ONE_KEY = SAFE_RANGE
};

const char* palindromes[42] = {
    "A nut for a jar of tuna.\n",
    "Borrow or rob?\n",
    "Taco cat!\n",
    "No lemon, no melon!\n",
    "Go hang a salami, I'm a lasagna hog.\n",
    "Stressed desserts!\n",
    "Rats live on no evil star.\n",
    "Do geese see God?\n",
    "Eva, can I see bees in a cave?\n",
    "Nurse, I spy gypsies, run!\n",
    "UFO tofu!\n",
    "Was it Eliot's toilet I saw?\n",
    "Golf? No sir, prefer prison flog.\n",
    "Doc, note, I dissent. A fast never prevents a fatness. I diet on cod.\n",
    "Dammit, I'm mad!\n",
    "Madam, in Eden, I'm Adam.\n",
    "Mr. Owl ate my metal worm.\n",
    "A man, a plan, a canal – Panama!\n",
    "Amore, Roma.\n",
    "Anne, I vote more cars race Rome to Vienna.\n",
    "Are we not drawn onward, we few, drawn onward to new era?\n",
    "Cigar? Toss it in a can. It is so tragic.\n",
    "Evade me, Dave.\n",
    "Flee to me, remote elf.\n",
    "Meet animals; laminate 'em.\n",
    "Must sell at tallest sum!\n",
    "No, it is open on one position.\n",
    "Oozy rat in a sanitary zoo.\n",
    "Race fast, safe car.\n",
    "Sir, I demand, I am a maid named Iris.\n",
    "Star comedy by Democrats.\n",
    "Too hot to hoot.\n",
    "Was it a car or a cat I saw?\n",
    "Rise to vote, sir.\n",
    "Live on time, emit no evil.\n",
    "Draw, o coward!\n",
    "Campus Motto: Bottoms up, Mac!\n",
    "So many dynamos.\n",
    "Too bad I hid a boot.\n",
    "Sit on a potato pan, Otis!\n",
    "Won't lovers revolt now?\n",
    "A dog! A panic in a pagoda!\n"
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │ X │
     * └───┘
     */
    [0] = LAYOUT_onekey(
        ONE_KEY
    )
};

bool seeded = false;
uint16_t seed_timer;

void keyboard_post_init_user(void) {
    seed_timer = timer_read();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t onekey_timer;

  switch (keycode) {
      case ONE_KEY:
          if (!seeded) {
              srand(timer_elapsed(seed_timer));
              seeded = true;
          }

          if (record->event.pressed) {
               onekey_timer = timer_read();
          } else {
              if (timer_elapsed(onekey_timer) >=5000) {
                  reset_keyboard();
              } else {
                  int r = rand() % 42;
                  SEND_STRING(palindromes[r]);
              }
          }
          return false;
  }
  return true;
}
