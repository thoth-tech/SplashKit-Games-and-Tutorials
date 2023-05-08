#include "Level1.h"
#include "splashkit.h"
#include "timers.h"

int score = 0;
int count = 3;

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

void score_hud(power_data &power)
{
    font my_font = load_font("Magma", "Magma.ttf");

    draw_text("SCORE: " + to_string(score), COLOR_BLACK, my_font, 20, 125, 20, option_to_screen());
    draw_text("HEALTH:", COLOR_BLACK, my_font, 20, 260, 20, option_to_screen());

    int a = 300;
    for (int i = 1; i <= count; i++)
    {
        draw_bitmap("heart", a, -20, option_to_screen(option_scale_bmp(0.5, 0.5)));
        a += 50;
    }

    if (score >= 1000)
    {
        // play_sound_effect("level");

        string message = "Level 1  UP";

        // Calculate the text dimensions
        float x = text_width(message, my_font, 50);
        float y = text_height(message, my_font, 50);

        // Calculate the coordinates of the text
        float width = (screen_width() - x) / 2;
        float heigth = (screen_height() - y) / 2;

        draw_text("LEVEL 1  UP", COLOR_BLACK, my_font, 100, width, heigth, option_to_screen());
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