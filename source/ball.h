#ifndef BALL_H
#define BALL_H

typedef struct{
    s32 x,y; //This being the beginning position of the ball
    s32 dx,dy; //Speed being tied to delta time
    u32 w,h; //Width and height, maybe for size?
} Ball;

void update_ball(Ball* ball); //function definition?

#endif