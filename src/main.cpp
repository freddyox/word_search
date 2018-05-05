//    ************************************************************
//    *                        WordSearch                        *
//    *                         Dec 2017                         *
//    ************************************************************
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include "../include/WordSearch.hh"
#include "../include/HandleMenus.hh"

int main() {

  sf::VideoMode desktop_dimensions = sf::VideoMode::getDesktopMode();
  unsigned int fDeskX = desktop_dimensions.width;
  unsigned int fDeskY = desktop_dimensions.height;
  
  sf::RenderWindow window(sf::VideoMode(fDeskX,fDeskY), "Word Search");
  // window.setFramerateLimit(60);

  //////////////////////////////////////////////////////
  //                   Initialize                     //
  //////////////////////////////////////////////////////
  WordSearch ws(fDeskX,fDeskY,20,20);
  int follow_mouse = false;

  sf::Clock success_clock;                  // clock to keep track of successful gameplay
  sf::Time success_time = sf::seconds(0.0); // this plays as a dummy to reset success_clock
  bool FT = true;                           // First try
  while( window.isOpen() ) {
    
    sf::Event event;
    while( window.pollEvent(event) ) {
      if( event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ) {
	window.close();
      }

      
      if(event.type == sf::Event::MouseButtonPressed &&
	 sf::Mouse::isButtonPressed(sf::Mouse::Left) ) {
	sf::Vector2i mouse = sf::Mouse::getPosition(window);
	ws.SetUserAttemptFlag(true);
	ws.update_mouse_pressed( window.mapPixelToCoords(mouse) );
	follow_mouse = true;
      }
      if(event.type == sf::Event::MouseMoved && follow_mouse ){
	sf::Vector2i mouse = sf::Mouse::getPosition(window);
	ws.update_mouse_move( window.mapPixelToCoords( mouse ) );
      }
      if(event.type == sf::Event::MouseButtonReleased){
	follow_mouse = false;
	ws.SetUserAttemptFlag(false);
	ws.update_mouse_released();
      }
    }

    bool success = ws.get_success_status();
     
    if( !success ) FT = true;
      
    if( success && FT ){
      success_time = success_clock.restart();
      success_time = sf::seconds(0.0);
      FT = false;
    }

    // We want to get in this loop, and not process any more events
    if( success ) {
      sf::Time elapsed = success_clock.getElapsedTime();
      ws.handle_completion( elapsed );
    }
    
    window.clear(sf::Color::White);
    window.draw(ws);
    window.display();      
  }
  return 0;
}
