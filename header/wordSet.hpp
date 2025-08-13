#ifndef WORD_SET
#define WORD_SET

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdexcept>
#include <utility>
#include <stack>


class Word{
    protected:
        std::string w;
        int size;

        Word() = default;

    public:

   //os construtores devem ser públicos, para serem usados em sideloop.cpp 
       Word(std::string word): w(word){
         if(w.length()==0||w.length()>6){
                throw std::invalid_argument("Tamanho da palavra deve ser entre 1 e 6");
            }          
        }
        
        Word(const char* word): Word(std::string (word)){
          
        } //?? deveria ser um único aqui

    //outros métodos

        std::string seeWord(){
            return w;
        }

        int size(){
            size=w.length();
            return size;
        }

        std::stack<int> correctLetter(std::string p, 
            std::map<int, Word> w, int v){}
            //função que vai servir para trocar a cadeia de * pela 
            //letra certa correspondente           
        
        bool operator<(const Word& v) const{
            return this->w<v.w;
        }

};

class Def{
    protected:
        std::string def;
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

        std::string seeDef() const {
            return def;
        }

        size_t size() const {
            return def.length();
        }

        int seeChoice() const {
            return choice;
        }

        void setDef(std::string d){
            def=d;
        }

       
};

//herda de Def e de Word
class WordDef : public Def, public Word{
    private:
    std::map<int, Word> wd;

    public:

    //WordDef() = default;

    WordDef(std::map<int, Word> WD): Word(), wd(std::move(WD)) {
       //wd[word]=choice;
    }
        

    bool choiceFromUser(int c){
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
            //retorno é se a palavra foi correta ou não 
        }
    }

};


class Star{
    public: 
    
    std::vector<std::string> estrelas={"*","*","*","*","*","*"};
    bool allStarsChange=false;

    Star() = default;
    //vetor de strings deve aparecer como parâmetro?
    //daí podemos saber se o loop 1 aparece ou o 2
    void seeStars(){  //possível usar static aqui, mas seria necessário mexer com allStarsChange
        std::cout<<"\tRETROCA"<<std::endl;

        if(allStarsChange==false){
            for(int i=0;i<5;i++){
                int index=i+1;
                std::cout<<index<<". * * * * * *"<<std::endl;
            }

        }
        else{
            //laço de acordo com changestars

        }
    //deve haver condicionais para exibir os * de acordo com as posições        
    }

    std::string changeStars(int c){
        //função para mudar em alguma das palavras 
        //os * pela(s) letra(s) correspondente(s)

        //vai usar a pilha 'etl'

        if(!allStarsChange){
          //impl  
        //controlador para ver se todas as estralas mudam
        }
    }
};

#endif //WORD_SET