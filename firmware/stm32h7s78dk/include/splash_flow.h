#ifndef SPLASH_FLOW_H
#define SPLASH_FLOW_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    SPLASH_STATE_BOOT = 0,
    SPLASH_STATE_SHOW_LIFE_AUGMENTED,
    SPLASH_STATE_SHOW_FUTURE_ELECTRONICS,
    SPLASH_STATE_FROZEN
} splash_state_t;

typedef struct {
    uint32_t life_augmented_ms;
    uint32_t future_electronics_ms;
} splash_timing_t;

typedef struct {
    splash_state_t state;
    uint32_t state_started_ms;
    splash_timing_t timing;
    bool freeze_enabled;
} splash_flow_t;

void splash_flow_init(splash_flow_t *flow, uint32_t now_ms, splash_timing_t timing, bool freeze_enabled);
void splash_flow_update(splash_flow_t *flow, uint32_t now_ms);
const char *splash_flow_text(const splash_flow_t *flow);
bool splash_flow_should_redraw(const splash_flow_t *flow, splash_state_t previous_state);

#endif
