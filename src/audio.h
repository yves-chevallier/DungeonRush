#pragma once

#include <SDL.h>
#include <SDL_mixer.h>

#define BGM_FADE_DURATION 800
void playBgm(int);
void playAudio(int);
void randomBgm();
void stopBgm();
void pauseSound();
void resumeSound();
