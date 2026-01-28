#ifndef WGAME
#define WGAME
#include "wordSet.hpp"
#include <memory>

class WordGame{
    private:
    std::vector<WordDef> word_def;
    Star starSys;
    int atual_rodada;
    int total_rod;
    bool game_over;

    public:
};

#endif //WGAME