#include "HomelessMan.h"

HomelessMan::HomelessMan(string name){
  this->setName(name);
  this->setBio(this->getName() + " was found around Bissonnet & Beltway 8...");
  this->setEnergy(80);
  this->setAtten(45);
  this->cStats.maxEnergy = 80;
  this->cStats.maxAttention = 45;
  this->cStats.physical = 6;
  this->cStats.mystique = 6;
  this->cStats.defense = 3;
  this->cStats.rizz = 2;
  this->cwKNS.fire = true;
  this->cwKNS.ice = false;
  this->cwKNS.electric = false;
  this->cwKNS.bullet = false;
  this->cwKNS.physical = false;
  this->cwKNS.taunt = true;
  this->cwKNS.dumbness = true;
  this->attack = defineAbility("Attack", 7, 0, "PHYSICAL", "PHYSICAL", "Light Physical Attack");
  this->stare = defineAbility("Stare", 8, 5, "RIZZ", "TAUNT", "Light Rizzical Taunt");
  this->shank = defineAbility("Shank", 10, 7, "PHYSICAL", "PHYSICAL", "Medium Physical Attack");
  this->wildPunches = defineAbility("Wild Punches", 13, 12, "PHYSICAL", "PHYSICAL", "Heavy Physical Attack");
  this->magicPowder = defineAbility("Magic Powder", 13, 12, "MAGIC", "DUMBNESS", "Heavy Magical Dumb-Attack");
}

HomelessMan::HomelessMan(string name, int level, int EXP, int energy, int atten, int maxEn, int maxAtten, int physical, int mystique, int defense, int rizz){
  this->setName(name);
  this->setBio(this->getName() + " was found around Bissonnet & Beltway 8...");
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
  this->cwKNS.fire = true;
  this->cwKNS.ice = false;
  this->cwKNS.electric = false;
  this->cwKNS.bullet = false;
  this->cwKNS.physical = false;
  this->cwKNS.taunt = true;
  this->cwKNS.dumbness = true;
  this->attack = defineAbility("Attack", 7, 0, "PHYSICAL", "PHYSICAL", "Light Physical Attack");
  this->stare = defineAbility("Stare", 8, 5, "RIZZ", "TAUNT", "Light Rizzical Taunt");
  this->shank = defineAbility("Shank", 10, 7, "PHYSICAL", "PHYSICAL", "Medium Physical Attack");
  this->wildPunches = defineAbility("Wild Punches", 13, 12, "PHYSICAL", "PHYSICAL", "Heavy Physical Attack");
  this->magicPowder = defineAbility("Magic Powder", 13, 12, "MAGIC", "DUMBNESS", "Heavy Magical Dumb-Attack");
}

string HomelessMan::Attack(Character* Target){

  if(!damagingAttack(Target, this->attack)){
    return "RETURN";
  }
  
  cout << this->getName() << " is getting up!" << endl;
  sleep(1);
  cout << "He\'s pulling something out his back..." << endl;
  sleep(2);
  cout << R"(
                               %##(,(***,         
                 ##(//*((((/,%&#(#,  *,%**        
                %/, %*.   .*%*/*,,   ,**/,*(***** 
               #(/,(,      /*,,*.    .(/#/,  //#* 
             %#/, %,       ,**,*.    /,/#,   (#// 
      &&&&&&/ ((/**.       %/#%*,   %###*   #.(#  
   %(*  %(*,   ,(,*.      /  (#*,*,,*,,**, &#%(   
  %%/ /*.       ,,/,,  /&%&(#*       **#***,,     
  .*#/*.        ,,/(,***,,.          *(/*         
  .,,*,         ((#/*,              / %***/,      
   .,*,        (.(%,*            #%(#(/***,.      
    .,*.    /%(#/*,,,*        (#(#(***(..         
       ,***//**   (/#,** *%#&/,.*/#.              
               #(##%(***/*//*%..                  
             ./ (#///*&%*..                       
               .,,,..
    )" << endl;
  cout << "Knuckle Dusters! Watch out!" << endl;
  
  sleep(1);
  
  cout << this->currentAttackDamage << " DAMAGE DEALT" << endl;
  sleep(1);
  
  return this->attack.typewKNS;
}

void HomelessMan::infoAttack(){
  cout << "   Attention Cost: " << this->attack.deltaAtten << endl;
  cout << "   " << this->attack.description << endl;
}


string HomelessMan::firstSkill(Character* Target){

  if(!damagingAtten(Target, this->stare)){
    return "RETURN";
  }
  
  cout << this->getName() << " is getting up!" << endl;
  sleep(1);
  cout << "What\'s he doing?..." << endl;
  sleep(1);
  cout << R"(
         .,/###((#(,
      ,*(##%&%#%((
    .,/#%#%%&%#%*. ...     .&@/          .     
     ,,#((%%*.%#......              ..  .#/,  
    . ./,/* (/.*   ....             ..  ,(/((,
    .,,.** ..   (/,  ..         ..  .  ./###*,.
     ..., .(,./(#*.    ...   .....    ..**((  ..
           ,*(.  *  *..            .,/,,, *.
                  . * . **, *, .,, /... 
  )";
  sleep(1);
  cout << "\nHe's just staring..." << endl;
  sleep(2);
  cout << "That was creepy as hell..." << endl;
  sleep(1);
  cout << this->currentAttackDamage << " ATTENTION-DAMAGE DEALT" << endl;
  
  return this->stare.typewKNS;
}

void HomelessMan::infoFirstSkill(){
  cout << "   Attention Cost: " << this->stare.deltaAtten << endl;
  cout << "   " << this->stare.description << endl;
}

string HomelessMan::secondSkill(Character* Target){

  if(!damagingAttack(Target, this->shank)){
    return "RETURN";
  }
  
  cout << this->getName() << " is getting up!" << endl;
  sleep(1);
  cout << "Is there something coming out of his hands!?" << endl;
  sleep(1);
  cout << R"(
......,,,,,,,,*/,%.,/%#&.%%%
.,,,.,,,.,*,*//,,,%..%,.    % %%'.@
,,,,.,,,,,..,...      %@(.,..    %/.
.,.,*(((((((((#&(,.,,.     &.,.    ,/
//..,,,,,,..((((((((@%.,,..   (/..    **
,,,,,,,,,.(*,,,..//##///&,.,,.   .%,.....@#%%%%%%&&/
,,,.,,,,,,,,,,,,,,.../(////%%.,..   (##%%%%%%%%%%%&&&(
...,,,,,,,,,,,,,,,.,,,../#%#//%%,...#%%%%%%#####%%%%%&&
.,.,,,,,.,,,,,,,,,,,,,.,,..****,,@(((#%%%%%%%%%%%%%%%%&%&
,,,,,,,,,,..,,,,,,,,,,,,,.,,*,.  ,(%%%%%%%%%%%%%%%%##%%%%%&&
,,,,,,,.,..,,,,,,,,,,,,,,,/%%%%%%%%%%%###((((######%%%%%%%%%&&%
....,.,.....,,,,,,,,,,,,,,#####%%#######(((((/((########%%%%%%%%%&&
............,,,,,,,,,,,,,,####((((//(((((((//////(((####(#(##%%%%%%%%
........,.,,,,,,...,,,,,,,,#(**/&////***,,(((//((//((((#(((((####%%%%
..........,,,,........,,,,....,(//***//**,%#((((((/////////(((((#####
..............................*((/*,..,***###(((((/////////////(((((#
......................,,......(##(((((//(###(((((((//*******///(((((#
..............................,###(##########((((/***********/(((((((
..................,....,..........#####%####(/////****.******* //,//(
                                                  (##((***
    )" << endl;
  cout << "HUH!? WAIT HE\'S COMING!" << endl;
  sleep(1);
  
  cout << this->currentAttackDamage << " DAMAGE DEALT" << endl;
  sleep(1);
  
  return this->shank.typewKNS;
}

void HomelessMan::infoSecondSkill(){
  cout << "   Attention Cost: " << this->shank.deltaAtten << endl;
  cout << "   " << this->shank.description << endl;
}

string HomelessMan::thirdSkill(Character* Target){

  if(!damagingAttack(Target, this->wildPunches)){
    return "RETURN";
  }
  
  cout << this->getName() << " is getting up!" << endl;
  sleep(1);
  cout << "He\'s approaching..." << endl;
  sleep(2);
  cout << R"(                                                           
                 @@     *                            ,                
          ,@@&@@@@@@@@@@@@@                 @@@@@@@@@@@@@ @@          
        *@@@@@@@@@@@@@@@@@@#                @@@@@@@@@@@@@@@@@@,       
    @@@@@@@@@@@@@@@@@@ @@@@@               @@@@@@&@@@@@@@@@@@@@@@@@   
     @@@@ @@@@@ @@@@@@ @@@@@.@@@        @@ @@@@@ @@@@@@ @@@@@ @@@@    
     *@@@@ @@@@@ @@@@@@ @@@@@ @@        @@(@@@@#&@@@@@*@@@@@ @@@@(    
      @@@@%@@@@@ @@@@@@ @@@@@ @&        @ @@@@@ @@@@@@ @@@@@*@@@@     
       @@@@ @@@@@ @@@@@,   /@@@.        @@@@    @@@@@ @@@@@ @@@@      
                     @@@@@@@@@@         ,@@@@@@@@@@                   
                                                                      
                                                                      
             @@      @@@@@@@@@@         @@@@@@@@@@      /@%           
       @@@@ @@@@@ @@@@@@ @/   @,        @@   &,.@@@@@,@@@@@ @@@@      
      @@@@ @@@@@ @@@@@@ @@@@@ @&        @ @@@@@ @@@@@@ @@@@@ @@@@     
     @@@@@/@@@@@,@@@@@@ @@@@@ @@        @@ @@@@@ @@@@@@/@@@@@@@@@@    
    %@@@@@@@@@@ @@@@@@ @@@@@ @@@        @@ @@@@@ @@@@@@ @@@@@@@@@@&   
    %@@@@@@@@@@@@@@@@@@@@@@@               *@@@@@@@@@@@@@@@@@@@@@@&   
         @@@@@@@@@@@@@@@@@@                 @@@@@@@@@@@@@@@@@@        
              ,@@@@@@@@@@@@                  @@@@@@@@@@@# 
)" << endl;
  cout << "A surprise barrage of fists!" << endl;
  sleep(1);
  
  cout << this->currentAttackDamage << " DAMAGE DEALT" << endl;
  sleep(1);
  
  return this->wildPunches.typewKNS;
}

void HomelessMan::infoThirdSkill(){
  cout << "   Attention Cost: " << this->wildPunches.deltaAtten << endl;
  cout << "   " << this->wildPunches.description << endl;
}

string HomelessMan::fourthSkill(Character* Target){

  if(!damagingAttack(Target, this->magicPowder)){
    return "RETURN";
  }

  cout << this->getName() << " is getting up!" << endl;
  sleep(1);
  cout << "He\'s pulling something out his pocket..." << endl;
  sleep(1);
  cout << R"(                                                           
                         /***/*,                            
                        *#//#(,,,,,,.                       
                      ,*,,,,,,/,(#*......                   
                     *....*..,.,.,*/,((..,.*,.              
                    .&.. ......,...,*.,.,/#*,.,,**          
                   ,.&.....,....,.,.,......,,,(#/,/         
                 .,*/*,.*/,,.......,.,.........,.           
                *&@#/%%((/.,,......,/,,.,,......            
               (/&&@@&@&&&&%%*%.....,,,.,.*.../             
              *&&%&&&&@&%%&%&%%%%%%*(,...,...               
              .&@&&%%%@&&&&&%&&%%%%%&%#,,,/*                
           (@@@&&&&&&&&%%%&&&%%%%%%%%&&%%/                  
        *@%###%%&&&&&&%&&&%&%%%%%%%&@&%(                    
             ,///#%%%%%%&%%%%%%&&%%%&&.                     
                  ./##%%%&%&%%%%%&&&(                       
                       *(#%#%%&&&&%                         
                           ,(%&&&#                          
                             #%% 
)" << endl;
  cout << "A bag with some powder..." << endl;
  sleep(1);
  cout << "AHH! HE SPRAYED SOME IN " << Target->getName() << "'s EYES!" << endl;
  sleep(1);
  cout << this->currentAttackDamage << " DAMAGE DEALT" << endl;
  sleep(1);
  
  return this->magicPowder.typewKNS;
}

void HomelessMan::infoFourthSkill(){
  cout << "   Attention Cost: " << this->magicPowder.deltaAtten << endl;
  cout << "   " << this->magicPowder.description << endl;
}
