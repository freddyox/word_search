#ifndef HANDLEMENUS_HH
#define HANDLEMENUS_HH

#include <SFML/Graphics.hpp>

class HandleMenus : public sf::Drawable{
private:

  
public:
  HandleMenus();
  ~HandleMenus();

  void draw(sf::RenderTarget&, sf::RenderStates) const;
  
};
#endif
