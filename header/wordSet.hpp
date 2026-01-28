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
        

    /* // >>> em ajuste <<<
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
    */

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

     // words_fromUser é um misto de letras e *, ou só letras, a depender do acerto do usuário    
    void seeStars(const std::vector<std::string>& word_fromUser) const { 
        std::cout<<"\tRETROCA"<<std::endl;

        if(allStarsChange==false){ // controle para checar se as estrelas mudam
            for(int i=0;i<5;i++){
                int index=i+1;
                std::cout<<index<<". * * * * * *"<<std::endl;
            }

        }
        else{
            for(size_t i=0; i<5; i++){
                int index=i+1;
                std::cout<<index<<". "<<word_fromUser[i]<<std::endl;
                /*
                */
                //std::cout<<index<<". "; 
            }

        }
    // deve haver condicionais para exibir os * de acordo com as posições        
    }

    std::string changeStars(std::stack<char> etl, int idx){ // idx 
        int count=0; //aqui o count vai contar se todos mudam;
       if(idx<0 || idx>=etl.size()){
        throw std::out_of_range("Tamanho inválido para o vetor de palavras \n - | - Invalid word index \n");
       }
       /*
       // como o acesso aleatório de uma stack não é possível
       // vamos alocar os dados da pilha em um outro container 
       // o tempContainer terá as estrelas atuais que restam
       
       */
      std::vector<char> tempContainer; // container temporário que vai tomar os dados da stack

        while(!etl.empty()){
            tempContainer.push_back(etl.top()); // toma a letra que está no topo
            etl.pop();
        }

        if(idx<tempContainer.size()) char c=tempContainer[idx];

       std::stack<char> tempStack=etl;

       // Atualização das * com as letras correspondentes
       size_t pos=0;
       
       while(!tempStack.empty() && pos<tempContainer.size()){
            char w=tempStack.top();
            tempStack.pop();
            // Atualiza se for uma letra:
            if(w!='*') tempContainer[pos]=w;
            pos++;
       }

       checkStarsIfRev(idx);
       updateAllStars();

    }
       
    // É importante que as próximas funções sejam apenas de leitura
    // por isso, o uso de 'const'; também não são capazes de chamar quaisquer função não-constante

    // Permite checar alguma palavra específica se foi revelada ou não
    bool check_word(int wordIdx) const{
        if(wordIdx<0 || wordIdx>=pos_rev.size()) return false;
        return pos_rev[wordIdx];
    }

    bool are_all_words_rev() const{
        return allStarsChange;
    }

    std::string WordState(int idx) const{
        if(idx<0 || idx>=estrelas.size()){
            throw std::out_of_range("Tamanho inválido para o vetor de palavras \n - | - Invalid word index \n");
            return "";
        }

        return estrelas[idx];
    }

    //∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼∟▼//

    private:
    void checkStarsIfRev(int idx){
        if(idx<0 || idx>estrelas.size()) return;

        const std::string& stars=estrelas[idx];

         // até o fim da string ocorre verificação de *
        pos_rev[idx]=(stars.find('*')==std::string::npos);
    }

    void updateAllStars(){
        someStarsChange=true;
        int count=0;
        for(bool r:pos_rev){
            if(!r){
                someStarsChange=true;
            }
            count++;
        }

        if(count==6) allStarsChange=true;
    }
    
};

#endif //WORD_SET