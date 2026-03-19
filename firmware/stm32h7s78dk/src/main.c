#include <stdint.h>
#include <stdbool.h>
#include "splash_flow.h"

/*
 * Replace these hooks with STM32CubeIDE-generated BSP/LCD functions.
 */
static uint32_t board_millis(void);
static void board_lcd_init(void);
static void board_lcd_clear(void);
static void board_lcd_draw_centered_text(const char *text);
static void board_delay_ms(uint32_t ms);

int main(void) {
    splash_flow_t splash;
    splash_state_t prev_state = SPLASH_STATE_BOOT;

    const splash_timing_t timing = {
        .life_augmented_ms = 2500,
        .future_electronics_ms = 0
    };

    board_lcd_init();
    board_lcd_clear();

    splash_flow_init(&splash, board_millis(), timing, true);

    while (1) {
        splash_flow_update(&splash, board_millis());

        if (splash_flow_should_redraw(&splash, prev_state)) {
            board_lcd_clear();
            board_lcd_draw_centered_text(splash_flow_text(&splash));
            prev_state = splash.state;
        }

        board_delay_ms(10);
    }
}

static uint32_t board_millis(void) { return 0; }
static void board_lcd_init(void) {}
static void board_lcd_clear(void) {}
static void board_lcd_draw_centered_text(const char *text) { (void)text; }
static void board_delay_ms(uint32_t ms) { (void)ms; }
