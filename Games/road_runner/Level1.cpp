#include "Level1.h"
#include "splashkit.h"
#include "timers.h"

int score = 0;

bitmap bitmap_power(power_b kind)
{
    switch (kind)
    {
    case COIN1:
        return bitmap_named("coin_bronz");
    case COIN2:
        return bitmap_named("coin_silver");
    case COIN3:
        return bitmap_named("coin_gold");
    default:
        return bitmap_named("coin_bronz");
    }
}

power_data new_power()
{
    power_data result;
    float_data brick;
    brick = new_float();

    // bitmap default_bitmap = bitmap_player(COIN);

    // result.power_sprite = create_sprite(default_bitmap);

    result.kind = static_cast<power_b>(rnd(4));
    result.power_sprite = create_sprite(bitmap_power(result.kind));

    sprite_set_x(result.power_sprite, rnd(80, 1000));
    sprite_set_y(result.power_sprite, rnd(100, 600));

    return result;
}

void draw_power(const power_data &power)
{
    draw_sprite(power.power_sprite);
}

void remove_sprite(const power_data &power)
{
    if (power.kind == COIN1)
    {
        sprite_hide_layer(power.power_sprite, static_cast<int>(COIN1));
    }
    if (power.kind == COIN2)
    {
        sprite_hide_layer(power.power_sprite, static_cast<int>(COIN2));
    }
    if (power.kind == COIN3)
    {
        sprite_hide_layer(power.power_sprite, static_cast<int>(COIN3));
    }
}

void add_power(power_data &result, float_data &brick)
{
    result = new_power();
    if (!sprite_collision(result.power_sprite, brick.float_sprite) || !sprite_collision(result.power_sprite, brick.float_sprite1) || !sprite_collision(result.power_sprite, brick.float_sprite2) || !sprite_collision(result.power_sprite, brick.float_sprite3))
    {
        draw_power(result);
        write_line("x " + to_string(sprite_x(result.power_sprite)) + " y " + to_string(sprite_y(result.power_sprite)));
    }
    else
    {
        result = new_power();
    }
}

void apply_powers(power_data &powers)
{
    if (powers.kind == COIN1)
    {
        play_sound_effect("coin_collect");
    }

    else if (powers.kind == COIN2)
    {
        play_sound_effect("coin_collect");
    }

    else if (powers.kind == COIN3)
    {
        play_sound_effect("coin_collect");
    }
}

void score_hud(power_data &power, player_data &player)
{
    font my_font = load_font("Magma", "Magma.ttf");

    draw_text("SCORE: " + to_string(score), COLOR_BLACK, my_font, 20, 125, 20, option_to_screen());
    draw_text("HEALTH:", COLOR_BLACK, my_font, 20, 260, 20, option_to_screen());

    int a = 300;

    if (player.level == 1)
    {
        for (int i = 1; i <= player.count; i++)
        {
            draw_bitmap("heart", a, -20, option_to_screen(option_scale_bmp(0.5, 0.5)));
            a += 50;
        }

        if (score >= 1000)
        {
            delay(2000);
            float width = (screen_width() - bitmap_width("levelup")) / 2;
            float heigth = (screen_height() - bitmap_height("levelup")) / 2;

            clear_screen(COLOR_BLACK);

            draw_bitmap("levelup", width, heigth);

            write_line("Level up");

            refresh_screen(60);

            play_sound_effect("level");

            delay(2000);

            score = 0;
            player.level = 3;
        }
    }
    if (player.level == 3)
    {
        for (int i = 1; i <= player.count; i++)
        {
            draw_bitmap("heart", a, -20, option_to_screen(option_scale_bmp(0.5, 0.5)));
            a += 50;
        }

        if (score >= 1000)
        {
            player.win = true;
            score = 0;
        }
    }
}

void update_power(player_data &player, power_data &power)
{
    float_data brick;
    if (sprite_collision(player.player_sprite, power.power_sprite))
    {
        apply_powers(power);
        remove_sprite(power);
        if (power.kind == COIN1)
        {
            score += 100;
        }

        else if (power.kind == COIN2)
        {
            score += 250;
        }

        else if (power.kind == COIN3)
        {
            score += 500;
        }
        else
        {
            score += 100;
        }
        add_power(power, brick);
    }
}