
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "prng.h"
#include "res.h"
#include "ui.h"

#ifdef DBG
#include <assert.h>
#endif

int main(int argc, char** args) {
    prngSrand(time(NULL));
    // Start up SDL and create window
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        // Load media
        if (!loadMedia()) {
            printf("Failed to load media!\n");
        } else {
            mainUi();
        }
    }
    cleanup();
}
