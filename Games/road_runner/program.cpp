#include "splashkit.h"
#include "Level1.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void load_resources()
{
    load_resource_bundle("game_bundle", "game.txt");
    load_sound_effect("coin_collect", "coin_collect.wav");
}

void menu()
{
    draw_bitmap("menu", (screen_width() - bitmap_width("menu")) / 2, (screen_height() - bitmap_height("menu")) / 2, option_to_screen(option_scale_bmp(1, 1)));
}

int main()
{
    open_window("Game", WIDTH, HEIGHT);
    load_resources();

    while (key_up(SPACE_KEY))
    {
        process_events();

        clear_screen(COLOR_WHITE_SMOKE);

        menu();

        refresh_screen(60);
    }

    player_data player;
    player = new_player();

    float_data brick;
    brick = new_float();

    power_data power;
    power = new_power();

    Ground ground;
    ground.x = 0;
    ground.y = 680;
    ground.width = 1600;
    ground.height = 50;

    while (key_up(ESCAPE_KEY))
    {
        process_events();
        handle_input(player);

        update_player(player, ground);

        update_float(brick, player);

        update_power(player, power);

        clear_screen();

        draw_bitmap("background", 0, 0, option_to_screen(option_scale_bmp(1, 1)));

        score_hud(power);

        draw_ground(ground);

        draw_player(player);

        draw_float_brick(brick);

        draw_power(power);

        refresh_screen(60);
    }

    return 0;
}