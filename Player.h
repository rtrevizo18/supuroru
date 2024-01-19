#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character{
  private:
    ability attack;
    ability bat;
    ability conversation;
    ability quickDiversion;
    ability sword;
  public:
    Player(string);
    Player(string, int, int, int, int, int, int, int, int, int, int);
    ~Player(){}
    string Attack(Character*) override;
    void infoAttack() override;
    string stringAttack() override {return attack.name;}
    string firstSkill(Character*) override;
    void infoFirstSkill() override;
    string stringFirstSkill() override {return bat.name;}
    string secondSkill(Character*) override;
    void infoSecondSkill() override;
    string stringSecondSkill() override {return conversation.name;}
    string thirdSkill(Character*) override;
    void infoThirdSkill() override;
    string stringThirdSkill() override {return quickDiversion.name;}
    string fourthSkill(Character*) override;
    void infoFourthSkill() override;
    string stringFourthSkill() override {return sword.name;}
};

#endif