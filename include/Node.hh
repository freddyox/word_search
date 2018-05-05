#ifndef NODE_HH
#define NODE_HH
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Node{
private:
  int fId;
  std::string fTitle;
  sf::Text fText;
  sf::Font fFont;
public:
  Node();
  ~Node();
  std::vector<Node*> fChildren;
};
#endif
