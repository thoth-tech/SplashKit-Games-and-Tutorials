#ifndef LOST_IN_SPACE_PLAYER
#define LOST_IN_SPACE_PLAYER

#include "splashkit.h"
#include <vector>

using namespace std;

#define PLAYER_ROTATE_SPEED 3
#define SCREEN_BORDER 100

enum character_b
{
    PERSON,
    PERSON1
};

struct player_data
{
    sprite player_sprite;
    character_b kind;

    double x, y;
    double width, height;
    double velocity_x, velocity_y;
    bool on_ground;
};

struct Ground
{
    double x, y;
    double width, height;
    color ground_color;
};

player_data new_player();

void draw_player(const player_data &player_to_draw);

void update_player(player_data &player_to_update, const Ground& ground);

void handle_input(player_data &player);

void draw_ground(const Ground& ground);

#endif