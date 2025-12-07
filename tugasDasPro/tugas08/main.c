#include "head.h"

int main(){
    int a = 0, aN;
    atr fighter[65];

    mReadFile(&a, &aN, fighter, "Fighter.txt");
    readFile(&a, fighter, "Race.txt");
    readFile(&a, fighter, "Universe.txt");
    readFile(&a, fighter, "Team.txt");

    mMerge(&aN, fighter, "FighterComplete.txt");
    
    mFunc();
    return 0;
}