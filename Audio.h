#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED

#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int loadMusic(const char* filename);
int loadChunk(const char* filename);

#endif // AUDIO_H_INCLUDED
