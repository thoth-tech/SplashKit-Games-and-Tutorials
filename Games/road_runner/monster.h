#include "splashkit.h"
#include "player1.h"

using namespace std;

enum character_mons
{
    MONSTER,
    MONSTER1,
    FIRE,
    ROCK,
    FGround1,
    SPIKE
};

struct mons_data
{
    sprite mons_sprite;
    sprite spiked;
    character_mons kind_mons;
    int mleve;

    double x, y;
};

mons_data monster();

void draw_mons(const mons_data &player_to_draw);

void update_mons(mons_data &player_to_update);

void update_float_mons(player_data &player, mons_data &mons);

void handle_input_mons(mons_data &player);

void change_mons_level(mons_data &monster_updat, int level);
