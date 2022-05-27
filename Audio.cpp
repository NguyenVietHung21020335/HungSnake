#include "Audio.h"

using namespace std;

vector<Mix_Chunk*> chunk;
vector<Mix_Music*> music;

int loadChunk(const char* filename){
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		printf("%s", Mix_GetError());
		return -1;
	}
    chunk.push_back(Mix_LoadWAV(filename));
	if (chunk[chunk.size()-1] == NULL)
	{
		printf("%s", Mix_GetError());
	}
    Mix_PlayChannel(-1, chunk[chunk.size()-1], 0);
}
int loadMusic(const char* filename){
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		printf("%s", Mix_GetError());
		return -1;
	}
	music.push_back(Mix_LoadMUS(filename));
	if (music[music.size()-1] == NULL)
	{
		printf("%s", Mix_GetError());
	}

    if (!Mix_PlayingMusic())
        Mix_PlayMusic(music[music.size()-1], 0);
}
