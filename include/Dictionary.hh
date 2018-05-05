#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <string>

class Dictionary{
private:
  std::map<int,std::string> fAllWords;
  std::map<int,std::string> fShortWords, fMediumWords, fLongWords;
  std::string fFileName;
  
public:
  Dictionary();
  ~Dictionary();
  void Setup(std::string); // takes file name, assumed to be in dict/
  void trim(std::string&); // utility function to remove trailing white spaces
  void CheckMaps();
  bool fOk;

  // I plan to extract words from the member maps on an random basis
  // so it makes sense to pass a word rather than the whole map
  int fSize, fShortSize, fMedSize, fLongSize;
  std::string GetWord(unsigned int i)      {return fAllWords[i];}
  std::string GetShortWord(unsigned int i) {return fShortWords[i];}
  std::string GetMedWord(unsigned int i)   {return fMediumWords[i];}
  std::string GetLongWord(unsigned int i)  {return fLongWords[i];}
};
