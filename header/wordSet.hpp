#ifndef WORD_SET
#define WORD_SET

#include <iostream>
#include <string>
#include <vector>
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
        //Word(const char* word): Word(std::string (word)){} 
        //acima: alternativa para fazer a atribuição funcionar  

    public:

        std::string seeWord(){
            return w;
        }

        int size(){
            size=w.length();
            return size;
        }

        std::vector<std::string> correctLetter(std::vector<std::string> etl, 
            std::map<Word, int> w){
            //função que vai servir para trocar a cadeia de * pela 
            //letra certa correspondente

            //'etl' é uma ref para 'estrelas'.
            

            //laço que vai iterar entras as letras de >>>uma<<<
            //das palavras de w 
            //for(int i=0; i<)
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

        //função para ordenação em map
        bool operator<(const Def& v) const{
            return this->choice<v.choice;
        }


};

//herda de Def e de Word
class WordDef : public Def, public Word{
    private:
    std::map<Word, int> wd;

    public:

    //WordDef() = default;

    WordDef(std::map<Word, int> WD): Word(), wd(std::move(WD)) {
       //wd[word]=choice;
    }

    /*

    WordDef& operator=(std::pair<const std::string*, int> p){
        wd.emplace(p.first, p.second);
        return *this;
    }

    */
        

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
    
    std::vector<std::string> estrelas={"*","*","*","*","*","*"};
    bool allStarsChange=false;


    //vetor de strings deve aparecer como parâmetro?
    //daí podemos saber se o loop 1 aparece ou o 2
    void seeStars(){
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

        if(!allStarsChange){
          //impl  
        //controlador para ver se todas as estralas mudam
        }
    }
};

#endif //WORD_SET


