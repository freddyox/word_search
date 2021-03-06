#ifndef WORDSEARCH_HH
#define WORDSEARCH_HH

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../include/Dictionary.hh"
#include "../include/CheckBox.hh"
#include "../include/Sounds.hh"
#include <vector>
#include <set>

struct compare {
  bool operator()(const std::string& first, const std::string& second) {
    return first.size() < second.size();
  }
};

class WordSearch : public sf::Drawable, public sf::Transformable{
private:
  float fX, fY;                                // Dimensions of desktop
  std::string fDifficulty;                     // Difficulty of WS
  int fNShort, fNMedium, fNLong;
   
  // Handle the board 
  int fRow, fCol;                              // Dimensions
  int fMinRow, fMinCol;                        // Min row/cols
  int fMaxRow, fMaxCol;                        // Max row/cols
  double fDx;                                  // Lattice size for text size, I chose .7*fDx
  sf::Color fBoardColor;                       // VertexArray color
  sf::VertexArray fLine;                       // Need a VA for the fBoard vector
  std::vector<sf::VertexArray> fBoard;         // Make a grid

  // Handle Colors
  std::map<int,sf::RectangleShape> fSquares;   // This is necessary to change colors
  std::map<int,int> fIDrow, fIDcol;            // ID->Row, ID->Col
  std::map<int,std::map<int,int> > fRowColID;  // Row/Col -> ID
  
  // Common Iterators, no explanations:
  std::map<int,int>::iterator fMii;
  std::string::iterator fStr;
  std::set<int>::iterator fSi;
  std::vector<std::string>::iterator fVstr;
  std::map<int,sf::RectangleShape>::iterator fMir;
  std::map<int,std::set<int> >::iterator fMisi;
  std::map<int,sf::Text>::iterator fMitxt;
  
  // The Letters and Handling the Board letters:
  std::map<std::string,int> fDirMap;    // Directional map, keeps it easy to read
  std::map<int,std::string> fDirMapInv; // The inverse of the above
  sf::Font fFont;                       // SFML font loader
  sf::Text fText;                       // SFML text loader
  std::map<int,sf::Text> fLetters;      // Letters physically on the board
  std::set<int> fListOfIDs;             // Easy access set with all IDs to be drawn
  std::map<int,char> fAlphabet;         // Alphabet for random letters
  std::vector<std::string> fWords;      // Vector of Words
  std::map<int,std::set<int> > fWordIDs;// List of all words in the form if IDs, key=dummy, val is ID
  int fWordCount;
  
  // The dictionary and word generation
  Dictionary *fDict;
  std::map<int,std::vector<std::string> > fRandomWords; // Organize dict words by string length
  std::map<std::string,int> fWordLength;                // Map for human readibility
  std::map<int,int> fNWordsGen;  // Based on difficulty, generate varying #s of short/med/long words

  // Make the LHS information
  float fOffsetX;                              // I'd like to put stuff on the LHS
  float fMaxLHSX;                              // In order to center LHS size / objects
  std::vector<sf::Text> fLHSInformation;       // All the words to be displayed
  CheckBox *fCheat;
  std::map<int,int> fWordScratchMap;
  std::vector<sf::VertexArray> fScratchedOut;
  
  // User functionality:
  sf::Color fUserColor, fFoundColor;
  bool fUserAttempt;
  bool fCheatStatus;
  int fInitialClick, fFinalClick;
  std::set<int> fUserFilledBlocks, fUserAttemptToFindWord;

  // Completion of the game
  bool fSuccess;
  sf::Time fCutOffTime;
  std::vector<sf::Text> fComplete, fCompleteDummy;
  int fSuccessCount;

  // Light-weight class to handle success/failure
  Sounds *fSounds;
  
public:
  WordSearch(float,float,int,int);
  ~WordSearch();

  // Utility
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  void to_upper(std::string&);
  
  void build_convenient_maps();
  std::set<int> which_dir_naive(std::string,int);
  std::vector<sf::Text> string_to_text(std::string);
  void set_difficulty_numbers(std::string);

  // WS Functionality
  void make_board();                        // Make VA 
  void randomly_fill_board();               // Randomly grab and place letters from fAlphabet
  bool insert_letters(std::string,int,int); // Insert Letters
  std::set<int> check_for_overlaps(std::set<int>&);   // returns overlap IDs, if any
  void handle_word_placement();             // The main word placement code
  void make_word_list();                    // Extract random words from Dict, and organize
  void cheat_function(sf::Color);           // Make words red, revealing the answers
  void user_interaction(sf::Color);         // This is user functionality
  void protected_interaction(sf::Color);    // Words that are accepted and correct, and do not update
  std::set<int> get_user_blocks(int,int,int);// tracks cursor movement
  bool did_user_find_word();
  
  // Info on LHS:
  void make_word_info();
  void update_mouse_pressed(sf::Vector2f);
  void update_mouse_move(sf::Vector2f);
  void update_mouse_released();
  
  // Set Methods:
  void SetXOffset(float x) {fOffsetX=x;}           
  void SetBoardColor(sf::Color col){fBoardColor=col;}
  void SetUserAttemptFlag(bool flag) {fUserAttempt=true;}

  float GetLHS(){return fMaxLHSX;}

  void handle_completion(sf::Time);
  void reset_everything();
  bool get_success_status() {return fSuccess;}
};
#endif
