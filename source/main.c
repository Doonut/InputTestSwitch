#include <string.h>
#include <stdio.h>
#include <switch.h>

#define START_BITMASK_SWITCH(x) \
            for (uint64_t bit = 1; x >= bit; bit *= 2) if (x & bit) switch (bit)

int main(int argc, char **argv){
    gfxInitDefault();
    consoleInit(NULL);

    // Main loop
    while(appletMainLoop()){
        //Scan all the inputs. This should be done once for each frame
        hidScanInput();

        //hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        printf("%d", kDown);

        START_BITMASK_SWITCH(kDown){
            case KEY_A:
                printf("A Pressed\n");
                break;
            case KEY_B:
                printf("B Pressed\n");
                break;
            case KEY_X:
                printf("X Pressed\n");
                break;
            case KEY_Y:
                printf("Y Pressed\n");
                break;
            case KEY_LSTICK:
                printf("Left Stick Pressed\n");
                break;
            case KEY_RSTICK:
                printf("Right Stick Pressed\n");
                break;
            case KEY_L:
                printf("L Pressed\n");
                break;
            case KEY_R:
                printf("R Pressed\n");
                break;
            case KEY_ZL:
                printf("ZL Pressed\n");
                break;
            case KEY_ZR:
                printf("ZR Pressed\n");
                break;
            case KEY_PLUS:
                printf("Plus Pressed\n");
                break;
            case KEY_MINUS:
                printf("Minus Pressed\n");
                break;
            case KEY_DLEFT:
                printf("Dpad Left Pressed\n");
                break;
            case KEY_DUP:
                printf("Dpad Up Pressed\n");
                break;
            case KEY_DRIGHT:
                printf("Dpad Right Pressed\n");
                break;
            case KEY_DDOWN:
                printf("Dpad Down Pressed\n");
                break;
            case KEY_LSTICK_LEFT:
                printf("Left Stick Left Pressed\n");
                break;
            case KEY_LSTICK_UP:
                printf("Left Stick Up Pressed\n");
                break;
            case KEY_LSTICK_RIGHT:
                printf("Left Stick Right Pressed\n");
                break;
            case KEY_LSTICK_DOWN:
                printf("Left Stick Down Pressed\n");
                break;
            case KEY_RSTICK_LEFT:
                printf("Right Stick Left Pressed\n");
                break;
            case KEY_RSTICK_UP:
                printf("Right Stick Up Pressed\n");
                break;
            case KEY_RSTICK_RIGHT:
                printf("Right Stick Right Pressed\n");
                break;
            case KEY_RSTICK_DOWN:
                printf("Right Stick Down Pressed\n");
                break;
            case KEY_SL:
                printf("SL Pressed\n");
                break;
            case KEY_SR:
                printf("SR Pressed\n");
                break;
            case KEY_TOUCH:
                printf("Pressed The Touch Screen\n");
                break;
        }

        if (kDown & KEY_PLUS) break; // break in order to return to hbmenu

        gfxFlushBuffers();
        gfxSwapBuffers();
        gfxWaitForVsync();
    }

    gfxExit();
    return 0;
}