#ifndef CHECKBOX_HH
#define CHECKBOX_HH
#include <SFML/Graphics.hpp>

class CheckBox : public sf::Transformable{
private:
  int fX, fY;
  float fScale;
  sf::Vector2f fSize;
  sf::Texture fTx, fTx1;
  sf::Sprite fUnchecked, fChecked;
  bool fStatus;
  
public:
  CheckBox(int,int,float);
  ~CheckBox();
  void update();
  
  sf::Sprite fBox;
  sf::Vector2f getSize() {return fSize;}
  void setPosition(sf::Vector2f pos) {fBox.setPosition(pos);}
  void setStatus(bool s);
};
#endif
