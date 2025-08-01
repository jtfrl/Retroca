#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stdexcept>

class Word{
    private:
    std::string w;
    int size;

    Word(std::string word, int s): w(word), size(s){
      if(word.length()==0||word.length()>6){
        throw std::invalid_argument("Tamanho da palavra deve ser entre 1 e 6");
      }
    }

    public:

    std::string seeWord(){
        return w;
    }

    int size(){
        return size;
    }


};

class Def{
    private:
    std::string def;
    int size;

    Def(std::string d, int s): def(d), size(s){
        if(def.length()==0||def.length()>50){
            throw std::invalid_argument("Descrição precisa ter, no máximo, 50 caracteres");
        }
    }

    public:

};


//herda de Def e de Word
class WordDef : public Def, public Word{
    std::map<Word, Def> wd;


};


