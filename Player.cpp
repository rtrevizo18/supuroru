#include "Player.h"

Player::Player(string name){
  this->setName(name);
  this->setBio(this->getName() + " is you!");
  this->setEnergy(70);
  this->setAtten(50);
  this->cStats.maxEnergy = 70;
  this->cStats.maxAttention = 50;
  this->cStats.physical = 5;
  this->cStats.mystique = 5;
  this->cStats.defense = 5;
  this->cStats.rizz = 5;
  this->cwKNS.fire = false;
  this->cwKNS.ice = false;
  this->cwKNS.electric = false;
  this->cwKNS.bullet = false;
  this->cwKNS.physical = false;
  this->cwKNS.taunt = false;
  this->cwKNS.dumbness = false;
  this->attack = defineAbility("Attack", 7, 0, "PHYSICAL", "PHYSICAL", "Light Physical Attack");
  this->bat = defineAbility("Bat", 10, 7, "PHYSICAL", "PHYSICAL", "Medium Physical Attack");
  this->conversation = defineAbility("Conversation", 9, 7, "RIZZ", "DUMBNESS", "Medium Rizzical Dumb-Attack");
  this->quickDiversion = defineAbility("Quick Diversion", 13, 12, "PHYSICAL", "DUMBNESS", "Heavy Physical Dumb-Attack");
  this->sword = defineAbility("Sword", 13, 12, "MAGIC", "DUMBNESS", "Heavy Magical Dumb-Attack");
}

Player::Player(string name, int level, int EXP, int energy, int atten, int maxEn, int maxAtten, int physical, int mystique, int defense, int rizz){
  this->setName(name);
  this->setBio(this->getName() + " is you!");
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
  this->cwKNS.electric = false;
  this->cwKNS.bullet = false;
  this->cwKNS.physical = false;
  this->cwKNS.taunt = false;
  this->cwKNS.dumbness = false;
  this->attack = defineAbility("Attack", 7, 0, "PHYSICAL", "PHYSICAL", "Light Physical Attack");
  this->bat = defineAbility("Bat", 10, 7, "PHYSICAL", "PHYSICAL", "Medium Physical Attack");
  this->conversation = defineAbility("Conversation", 9, 7, "RIZZ", "DUMBNESS", "Medium Rizzical Dumb-Attack");
  this->quickDiversion = defineAbility("Quick Diversion", 13, 12, "PHYSICAL", "DUMBNESS", "Heavy Physical Dumb-Attack");
  this->sword = defineAbility("Sword", 13, 12, "MAGIC", "DUMBNESS", "Heavy Magical Dumb-Attack");
}

string Player::Attack(Character* Target){

  if(!damagingAttack(Target, this->attack)){
    return "RETURN";
  }
  
  cout << this->getName() << "\'s ready for attack!" << endl;
  sleep(1);
  cout << "Everyone is standing still..." << endl;
  sleep(2);
  cout << this->getName() << ": \"I guess Imma just go up then...\"" << endl;
  sleep(1);
  cout << this->getName() << " performs a casual punch..." << endl;
  
  sleep(1);
  
  cout << this->currentAttackDamage << " DAMAGE DEALT" << endl;
  sleep(1);
  
  return this->attack.typewKNS;
}

void Player::infoAttack(){
  cout << "   Attention Cost: " << this->attack.deltaAtten << endl;
  cout << "   " << this->attack.description << endl;
}


string Player::firstSkill(Character* Target){

  if(!damagingAttack(Target, this->bat)){
    return "RETURN";
  }
  
  cout << this->getName() << "\'s ready for attack!" << endl;
  sleep(1);
  cout << this->getName() << " is pulling something out his pocket..." << endl;
  sleep(1);
  cout << "It's a bat...How did that even fit in there..." << endl;
  sleep(1);
  cout << "They\'re approaching!" << endl;
  
  cout << this->currentAttackDamage << " DAMAGE DEALT" << endl;

  sleep(1);
  
  return this->bat.typewKNS;
}

void Player::infoFirstSkill(){
  cout << "   Attention Cost: " << this->bat.deltaAtten << endl;
  cout << "   " << this->bat.description << endl;
}

string Player::secondSkill(Character* Target){

  if(!damagingAtten(Target, this->conversation)){
    return "RETURN";
  }
  
  cout << this->getName() << "\'s ready for attack!" << endl;
  sleep(1);
  cout << this->getName() << ": \"Hey man, I really like your shoes!\"" << endl;
  sleep(1);
  cout << Target->getName() << ": \"Ay, I really appreciate it man!\"" << endl;
  sleep(1);
  cout << this->getName() << ": \"Yeah man for sure! I feel like we gotta compliment each other more man, you know what I mean\"" << endl;
  sleep(1);
  cout << Target->getName() << ": \"Yeah man, I feel that fr\"" << endl;
  sleep(1);
  cout << "These dudes are having a full-on conversation right now..." << endl;
  sleep(1);
  cout << this->currentAttackDamage << " ATTENTION-DAMAGE DEALT" << endl;
  sleep(1);
  
  return this->conversation.typewKNS;
}

void Player::infoSecondSkill(){
  cout << "   Attention Cost: " << this->conversation.deltaAtten << endl;
  cout << "   " << this->conversation.description << endl;
}

string Player::thirdSkill(Character* Target){

  if(!damagingAttack(Target, this->quickDiversion)){
    return "RETURN";
  }
  
  cout << this->getName() << "\'s ready for attack!" << endl;
  sleep(1);
  cout << this->getName() << ": \"Ay, you know what time it is?\"" << endl;
  sleep(1);
  cout << Target->getName() << ": \"Naw, lemme check my phone...\"" << endl;
  sleep(1);
  cout << this->getName() << ": \"Oh yeah lemme see\"" << endl;
  sleep(1);
  cout << this->getName() << " inches closer..." << endl;
  sleep(2);
  cout << R"(
                                    ,&                               
                         ,@@@@@@@@@@@    /@@@@@@@@@@             
                        %@@@@@@@@@@@@@@@@@@@@@@@@@@@@.           
             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*          
           (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@          
          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.         
  (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         
(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@% ,@@@@@@@@@@@@         
&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@@@@@&  @@    
 @@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@%  @@@@@@@@@@@@  @@@@@@
 @@@@@@@@@@@  @@@@@@@@@@@@. %@@@@@@@@@@@@@@  @@@@@@@@@@@@&  @@@@@
  @@@@@@@@@@@  @@@@@@@@@@@@  @@@@@@@@@@@@@@&  @@@@@@@@@@@@  @@@@@
   @@@@@@@@@@  &@@@@@@@@@@@* /@@@@@@@@@@@@@@  &@@@@@@@@@@@, *@@@@
    @@@@@@@@@@  @@@@@@@@@@@@  @@@@@@@@@@@@@@@  @@@@@@@@@@@@  @@@@
     @@@@@@@@@@ .@@@@@@@@@@@# .@@@@@@@@@@@@@@  #@@@@@@@@@@@. (@@@
     .@@@@@@@@@, &@@@@@@@@@@@  @@@@@@@@@@@@@@@  @@@@@@@@@@@@  @@@
      *@@@@@@@@@  @@@@@@@@@@@&  @@@@@@@@@@@@@@  /@@@@@@@*    @@@@
       &@@@@@@@@@  @@@@@@@@@@@  %@@@@@@@@@@@@*        ,%@@@@@@@@@
        &@@@@@%    @@@@@@@@@@@(  .,.        ,&@@@@@@@@@@@@@@@@@@#
                                       @@@@@@@@@@@@@@@@@@@@@@@@@ 
                                       @@@@@@@@@@@@@@@@@@@@@@(
    )" << endl;
  cout << "BOOOOOOOOOOOOM" << endl;
  sleep(1);
  cout << Target->getName() << ": \"MAANNN WHAT THE HELL!?\"" << endl;
  sleep(1);
  cout << this->currentAttackDamage << " DAMAGE DEALT" << endl;
  sleep(1);
  
  return this->quickDiversion.typewKNS;
}

void Player::infoThirdSkill(){
  cout << "   Attention Cost: " << this->quickDiversion.deltaAtten << endl;
  cout << "   " << this->quickDiversion.description << endl;
}

string Player::fourthSkill(Character* Target){

  if(!damagingAttack(Target, this->sword)){
    return "RETURN";
  }

  cout << this->getName() << " is getting up!" << endl;
  sleep(1);
  cout << "Is that a sword on the ground?!" << endl;
  sleep(1);
  cout << "That wasn't even on the ground a second ago!!!!" << endl;
  sleep(2);
  cout << this->getName() << " picks up the sword..." << endl;
  sleep(2);
  cout << R"(                                                           
                               (                            
                         @@  @                              
                     @    *@                                
                  @     @                                   
               @      @         @@@                         
            @       @   .@,   @                             
          @        # @     @(                               
        @        @@      @.                                 
      @                 @     @@@,@                         
     @                ,* @     @                            
   @                 @@      &(                             
  *                         @                               
..@...........@            @                                
 .... .........../        @                                 
 .. ...@...........*     @@    #%                           
 @...................@        @                             
 @..........@..........@     @                              
  @....................../ /                                
     @...........@..........@                               
        @.....................@                             
           @/.........@.........@                           
              &%........,.......@@@@                        
                 %&..................@       @@@            
                     @........@........@     @////@         
                        @..... .,........@ @//,*(,          
                          @,.......@.....@///*@             
                             @.........@///@*               
                                @...,#//,@/@//@             
                                  @////@@(@/@(((/#          
                             (@@@////@    &((((@/@(@        
                             @////#@         @/@(((@/@      
                                @@              @@/@((@///&*
                                                   @*/@..///
                                                   @//////*@
                                                     .@@(
)" << endl;
  cout << "SWOOOSHHHH" << endl;
  sleep(1);
  cout << this->currentAttackDamage << " DAMAGE DEALT" << endl;
  sleep(1);
  
  return this->sword.typewKNS;
}

void Player::infoFourthSkill(){
  cout << "   Attention Cost: " << this->sword.deltaAtten << endl;
  cout << "   " << this->sword.description << endl;
}
