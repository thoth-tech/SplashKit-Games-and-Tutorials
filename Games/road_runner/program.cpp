#include "splashkit.h"
#include "Level1.h"

using namespace std;

void load_resources()
{
    load_resource_bundle("game_bundle", "game.txt");
    load_sound_effect("coin_collect", "coin_collect.wav");
    load_sound_effect("level", "level.wav");
}

void menu()
{
    font my_font = load_font("Renegade_Pursuit", "Renegade_Pursuit.otf");

    draw_bitmap("menu", (screen_width() - bitmap_width("menu")) / 2, (screen_height() - bitmap_height("menu")) / 2, option_to_screen(option_scale_bmp(1, 1)));
    draw_text("PRESS SPACE TO START", COLOR_BLACK, my_font, 60, (screen_width() - text_width("PRESS SPACE TO START", "Renegade_Pursuit", 60)) / 2, ((screen_height() - text_height("PRESS SPACE TO START", "Renegade_Pursuit", 60)) / 2) + 200, option_to_screen());
}

int main()
{
    load_sound_effect("Lobby", "Lobby.wav");

    play_sound_effect("Lobby");

    open_window("Game", WIDTH, HEIGHT);
    load_resources();

    while (key_up(SPACE_KEY))
    {
        process_events();

        clear_screen(COLOR_ANTIQUE_WHITE);

        menu();

        refresh_screen(60);
    }

    player_data player;
    player = new_player();

    mons_data mons;
    mons = monster();

    float_data brick;
    brick = new_float();

    power_data power;
    power = new_power();

    Ground ground;
    ground.x = 0;
    ground.y = 680;
    ground.width = 1600;
    ground.height = 50;

    stop_sound_effect("Lobby");

    while (key_up(ESCAPE_KEY) && player.level != 3)
    {
        process_events();
        handle_input(player);

        update_player(player, ground);

        update_float(brick, player);

        update_power(player, power);

        clear_screen();

        draw_bitmap("background", 0, 0, option_to_screen(option_scale_bmp(1, 1)));

        level1(brick);

        score_hud(power, player);

        draw_ground(ground);

        draw_player(player);

        draw_float_brick(brick);

        draw_power(power);

        refresh_screen(60);
    }

    while (player.level == 3)
    {
        write_line(player.level);
        process_events();

        handle_input_mons(mons);

        handle_input(player);

        update_mons(mons);

        update_player(player, ground);

        update_float_mons(player, mons);

        update_float(brick, player);

        update_power(player, power);

        clear_screen();

        draw_bitmap("background", 0, 0, option_to_screen(option_scale_bmp(1, 1)));

        score_hud(power, player);

        draw_ground(ground);

        draw_float_brick(brick);

        draw_player(player);

        draw_mons(mons);

        draw_power(power);

        level2(brick);

        if (player.close == true)
        {
            font my_font = load_font("Magma", "Magma.ttf");

            string message = "YOU LOSS";

            // Calculate the text dimensions
            float x = text_width(message, my_font, 50);
            float y = text_height(message, my_font, 50);

            // Calculate the coordinates of the text
            float width = (screen_width() - x) / 2;
            float heigth = (screen_height() - y) / 2;

            draw_text("YOU LOSS 😭😵", COLOR_BLACK, my_font, 100, width, heigth, option_to_screen());

            write_line("you LOSS");

            play_sound_effect("level");

            delay(4000);
            break;
        }
        if (player.win == true)
        {
            break;
        }
        refresh_screen(60);
    }

    return 0;
}