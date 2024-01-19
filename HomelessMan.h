#ifndef HOMELESSMAN_H
#define HOMELESSMAN_H

#include "Character.h"

class HomelessMan : public Character{
  private:
    ability attack;
    ability stare;
    ability shank;
    ability wildPunches;
    ability magicPowder;
  public:
    HomelessMan(string);
    HomelessMan(string, int, int, int, int, int, int, int, int, int, int);
    ~HomelessMan(){}
    string Attack(Character*) override;
    void infoAttack() override;
    string stringAttack() override {return attack.name;}
    string firstSkill(Character*) override;
    void infoFirstSkill() override;
    string stringFirstSkill() override {return stare.name;}
    string secondSkill(Character*) override;
    void infoSecondSkill() override;
    string stringSecondSkill() override {return shank.name;}
    string thirdSkill(Character*) override;
    void infoThirdSkill() override;
    string stringThirdSkill() override {return wildPunches.name;}
    string fourthSkill(Character*) override;
    void infoFourthSkill() override;
    string stringFourthSkill() override {return magicPowder.name;}
};

#endif