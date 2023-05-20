#include "splashkit.h"
#include "Level1.h"

using namespace std;
bool win_close = false;

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

    open_window("Game", WIDTH, HEIGHT);
    load_resources();

    while (win_close == false)
    {
        play_sound_effect("Lobby");

        while (key_up(SPACE_KEY))
        {
            process_events();

            clear_screen(COLOR_ANTIQUE_WHITE);

            menu();

            if (quit_requested())
            {
                win_close = true;
                break;
            }

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

        while (win_close == false and player.level == 1)
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
        while (win_close == false and player.level == 2)
        {

            process_events();

            change_mons_level(mons, 2);

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
                delay(2000);
                break;
            }
            if (player.win == true)
            {
                delay(2000);
                break;
            }
            refresh_screen(60);
        }


        while (win_close == false and player.level == 3)
        {
            process_events();

            handle_input_mons(mons);

            change_mons_level(mons, 3);

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
                delay(2000);
                break;
            }
            if (player.win == true)
            {
                delay(2000);
                break;
            }
            refresh_screen(60);
        }

        if (player.close == true)
        {
            float width = (screen_width() - bitmap_width("loss")) / 2;
            float heigth = (screen_height() - bitmap_height("loss")) / 2;

            clear_screen(COLOR_BLACK);

            draw_bitmap("loss", width, heigth);

            write_line("YOU LOSS");

            refresh_screen(60);

            delay(2000);
        }
        if (player.win == true)
        {
            delay(2000);

            float width = (screen_width() - bitmap_width("won")) / 2;
            float heigth = (screen_height() - bitmap_height("won")) / 2;

            clear_screen(COLOR_BLACK);

            draw_bitmap("won", width, heigth);

            write_line("YOU WON");

            refresh_screen(60);

            delay(2000);
        }
        refresh_screen(60);
    }

    return 0;
}
