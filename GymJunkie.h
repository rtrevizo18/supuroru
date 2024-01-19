#ifndef GYMJUNKIE_H
#define GYMJUNKIE_H

#include "Character.h"

class GymJunkie : public Character{
  private:
    ability attack;
    ability HGHPunch;
    ability roidRage;
    ability TRTTackle;
    ability syringeTime;
  public:
    GymJunkie(string);
    GymJunkie(string, int, int, int, int, int, int, int, int, int, int);
    ~GymJunkie(){}
    string Attack(Character*) override;
    void infoAttack() override;
    string stringAttack() override {return attack.name;}
    string firstSkill(Character*) override;
    void infoFirstSkill() override;
    string stringFirstSkill() override {return HGHPunch.name;}
    string secondSkill(Character*) override;
    void infoSecondSkill() override;
    string stringSecondSkill() override {return roidRage.name;}
    string thirdSkill(Character*) override;
    void infoThirdSkill() override;
    string stringThirdSkill() override {return TRTTackle.name;}
    string fourthSkill(Character*) override;
    void infoFourthSkill() override;
    string stringFourthSkill() override {return syringeTime.name;}
};

#endif