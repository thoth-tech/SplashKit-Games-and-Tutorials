#include "splashkit.h"

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

void draw_ground(const Ground &ground)
{
    fill_rectangle(COLOR_GREEN, ground.x, ground.y, ground.width, ground.height);
}

bool check_collision(const Player &player, const Ground &ground)
{
    return player.x < ground.x + ground.width &&
           player.x + player.width > ground.x &&
           player.y < ground.y + ground.height &&
           player.y + player.height > ground.y;
}

void update_player(Player &player, double gravity, const Ground &ground)
{
    double terminal_velocity = 500;
    // Update horizontal position and check for collision
    player.x += player.velocity_x * 0.01;
    if (check_collision(player, ground))
    {
        if (player.velocity_x > 0)
        {
            player.x = ground.x - player.width;
        }
        else if (player.velocity_x < 0)
        {
            player.x = ground.x + ground.width;
        }
    }

    // Update vertical position and check for collision
    player.y += player.velocity_y * 0.01;
    player.velocity_y += gravity * 0.01;
    player.on_ground = false;
    // Limit the vertical velocity to the terminal velocity
    if (player.velocity_y > terminal_velocity)
    {
        player.velocity_y = terminal_velocity;
    }

    player.on_ground = false;
    if (check_collision(player, ground))
    {
        if (player.velocity_y > 0)
        {
            player.y = ground.y - player.height;
            player.on_ground = true;
        }
        else if (player.velocity_y < 0)
        {
            player.y = ground.y + ground.height;
        }
    }
}

void draw_player(const Player &player)
{
    fill_rectangle(COLOR_RED, player.x, player.y, player.width, player.height);
}

int main()
{
    open_window("Simple Platformer", 800, 600);

    Player player = {100, 399, 32, 32, 0, 0, false};
    Ground ground = {0, 400, 800, 20};
    double gravity = 1500;
    double jump_strength = 500;

    while (!quit_requested())
    {
        

        clear_screen(COLOR_WHITE);


        if (key_typed(SPACE_KEY) && player.on_ground)
        {
            player.velocity_y = -jump_strength;
            player.on_ground = false;
        }
        if (key_down(A_KEY))
        {
            player.x -= 5;
        }
        if (key_down(D_KEY))
        {
            player.x += 5;  
        }
        

        draw_ground(ground);
        draw_player(player);
        update_player(player, gravity, ground);

        refresh_screen(60);
        process_events();
    }

    return 0;
}
