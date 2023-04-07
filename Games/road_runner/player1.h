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
};

player_data new_player();

void draw_player(const player_data &player_to_draw);

void update_player(player_data &player_to_update);

void handle_input(player_data &player);

#endif