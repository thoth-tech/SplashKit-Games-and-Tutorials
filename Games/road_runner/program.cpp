#include "splashkit.h"
#include "player1.h"

void load_resources()
{
    load_resource_bundle("game_bundle", "game.txt");
}

string location_to_string(const player_data &player_data)
{
    point_2d location = center_point(player_data.player_sprite);
    int x = (int)location.x;
    int y = (int)location.y;
    return to_string(x) + "," + to_string(y);
}

int main()
{
    open_window("Game", 1280, 720);
    load_resources();

    player_data player;
    player = new_player();

    Ground ground;
    ground.x = 0;
    ground.y = 650;
    ground.width = 1600;
    ground.height = 50;
    ground.ground_color = COLOR_FOREST_GREEN;

    while (key_up(ESCAPE_KEY))
    {
        process_events();
        handle_input(player);

        update_player(player, ground);

        clear_screen();

        draw_bitmap("bg", 0, 0, option_to_screen(option_scale_bmp(3, 1)));

        draw_ground(ground);

        draw_player(player);

        refresh_screen(60);
    }

    return 0;
}