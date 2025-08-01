#include <iostream>
#include <string>
#include <algorithm>
#include <map>


class Word{
    std::string w;
    int size;

    Word(std::string word, int s): w(word), size(s){
      //impl  
    }

};

class Def{
    std::string def;
    int size;

    Def(std::string d, int s): def(d), size(s){
        //impl
    }
};

/*
herda de Def e de Word
class WordDef{
    std::map<Word, Def> wd;


};
*/