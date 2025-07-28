#include <math.h>
#include <zmk/input/transform.h>
#include <zmk/input/processor.h>

#define ROTATION_DEGREE -40.0f
#define DEG_TO_RAD(x) ((x) * M_PI / 180.0f)

static struct input_event rotate_event(struct input_event event) {
    float theta = DEG_TO_RAD(ROTATION_DEGREE);

    float x = event.movement.x;
    float y = event.movement.y;

    float new_x = x * cosf(theta) + y * sinf(theta);
    float new_y = -x * sinf(theta) + y * cosf(theta);

    event.movement.x = (int8_t)roundf(new_x);
    event.movement.y = (int8_t)roundf(new_y);

    return event;
}

INPUT_TRANSFORM_DEFINE(custom_rotation, rotate_event);
