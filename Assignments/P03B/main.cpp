/*****************************************************************************
*
*  Author:           Samuel Campbell
*  Email:            Sccampbell1019@my.msutexas.edu
*  Label:            P03b
*  Title:            BolNiverse Fight Club
*  Course:           CMPS 2143
*  Semester:         Fall 2021
*
*  Description:
*        A game management program that pits attackers against defenders.
        Utilizes inheritance to make characters of differing types. 
*
*  Usage:
*         srand(time(0));
    ofstream fout;
    ifstream read;

    // fout.open("output.txt");
    read.open("input.txt");
    // srand(time(0));
    string input;

    // 2) instance of the combat feed

    CombatFeed CF;
    CF.totatt = 0;
    while(read >> input){
        CF.addAttacker(input);
    }
    
    CF.printAttackers();
    cout << CF.Attackers.size()<<endl;
    cout << CF.Defenders.size()<<endl;
    cout <<"Total Attackers: " << CF.totatt <<endl;
  

    for(int i =0;i<500;i++){
    CF.runBattle();
    CF.rndcnt++;
    }
    cout<<"adub"<<CF.adub<<endl;
    cout<<"ddub"<<CF.ddub<<endl;
    cout<<"rndcnt"<<CF.rndcnt<<endl;
*
*  Files:            dice.hpp
*                    fighter.hpp
*                    helpers.hpp
*                    weapon.hpp
*///************************************************************************************

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

/**
 * Struct CombatFeed
 * 
 * Description:
 *      Manager for the game, runs and creates all the attackers and defenders
 * 
 * Public Methods:
 *      -                   CombatFeed(){
 *      -              void addAttacker(string input)
 *       -             void addDefender(string t)
 *       -             void printAttackers()
 *       -             void runBattle()         
 * 
 * Usage: 
 *
 *       srand(time(0));
    ofstream fout;
    ifstream read;

    // fout.open("output.txt");
    read.open("input.txt");
    // srand(time(0));
    string input;

    // 2) instance of the combat feed

    CombatFeed CF;
    CF.totatt = 0;
    while(read >> input){
        CF.addAttacker(input);
    }
    
 *
 *      
 */
struct CombatFeed{
    int totatt=0;           //total attackers
    int totdef=0;           //total defenders
    int rndcnt=0;           // round count
    int adub=0;             //attackers win count
    int ddub=0;             //defenders win count
    bool aWins;
    bool dWins;

    int threshhold = 3;
    int warriorCount = 0;
    int wizardCount = 0;
    int archerCount = 0;
    int elfCount = 0;
    int dragonbornCount = 0;

    vector<BaseFighter*> Attackers; 
    vector<BaseFighter*> Defenders;
    BaseFighter* captainDefender;
    BaseFighter* captainAttacker;

    CombatFeed(){
      int rndcnt = 0;
      int adub= 0;
      int ddub = 0;
       
    }
    // 1) add a method to push an attacker onto the Attacker vector
    // create a new attacker of type input and pushback onto vector
     void addAttacker(string input){
      BaseFighter* attacker; // instance of attackers used to add attackers
      if (input == "Warrior" || input == "warrior"){
          attacker = new Warrior;
          warriorCount++;
          if(warriorCount % threshhold == 10){
            addDefender("warrior");
            
          }
      }else if (input == "Wizard" || input == "wizard"){
          attacker = new Wizard;
          wizardCount++;
          if(wizardCount % threshhold == 10){
            addDefender("wizard");
            
          }
      }else if (input == "Archer" || input == "archer"){
          attacker = new Archer;
          archerCount++;
          if(archerCount % threshhold == 10){
            addDefender("archer");
            
          }
      }else if (input == "Elf" || input == "elf"){
          attacker = new Elf;
          elfCount++;
          if(elfCount % threshhold == 10){
            addDefender("elf");
            
          }
      }else if (input == "DragonBorn" || input == "dragonborn"){
          attacker = new DragonBorn; 
          dragonbornCount++;
          if(dragonbornCount % threshhold == 10){
            addDefender("dragonborn");
            
          }
      }else  cout << "input : "<< input << " is not recognized" <<endl;

      Attackers.push_back(attacker);
      totatt++;
    }

    // Adds one defender of specified type.
    // add "t" (type) of defender
    void addDefender(string t){
      BaseFighter* temp;
       if (t == "Warrior" || t == "warrior"){
          temp = new Warrior;
      }else if (t == "Wizard" || t == "wizard")
          temp = new Wizard;
      else if (t == "Archer" || t == "archer")
          temp = new Archer;
      else if (t == "Elf" || t == "elf")
          temp = new Elf;
      else if (t == "DragonBorn" || t == "dragonborn")
          temp = new DragonBorn; 
      else  cout << "input : "<< t << " is not recognized" <<endl;

      Defenders.push_back(temp);
      totdef++;
    }

    void printAttackers(){
      cout<<Attackers.size()<<endl;
      // loop through and print attacVector
      for (BaseFighter* it : Attackers) {
        cout << it->name << endl;
      }
    }

    /*
    [0]=>Warrior
    [1]=>Elf
    [2]=>Archer
    [3]=>dragonborn
    [4]=>Wizard
    */

    void runBattle(){
        while(Attackers.size()!=0 && Defenders.size()!=0){
          captainAttacker = Attackers[0];
          int i = 0;
          captainDefender = Defenders[i];
          while(captainAttacker->name != captainDefender->name){
            
            if (i<Defenders.size()){
            captainDefender = Defenders[i++];
            }else 
            break;

          }
          while(captainDefender->alive() && captainAttacker->alive()){
            int defDamage = 0;
            int attDamage = 0;
            attDamage = captainAttacker->attack();
           // cout<<"damage:"<<attDamage<<endl;
            defDamage = captainDefender->attack();
            if(attDamage < defDamage){
              captainAttacker->takeDamage(defDamage);
            }
            
            attDamage = captainAttacker->attack();
            defDamage = captainDefender->attack();
            if(defDamage<attDamage){
            captainDefender->takeDamage(attDamage);
            cout<<"hey"<<endl;
            }
          }
          if(captainDefender->alive()){
         
            cout<<captainDefender->currhp;
            cout<<"attacker dies"<<endl;
            cout<<"Attack size"<<Attackers.size()<<endl;
            Attackers.pop_back();
            
            
          }else if(captainAttacker->alive()){
          
            cout<<"Defender dies"<<endl;
            if(Defenders[i++]){
            Defenders.pop_back(); 
           
            }else captainDefender->currhp=0;
          }          
        }
        if(Defenders.size()==0){
          adub++;
        }
        if (Attackers.size()==0)
          ddub++;
    }
};


int main(){
    srand(time(0));
    ofstream fout;
    ifstream read;

    
    read.open("input.txt");
    string input;

    CombatFeed CF;
    CF.totatt = 0;
    while(read >> input){
        CF.addAttacker(input);
    }
    
    CF.printAttackers();
    cout << CF.Attackers.size()<<endl;
    cout << CF.Defenders.size()<<endl;
    cout <<"Total Attackers: " << CF.totatt <<endl;
  

    for(int i =0;i<500;i++){
    CF.runBattle();
    CF.rndcnt++;
    }
    cout<<"adub"<<CF.adub<<endl;
    cout<<"ddub"<<CF.ddub<<endl;
    cout<<"rndcnt"<<CF.rndcnt<<endl;
    
    return 0;
}
