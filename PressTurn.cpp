#include "PressTurn.h"

PressTurn::PressTurn(vector<Character*>& Party, vector<Character*>& Enemies){
  this->Party = Party;
  this->Enemies = Enemies;
  partyTurns = Party.size();
  enemiesTurns = Enemies.size();
  maxPartyTurns = (Party.size() * 2);
  maxEnemyTurns = (Enemies.size() * 2);
  isPartyTurn = 1;
}

void PressTurn::BattleMenu(){
  int i;
  cout << "---------------------------" << "BATTLE" << "---------------------------" << endl;
  cout << setfill(' ');
  for(i = 0; i < Enemies.size(); ++i){
    cout << (i + 1) << ". " << Enemies[i]->getName() << setw(12 - Enemies[i]->getName().length()) << "";
  }
  cout << endl;
  for(i = 0; i < Enemies.size(); ++i){
    cout << "Energy: " << Enemies[i]->getEnergy() << setw(7 - to_string(Enemies[i]->getEnergy()).size()) << "";
  }
  cout << endl;
  for(i = 0; i < Enemies.size(); ++i){
    cout << "Attention: " << Enemies[i]->getAtten() << setw(4 - to_string(Enemies[i]->getAtten()).size()) << "";
  }
  cout << endl << endl;
  for(i = 0; i < Party.size(); ++i){
    cout << (i + 1) << ". " << Party[i]->getName() << setw(12 - Party[i]->getName().length()) << "";
  }
  cout << endl;
  for(i = 0; i < Party.size(); ++i){
    cout << "Energy: " << Party[i]->getEnergy() << setw(7 - to_string(Party[i]->getEnergy()).size()) << "";
  }
  cout << endl;
  for(i = 0; i < Party.size(); ++i){
    cout << "Attention: " << Party[i]->getAtten() << setw(4 - to_string(Party[i]->getAtten()).size()) << "";
  }
  cout << endl;
  if (isPartyTurn){
    cout << "------------------------TURNSLEFT: " << (partyTurns - TURN) << "------------------------" << endl;
  }
  else{
    cout << "------------------------TURNSLEFT: " << (enemiesTurns - TURN) << "------------------------" << endl;
  }
  if (isPartyTurn){
    cout << "[PARTY] " << Party[TURN % Party.size()]->getName() << "\'s Turn!" << endl;
  }
  else{
    cout << "[ENEMIES] " << Enemies[TURN % Enemies.size()]->getName() << "\'s Turn!" << endl;
  }
  return; 
}

string PressTurn::checkEnd(){
  if(Party[0]->isDead()){
    return "DEATH";
  }
  else if (Enemies.size() > 0){
    return "ONGOING";
  }
  else{
    return "VICTORY";
  }
}

bool PressTurn::Battle(){
  while(checkEnd() == "ONGOING"){
    if(isPartyTurn){
      playersTurn();
    }
    else{
      enemiesTurn();
    }
  }
  if (checkEnd() == "DEATH"){
    cout << "GAME OVER!!!" << endl;
    return false;
  }
  else if (checkEnd() == "VICTORY"){
    cout << "YOU WON THE BATTLE!" << endl;
    for(int i = 0; i < Enemies.size(); ++i){
      cout << Enemies[i]->getName() << endl;
    }
    return true;
  }
  cout << "FAILED MAIN BATTLE FUNCTON" << endl;
  return false;
}

void PressTurn::enemiesTurn(){
  TURN = 0;
  
  if(checkDeath()){
      return;
  }

  cout << "Start of enemy turn!" << endl;
  
  enemiesTurns = Enemies.size();
  maxEnemyTurns = enemiesTurns * 2;
  
  int randomSkill;
  int randomTarget;
  bool cinValid;
  string wkNStype;
  while(TURN < enemiesTurns){
    cinValid = false;
    if(checkDeath()){
      break;
    }
    sleep(2);
    BattleMenu();
    cout << Enemies[TURN % Enemies.size()]->getName() << " is choosing their next move..." << endl;
    sleep(2);
    while(!cinValid){
      randomSkill = rand() % 5;
      randomTarget = rand() % Party.size();
      switch (randomSkill){
        case 0:
          wkNStype = Enemies[TURN % Enemies.size()]->Attack(Party[randomTarget]);
          if((Party[randomTarget]->isWK(wkNStype)) && enemiesTurns < maxEnemyTurns){
            cout << Party[randomTarget]->getName() << " is weakened!!!" << endl;
            sleep(2);
            enemiesTurns++;
            cinValid = true;
          }
          else if (wkNStype == "RETURN"){
            continue;
          }
          else{
            cinValid = true;
          }
          break;
        case 1:
          wkNStype = Enemies[TURN % Enemies.size()]->firstSkill(Party[randomTarget]);
          if((Party[randomTarget]->isWK(wkNStype)) && enemiesTurns < maxEnemyTurns){
            cout << Party[randomTarget]->getName() << " is weakened!!!" << endl;
            sleep(2);
            enemiesTurns++;
            cinValid = true;
          }
          else if (wkNStype == "RETURN"){
            continue;
          }
          else{
            cinValid = true;
          }
          break;
        case 2:
          wkNStype = Enemies[TURN % Enemies.size()]->secondSkill(Party[randomTarget]);
          if((Party[randomTarget]->isWK(wkNStype)) && enemiesTurns < maxEnemyTurns){
            cout << Party[randomTarget]->getName() << " is weakened!!!" << endl;
            sleep(2);
            enemiesTurns++;
            cinValid = true;
          }
          else if (wkNStype == "RETURN"){
            continue;
          }
          else{
            cinValid = true;
          }
          break;
        case 3:
          wkNStype = Enemies[TURN % Enemies.size()]->thirdSkill(Party[randomTarget]);
          if((Party[randomTarget]->isWK(wkNStype)) && enemiesTurns < maxEnemyTurns){
            cout << Party[randomTarget]->getName() << " is weakened!!!" << endl;
            sleep(2);
            enemiesTurns++;
            cinValid = true;
          }
          else if (wkNStype == "RETURN"){
            continue;
          }
          else{
            cinValid = true;
          }
          break;
        case 4:
          wkNStype = Enemies[TURN % Enemies.size()]->fourthSkill(Party[randomTarget]);
          if((Party[randomTarget]->isWK(wkNStype)) && enemiesTurns < maxEnemyTurns){
            cout << Party[randomTarget]->getName() << " is weakened!!!" << endl;
            sleep(2);
            enemiesTurns++;
            cinValid = true;
          }
          else if (wkNStype == "RETURN"){
            continue;
          }
          else{
            cinValid = true;
          }
          break;
        default:
          cout << "The Enemy attack function messed up lol" << endl;
          break;
      }
    }
    TURN++;
  }
  isPartyTurn = true;
  cout << "End of enemy turn..." << endl;
  sleep(1);
}

void PressTurn::playersTurn(){
  TURN = 0;
  if(checkDeath()){
    return;
  }

  partyTurns = Party.size();
  maxPartyTurns = partyTurns * 2;

  while (TURN < partyTurns){
    if(checkDeath()){
      break;
    }
    int actionNum;
    BattleMenu();
    cout << "1. Attack " << endl;
    cout << "2. Check stats" << endl;
    cout << "Enter number: ";
    cin >> actionNum;
    if (actionNum == 1){
      int targetPos;
      cout << "Pick target: ";
      cin >> targetPos;
      if (targetPos <= 0 || targetPos > Enemies.size()){
        cout << "Please pick valid enemy target!" << endl;
        continue;
      }
      else{
        playerAttack(targetPos);
      }
    }
    else if (actionNum == 2){
      int partyOrEnemy;
      int targetPos;
      cout << "Party - 1 or Enemies - 2: ";
      cin >> partyOrEnemy;
      if (partyOrEnemy == 1){
        cout << "Pick party member: ";
        cin >> targetPos;
        if ((targetPos <= 0) || (targetPos > Party.size())){
          cout << "Please pick valid party number!" << endl;
          continue;
        }
        else{
          cout << endl;
          Party[targetPos - 1]->printStats();
          Party[targetPos - 1]->printwKNS();
          sleep(3);
          continue;
        }
      }
      else if (partyOrEnemy == 2){
        bool inputValid = false;
        while(!inputValid){
          cout << "Pick enemy member: ";
          cin >> targetPos;
          if ((targetPos <= 0) || (targetPos > Enemies.size())){
            cout << "Please pick valid enemy number!" << endl;
            continue;
          }
          else{
            Enemies[targetPos - 1]->printStats();
            Enemies[targetPos - 1]->printwKNS();
            sleep(3);
            inputValid = true;
          }
        }
        continue;
      }
      else{
        cout << "Pick a number (1-2)" << endl;
        continue;
      }
    }
    else{
      cout << "Pick a number (1-2)" << endl;
      continue;
    }
  }
  isPartyTurn = false;
  cout << "End of player turn..." << endl;
  sleep(1);
}

void PressTurn::printSkills(int charPos){
  for(int i = 1; i < 6; ++i){
    cout << i << ". ";
    switch (i){
      case 1:
        cout << Party[charPos]->stringAttack() << endl;
        Party[charPos]->infoAttack();
      break;
      case 2:
        cout << Party[charPos]->stringFirstSkill() << endl;
        Party[charPos]->infoFirstSkill();
        break;
      case 3:
        cout << Party[charPos]->stringSecondSkill() << endl;
        Party[charPos]->infoSecondSkill();
        break;
      case 4:
        cout << Party[charPos]->stringThirdSkill() << endl;
        Party[charPos]->infoThirdSkill();
        break;
      case 5:
        cout << Party[charPos]->stringFourthSkill() << endl;
        Party[charPos]->infoFourthSkill();
        break;
    }
  }
}

void PressTurn::playerAttack(int targetPos){
  int attackPick;
  bool cinValid = false;
  string wkNStype;
  while(!cinValid){
    printSkills(TURN % Party.size());
    cout << "Choose attack (1-5): ";
    cin >> attackPick;
    if (attackPick <= 0 || attackPick > 5){
      cout << "Choose valid attack number!" << endl;
      continue;
    }
    else{
      switch (attackPick){
      case 1:
        wkNStype = Party[TURN % Party.size()]->Attack(Enemies[targetPos - 1]);
        if((Enemies[targetPos - 1]->isWK(wkNStype)) && partyTurns < maxPartyTurns){
          cout << Enemies[targetPos - 1]->getName() << " is weakened!!!" << endl;
          sleep(2);
          partyTurns++;
          cinValid = true;
        }
        else if (wkNStype == "RETURN"){
          cout << "Not enough attention!" << endl;
          continue;
        }
        else{
          cinValid = true;
        }
        break;
      case 2:
        wkNStype = Party[TURN % Party.size()]->firstSkill(Enemies[targetPos - 1]);
        if((Enemies[targetPos - 1]->isWK(wkNStype)) && partyTurns < maxPartyTurns){
          cout << Enemies[targetPos - 1]->getName() << " is weakened!!!" << endl;
          sleep(2);
          partyTurns++;
          cinValid = true;
        }
        else if (wkNStype == "RETURN"){
          cout << "Not enough attention!" << endl;
          continue;
        }
        else{
          cinValid = true;
        }
        break;
      case 3:
        wkNStype = Party[TURN % Party.size()]->secondSkill(Enemies[targetPos - 1]);
        if((Enemies[targetPos - 1]->isWK(wkNStype)) && partyTurns < maxPartyTurns){
          cout << Enemies[targetPos - 1]->getName() << " is weakened!!!" << endl;
          sleep(2);
          partyTurns++;
          cinValid = true;
        }
        else if (wkNStype == "RETURN"){
          cout << "Not enough attention!" << endl;
          continue;
        }
        else{
          cinValid = true;
        }
        break;
      case 4:
        wkNStype = Party[TURN % Party.size()]->thirdSkill(Enemies[targetPos - 1]);
        if((Enemies[targetPos - 1]->isWK(wkNStype)) && partyTurns < maxPartyTurns){
          cout << Enemies[targetPos - 1]->getName() << " is weakened!!!" << endl;
          sleep(2);
          partyTurns++;
          cinValid = true;
        }
        else if (wkNStype == "RETURN"){
          cout << "Not enough attention!" << endl;
          continue;
        }
        else{
          cinValid = true;
        }
        break;
      case 5:
        wkNStype = Party[TURN % Party.size()]->fourthSkill(Enemies[targetPos - 1]);
        if((Enemies[targetPos - 1]->isWK(wkNStype)) && partyTurns < maxPartyTurns){
          cout << Enemies[targetPos - 1]->getName() << " is weakened!!!" << endl;
          sleep(2);
          partyTurns++;
          cinValid = true;
        }
        else if (wkNStype == "RETURN"){
          cout << "Not enough attention!" << endl;
          continue;
        }
        else{
          cinValid = true;
        }
        break;
      default:
        cout << "The Party attack function messed up lol" << endl;
        break;
      }
      TURN++;
    }
  }
}

bool PressTurn::checkDeath(){
  if (Party[0]->isDead()){
    return true;
  }
  int i;
  int partySize = Party.size();
  int enemySize = Enemies.size();

  auto it = Party.begin();
  while(it != Party.end()){
    if ((*it)->isDead()){
      delete (*it);
      (*it) = nullptr;
      it = Party.erase(it);
    }
    else{
      it++;
    }
  }
  it = Enemies.begin();
  while(it != Enemies.end()){
    if ((*it)->isDead()){
      delete (*it);
      (*it) = nullptr;
      it = Enemies.erase(it);
    }
    else{
      it++;
    }
  }
  
  if (Enemies.size() == 0){
    return true;
  }
  
  return false;
}