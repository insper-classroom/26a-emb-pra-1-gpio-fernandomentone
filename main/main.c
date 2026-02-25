#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int FASE_1    = 13;
const int FASE_2 = 12;
const int FASE_3   = 11;
const int FASE_4 = 10; 
const int LED_PIN = 14;

const int BTN_PIN = 15;

static void all_off(void) {
  gpio_put(FASE_1, 0);
  gpio_put(FASE_2, 0);
  gpio_put(FASE_3, 0);
  gpio_put(FASE_4, 0);
}

int main() {
  stdio_init_all();

  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  gpio_init(FASE_1);    gpio_set_dir(FASE_1, GPIO_OUT);
  gpio_init(FASE_2); gpio_set_dir(FASE_2, GPIO_OUT);
  gpio_init(FASE_3);   gpio_set_dir(FASE_3, GPIO_OUT);
  gpio_init(FASE_4); gpio_set_dir(FASE_4, GPIO_OUT);

  all_off();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN  );

  while (true) {
    if (!gpio_get(BTN_PIN)) {
        gpio_put(LED_PIN, 1);
      for (int i = 0; i <= 512; i++) {
        all_off();
        gpio_put(FASE_1, 1);
        sleep_ms(10);

        all_off();
        gpio_put(FASE_2, 1);
        sleep_ms(10);

        all_off();
        gpio_put(FASE_3, 1);
        sleep_ms(10);

        all_off();
        gpio_put(FASE_4, 1);
        sleep_ms(10);

        all_off();
        }
    gpio_put(LED_PIN, 0);
    }
}
}