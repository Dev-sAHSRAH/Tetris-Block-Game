#include "SoundManager.h"
#include <raylib.h>

SoundManager::SoundManager()
{

    music = LoadMusicStream("Sounds/music.mp3");
    PlayMusicStream(music);
    rotateSound = LoadSound("Sounds/rotate.mp3");
    clearSound = LoadSound("Sounds/clear.mp3");
}

SoundManager::~SoundManager()
{
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
}

void SoundManager::PlayRotateSound()
{
    PlaySound(rotateSound);
}

void SoundManager::PlayClearSound()
{
    PlaySound(clearSound);
}