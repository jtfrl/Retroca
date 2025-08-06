#ifndef WORD_SET
#define WORD_SET

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stdexcept>
#include <utility>

class Word{
    protected:
        std::string w;
        int size;

        Word() = default;

        Word(std::string word): w(word){
            if(word.length()==0||word.length()>6){
                throw std::invalid_argument("Tamanho da palavra deve ser entre 1 e 6");
            }
        }

    public:

        std::string seeWord(){
            return w;
        }

        int size(){
            size=w.length();
            return size;
        }


};

class Def{
    protected:
        std::string def;
        int size;
        int choice;

    public:

       Def() = default;

       Def(std::string d, int c): def(d), choice(c){
            if(def.length()==0||def.length()>50){
                throw std::invalid_argument("Descrição precisa ter, no máximo, 50 caracteres");
            }

            if(choice<1||choice>6){
                throw std::invalid_argument("Número da def. precisa ser inteiro e estar entre 1 e 5");       
            }

            //std::pair<std::string, int> defpair;
            //ver como atribuir: escolha e definição
        }

        std::string seeDef(){
            return def;
        }

        int size(){
            size=def.length();
            return size;
        }

        int seeChoice(){
            return choice;
        }

};


//herda de Def e de Word
class WordDef : public Def, public Word{
    private:
    std::map<Word, int> wd;

    public:

    WordDef() = default;

    WordDef(std::map<Word, int> WD, const Word& word, int choice): 
    wd(std::move(WD)) {
       wd[word]=choice;
    }

    void choiceFromUser(int c){
        switch(c){
            case 1:{ 
                //em wd, teríamos 1 em int
            }
            case 2:{

            }
            case 3:{

            }
            case 4:{

            }
            case 5:{

            }
            //implementar default
        }
    }



};


class Star{
    public: 


    void seeStars(){
        std::cout<<"RETROCA"<<std::endl;
        for(int i=0;i<5;i++){
            std::cout<<(i+1)+". * * * * *"<<std::endl;
        }
        //deve haver condicionais para exibir os * de acordo com as posições
    }
};

#endif //WORD_SET


