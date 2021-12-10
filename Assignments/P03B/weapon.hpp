/**
 * Class Weapon
 * 
 * Description:
 *      acts as a base class for the weapons that the fighters will use
 * 
 * Public Methods:
 *      -                   Weapon()
 *      -                   Weapon(vector< string > choices)
 *       -                  double use()
 *                          string getDamage()
 *                          friend ostream& operator<<(ostream& os, const Weapon& w) {
 *                          string getName()
*/

#include <iostream>
#include <string>
#include <vector>

#include "dice.hpp"
#include "helpers.hpp"

using namespace std;

#pragma once

class Weapon{
  protected:
  string damage;  // damage per roll or "use"
  

  public:
    string name;
    Dice* die;
    string weaponTxt;
   
    Weapon(){
        name = "Fists&Feet";
        damage = "1.d.4";
        die = new Dice(damage);
    }
    /**
     * @brief Overloaded Constructor for a new Base Weapon object
     *  Also invokes the Dice class constructor with the "die" type
     * @param choices-vector of string "die" choices like {"2.d.8","2.d.10","3.d.4"}
     */
    Weapon(vector< string > choices) {
        name = "Fists&Feet";
        damage = randomChoice(choices);
        die = new Dice(damage);
    }

    double use(){
        return die->roll();
    }

    string getDamage(){
      return "";
    }

    friend ostream& operator<<(ostream& os, const Weapon& w) {
        return os << "[" << w.name << " , " << w.damage << "]";
    }

    string getName(){
     return name;
    }
};

class Sword : public Weapon{
  public:
    Sword(){
      name = "Sword";
      damage = getDamage();
      die = new Dice(damage);
      weaponTxt = " sword strike!";
    }
    //1.d.12 OR 2.d.6 OR 3.d.4
    string getDamage(){
      string d;
      int r = rand()%3;
      switch(r){
        case 0:
          d = "1.d.12";
        break;
        case(1):
          d = "2.d.6";
        break;
        case(2):
          d = "3.d.4";
        break;
        }
      return d;
    } 
};
      
class Bow : public Weapon{
  public:
    Bow(){
      name = "Bow";
      damage = getDamage();
      die = new Dice(damage);
      weaponTxt = "Archer's arrow strikes home!";
    }
    //1.d.8 OR 2.d.4 OR 1.d.10
    string getDamage(){
      string d;
      int r = rand()%3;
      switch(r){
        case 0:
          d = "1.d.8";
        break;
        case(1):
          d = "2.d.4";
        break;
        case(2):
          d = "1.d.10";
        break;
        }
      return d;
    } 
};

class AttackSpell : public Weapon{
  public:
    AttackSpell(){
      name = "Attack Spell";
      damage = getDamage();
      die = new Dice(damage);
      weaponTxt = "Mages attack spell melts an enemy";
    }
    //1.d.20 OR 2.d.10 OR 3.d.6 OR 5.d.4
    string getDamage(){
      string d;
      int r = rand()%4;
      switch(r){
        case 0:
          d = "1.d.20";
        break;
        case(1):
          d = "2.d.10";
        break;
        case(2):
          d = "3.d.6";
        break;
        case(3):
          d = "5.d.4";
        break;
        }
      return d;
    } 
};

class FlameSword : public Weapon{
  public:
    FlameSword(){
      name = "Flame Sword";
      damage = getDamage();
      die = new Dice(damage);
      weaponTxt = " flaming sword cutts deep";
    }
    //1.d.20 OR 2.d.10 OR 3.d.6 OR 5.d.4
    string getDamage(){
      string d;
      int r = rand()%4;
      switch(r){
          case 0:
          d = "2.d.12";
        break;
        case(1):
          d = "3.d.6";
        break;
        case(2):
          d = "4.d.4";
        break;
        }
      return d;
    } 
};

class FlameBow : public Weapon{
  public:
    FlameBow(){
      name = "Flame Bow";
      damage = getDamage();
      die = new Dice(damage);
      weaponTxt = "Archer's flamming arrow strikes home!";
    }
    //1.d.8 OR 2.d.4 OR 1.d.10
    string getDamage(){
      string d;
      int r = rand()%3;
      switch(r){
        case 0:
          d = "2.d.8";
        break;
        case(1):
          d = "3.d.4";
        break;
        case(2):
          d = "2.d.10";
        break;
        }
      return d;
    } 
};