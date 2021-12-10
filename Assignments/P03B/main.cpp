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


struct CombatFeed{
    int totatt=0;           //total attackers
    int totdef=0;    //total defenders
    int rndcnt=0;    // round count
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

    vector<BaseFighter*> Attackers; //need a new instance
    vector<BaseFighter*> Defenders;
   // vector<BaseFighter*> dead;
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

    // // read a file or autogenerate sum amount of defenders
    // // adds on defender of each type
    // void addDefenders(){
    //   //variabl
    // }

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

    captainDefender* = defenders[0]
    */

    void runBattle(){
        // 0) while there are still defenders and attackers
        // 1) use first attacker in the vector
        // 2) base on attacker point your captainDefender to the correct defender 
        // 3) do the game loop like below in main until someone dies
        // 4) remove the dead player from the appropriate vector
        //    if(!alive()){


           
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
          //  cout<<"captainAttcker wins"<<endl;
          //  cout<<"def Size:"<<Defenders.size()<<endl;
            cout<<captainDefender->currhp;
            cout<<"attacker dies"<<endl;
            cout<<"Attack size"<<Attackers.size()<<endl;
            Attackers.pop_back();
            
            //test
            // cout<<"def Size:"<<Defenders.size()<<endl;
          }else if(captainAttacker->alive()){
            // cout<<"captainDefender wins"<<endl;
            // //test
            // cout<<"def Size:"<<Attackers.size()<<endl;
            cout<<"Defender dies"<<endl;
            if(Defenders[i++]){
            Defenders.pop_back(); 
           
            }else captainDefender->currhp=0;
          }

            //test
            // cout<<"def Size:"<<Attackers.size()<<endl;
           
        
          
        }
        if(Defenders.size()==0){
          adub++;
        }
        if (Attackers.size()==0)
          ddub++;
    }
};

//~/P03B$ g++ main.cpp -std=c++17 -o runit
//~/P03B$ ./runit

int main(){
    srand(time(0));
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


    /*
    // attack in game idea
    // int w1Attack = 0;
    // int w2Attack = 0;

    // Warrior W1;
    // Warrior W2;

    if(Attackers[0].getName == "Warrior"){
        int i = 0;
       captainDefender = Defenders[i];
       if()
     }

     while(Attackers[0].alive() && captainDefender.alive())

    // while(W1.alive() && W2.alive()){
    //   w1Attack = W1.attack();
    //   w2Attack = W2.attack();
    //   if(w1Attack > w2Attack){
    //     W2.takeDamage(w1Attack);
    //   }

    //   w1Attack = W1.attack();
    //   w2Attack = W2.attack();
    //   if(w2Attack > w1Attack){
    //     W1.takeDamage(w2Attack);
    //   }
    // }

    // if(W1.alive()){
    //   cout<<"W1 wins"<<endl;
    // }else{
    //   cout<<"W2 wins"<<endl;
    // }

    */
    
    return 0;
}
