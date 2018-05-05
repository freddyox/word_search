#include "../include/Sounds.hh"
#include <iostream>

Sounds::Sounds(){
  if( !buffer.loadFromFile("sounds/correct.wav") ) {
    std::cout << "Issue opening correct sound" << std::endl;
  }
  fCorrect.setBuffer(buffer);
  if( !buffer1.loadFromFile("sounds/incorrect.wav") ) {
    std::cout << "Issue opening incorrect sound" << std::endl;
  }
  fIncorrect.setBuffer(buffer1);
  if( !buffer2.loadFromFile("sounds/gameover.wav") ) {
    std::cout << "Issue opening incorrect sound" << std::endl;
  }
  fWin.setBuffer(buffer2);
}

Sounds::~Sounds(){;}
