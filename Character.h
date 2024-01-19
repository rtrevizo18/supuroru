#ifndef CHARACTER_H
#define CHARACTER_H

#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

struct stats{
  int lvl = 1;
  int exp = 0;
  int maxEnergy = -1;
  int maxAttention = -1;
  int physical = -1;
  int mystique = -1;
  int defense = -1;
  int rizz = -1;
};

struct weakness{
  bool fire;
  bool ice;
  bool electric;
  bool bullet;
  bool physical;
  bool taunt;
  bool dumbness;
};

struct ability{
  string name;
  int damage;
  int deltaAtten;
  string typeStat;
  string typewKNS;
  string description;
};

class Character {
  private:
    string name;
    string bio;
    int energy;
    int attention;
    string getStatsString(string, int) const;
    string getWKorST(string, bool) const;
    int typeStat(string);
    void checkLVLUP();
  protected:
    stats cStats;
    weakness cwKNS;
    int currentAttackDamage;
    bool damagingAttack(Character*, ability);
    bool damagingAtten(Character*, ability);
    ability defineAbility(string, int, int, string, string, string);
  public:
    virtual ~Character();
    virtual string Attack(Character*) = 0;
    virtual void infoAttack() = 0;
    virtual string stringAttack() = 0;
    virtual string firstSkill(Character*) = 0;
    virtual void infoFirstSkill() = 0;
    virtual string stringFirstSkill() = 0;
    virtual string secondSkill(Character*) = 0;
    virtual void infoSecondSkill() = 0;
    virtual string stringSecondSkill() = 0;
    virtual string thirdSkill(Character*) = 0;
    virtual void infoThirdSkill() = 0;
    virtual string stringThirdSkill() = 0;
    virtual string fourthSkill(Character*) = 0;
    virtual void infoFourthSkill() = 0;
    virtual string stringFourthSkill() = 0;
    void setName(string name) {this->name = name;}
    string getName() const {return name;}
    void setBio(string bio) {this->bio = bio;}
    string getBio() const {return bio;}
    void setEnergy(int energy) {this->energy = energy;}
    int getEnergy() const {return energy;}
    void setAtten(int attention) {this->attention = attention;}
    int getAtten() const {return attention;}
    void setEXP(int exp) {this->cStats.exp = exp;}
    int getEXP() {return cStats.exp;}
    void readStats();
    void printStats() const;
    void printwKNS() const;
    bool isWK(string);
    bool isDead();
    friend bool saveGame(int, vector<Character*>&);
};

/*
Putting these away for later:
void setStats(stats pStats) {this->cStats = pStats;}
stats getStats() const {return cStats;}
void setwKNS(weakness cwKNS) {this->cwKNS = cwKNS;}
weakness getwKNS() {return cwKNS;}
*/


#endif