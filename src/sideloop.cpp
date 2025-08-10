#include "wordSet.hpp"



//WordDef w1;
//WordDef w2;
//w1["COMPRA"]=1;

std::map<Word, int> w1={{Word("COMPRA"), 1}};
//std::map<Word, int> allwords={{"COMPRA"}, 1,};

WordDef g1(w1); 

/*VERIFICANDO COMO DEFINIR
WordDef w1.at("COMPRA")=1;
WordDef w2.at("COMERA")=2;
WordDef w3.at("COMETA")=3;
WordDef w4<"COLETA", 4>;
WordDef w5<"ROLETA", 5>;
*/




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