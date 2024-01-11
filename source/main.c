#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
u16 Pressed;
u16 Held;
u16 Released;
u8 ballVertSpeed=1;
u8 ballHoriSpeed=1;
s16 ballX=128;
s16 ballY=81;
s16 res_width=256;
s16 res_height=192;
char coords[64];
int main(int argc, char **argv)
{
    s8 movespeed=2;
    s16 player_x=96;
    //u8 ballActiveScreen=1;
    NF_Set2D(0,0);
    NF_Set2D(1,0);
    nitroFSInit(NULL);
    NF_SetRootFolder("NITROFS");
    

    NF_InitTiledBgBuffers(); //Prepare BG Buffers
    NF_InitTiledBgSys(0);   //Prepare BG system
    NF_InitTiledBgSys(1);
    NF_InitSpriteBuffers();  //Prepare sprite buffers
    NF_InitSpriteSys(0);    //Prepare sprite system
    NF_InitSpriteSys(1);

    NF_LoadTiledBg("bg/fieldtop","fieldtop",256,256);
    NF_LoadTiledBg("bg/fieldbottom","fieldbottom",256,256);
    NF_CreateTiledBg(0,3,"fieldtop");
    NF_CreateTiledBg(1,3,"fieldbottom"); //Loads and renders the backgrounds.

    NF_LoadSpriteGfx("sprite/paddle",0,64,32);
    NF_LoadSpriteGfx("sprite/ball",1,16,16); //Ball sprite in RAM slot 1
    NF_LoadSpritePal("sprite/paddle",0);
    NF_LoadSpritePal("sprite/ball",1); //Load the sprites and their palettes

    NF_VramSpriteGfx(0,0,0,false); //Load the paddle sprites into VRAM
    NF_VramSpriteGfx(1,0,1,false);
    //Ball vram sprite loading
    NF_VramSpriteGfx(1,1,2,false);

    NF_VramSpritePal(0,0,0); //Load the palettes into VRAM for both screens
    NF_VramSpritePal(1,0,0); 
    NF_VramSpritePal(0,1,1); //Load ball palette for both screens
    NF_VramSpritePal(1,1,1);
    
    NF_CreateSprite(0,0,0,0,96,16); //Make a paddle sprite on the top screen
    NF_CreateSprite(1,0,1,0,player_x,160);
    NF_CreateSprite(1,1,2,1,ballX,ballY); //Make the ball or something
    while (1){
        ballX += ballHoriSpeed;
        ballY += ballVertSpeed;
        Pressed = keysDown();
        Held = keysHeld();
        Released = keysUp();
        
        scanKeys();
        NF_MoveSprite(1,0,player_x,160); //Move the paddle when expected to do so
        NF_MoveSprite(1,1,ballX,ballY);
        if(ballX<0||ballX>res_width){
            ballHoriSpeed *= -1;
        }
        if(ballY<0||ballY>res_height){
            ballVertSpeed *= -1;
        }
        
        if(KEY_LEFT & Held){
            player_x -= movespeed;
        }
        else if(KEY_RIGHT & Held){
            player_x += movespeed;
        }
        // Wait for the screen refresh
        NF_SpriteOamSet(0);
        NF_SpriteOamSet(1);
        swiWaitForVBlank();
        oamUpdate(&oamMain);
        oamUpdate(&oamSub);
    }

    // If this is reached, the program will return to the loader if the loader
    // supports it.
    return 0;
}
