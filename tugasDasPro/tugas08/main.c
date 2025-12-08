#include "head.h"

int main(){
    int a = 0, aN, aR, aU, aT;
    atr fighter[65];

    mReadFile(&a, &aN, fighter, "Fighter.txt");
    readFile(&a, &aR, fighter, "Race.txt");
    readFile(&a, &aU, fighter, "Universe.txt");
    readFile(&a, &aT, fighter, "Team.txt");

    mMerge(&aN, &aR, &aU, &aT, fighter, "FighterComplete.txt");
    
    mFunc();
    return 0;
}