#include "wordSet.hpp"


std::map<Word, int> allWords={{"COMPRA", 1}, {"COMERA", 2}, {"COMETA", 3}, 
{"COLETA", 4}, {"ROLETA", 5}};

//função com laço para retornar o vetor com todos os caracteres corretos 
//ou o vetor inteiro com todas as letras, se tudo certo
std::vector<std::string> Word::correctLetter(std::vector<std::string> etl, 
std::map<Word, int> w, std::string v){
    if(v<0||v>6){
        throw std::invalid_argument("Valor inválido para a escolha.\n");
    }
    std::string answerInMap=w.at(v); //prob em acessar valor

    //v aqui seria um valor que corresponde a palavra no mapa das respostas

    //for(int i=0; i<)
}
/* ##### OUTROS CÓDIGOS QUE PODEM AJUDAR ##### */ 


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