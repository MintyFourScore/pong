#include "ball.h"
#include <nds.h>
void update_ball(Ball* ball){
    ball->x += ball->dx;
    ball->y += ball->dy;

    if (ball->x >= (screenWidth-ball->w-1) || ball->x < 0){ //Check the boundary horizontally.
        ball->dx *= -1;
        ball->x -= 2 * (ball.x % screenWidth); //Returns the ball back to the screen and bounces it back
    }
    if (ball.y >= (screenHeight-ball.h-1) || ball.y < 0){ //Check the boundary horizontally.
        ball.dy *= -1;
        ball.y -= 2 * (ball.y % screenHeight); //Returns the ball back to the screen and bounces it back
    }
}