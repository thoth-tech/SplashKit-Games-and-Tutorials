#include "splashkit.h"
#include "player1.h"

using namespace std;

enum character_mons
{
    MONSTER,
    MONSTER1,
    FGround1
};

struct mons_data
{
    sprite mons_sprite;
    character_mons kind_mons;

    double x, y;
    bool on_ground;
};

struct mons_float_data
{
    sprite float_sprite, float_sprite1, float_sprite2, float_sprite3, float_sprite4;
    character_b kind;
};

mons_data monster();

void draw_mons(const mons_data &player_to_draw);

void update_mons(mons_data &player_to_update);

void update_float_mons(player_data &player, mons_data &mons);

void handle_input_mons(mons_data &player);