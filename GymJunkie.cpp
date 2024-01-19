#include "GymJunkie.h"

GymJunkie::GymJunkie(string name){
  this->setName(name);
  this->setBio(this->getName() + " usually hangs around the shady corner outside LA Fitness...");
  this->setEnergy(100);
  this->setAtten(30);
  this->cStats.maxEnergy = 100;
  this->cStats.maxAttention = 30;
  this->cStats.physical = 7;
  this->cStats.mystique = 2;
  this->cStats.defense = 4;
  this->cStats.rizz = 4;
  this->cwKNS.fire = false;
  this->cwKNS.ice = false;
  this->cwKNS.electric = true;
  this->cwKNS.bullet = false;
  this->cwKNS.physical = false;
  this->cwKNS.taunt = true;
  this->cwKNS.dumbness = true;
  this->attack = defineAbility("Attack", 5, 0, "PHYSICAL", "PHYSICAL", "Light Physical Attack");
  this->HGHPunch = defineAbility("HGHPunch", 8, 5, "PHYSICAL", "ELECTRIC", "Medium Electrical Attack");
  this->roidRage = defineAbility("Roid Rage", 7, 5, "PHYSICAL", "TAUNT", "Medium Physical Taunt");
  this->TRTTackle = defineAbility("TRT Tackle", 13, 12, "PHYSICAL", "PHYSICAL", "Heavy Physical Attack");
  this->syringeTime = defineAbility("SyringeTime", 13, 12, "MAGIC", "DUMBNESS", "Heavy Magical Dumb-Attack");
}

GymJunkie::GymJunkie(string name, int level, int EXP, int energy, int atten, int maxEn, int maxAtten, int physical, int mystique, int defense, int rizz){
  this->setName(name);
  this->setBio(this->getName() + " usually hangs around the shady corner outside LA Fitness...");
  this->setEnergy(energy);
  this->setAtten(atten);
  this->cStats.lvl = level;
  this->cStats.exp = EXP;
  this->cStats.maxEnergy = maxEn;
  this->cStats.maxAttention = maxAtten;
  this->cStats.physical = physical;
  this->cStats.mystique = mystique;
  this->cStats.defense = defense;
  this->cStats.rizz = rizz;
  this->cwKNS.fire = false;
  this->cwKNS.ice = false;
  this->cwKNS.electric = true;
  this->cwKNS.bullet = false;
  this->cwKNS.physical = false;
  this->cwKNS.taunt = true;
  this->cwKNS.dumbness = true;
  this->attack = defineAbility("Attack", 5, 0, "PHYSICAL", "PHYSICAL", "Light Physical Attack");
  this->HGHPunch = defineAbility("HGHPunch", 8, 5, "PHYSICAL", "ELECTRIC", "Medium Electrical Attack");
  this->roidRage = defineAbility("Roid Rage", 7, 5, "PHYSICAL", "TAUNT", "Medium Physical Taunt");
  this->TRTTackle = defineAbility("TRT Tackle", 13, 12, "PHYSICAL", "PHYSICAL", "Heavy Physical Attack");
  this->syringeTime = defineAbility("SyringeTime", 13, 12, "MAGIC", "DUMBNESS", "Heavy Magical Dumb-Attack");
}

string GymJunkie::Attack(Character* Target){
  
  if(!damagingAttack(Target, this->attack)){
    return "RETURN";
  }
  
  cout << this->getName() << " stopped his set..." << endl;
  sleep(1);
  cout << "What's he doing?..." << endl;
  sleep(1);
  cout << R"(
..................................................
..................................................
..................................................
............... ..................................
...........&@@@@*.................@@@@@...........
...... *@@*@@@@@* ................@@@@@.@@%.......
.......@@@@&@@@@* ................@@@@@,@@@.......
.......@@@@&@@@@* ............. ..@@@@@,@@@ ......
....%@&@@@@&@@@@*@@@@@@@@@@@@@@@@.@@@@@,@@@.@@....
...... @@@@&@@@@* .............. .@@@@@,@@@ ......
.......@@@@&@@@@* ................@@@@@,@@@.......
.......*@@,@@@@@* ................@@@@@ @@% ......
...........&@@@@* ................@@@@@...........
..................................................
..................................................
..................................................
    )" << endl;
  cout << "He threw the barbell, watch out!" << endl;
  
  sleep(1);
  
  cout << this->currentAttackDamage << " DAMAGE DEALT" << endl;
  sleep(1);
  
  return this->attack.typewKNS;
}

void GymJunkie::infoAttack(){
  cout << "   Attention Cost: " << this->attack.deltaAtten << endl;
  cout << "   " << this->attack.description << endl;
}

string GymJunkie::firstSkill(Character* Target){
  
  if(!damagingAttack(Target, this->HGHPunch)){
    return "RETURN";
  }
  
  cout << this->getName() << " stopped his set..." << endl;
  sleep(1);
  cout << "He's rubbing his hands together...there's electricity coming out..." << endl;
  sleep(1);
  cout << "HUH?!" << endl;
  cout << R"(
      \\           \\\        ///          //            \\         \\\             //   //        /    
       \\\          \\         //          //           \\\          \\            //   ///      //       
         \\\         @@@@@@@  *@@@@@@  //                  \\   %@@@@@#  &@@@@@@  //  //       ///     
          \\  @@@@@@@@@@@@@@@@@@@@@@@@*                     \\ @@@@@@@@@@@@@@@@@@@@@@@#        //     
            &@@@@@@@@@@@@@@@@@@@@@@@@@@                       ,@@@@@@@@@@@@@@@@@@@@@@@@@@    //       
       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.                      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      
      @@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@ @                 ,. @@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@     
      @@@@@@@*@@@@@@@# @@@@@@@@@ @@@@@@@  @@@           %@@@ @@@@@@@% @@@@@@@@% @@@@@@@#@@@@@@@     
       @@@@@@# @@@@@@@ @@@@@@@@@ &@@@@@@@ @@@           ,@@( @@@@@@@ @@@@@@@@@ @@@@@@@/ @@@@@@      
        @@@@@@ @@@@@@@@ @@@@@@@@@ @@@@@@@ (@@            @@ @@@@@@@, @@@@@@@@  @@@@@@@ @@@@@@       
         @@@@@@ @@@@@@@ #@@@@@@@@ *@@@@@@@ @@            @@ @@@@@@@ @@@@@@@@@ @@@@@@@ @@@@@@        
          @@@@@( @@@@@@@ @@@@@@@@@ @@@(   &@@            @@    %@@  @@@@@@@@ *@@@@@@, @@@@@         
           @@@@. &@@@@@@  @@*    .@@@@@@@@@@@            @@@@@@@@@@@     *#( @@@@@@@  @@@@          
                             @@@@@@@@@@@@@@@              @@@@@@@@@@@@@@
  )";
  cout << "WOAH!" << endl;
  sleep(2);
  
  cout << this->currentAttackDamage << " DAMAGE DEALT" << endl;
  
  return this->HGHPunch.typewKNS;
}
void GymJunkie::infoFirstSkill(){
  cout << "   Attention Cost: " << this->HGHPunch.deltaAtten << endl;
  cout << "   " << this->HGHPunch.description << endl;
}

string GymJunkie::secondSkill(Character* Target){
  
  if(!damagingAtten(Target, this->roidRage)){
    return "RETURN";
  }
  
  cout << Target->getName() << ": \"If you\'re a natty then I'm Chris Bumstead\"." << endl;
  sleep(1);
  cout << "Woah, he's getting red..." << endl;
  sleep(1);
  cout << this->getName() << ": \"THAT\'S NOT TRUE!!!!!!!!!!!!!!!!!\"" << endl;
  sleep(1);
  cout << "Woah, that was loud...my ears are ringing..." << endl;
  sleep(1);
  cout << this->currentAttackDamage << " ATTENTION-DAMAGE DEALT" << endl;
  
  return this->roidRage.typewKNS;
}
void GymJunkie::infoSecondSkill(){
  cout << "   Attention Cost: " << this->roidRage.deltaAtten << endl;
  cout << "   " << this->roidRage.description << endl;
}

string GymJunkie::thirdSkill(Character* Target){
  
  if(!damagingAttack(Target, this->TRTTackle)){
    return "RETURN";
  }
  
  cout << this->getName() << " stopped his set..." << endl;
  sleep(1);
  cout << "He\'s mumbling something..." << endl;
  sleep(1);
  cout << R"(
TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...TRT...
  )" << endl;
  sleep(1);
  cout << "I think that the Testosterone Replacement Therapy got to him..." << endl;
  sleep(2);
  cout << "Wait...He's rushing forward!" << endl;
  sleep(1);
  cout << this->currentAttackDamage << " DAMAGE DEALT" << endl;
  
  return this->TRTTackle.typewKNS;
}

void GymJunkie::infoThirdSkill(){
  cout << "   Attention Cost: " << this->TRTTackle.deltaAtten << endl;
  cout << "   " << this->TRTTackle.description << endl;
}

string GymJunkie::fourthSkill(Character* Target){
  
  if(!damagingAttack(Target, this->syringeTime)){
    return "RETURN";
  }
  
  cout << this->getName() << " stopped his set..." << endl;
  sleep(1);
  cout << "He\'s pulling something out his gym bag..." << endl;
  cout << "It\'s a bunch of syringes...He injected himself!" << endl;
  sleep(1);
  cout << "Wait...he\'s gone..." << endl;
  sleep(1);
  cout << "HE TELEPORTED RIGHT BEHIND US!" << endl;
  sleep(1);
  cout << this->currentAttackDamage << " DAMAGE DEALT" << endl;
  
  return this->syringeTime.typewKNS;
}

void GymJunkie::infoFourthSkill(){
  cout << "   Attention Cost: " << this->syringeTime.deltaAtten << endl;
  cout << "   " << this->syringeTime.description << endl;
}