#include "player1.h"
#include "splashkit.h"
#include <math.h>

int main();

struct Ground
{
    double x, y;
    double width, height;
};

struct Player
{
    double x, y;
    double width, height;
    double velocity_x, velocity_y;
    bool on_ground;
};

bool check_collision(const Player &player, const Ground &ground)
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
    default:
        return bitmap_named("person");
    }
}

player_data new_player()
{
    player_data result;
    bitmap default_bitmap = bitmap_player(PERSON);

    result.player_sprite = create_sprite(default_bitmap);

    sprite_add_layer(result.player_sprite, bitmap_player(PERSON1), "person1");

    sprite_hide_layer(result.player_sprite, 1);

    result.kind = PERSON;

    sprite_set_x(result.player_sprite, 0);
    sprite_set_y(result.player_sprite, 650);

    return result;
}

void draw_player(const player_data &player_to_draw)
{
    draw_sprite(player_to_draw.player_sprite);
}

void update_player(player_data &player_to_update)
{
    update_sprite(player_to_update.player_sprite);

    double left_edge = camera_x() + SCREEN_BORDER;
    double right_edge = left_edge + screen_width() - 2 * SCREEN_BORDER;
    double top_edge = camera_y() + SCREEN_BORDER;
    double bottom_edge = top_edge + screen_height() - 2 * SCREEN_BORDER;

    point_2d sprite_center = center_point(player_to_update.player_sprite);

    if (sprite_center.y < top_edge)
        move_camera_by(0, sprite_center.y - top_edge);
    if (sprite_center.y > bottom_edge)
        move_camera_by(0, sprite_center.y - bottom_edge);
    if (sprite_center.x < left_edge)
        move_camera_by(sprite_center.x - left_edge, 0);
    if (sprite_center.x > right_edge)
        move_camera_by(sprite_center.x - right_edge, 0);
}


void handle_input(player_data &player)
{
    int x = 0;
    if (key_down(UP_KEY))
    {
        move_sprite(player.player_sprite, {0, 1}, -5);
    }
    if (key_down(LEFT_KEY))
    {
        sprite_show_layer(player.player_sprite, static_cast<int>(PERSON1));
        sprite_hide_layer(player.player_sprite, static_cast<int>(PERSON));

        move_sprite(player.player_sprite, {1, 0}, -3);
    }
    if (key_down(RIGHT_KEY))
    {
        sprite_show_layer(player.player_sprite, static_cast<int>(PERSON));
        sprite_hide_layer(player.player_sprite, static_cast<int>(PERSON1));

        move_sprite(player.player_sprite, {1, 0}, 3);
    }
}