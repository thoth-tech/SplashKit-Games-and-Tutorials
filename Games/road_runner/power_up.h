#include "splashkit.h"
#include <vector>
using namespace std;

#define PLAYER_SPEED 1.5
#define PLAYER_ROTATE_SPEED 3
#define SCREEN_BORDER 100

enum power_up_kind
{
    shield,
    power,
    fuel,
    diamond,
    coin,
    heart,
    nos
};

/**
 * The power data keeps track of all of the information related to the power.
 *
 * @field   power_up_sprite   The powerup's sprite - used to track position and movement
 * @field   power_visit    If the powerup visited, true, if not, false.
 * @field   kind            Current kind of powerup ship
 */
struct power_up_data
{
    sprite power_up_sprite;
    bool power_visit;
    power_up_kind kind;
};

/**
 * Actions a step update of the player - moving them and adjusting the camera.
 *
 * @param player_to_update      The player being updated
 */
bitmap power_up_bitmap(power_up_kind kind);
/**
 * Creates a new power in the at the desired x and y coordinates.
 *
 * @param  x,y  The x and y coordinates of the powerup
 * @returns     The new power data
 */
power_up_data new_power_up(double x, double y);
/**
 * Draws the power to the screen.
 *
 * @param power_to_draw    The power to draw to the screen
 */
void draw_power(const power_up_data &power_to_draw);
/**
 * Actions a step update of the power.
 *
 * @param power_to_update     The power being updated
 */
void update_power(power_up_data &power_to_update);