#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iomanip>
#include <string>
#include <algorithm>
#include "fighter.hpp"
#include "dice.hpp"
#include "helpers.hpp"
#include "weapon.hpp"

using namespace std;

//SET TO TRUE TO USE AN INPUT FILE FROM THE COMMAND LINE
//When true, processes battle based on an input file.
bool commandLineProcessing = false;
ofstream fout;
ifstream read;

struct CombatFeed{
    int totatt; //total attackers
    int totdef; //total defenders
    int rndcnt; // round count
    int adub;//attackers win count
    int ddub;//defenders win count
    bool aWins;
    bool dWins;
    vector<BaseFighter*> Attackers;
    vector<BaseFighter*> Defenders;
    vector<BaseFighter*> dead;

    CombatFeed(){
        int rndcnt = 0;
        int adub= 0;
        int ddub = 0;

    }   
};

int main(){
    fout.open("output.txt");
    read.open("input.txt");
    srand(time(0));
    string input;

    while(cin >> input){
        BaseFighter* tempFighter;
        transform(in)

    }

    //gathering variables
    



    return 0;
}
