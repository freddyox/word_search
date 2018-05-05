#include "../include/Node.hh"

Node::Node(){
  
  if( !fFont.loadFromFile("fonts/arial.ttf")) {
    std::cerr << "ERROR: Font did not load properly." << std::endl;
  }
  fText.setFont(fFont);
}

Node::~Node(){;}
