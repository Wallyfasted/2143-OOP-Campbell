#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "weapon.hpp"
#include "helpers.hpp"

using namespace std;

#pragma once

/**
 * Class BaseFighter
 * 
 * Description:
 *      acts as a base class for all the fighter types
 * 
 * Public Methods:
 *      -                   BaseFighter()
 *      -                   int getcurrhp()
 *       -                  int getmaxhp()
 *                          virtual int attack()=0
 *                          void takeDamage(int x)
 *                          string getName()
 *                          void regen()
 *                          void heal(){
 *                          bool alive()
 *                          virtual void weaponupgrade()=0
 *                          
*/
class BaseFighter {
  protected:
    //int currhp;
    int maxhp;
    double regenR;
    int FlameWeapon;
    
public:
    string name;
    int currhp;
    Weapon *weapon;
    Weapon *weapon2;

    BaseFighter(){
        name = "None";
        maxhp = 15;
        currhp = 0;
        regenR = (rand()%70)/100;     //health regen rate
        weapon = new Weapon;
        FlameWeapon = rand()%10;      //used for weapon upgrade
        
    }
    int getcurrhp(){
      return currhp;
    }
    int getmaxhp(){
      return maxhp;
    }

    virtual int attack() =0;

    void takeDamage(int x){
      currhp -= x;
    }

    void regen(){
      currhp += (maxhp*regenR);
    }

    void heal(){
      int h = rand()%5+3;
      if (this-> currhp + h < this-> maxhp){
        currhp += h;
      }else{
        currhp = maxhp;
      }
    }

    bool alive(){
      if (currhp > 0){
      return true;
      }else{
      return false;
      }
    }

  virtual void weaponupgrade()=0;
};

class Warrior: public BaseFighter{
  protected:
    int dice;
  public:
    Warrior(){
      name = "Warrior";
      dice = 6;
      maxhp += rand()%10;
      currhp += maxhp;
      weapon = new Sword();
    }
    int attack(){
      cout<<" Warrior Attacks!"<<endl;
      int r = weapon -> die -> roll();
      cout << r << endl;
      return r;
    }
    void weaponupgrade(){
      if(!FlameWeapon){
        weapon = new FlameSword();
      }
    }
};

class Wizard: public BaseFighter{
  protected:
    int dice;
  public:
    Wizard(){
      name = "Wizard";
      dice = 8;
      maxhp += rand()%10;
      currhp += maxhp;
      weapon = new AttackSpell();
    }
    int attack(){
      cout<<" Wizard Attacks!"<<endl;
      int r = weapon -> die -> roll();
      cout << r << endl;
      return r;
    }
    void weaponupgrade(){
      if(!FlameWeapon){
        weapon = new FlameBow();
      }
    }
     
};

class Archer: public BaseFighter{
  protected:
    int dice;
  public:
    Archer(){
      name = "Archer";
      dice = 4;
      maxhp += rand()%10;
      currhp += maxhp;
      weapon = new Bow();
    }
    int attack(){
      cout<<" Archer Attacks!"<<endl;
      int r = weapon -> die -> roll();
      cout << r << endl;
      return r;
    }
    void weaponupgrade(){
      if(!FlameWeapon){
        weapon = new FlameBow();
      }
    }
};

class Elf: public BaseFighter{
  protected:
    int dice;
  public:
    Elf(){
      name = "Elf";
      dice = 8;
      maxhp += rand()%10;
      currhp += maxhp;
      weapon = new AttackSpell();
      weapon2 = new Sword();
    }
    int attack(){
      cout<<" Elf Attacks!"<<endl;
      int r = weapon -> die -> roll();
      cout << r << endl;
      return r;
    }
    void weaponupgrade(){
      if(!FlameWeapon){
        weapon2 = new FlameSword();
      }
    }
};

class DragonBorn: public BaseFighter{
  protected:
    int dice;
  public:
    DragonBorn(){
      name = "Dragon Born";
      dice = 8;
      maxhp += rand()%8;
      currhp += maxhp;
      weapon = new AttackSpell();
      weapon2 = new FlameSword();
    }
    int attack(){
      cout<<" Dragon Born Attacks!"<<endl;
      int r = weapon -> die -> roll();
      cout << r << endl;
      return r;
    }

  void weaponupgrade(){
      if(!FlameWeapon){           //since function is pure virtual in parent
        weapon = new FlameSword();//need to upgrade the weapon
      }
  }
};
