#include "../include/CheckBox.hh"
#include <iostream>

CheckBox::CheckBox(int x, int y, float s) : fX(x), fY(y), fScale(s) {
  
  if( !fTx.loadFromFile("unchecked.png") ) {
    std::cerr << "ERROR: Texture failed..." << std::endl;
  }
  fUnchecked.setTexture( fTx );
  sf::FloatRect rect = fUnchecked.getLocalBounds();
  fUnchecked.setOrigin(0.5*rect.width,0.5*rect.height);
  fUnchecked.setPosition(sf::Vector2f(x,y));
  
  fUnchecked.setScale(fScale,fScale);
  fSize = sf::Vector2f(fScale*rect.width,fScale*rect.height);

  if( !fTx1.loadFromFile("checked.png") ) {
    std::cerr << "ERROR: Texture failed..." << std::endl;
  }
  fChecked.setTexture( fTx1 );
  rect = fChecked.getLocalBounds();
  fChecked.setOrigin(0.5*rect.width,0.5*rect.height);
  fChecked.setPosition(sf::Vector2f(x,y));
  fChecked.setScale(fScale,fScale);

  fStatus = false;
}

CheckBox::~CheckBox(){;}

void CheckBox::update(){
  fBox = fUnchecked;
}

void CheckBox::setStatus(bool s){
  fStatus = s;
  if( fStatus ) fBox = fChecked;
  else fBox = fUnchecked;
}
