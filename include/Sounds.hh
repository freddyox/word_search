#ifndef SOUNDS_HH
#define SOUNDS_HH
#include <SFML/Audio.hpp>

class Sounds{
private:
  sf::Sound fCorrect,fIncorrect;
  sf::SoundBuffer buffer,buffer1, buffer2;
  sf::Sound fWin;
public:
  Sounds();
  ~Sounds();
  void play_success(){ fCorrect.play(); }
  void play_failure(){ fIncorrect.play(); }
  void play_win(){ fWin.play(); }
};
#endif
