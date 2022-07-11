/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** include
*/

#ifndef MY_INCLUDE
    #define MY_INCLUDE

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <SFML/Network.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Text.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Types.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/OpenGL.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <math.h>
    #include <time.h>
    #include <string.h>
    #include <stddef.h>
    #include <limits.h>
    #include <dirent.h>

    #define WIDTH 1920
    #define HEIGHT 1080


    typedef struct all {
        sfRenderWindow *window;
        sfSprite *balle;
        sfSprite *racket1;
        sfVector2f racket1_pos;
        sfVector2f racket2_pos;
        sfVector2f balle_pos;
        sfVector2f balle_movement;
        float value_y;
        sfSprite *racket2;
        sfTexture *tex_balle;
        sfTexture *tex_racket;
        int score_player1;
        int score_player2;
        sfText *text;
        sfFont *font;
        sfVector2f pos_text;
        sfEvent event;
    } all_t;

    float random_float();
#endif
