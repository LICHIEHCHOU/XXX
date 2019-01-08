#include <stdio.h>
#include <stdlib.h>

#include "functionlist.h"
#include "header.h"

int main( void )
{
    g GAME;
    /* first, set up Allegro and the graphics mode */
    al_init(); /* initialize Allegro */
    al_install_keyboard(); /* install the keyboard for Allegro to use */
    al_init_image_addon();

    // Initial game structure
    gameStructInit(&GAME);

    // display = al_create_display(SCREEN_W, SCREEN_H);
    GAME.display = al_create_display(SCREEN_W, SCREEN_H);
    // bar1 = al_load_bitmap( "bar1.jpg"); /* load the bar bitmap */
    GAME.bar1 = al_load_bitmap( "bar1.bmp"); /* load the bar bitmap */
    // barD_x = SCREEN_H / 2; /* give right paddle its initial X-coordinate */
    GAME.brick = al_load_bitmap( "brick.jpg");
    GAME.barD_x = SCREEN_W / 2; /* give right paddle its initial X-coordinate */

    while(1)
    {
        // al_get_keyboard_state(&KBstate);
        al_get_keyboard_state(&GAME.KBstate);
        // if (al_key_down(&KBstate, ALLEGRO_KEY_ESCAPE))
        if (al_key_down(&GAME.KBstate, ALLEGRO_KEY_ESCAPE))
            break;

        // moveAming(); /* move the paddles */
         /* move the paddles */

        // al_draw_bitmap( bar1, barD_x,barD_y-100, 0);
        al_draw_bitmap( GAME.bar1, GAME.barD_x,GAME.barD_y, 0);
        al_draw_bitmap(GAME.brick,GAME.x,GAME.y,0);
moveAming(&GAME);
        groundthorn(&GAME);
        al_rest(0.01);

        /* display */
        al_flip_display(); /* Wait for the beginning of a vertical retrace. */
        al_clear_to_color(al_map_rgb(0,0,0));

        /* Clear the complete target bitmap, but confined by the clipping rectangle. */
    }

    // al_destroy_display( bar1);
    al_destroy_bitmap( GAME.bar1);
    // al_destroy_display( display); /* destroy the display */
    al_destroy_bitmap( GAME.brick);
    al_destroy_display( GAME.display); /* destroy the display */

    return 0;
} /* end function main */
