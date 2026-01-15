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
        } 
        std::string seeWord(){
            return w;
        }

        int size(){
            size=w.length();
            return size;
        }

        std::stack<char> correctLetter(std::string p, 
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
    WordDef(): Def("", 0), Word(){} // padrão

    WordDef(std::map<int, Word> WD, std::string word, std::string def, int id):
     Def(def, id), Word(word), wd(std::move(WD)) {
    }

    //getDef  
        
    bool choiceFromUser(int c){
        switch(c){
            case 1:{ 
               Def dica1("Uma volta na feira", 1);
            }
            case 2:{
               Def dica2("Futuro do verbo comer", 2);
            }
            case 3:{
               Def dica3("Fenômeno observável no céu", 3);
            }
            case 4:{
                Def dica4("Processo comum em laboratórios de saúde", 4);
            }
            case 5:{
                Def dica5("Objeto comum em programas de auditório", 5);
            }
        }
    }

    bool checkPal(const std::string& _w){ //previne mudanças na palavra escolhida pelo usuário
        return _w==w;
    }

    // revela todas as letras
    void reveal(const std::string& _w){
        for(size_t i=0; i<_w.length() && i<w.length(); i++){
            if(_w[i]==w[i]){
                //incluir revealLetter de word aqui
            } 
        }
    }

};


class Star{
    public: 
    
    //std::vector<std::string> estrelas={"*","*","*","*","*","*"};
    std::vector<std::string> estrelas;
    bool allStarsChange;
    bool someStarsChange=false;
    std::vector<bool> pos_rev; // posições reveladas

    Star(): estrelas(5, "* * * * * *"), allStarsChange(false), pos_rev(5, someStarsChange){
       
    }
    Star(const std::vector<std::string>& iniStars): 
        estrelas(iniStars), allStarsChange(false), pos_rev(iniStars.size(), false){
            if(estrelas.size()>5) estrelas.resize(5); // reajuste no tamanho
        }

    void seeStars(){  // possível usar static aqui, mas seria necessário mexer com allStarsChange
        std::cout<<"\tRETROCA"<<std::endl;

        if(allStarsChange==false){
            for(int i=0;i<5;i++){
                int index=i+1;
                std::cout<<index<<". * * * * * *"<<std::endl;
            }

        }
        else{
            for(int i=0; i<5; i++){
                int index=i+1;
                // pilha sendo usada aqui

                // condicional aqui: se o caractere estiver certo, coloca a letra
                // senão, usa-se *
                std::cout<<index<<". "; 
            }

        }
    //deve haver condicionais para exibir os * de acordo com as posições        
    }

    std::string changeStars(std::stack<char> etl){
        int count=0; //aqui o count vai contar se todos mudam;
        while(!etl.empty()){  
            char atualChar=etl.top();
            if(atualChar!='*'){
                someStarsChange=true;
                count++;
            }
            etl.pop();
        }
        if(count==6) allStarsChange=true;

        //checar código do changeStars com o uso de uma 
        //variável para resultado

        if(!allStarsChange){
          //impl  
        //controlador para ver se todas as estralas mudam
        }
    }
};

#endif //WORD_SET