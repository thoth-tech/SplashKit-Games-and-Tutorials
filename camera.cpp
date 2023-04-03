#include <splashkit/splashkit.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

camera cam;
bitmap character;
float characterX, characterY;

void load_resources()
{
    character = bitmap_named("character");
}

void update_character_position()
{
    // Update character position here
    characterX += 5;
}

void draw_game_objects()
{
    clear_screen(COLOR_WHITE);
    draw_bitmap(character, characterX, characterY);
}

int main()
{
    open_window("Camera Example", SCREEN_WIDTH, SCREEN_HEIGHT);
    
    // Set character initial position
    characterX = 0;
    characterY = SCREEN_HEIGHT / 2;

    // Create camera object
    cam = create_camera();

    while (!window_close_requested("Camera Example"))
    {
        // Update character position
        update_character_position();

        // Update camera position to follow character
        set_camera_position(cam, characterX - SCREEN_WIDTH / 2, characterY - SCREEN_HEIGHT / 2);

        // Begin camera view
        begin_camera(cam);

        // Draw game objects
        draw_game_objects();

        // End camera view
        end_camera();

        // Update the screen
        refresh_screen(60);
    }

    return 0;
}