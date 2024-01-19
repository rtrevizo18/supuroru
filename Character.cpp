#include "Character.h"

Character::~Character(){
  cout << this->name << " fell asleep!!!" << endl;
  sleep(2);
}

void Character::checkLVLUP(){
  if (cStats.exp >= 100){

    cout << this->name << " leveled up!" << endl;
      
    int temp;

    temp = cStats.exp - 100;

    cStats.exp = temp;

    cStats.lvl++;
    cStats.maxEnergy += 5;
    cStats.maxAttention += 3;
    this->energy = cStats.maxEnergy;
    this->attention = cStats.maxAttention;
    cStats.physical++;
    cStats.mystique++;
    cStats.defense++;
    cStats.rizz++;

    this->printStats();

    return;
  }
  else{
    return;
  }
}

void Character::readStats(){
  cout << "Please enter stats:" << endl;
  cout << "Enter Level: ";
  cin >> cStats.lvl;
  cout << "Please enter stats:" << endl;
  cout << "Enter Max Energy: ";
  cin >> cStats.maxEnergy;
  cout << "Please enter stats:" << endl;
  cout << "Enter Max Attention: ";
  cin >> cStats.maxAttention;
  cout << "Please enter stats:" << endl;
  cout << "Enter Physical: ";
  cin >> cStats.physical;
  cout << "Please enter stats:" << endl;
  cout << "Enter Mystique: ";
  cin >> cStats.mystique;
  cout << "Please enter stats:" << endl;
  cout << "Enter Defense: ";
  cin >> cStats.defense;
  cout << "Please enter stats:" << endl;
  cout << "Enter Rizz: ";
  cin >> cStats.rizz;
}

string Character::getStatsString(string statName, int statNum) const{
  stringstream returnS;

  int length = (20 - statName.length()) + name.length();
  
  if(statName == "ENERGY: "){
    returnS << statName << right << setw(length) << this->energy << "/" << statNum;
  }
  else if(statName == "ATTENTION: "){
    returnS << statName << right << setw(length) << this->attention << "/" << statNum;
  }
  else{
  returnS << statName << right << setw(length) << statNum;
  }
  
  return returnS.str();
}

void Character::printStats() const {
  cout << "----------" << name << "----------" << endl;
  cout << getStatsString("LEVEL: ",cStats.lvl) << endl;
  cout << getStatsString("EXPERIENCE: ", cStats.exp) << endl;
  cout << getStatsString("ENERGY: ", cStats.maxEnergy) << endl;
  cout << getStatsString("ATTENTION: ", cStats.maxAttention) << endl;
  cout << getStatsString("PHYSICAL: ", cStats.physical) << endl;
  cout << getStatsString("MYSTIQUE: ", cStats.mystique) << endl;
  cout << getStatsString("DEFENSE: ", cStats.defense) << endl;
  cout << getStatsString("RIZZ: ", cStats.rizz) << endl;
  cout << setfill('-') << setw(20 + name.length()) << "" << endl;
  cout << setfill(' ') << endl;
}

string Character::getWKorST(string eleName, bool wKNS) const{
  string weakOrStrong;
  stringstream returnS;
  int length = (20 - eleName.length()) + name.length();

  returnS << eleName << right << setw(length);
  
  if(wKNS){
    weakOrStrong = "WEAK";
  }
  else{
    weakOrStrong = "STRONG";
  }

  returnS << weakOrStrong;
  
  return returnS.str();
}

void Character::printwKNS() const {
  cout << "----------" << name << "----------" << endl;
  cout << getWKorST("FIRE: ", cwKNS.fire) << endl;
  cout << getWKorST("ICE: ", cwKNS.ice) << endl;
  cout << getWKorST("ELECTRIC: ", cwKNS.electric) << endl;
  cout << getWKorST("BULLET: ", cwKNS.bullet) << endl;
  cout << getWKorST("PHYSICAL: ", cwKNS.physical) << endl;
  cout << getWKorST("TAUNT: ", cwKNS.taunt) << endl;
  cout << getWKorST("DUMBNESS: ", cwKNS.dumbness) << endl;
  cout << setfill('-') << setw(20 + name.length()) << "" << endl;
  cout << setfill(' ') << endl;
}

bool Character::isWK(string typeWK){
  if(typeWK == "FIRE"){
    return cwKNS.fire;
  }
  else if (typeWK == "ICE"){
    return cwKNS.ice;
  }
  else if (typeWK == "ELECTRIC"){
    return cwKNS.electric;
  }
  else if (typeWK == "BULLET"){
    return cwKNS.bullet;
  }
  else if (typeWK == "PHYSICAL"){
    return cwKNS.physical;
  }
  else if (typeWK == "TAUNT"){
    return cwKNS.taunt;
  }
  else if (typeWK == "DUMBNESS"){
    return cwKNS.dumbness;
  }
  return false;
}

int Character::typeStat(string typeAttackString){
  if(typeAttackString == "PHYSICAL"){
    return cStats.physical;
  }
  else if(typeAttackString == "MAGIC"){
    return cStats.mystique;
  }
  else if(typeAttackString == "DEFENSE"){
    return cStats.defense;
  }
  else if(typeAttackString == "RIZZ"){
    return cStats.rizz;
  }
  return -1;
}

bool Character::damagingAttack(Character* Target, ability skill){
  int calcDamage;
  int calcExperience;
  if(this->attention < skill.deltaAtten){
    return false;
  }
  
  this->attention -= skill.deltaAtten;

  calcDamage = skill.damage * typeStat(skill.typeStat);

  this->currentAttackDamage = (calcDamage / Target->cStats.defense);

  Target->energy -= this->currentAttackDamage;

  if (Target->energy < 0){
    Target->energy = 0;
  }

  calcExperience = (Target->cStats.lvl / this->cStats.lvl) * 20;

  this->cStats.exp += calcExperience;

  this->checkLVLUP();

  return true;

  return true;
}

bool Character::damagingAtten(Character* Target, ability skill){
  int calcDamage;
  int calcExperience;
  if(this->attention < skill.deltaAtten){
    return false;
  }
  
  this->attention -= skill.deltaAtten;

  calcDamage = skill.damage * typeStat(skill.typeStat);

  this->currentAttackDamage = (calcDamage / Target->cStats.defense);

  Target->attention -= this->currentAttackDamage;

  if (Target->attention < 0){
    Target->attention = 0;
  }

  //EXP Calculation

  calcExperience = (Target->cStats.lvl / this->cStats.lvl) * 20;

  this->cStats.exp += calcExperience;

  this->checkLVLUP();

  return true;
}

ability Character::defineAbility(string name, int damage, int deltaAtten, string typeStat, string typewKNS, string description){
  ability returnAbility;
  returnAbility.name = name;
  returnAbility.damage = damage;
  returnAbility.deltaAtten = deltaAtten;
  returnAbility.typeStat = typeStat;
  returnAbility.typewKNS = typewKNS;
  returnAbility.description = description;

  return returnAbility;
}

bool Character::isDead(){
  if (this->energy <= 0){
    return true;
  }
  return false;
}

bool saveGame(int stage, vector<Character*>& Party){
  int i;
  ofstream saveFile;

  saveFile.open("saveFile.txt", ofstream::out | ofstream::trunc);

  if (!saveFile.is_open()) {
      cout << "Could not open file saveFile.txt." << endl;
      return false;
   }
  
  saveFile.close();

  saveFile.open("saveFile.txt");

  saveFile << stage << endl;

  if (stage == 1){
    for (i = 0; i < 2; ++i){
      saveFile << Party[i]->name << endl;
      saveFile << Party[i]->cStats.lvl << endl;
      saveFile << Party[i]->cStats.exp << endl;
      saveFile << Party[i]->energy << endl;
      saveFile << Party[i]->attention << endl;
      saveFile << Party[i]->cStats.maxEnergy << endl;
      saveFile << Party[i]->cStats.maxAttention << endl;
      saveFile << Party[i]->cStats.physical << endl;
      saveFile << Party[i]->cStats.mystique << endl;
      saveFile << Party[i]->cStats.defense << endl;
      saveFile << Party[i]->cStats.rizz << endl;
    }
  }
  if (stage == 2){
    for (i = 0; i < 4; ++i){
      saveFile << Party[i]->name << endl;
      saveFile << Party[i]->cStats.lvl << endl;
      saveFile << Party[i]->cStats.exp << endl;
      saveFile << Party[i]->energy << endl;
      saveFile << Party[i]->attention << endl;
      saveFile << Party[i]->cStats.maxEnergy << endl;
      saveFile << Party[i]->cStats.maxAttention << endl;
      saveFile << Party[i]->cStats.physical << endl;
      saveFile << Party[i]->cStats.mystique << endl;
      saveFile << Party[i]->cStats.defense << endl;
      saveFile << Party[i]->cStats.rizz << endl;
    }
  }
  saveFile.close();

  return true;
}