#include "power_up.h"
#include "player1.h"
#include "splashkit.h"

bitmap power_up_bitmap(power_up_kind kind)
{
    switch (kind)
    {
    case coin:
        return bitmap_named("coin");
    default:
        return bitmap_named("coin");
    }
}

/**
 * Creates a new power in the at the desired x and y coordinates.
 *
 * @param  x,y  The x and y coordinates of the powerup
 * @returns     The new power data
 */
power_up_data new_power_up(double x, double y)
{
    float_data brick;
    ;
    power_up_data result;
    result.kind = static_cast<power_up_kind>(1);
    result.power_up_sprite = create_sprite(power_up_bitmap(result.kind));
    result.power_visit = false;

    sprite_set_x(result.power_up_sprite, sprite_width(brick.float_sprite) / 2);
    sprite_set_y(result.power_up_sprite, 450);

    return result;
}

void draw_power(const power_up_data &power_to_draw)
{
    draw_sprite(power_to_draw.power_up_sprite);
}