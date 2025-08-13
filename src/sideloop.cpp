#include "wordSet.hpp"


std::map<int, Word> allWords={{1, "COMPRA"}, {2,"COMERA"}, {3,"COMETA"}, 
{4, "COLETA"}, {5,"ROLETA"}};

//função com laço para retornar o vetor com todos os caracteres corretos 
//p é a palavra indicada pelo usuário para uma das dicas
std::stack<char> Word::correctLetter(std::string p, std::map<int, Word> w, int v){

    std::stack<char> etl;

    if(v<1||v>5){
        throw std::invalid_argument("Valor inválido para a escolha.\n");
    }

    Word answerInMap=w.at(v);
    std::string ansItself=answerInMap.w;

    for(int i=0; i<answerInMap.size(); i++){
        for(char s:p){
            if(s==ansItself[i]){
                etl.push(s);
                //necessário apontar cada letra correspondente aqui
            }else{
                etl.push('*');
            }
        }
    }

    return etl;
}


/* ##### OUTROS CÓDIGOS QUE PODEM AJUDAR ##### */ 

//mais sobre maps:
//https://medium.com/@chittaranjansethi/a-comprehensive-guide-to-std-map-in-c-with-code-examples-f5cd576669f1

//mais aqui:https://gist.github.com/thecoreyford/e23783941df423906655e658f9dfc50d
//ÚTIL PARA VER COMO FAZER O LAÇO

/*
 for (int i = 0; i < answer.length(); ++i)
        {
            // if the vector contrains this characters index
            if (std::find (foundCharIndexes.begin(), foundCharIndexes.end(), i) != foundCharIndexes.end())
            {
                // it has been found
                std::cout << answer[i] << " "; // so print the char
                foundCount++; // and add one to the count
            }
            else
            {
                // it hasn't been found
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;
*/



//ÚTIL PARA EXIBIÇÃO DE MAPA
/*
void print_map(std::string_view comment, const std::map<std::string, int>& m)
{
    std::cout << comment;
    // Iterate using C++17 facilities
    for (const auto& [key, value] : m)
        std::cout << '[' << key << "] = " << value << "; ";
 
// C++11 alternative:
//  for (const auto& n : m)
//      std::cout << n.first << " = " << n.second << "; ";
//
// C++98 alternative:
//  for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); ++it)
//      std::cout << it->first << " = " << it->second << "; ";
 
    std::cout << '\n';
}
*/


//laço para o jogo
/*
bool checkWord(){

}

while(true){
   
}

*/