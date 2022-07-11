#include "include/my.h"

void init_base(all_t *all)
{
    all->window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32}, "my Rpg",
    sfResize | sfClose | sfTitlebar | sfFullscreen, NULL);
    all->balle = sfSprite_create();
    all->racket1 = sfSprite_create();
    all->racket2 = sfSprite_create();
    all->tex_balle = sfTexture_createFromFile("balle.png", NULL);
    all->tex_racket = sfTexture_createFromFile("barre.png", NULL);
    all->racket1_pos = (sfVector2f) {-150, 500};
    all->racket2_pos = (sfVector2f) {1500, 500};
    all->text = sfText_create();
    all->font = sfFont_createFromFile("bubblegum.ttf");
    float y = random_float();
    y += 5;
    if (y < 0.5)
        y += 0.3;
    all->balle_movement = (sfVector2f) {10, y};
    all->score_player1 = 0;
    all->score_player2 = 0;
}

void close_menu(all_t *all)
{
    if (all->event.type == sfEvtClosed)
        sfRenderWindow_close(all->window);
    if (all->event.type == sfEvtKeyPressed && all->event.key.code == sfKeyEscape)
        sfRenderWindow_close(all->window);
}

void display_first_racket(all_t *all)
{
    sfSprite_setTexture(all->racket1, all->tex_racket, sfTrue);
    sfSprite_setScale(all->racket1, (sfVector2f) {0.25, 0.25});
    sfSprite_setPosition(all->racket1, all->racket1_pos);
    sfRenderWindow_drawSprite(all->window, all->racket1, NULL);
}

void display_second_racket(all_t *all)
{
    sfSprite_setTexture(all->racket2, all->tex_racket, sfTrue);
    sfSprite_setScale(all->racket2, (sfVector2f) {0.25, 0.25});
    sfSprite_setPosition(all->racket2, all->racket2_pos);
    sfRenderWindow_drawSprite(all->window, all->racket2, NULL);
}

void display_balle(all_t *all)
{
    sfSprite_setTexture(all->balle, all->tex_balle, sfTrue);
    sfSprite_setScale(all->balle, (sfVector2f) {0.5, 0.5});
    sfRenderWindow_drawSprite(all->window, all->balle, NULL);
}

void move_balle(all_t *all)
{
    sfSprite_move(all->balle, all->balle_movement);
}

void bounce_ball(all_t *all)
{
    sfVector2f balle_position = sfSprite_getPosition(all->balle);

    if (balle_position.y >= all->racket2_pos.y - 230 && balle_position.y <= all->racket2_pos.y && balle_position.x >= all->racket2_pos.x - 300) {
        all->balle_movement.x = all->balle_movement.x * -1;
    }
    if (balle_position.y >= all->racket1_pos.y - 230 && balle_position.y <= all->racket1_pos.y && balle_position.x <= all->racket1_pos.x - 200) {
        all->balle_movement.x = all->balle_movement.x * -1;
    }
}

void border_topanddown(all_t *all)
{
    sfVector2f balle_position = sfSprite_getPosition(all->balle);

    if (balle_position.y + 250 <= 0 || balle_position.y +1150 >= 1920) {
        all->balle_movement.y = all->balle_movement.y - (all->balle_movement.y * 2);
    }
}


char *my_strcat(char const *src1, char const *src2)
{
    int dest_size = strlen(src1);
    int i = 0;
    int j = 0;
    char *dest = malloc(sizeof(char) * (strlen(src1) + \
    strlen(src2) + 1));

    for (; src1[i] != '\0'; i++)
        dest[i] = src1[i];
    for (; src2[j] != '\0'; i++, j++)
        dest[i] = src2[j];
    dest[i] = '\0';

    return (dest);
}

void my_revstr(char *str)
{
    int len = strlen(str);
    int i = 0;

    while (i < len / 2) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
        i++;
    }
}

char value(int nbr)
{
    if (nbr >= 0 && nbr <= 9) {
        return (char)(nbr) + '0';
    }
    else if (nbr > 9) {
        return (char)(nbr - 10);
    }
    return 'b';
}

char *my_getnbr(int nbr)
{
    int rank = 0;
    char *result = malloc(sizeof(char) * 255);
    if (nbr == 0) {
        return "0";
    }
    while (nbr != 0) {
        result[rank] = value(nbr % 10);
        nbr = nbr / 10;
        rank++;
    }
    result[rank++] = 0;
    my_revstr(result);
    return result;
}
void dispay_score(all_t *all)
{
    all->pos_text.x = 700;
    all->pos_text.y = 0;
    sfText_setString(all->text, my_strcat
    ("player1:  ", my_getnbr(all->score_player1)));
    sfText_setFont(all->text, all->font);
    sfText_setCharacterSize(all->text, 30);
    sfText_setPosition(all->text, all->pos_text);
    sfText_setColor(all->text, sfWhite);
    sfRenderWindow_drawText(all->window, all->text, NULL);
}

void dispay_score2(all_t *all)
{
    all->pos_text.x = 1000;
    all->pos_text.y = 0;
    sfText_setString(all->text, my_strcat
    ("player2:  ", my_getnbr(all->score_player2)));
    sfText_setFont(all->text, all->font);
    sfText_setCharacterSize(all->text, 30);
    sfText_setPosition(all->text, all->pos_text);
    sfText_setColor(all->text, sfWhite);
    sfRenderWindow_drawText(all->window, all->text, NULL);
}

void ad_score(all_t *all)
{
    sfVector2f balle_position = sfSprite_getPosition(all->balle);
    if (balle_position.x + 500 <= 0) {
        all->score_player2 += 1;
        sfSprite_setPosition(all->balle, (sfVector2f) {350, 350});
    }
    if (balle_position.x + 500 >= 1900) {
        all->score_player1 += 1;
        sfSprite_setPosition(all->balle, (sfVector2f) {350, 350});
    }
}

void manage_menu(all_t *all)
{
    display_first_racket(all);
    display_second_racket(all);
    display_balle(all);
    move_balle(all);
    bounce_ball(all);
    border_topanddown(all);
    ad_score(all);
    dispay_score(all);
    dispay_score2(all);
}

void move_secondracket(all_t *all)
{
    if (all->event.key.code == sfKeyUp && all->racket2_pos.y > -50)
        all->racket2_pos.y -= 50;
    if (all->event.key.code == sfKeyDown && all->racket2_pos.y < 850)
        all->racket2_pos.y += 50;
}


void move_firstracket(all_t *all)
{
    if (all->event.key.code == sfKeyZ && all->racket1_pos.y > -50)
        all->racket1_pos.y -= 50;
    if (all->event.key.code == sfKeyS && all->racket1_pos.y < 850)
        all->racket1_pos.y += 50;
}

void manage_pollevent(all_t *all)
{
    move_secondracket(all);
    move_firstracket(all);
}

void my_h(void)
{
    printf("welcome to my pong game\n\n");
    printf("you can play this game with 2 players\n");
    printf("the first one need to press 'z' and 's'\n");
    printf("the second one need to press 'up arrow' and 'down arrow'\n");
    printf("the goal of this game is to send the ball behind the ennemi border\n\n");
    printf("Good luck and Have fun :)\n");
}

int main (int ac, char **av)
{
    if (ac == 2)
        my_h();
    else {
        all_t *all = malloc(sizeof(all_t));
        init_base(all);

        sfSprite_setPosition(all->balle, (sfVector2f) {350, 350});
        sfRenderWindow_setFramerateLimit(all->window, 60);

        while (sfRenderWindow_isOpen(all->window)) {
            printf("%f\n", all->balle_movement.x);
            sfRenderWindow_clear(all->window, sfBlack);
            manage_menu(all);
            sfRenderWindow_display(all->window);
            while (sfRenderWindow_pollEvent(all->window, &all->event)) {
                manage_pollevent(all);
                close_menu(all);
            }
        }
    }
    return 0;
}