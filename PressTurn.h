#ifndef PRESSTURN_H
#define PRESSTURN_H

#include "Character.h"

class PressTurn{
  private:
    int partyTurns;
    int enemiesTurns;
    int maxPartyTurns;
    int maxEnemyTurns;
    int TURN;
    bool isPartyTurn;
    bool checkDeath();
    void playerAttack(int);
    void enemiesTurn();
    void playersTurn();
    void printSkills(int);
    string checkEnd();
    vector<Character*> Party;
    vector<Character*> Enemies;
  public:
    PressTurn(vector<Character*>&, vector<Character*>&);
    void BattleMenu();
    bool Battle();
};



#endif