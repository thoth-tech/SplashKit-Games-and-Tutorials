#include "player1.h"
#include "splashkit.h"

const double GRAVITY = 0.5;
const double JUMP_STRENGTH = 15;
const double JUMP_STRENGTH1 = 8;

bool check_collision(const player_data &player, const Ground &ground)
{
    return player.x < ground.x + ground.width &&
           player.x + player.width > ground.x &&
           player.y < ground.y + ground.height &&
           player.y + player.height > ground.y;
}

bitmap bitmap_player(character_b kind)
{
    switch (kind)
    {
    case PERSON:
        return bitmap_named("person");
    case PERSON1:
        return bitmap_named("person1");
    case FGround:
        return bitmap_named("float_G");
    default:
        return bitmap_named("person");
    }
}

void draw_ground(const Ground &ground)
{
    fill_rectangle(ground.ground_color, ground.x, ground.y, ground.width, ground.height);
}

player_data new_player()
{
    player_data result;
    bitmap default_bitmap = bitmap_player(PERSON);

    result.player_sprite = create_sprite(default_bitmap);

    sprite_add_layer(result.player_sprite, bitmap_player(PERSON1), "person1");

    sprite_hide_layer(result.player_sprite, 1);

    result.kind = PERSON;

    result.x = 0;
    result.y = 680;
    result.width = sprite_width(result.player_sprite);
    result.height = sprite_height(result.player_sprite);
    result.velocity_x = 0;
    result.velocity_y = 0;
    result.on_ground = false;

    sprite_set_x(result.player_sprite, result.x);
    sprite_set_y(result.player_sprite, result.y);

    return result;
}

float_data new_float()
{
    float_data result;

    bitmap floating = bitmap_player(FGround);
    bitmap floating1 = bitmap_player(FGround);
    bitmap floating2 = bitmap_player(FGround);
    bitmap floating3 = bitmap_player(FGround);

    result.float_sprite = create_sprite(floating);
    result.float_sprite1 = create_sprite(floating1);
    result.float_sprite2 = create_sprite(floating2);
    result.float_sprite3 = create_sprite(floating3);

    return result;
}

void draw_player(const player_data &player_to_draw)
{
    draw_sprite(player_to_draw.player_sprite);
}

void draw_float_brick(const float_data &float_to_draw)
{
    draw_sprite(float_to_draw.float_sprite);
    draw_sprite(float_to_draw.float_sprite1);
    draw_sprite(float_to_draw.float_sprite2);
    draw_sprite(float_to_draw.float_sprite3);
}

void level1(const float_data &float_to_draw)
{
    sprite_set_x(float_to_draw.float_sprite, 0);
    sprite_set_y(float_to_draw.float_sprite, 450);

    sprite_set_x(float_to_draw.float_sprite1, 85 + sprite_width(float_to_draw.float_sprite));
    sprite_set_y(float_to_draw.float_sprite1, 250);

    sprite_set_x(float_to_draw.float_sprite2, 390 + sprite_width(float_to_draw.float_sprite));
    sprite_set_y(float_to_draw.float_sprite2, 450);

    sprite_set_x(float_to_draw.float_sprite3, 870);
    sprite_set_y(float_to_draw.float_sprite3, 200);
}

void level2(const float_data &result)
{
    sprite_set_x(result.float_sprite, 200);
    sprite_set_y(result.float_sprite, 450);

    sprite_set_x(result.float_sprite1, 185 + sprite_width(result.float_sprite));
    sprite_set_y(result.float_sprite1, 250);

    sprite_set_x(result.float_sprite2, 500 + sprite_width(result.float_sprite));
    sprite_set_y(result.float_sprite2, 390);

    sprite_set_x(result.float_sprite3, 970);
    sprite_set_y(result.float_sprite3, 500);
}

void update_player(player_data &player_to_update, const Ground &ground)
{
    update_sprite(player_to_update.player_sprite);

    // Apply gravity
    player_to_update.velocity_y += GRAVITY;
    player_to_update.y += player_to_update.velocity_y;
    sprite_set_y(player_to_update.player_sprite, player_to_update.y);

    // Check for ground collision
    if (check_collision(player_to_update, ground))
    {
        player_to_update.on_ground = true;
        player_to_update.velocity_y = 0;
        player_to_update.y = ground.y - player_to_update.height;
        sprite_set_y(player_to_update.player_sprite, player_to_update.y);
    }
    else
    {
        player_to_update.on_ground = false;
    }

    if (sprite_x(player_to_update.player_sprite) < 0)
    {
        sprite_set_x(player_to_update.player_sprite, 0);
    }
    else if (sprite_x(player_to_update.player_sprite) + sprite_width(player_to_update.player_sprite) > screen_width())
    {
        sprite_set_x(player_to_update.player_sprite, screen_width() - sprite_width(player_to_update.player_sprite));
    }
}

void update_float(float_data &brick, player_data &player)
{
    if (sprite_collision(brick.float_sprite, player.player_sprite))
    {
        player.on_ground = true;
        // player.velocity_y = 0;
        player.y = sprite_y(brick.float_sprite) - sprite_height(player.player_sprite);
        sprite_set_y(player.player_sprite, player.y);
    }
    else if (sprite_collision(brick.float_sprite1, player.player_sprite))
    {
        player.on_ground = true;
        // player.velocity_y = 0;
        player.y = sprite_y(brick.float_sprite1) - sprite_height(player.player_sprite);
        sprite_set_y(player.player_sprite, player.y);
    }
    else if (sprite_collision(brick.float_sprite2, player.player_sprite))
    {
        player.on_ground = true;
        // player.velocity_y = 0;
        player.y = sprite_y(brick.float_sprite2) - sprite_height(player.player_sprite);
        sprite_set_y(player.player_sprite, player.y);
    }
    else if (sprite_collision(brick.float_sprite3, player.player_sprite))
    {
        player.on_ground = true;
        // player.velocity_y = 0;
        player.y = sprite_y(brick.float_sprite3) - sprite_height(player.player_sprite);
        sprite_set_y(player.player_sprite, player.y);
    }
}

void handle_input(player_data &player)
{
    if (key_down(UP_KEY))
    {
        move_sprite(player.player_sprite, {0, 1}, -5);
    }
    if (key_down(LEFT_KEY))
    {
        sprite_show_layer(player.player_sprite, static_cast<int>(PERSON1));
        sprite_hide_layer(player.player_sprite, static_cast<int>(PERSON));

        move_sprite(player.player_sprite, {1, 0}, -4);
    }
    if (key_down(RIGHT_KEY))
    {
        sprite_show_layer(player.player_sprite, static_cast<int>(PERSON));
        sprite_hide_layer(player.player_sprite, static_cast<int>(PERSON1));

        move_sprite(player.player_sprite, {1, 0}, 4);
    }
    if (key_typed(SPACE_KEY) && player.on_ground)
    {
        player.velocity_y = -JUMP_STRENGTH;
        player.y += player.velocity_y;
        sprite_set_y(player.player_sprite, player.y);
    }
    if (key_typed(LEFT_CTRL_KEY) && player.on_ground)
    {
        player.velocity_y = -JUMP_STRENGTH1;
        player.y += player.velocity_y;
        sprite_set_y(player.player_sprite, player.y);
    }
}