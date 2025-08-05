#ifndef WORD_SET
#define WORD_SET

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stdexcept>

class Word{
    protected:
        std::string w;
        int size;

        Word(std::string word): w(word){
            if(word.length()==0||word.length()>6){
                throw std::invalid_argument("Tamanho da palavra deve ser entre 1 e 6");
            }
            size=word.length();
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
    protected:
        std::string def;
        int size;
        int choice;

        Def(std::string d, int c): def(d), choice(c){
            if(def.length()==0||def.length()>50){
                throw std::invalid_argument("Descrição precisa ter, no máximo, 50 caracteres");
            }

            std::pair<std::string, int> defpair;
            //ver como atribuir: escolha e definição
        }

    public:

        std::string seeDef(){
            return def;
        }

        int size(){
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

    WordDef(std::map<Word, int> WD, std::string neword, Word(newword)){
        for(const auto& pair: WD){
            if(pair.second>6||pair.second<0){
                throw std::invalid_argument("Escolha precisa ser um inteiro entre 1 e 5\n");
            }
        }
    }

    void add(const std::string&word, int id){
        wd[word]=id;
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


