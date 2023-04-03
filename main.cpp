#include "splashkit.h"

int main()
{
    open_window("Game", 1280, 720);

    while (key_up(ESCAPE_KEY))
    {
        process_events();

        clear_screen(COLOR_BLACK);

        refresh_screen(60);
    }

    close_window("Game");

    return 0;
}