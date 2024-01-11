#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
u16 Pressed;
u16 Held;
u16 Released;

int main(int argc, char **argv)
{
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
    NF_CreateTiledBg(1,3,"fieldbottom");

    while (1){
        scanKeys();
        // Wait for the screen refresh
        swiWaitForVBlank();
    }

    // If this is reached, the program will return to the loader if the loader
    // supports it.
    return 0;
}
