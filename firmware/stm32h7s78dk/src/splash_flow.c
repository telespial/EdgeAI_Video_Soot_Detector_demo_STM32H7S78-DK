#include "splash_flow.h"

static uint32_t elapsed_ms(uint32_t now_ms, uint32_t started_ms) {
    return now_ms - started_ms;
}

void splash_flow_init(splash_flow_t *flow, uint32_t now_ms, splash_timing_t timing, bool freeze_enabled) {
    if (!flow) {
        return;
    }

    flow->state = SPLASH_STATE_SHOW_LIFE_AUGMENTED;
    flow->state_started_ms = now_ms;
    flow->timing = timing;
    flow->freeze_enabled = freeze_enabled;
}

void splash_flow_update(splash_flow_t *flow, uint32_t now_ms) {
    if (!flow) {
        return;
    }

    switch (flow->state) {
        case SPLASH_STATE_SHOW_LIFE_AUGMENTED:
            if (elapsed_ms(now_ms, flow->state_started_ms) >= flow->timing.life_augmented_ms) {
                flow->state = SPLASH_STATE_SHOW_FUTURE_ELECTRONICS;
                flow->state_started_ms = now_ms;
            }
            break;

        case SPLASH_STATE_SHOW_FUTURE_ELECTRONICS:
            if (flow->freeze_enabled) {
                flow->state = SPLASH_STATE_FROZEN;
            } else if (elapsed_ms(now_ms, flow->state_started_ms) >= flow->timing.future_electronics_ms) {
                flow->state = SPLASH_STATE_FROZEN;
            }
            break;

        case SPLASH_STATE_FROZEN:
        case SPLASH_STATE_BOOT:
        default:
            break;
    }
}

const char *splash_flow_text(const splash_flow_t *flow) {
    if (!flow) {
        return "";
    }

    switch (flow->state) {
        case SPLASH_STATE_SHOW_LIFE_AUGMENTED:
            return "FUTURE ELECTRONICS FIRE DEMO";
        case SPLASH_STATE_SHOW_FUTURE_ELECTRONICS:
        case SPLASH_STATE_FROZEN:
            return "Future Electronics";
        case SPLASH_STATE_BOOT:
        default:
            return "";
    }
}

bool splash_flow_should_redraw(const splash_flow_t *flow, splash_state_t previous_state) {
    if (!flow) {
        return false;
    }
    return flow->state != previous_state;
}
