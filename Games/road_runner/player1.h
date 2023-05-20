#include "splashkit.h"

using namespace std;

enum character_b
{
    PERSON,
    PERSON1,
    FGround
};

struct player_data
{
    sprite player_sprite;
    character_b kind;

    double x, y;
    double width, height;
    double velocity_x, velocity_y;
    bool on_ground;
    int count = 3;
    int level = 1;
    bool close = false;
    bool win = false;
};

struct float_data
{
    sprite float_sprite, float_sprite1, float_sprite2, float_sprite3, float_sprite4;
    character_b kind;
};

struct Ground
{
    double x, y;
    double width, height;
    color ground_color;
};

player_data new_player();

float_data new_float();

void draw_player(const player_data &player_to_draw);

void draw_float_brick(const float_data &float_to_draw);

void update_player(player_data &player_to_update, const Ground &ground);

void update_float(float_data &brick, player_data &player);

void level1(const float_data &float_to_draw);

void level2(const float_data &result);

void handle_input(player_data &player);

void draw_ground(const Ground &ground);