#include "head.h"

int main(){
    int a = 0, aN = 0, aR = 0, aU = 0, aT = 0;
    atr fighter[65];

    mReadFile(&a, &aN, fighter, "Fighter.txt");
    readFile(&a, &aR, fighter, "Race.txt");
    mMerge(&aN, &aR, &aU, &aT, fighter, "FighterComplete.txt");
    readFile(&a, &aU, fighter, "Universe.txt");
    mMerge(&aN, &aR, &aU, &aT, fighter, "FighterComplete.txt");
    readFile(&a, &aT, fighter, "Team.txt");
    mMerge(&aN, &aR, &aU, &aT, fighter, "FighterComplete.txt");

    mFunc();
    return 0;
}