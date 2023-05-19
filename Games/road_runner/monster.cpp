#include "monster.h"
#include "splashkit.h"

int temp = 0;

bitmap bitmap_mons(character_mons kind_mons)
{
    switch (kind_mons)
    {
    case MONSTER:
        return bitmap_named("monster");
    case MONSTER1:
        return bitmap_named("monster1");
    case FGround1:
        return bitmap_named("float_G");
    case SPIKE:
        return bitmap_named("spike");
    default:
        return bitmap_named("monster");
    }
}

mons_data monster()
{
    mons_data result;
    bitmap default_bitmap = bitmap_mons(MONSTER);
    bitmap spikes = bitmap_mons(SPIKE);

    result.mons_sprite = create_sprite(default_bitmap);
    result.spiked = create_sprite(spikes);

    sprite_add_layer(result.mons_sprite, bitmap_mons(MONSTER1), "monster1");

    sprite_hide_layer(result.mons_sprite, 1);

    result.kind_mons = MONSTER;

    result.x = rnd();
    result.y = 280;

    sprite_set_x(result.mons_sprite, result.x);
    sprite_set_y(result.mons_sprite, result.y);

    sprite_set_x(result.spiked, (screen_width() - sprite_width(result.spiked)) / 2);
    sprite_set_y(result.spiked, 590);

    return result;
}

void draw_mons(const mons_data &monster)
{
    draw_sprite(monster.mons_sprite);
    draw_sprite(monster.spiked);
}

void update_mons(mons_data &monster_update)
{
    update_sprite(monster_update.mons_sprite);

    update_sprite(monster_update.spiked);

    if (sprite_x(monster_update.mons_sprite) < 0)
    {
        temp += 1;
        sprite_set_x(monster_update.mons_sprite, 0);
    }
    else if (sprite_x(monster_update.mons_sprite) + sprite_width(monster_update.mons_sprite) > screen_width())
    {
        temp -= 1;
        sprite_set_x(monster_update.mons_sprite, screen_width() - sprite_width(monster_update.mons_sprite));
    }
}

void update_float_mons(player_data &player, mons_data &mons)
{
    if (sprite_collision(mons.mons_sprite, player.player_sprite))
    {
        sprite_set_x(player.player_sprite, rnd());
        sprite_set_y(player.player_sprite, 680);
        player.count -= 1;
        if (player.count <= 0)
        {
            player.close = true;
        }
    }
    if (sprite_collision(mons.spiked, player.player_sprite))
    {
        sprite_set_x(player.player_sprite, rnd());
        sprite_set_y(player.player_sprite, 680);
        player.count -= 1;
        if (player.count <= 0)
        {
            player.close = true;
        }
    }
}

void handle_input_mons(mons_data &mons)
{
    if (temp == 1)
    {
        sprite_show_layer(mons.mons_sprite, static_cast<int>(MONSTER));
        sprite_hide_layer(mons.mons_sprite, static_cast<int>(MONSTER1));

        move_sprite(mons.mons_sprite, {1, 0}, 5);
    }
    if (temp == 0)
    {
        sprite_show_layer(mons.mons_sprite, static_cast<int>(MONSTER1));
        sprite_hide_layer(mons.mons_sprite, static_cast<int>(MONSTER));

        move_sprite(mons.mons_sprite, {1, 0}, -5);
    }
}