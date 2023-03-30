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
    open_window("Game", 1600, 900);
    load_resources();

    player_data player;
    player = new_player();

    while (key_up(ESCAPE_KEY))
    {
        process_events();
        handle_input(player);

        update_player(player);

        clear_screen();

        draw_bitmap("bg", 0, 0, option_to_screen(option_scale_bmp(3, 1)));
        draw_bitmap("bg1", 0, 650, option_to_screen(option_scale_bmp(3, 1)));

        draw_player(player);

        refresh_screen(60);
    }

    return 0;
}