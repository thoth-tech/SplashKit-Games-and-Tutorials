#include "splashkit.h"
#include "player1.h"

using namespace std;

#define WIDTH 1280
#define HEIGHT 720

enum power_b
{
    COIN3,
    COIN1,
    COIN2,
};

struct power_data
{
    sprite power_sprite;
    power_b kind;
    int heart;
};

bitmap bitmap_power(power_b kind);

power_data new_power();

void draw_power(const power_data &power_to_draw);

void score_hud(power_data &power);

void update_power(player_data &player, power_data &power);