#include <raylib.h>

class SoundManager
{
public:
    SoundManager();
    ~SoundManager();

    void PlayRotateSound();
    void PlayClearSound();

    Music music;

private:
    Sound rotateSound;
    Sound clearSound;
};