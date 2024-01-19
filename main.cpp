#include "Character.h"
#include "HomelessMan.h"
#include "GymJunkie.h"
#include "Player.h"
#include "PressTurn.h"

int loadGame(string &name, vector<Character *> &Party)
{
  int i;
  ifstream saveFile;
  int saveStage;
  string saveName;
  int saveLevel;
  int saveEXP;
  int saveEnergy;
  int saveAtten;
  int saveMaxEn;
  int saveMaxAtten;
  int savePhysical;
  int saveMystique;
  int saveDefense;
  int saveRizz;

  saveFile.open("saveFile.txt");

  if (!saveFile.is_open())
  {
    cout << "Could not open file saveFile.txt." << endl;
    return -1;
  }

  saveFile >> saveStage;

  if (saveStage == 1)
  {
    for (i = 0; i < 2; ++i)
    {
      saveFile >> saveName;
      saveFile >> saveLevel;
      saveFile >> saveEXP;
      saveFile >> saveEnergy;
      saveFile >> saveAtten;
      saveFile >> saveMaxEn;
      saveFile >> saveMaxAtten;
      saveFile >> savePhysical;
      saveFile >> saveMystique;
      saveFile >> saveDefense;
      saveFile >> saveRizz;

      if (i == 0)
      {
        Character *userPlayer = new Player(saveName, saveLevel, saveEXP, saveEnergy, saveAtten, saveMaxEn, saveMaxAtten, savePhysical, saveMystique, saveDefense, saveRizz);
        Party.push_back(userPlayer);
      }
      else if (i == 1)
      {
        Character *Bob = new HomelessMan(saveName, saveLevel, saveEXP, saveEnergy, saveAtten, saveMaxEn, saveMaxAtten, savePhysical, saveMystique, saveDefense, saveRizz);
        Party.push_back(Bob);
      }
    }
  }
  if (saveStage == 2)
  {
    for (i = 0; i < 4; ++i)
    {
      saveFile >> saveName;
      saveFile >> saveLevel;
      saveFile >> saveEXP;
      saveFile >> saveEnergy;
      saveFile >> saveAtten;
      saveFile >> saveMaxEn;
      saveFile >> saveMaxAtten;
      saveFile >> savePhysical;
      saveFile >> saveMystique;
      saveFile >> saveDefense;
      saveFile >> saveRizz;

      if (i == 0)
      {
        name = saveName;
        Character *userPlayer = new Player(saveName, saveLevel, saveEXP, saveEnergy, saveAtten, saveMaxEn, saveMaxAtten, savePhysical, saveMystique, saveDefense, saveRizz);
        Party.push_back(userPlayer);
      }
      else if (i == 1)
      {
        Character *Bob = new HomelessMan(saveName, saveLevel, saveEXP, saveEnergy, saveAtten, saveMaxEn, saveMaxAtten, savePhysical, saveMystique, saveDefense, saveRizz);
        Party.push_back(Bob);
      }
      else if (i == 2)
      {
        Character *Jimmy = new GymJunkie(saveName, saveLevel, saveEXP, saveEnergy, saveAtten, saveMaxEn, saveMaxAtten, savePhysical, saveMystique, saveDefense, saveRizz);
        Party.push_back(Jimmy);
      }
      else if (i == 3)
      {
        Character *Dude = new GymJunkie(saveName, saveLevel, saveEXP, saveEnergy, saveAtten, saveMaxEn, saveMaxAtten, savePhysical, saveMystique, saveDefense, saveRizz);
        Party.push_back(Dude);
      }
    }
  }
  saveFile.close();

  return saveStage;
}

string reverseStr(string str)
{
  int len = str.length();
  int n = len - 1;
  int i = 0;
  while (i <= n)
  {
    // Using the swap method to switch values at each index
    swap(str[i], str[n]);
    n = n - 1;
    i = i + 1;
  }
  return str;
}

bool firstEncounter(vector<Character *> &Party, vector<Character *> &Enemies)
{
  int i;
  Character *Bob = new HomelessMan("Bob");
  Enemies.push_back(Bob);
  cout << "It was a sunny day in the City..." << endl;
  sleep(2);
  cout << "You're turning the corner on an intersection..." << endl;
  sleep(2);
  cout << "Homeless Man on the corner: \"Can anybody help me, I'm blind and hungry!\"" << endl;
  sleep(3);
  cout << "You check your wallet and see you have a dollar bill..." << endl;
  sleep(2);
  cout << "...but because you\'re naturally cynical, you decide to try something..." << endl;
  sleep(3);
  cout << "You: \"Hey, here's a 10 dollar bill, stay safe.\"" << endl;
  sleep(2);
  cout << "Homeless Man: \"I appreciate it, God bless you!\"" << endl;
  sleep(2);
  cout << "Homeless Man: \"Ay, wait a minute...this is a ONE DOLLAR BILL!!!\"" << endl;
  sleep(2);
  cout << "You: \"Ay I thought you were blind!!!\"" << endl;
  sleep(2);
  cout << "Homeless Man: \"..............\"" << endl;
  sleep(2);
  cout << "Homeless Man: \"Alright put your hands up\"" << endl;
  sleep(2);
  cout << "You: \"Woah, woah, woah chill out!\"" << endl;
  sleep(2);
  cout << "Homeless Man: \"Nope, come on put up them paws\"" << endl;
  sleep(2);
  cout << "You: \"You know what I'm tired of you come on then\"" << endl;
  sleep(2);
  cout << "BEGIN BATTLE!!!!!!!!!!!!!" << endl;
  sleep(2);
  PressTurn oneEncounter(Party, Enemies);
  if (!oneEncounter.Battle())
  {
    cout << "Homeless Man: \"Your mama should have told you never to tussle with a blind man...\"" << endl;
    return false;
  }
  cout << "Homeless Man: \"Alright, I'm sorry! I shouldn't have lied!\"" << endl;
  sleep(2);
  cout << "You feel like getting petty but decide not to..." << endl;
  sleep(2);
  cout << "You: \"Naw it's cool, I respect the bag-chasing...\"" << endl;
  sleep(2);
  cout << "Homeless Man: \"Man, you know what, you're a cool kid.\"" << endl;
  sleep(2);
  cout << "Homeless Man: \"Let me join you!\"" << endl;
  sleep(2);
  cout << "You: \"What do you mean \'join\' me? This is not a game!\"" << endl;
  sleep(2);
  cout << "Homeless Man: \"Sure it is!\"" << endl;
  sleep(2);
  cout << "You: \"You\'re off your rocker old man...\"" << endl;
  sleep(2);
  Bob = new HomelessMan("Bob");
  Party.push_back(Bob);
  cout << "Bob joined your party!" << endl;
  sleep(2);
  cout << "End of encounter!..." << endl;
  sleep(2);
  return true;
}

bool secondEncounter(vector<Character *> &Party, vector<Character *> &Enemies)
{
  Enemies.clear();
  Character *Jimmy = new GymJunkie("Jimmy");
  Character *Dude = new GymJunkie("Dude");
  Enemies.push_back(Jimmy);
  Enemies.push_back(Dude);
  cout << "Two gymbros approach you and the homeless guy..." << endl;
  sleep(2);
  cout << "Jimmy: \"Hey, leave that homeless dude alone!\"" << endl;
  sleep(2);
  cout << "You: \"Nah it's a misunderstanding, we're cool now\"" << endl;
  sleep(2);
  cout << "Dude: \"Distance yourself from the homeless man or you\'re gonna get it!\"" << endl;
  sleep(2);
  cout << "Did these dudes not hear me..." << endl;
  sleep(2);
  cout << "Homeless Man: \"Wait, it\'s cool I\'m with him now\"" << endl;
  sleep(2);
  cout << "You: \"Yeah see look we\'re cool\"" << endl;
  sleep(1);
  cout << "Jimmy: \"BACK AWAY BRO\"" << endl;
  sleep(1);
  cout << "Dude: \"BRO WE TOLD YOU TO BACK AWAY\"" << endl;
  sleep(1);
  cout << "You: \"WOAH, chill out man, I'm not tryna-\"" << endl;
  sleep(1);
  cout << "Dude: \"At this point WE GONNA FRY YOU\"" << endl;
  sleep(1);
  cout << "I just got done fighting a damn homeless man and now this..." << endl;
  sleep(3);
  cout << "BEGIN BATTLE!!!!!!!!!!!!!" << endl;
  sleep(2);
  PressTurn twoEncounter(Party, Enemies);
  if (!twoEncounter.Battle())
  {
    cout << "Jimmy: \"You really thought you could beat us, huh...\"" << endl;
    cout << "Dude: \"he really thought he was him lol\"" << endl;
    return false;
  }
  cout << "Jimmy: \"WOAH man, im sorry, i didnt know you were like that...\"" << endl;
  cout << "Dude: \"WOAH man, im sorry, i didnt know you were like that...\"" << endl;
  sleep(3);
  cout << "You: \"I told y\'all man, this what happens when you don\'t chill out\"" << endl;
  sleep(3);
  cout << "Dude: \"I didn\'t know you had it on you like that...What do you use?\"" << endl;
  sleep(1);
  cout << "Jimmy: \"Anadrol?\"" << endl;
  sleep(1);
  cout << "Dude: \"Anavar?\"" << endl;
  sleep(1);
  cout << "Jimmy: \"Arimidex?\"" << endl;
  sleep(1);
  cout << "Dude: \"Clenbuterol?\"" << endl;
  sleep(1);
  cout << "Jimmy: \"Deca-Durabolin?\"" << endl;
  sleep(1);
  cout << "Dude: \"Dianabol?\"" << endl;
  sleep(1);
  cout << "Jimmy: \"Equipoise?\"" << endl;
  sleep(1);
  cout << "Dude: \"HGH?\"" << endl;
  sleep(1);
  cout << "Jimmy: \"Proviron?\"" << endl;
  sleep(1);
  cout << "You: \"Oh wow...Have they taken all of these?????\"" << endl;
  sleep(2);
  cout << "Dude: \"Test?\"" << endl;
  sleep(1);
  cout << "Jimmy: \"Tren?\"" << endl;
  sleep(1);
  cout << "Dude: \"Virilon?\"" << endl;
  sleep(1);
  cout << "Jimmy: \"Cheque?\"" << endl;
  sleep(1);
  cout << "Dude: \"Halotestin?\"" << endl;
  sleep(1);
  cout << "Jimmy: \"Primo?\"" << endl;
  sleep(1);
  cout << "Dude: \"Depotest?\"" << endl;
  sleep(1);
  cout << "You: \"Alright man, stop! No, I haven\'t taken any of these...\"" << endl;
  sleep(2);
  cout << "Jimmy: \"Wow...you\'re a natty? You know what, you got the ultimate sleeper build...\"" << endl;
  sleep(3);
  cout << "Dude: \"Jimmy...Do you think it\'s him?\"" << endl;
  sleep(2);
  cout << "Jimmy: \"He might just be...\"" << endl;
  sleep(2);
  cout << "You: \"What are y\'all talking about???\"" << endl;
  sleep(2);
  cout << "Jimmy: \"The prophesied \'natty to save us all\'...\"" << endl;
  sleep(2);
  cout << "You: \"Ummmmm no. Nah, that\'s not me. Nope.\"" << endl;
  sleep(2);
  cout << "Dude: \"Please let us join you! We\'ll stop using!\"" << endl;
  sleep(2);
  cout << "You: \"Please leave me alone man, I\'m just trying to get to work\"" << endl;
  sleep(2);
  cout << "Jimmy: \"We\'ll be quiet, it\'s like we\'re not even there!\"" << endl;
  sleep(2);
  cout << "They\'re built like Greek gods...they\'ll stand out like a sore thumb..." << endl;
  sleep(2);
  cout << "You: \"You know what man, come on then man...\"" << endl;
  sleep(2);
  cout << "I\'ll just keep going to work, turn the corner, and just book it..." << endl;
  sleep(2);
  cout << "They don\'t do their cardio probably anyway..." << endl;
  sleep(2);
  Jimmy = new GymJunkie("Jimmy");
  Dude = new GymJunkie("Dude");

  Party.push_back(Jimmy);
  Party.push_back(Dude);

  cout << "Jimmy and Dude joined your party!" << endl;
  sleep(2);
  cout << "End of encounter!..." << endl;
  sleep(2);
  return true;
}

bool thirdEncounter(string name, vector<Character *> &Party, vector<Character *> &Enemies)
{
  Enemies.clear();

  Character *inversePlayer = new Player(reverseStr(name));
  Character *inverseBob = new HomelessMan("Bob");
  Character *inverseJimmy = new GymJunkie("Ymmij");
  Character *inverseDude = new GymJunkie("Edud");

  Enemies.push_back(inversePlayer);
  Enemies.push_back(inverseBob);
  Enemies.push_back(inverseJimmy);
  Enemies.push_back(inverseDude);

  cout << R"(
                                        ,* . ,, ,/  .,.                             
                     , , ..  ,* / .   . .. ...  /  . ,   .   .                  
                  .        .,  ..  . ,.*.*(* ,, *  ...                          
                      . ..*/ ..#.*(#(/* ./* /###(/, *, .                        
                ,  *..  ,,,/./,*(#*           *.%%#//, /* ,.                    
               ,  ,    .,/,((#/*,                ,*%*,*.*   . .                 
                 ,.  ./,(,,%/.                    ..%%#*,, ,..                  
                     # #/(#*                         /(#/...  *                 
                  . .. #(/ .                         ,(*(/  ..   .   .          
            ,    .. .,.%%,%                           (,(*...,.. .              
             .    ( .  (%%#.                          /*#(   **                 
              .      .,. %#,                        ,,((,#,,,  ,                
                .  .  ,/(*/%#.                     ,,%,,,,.   .,                
                  , *..,* /./#,.                 ,*#%,,*    . ,                 
                      . ,* ./,##&.%   .     ..**(# #*,.,. ....                  
                  .. ,     ,* **((%*.(../,.**#,.*(./*/, ,. . .                  
                         . ... .,,*/ ,*,(,.*.,,. .*., ,   .                     
                   ,       ,    .       *.,, ., ... ,..  .
  )" << endl;

  cout << "oh, it\'s a portal to another world..." << endl;
  sleep(4);
  cout << "Wait...HUH!?" << endl;
  sleep(2);
  cout << "Jimmy: \"Oh, I forgot to tell you, the prophecy ends with us battling ourselves.\"" << endl;
  sleep(3);
  cout << "Dude: \"Oh yeah, it\'s actually really dope, I think you die at the end and we avenge you.\"" << endl;
  sleep(4);
  cout << "Alright." << endl;
  sleep(4);
  cout << reverseStr(name) << ", Bob, Ymmij, and Edud come out of the portal" << endl;
  sleep(3);
  cout << "Portal Guys: \"We are " << reverseStr(name) << ", Bob, Ymmij, and Edud, and we have trained for years for this moment.\"" << endl;
  sleep(4);
  cout << "You: \"Alright man, let\'s just fight.\"" << endl;
  sleep(2);
  cout << "Jimmy: \"Wow, just like in the prophecy...\"" << endl;
  cout << "Dude: \"Wow, just like in the prophecy...\"" << endl;
  sleep(4);
  cout << "BEGIN BATTLE!!!!!!!!!!!!!" << endl;
  sleep(2);
  PressTurn threeEncounter(Party, Enemies);
  if (!threeEncounter.Battle())
  {
    cout << "Portal Guys: \"We are all slaves to prophecy...\"" << endl;
    cout << "Jimmy: \"No...how could you do this...\"" << endl;
    cout << "Dude: \"No...how could you do this...\"" << endl;
    return false;
  }
  cout << "Portal Guys: \"...How did you do it...How did you defy the prophecy?\"" << endl;
  sleep(3);
  cout << "You: \"Alright, Imma head to work. I\'ll see y\'all later man.\"" << endl;
  sleep(3);
  cout << "Portal Guys: \"No please, please teach us your ways!\"" << endl;
  sleep(3);
  cout << "You: \"No, no, no, no, no. I\'m not doing this anymore man, I\'m gone, bye\"" << endl;
  sleep(3);
  cout << "Portal Guys: \"*Silence*\"" << endl;
  sleep(3);
  cout << "You: \"Alright, peace...\"" << endl;
  sleep(3);
  cout << "You finally turn the corner and start walking away when you feel something..." << endl;
  sleep(3);
  cout << "........My socks don\'t feel connected to my feet.......what is happening" << endl;
  sleep(3);
  cout << "Portal Guys: \"This is what happens when you miss with prophecy.\"" << endl;
  sleep(3);
  cout << "You: \"What did you do?!\"" << endl;
  sleep(2);
  cout << "Portal Guys: \"Reality is breaking...that\'s our cue!\"" << endl;
  sleep(3);
  cout << R"(
                                        ,* . ,, ,/  .,.                             
                     , , ..  ,* / .   . .. ...  /  . ,   .   .                  
                  .        .,  ..  . ,.*.*(* ,, *  ...                          
                      . ..*/ ..#.*(#(/* ./* /###(/, *, .                        
                ,  *..  ,,,/./,*(#*           *.%%#//, /* ,.                    
               ,  ,    .,/,((#/*,                ,*%*,*.*   . .                 
                 ,.  ./,(,,%/.                    ..%%#*,, ,..                  
                     # #/(#*                         /(#/...  *                 
                  . .. #(/ .                         ,(*(/  ..   .   .          
            ,    .. .,.%%,%                           (,(*...,.. .              
             .    ( .  (%%#.                          /*#(   **                 
              .      .,. %#,                        ,,((,#,,,  ,                
                .  .  ,/(*/%#.                     ,,%,,,,.   .,                
                  , *..,* /./#,.                 ,*#%,,*    . ,                 
                      . ,* ./,##&.%   .     ..**(# #*,.,. ....                  
                  .. ,     ,* **((%*.(../,.**#,.*(./*/, ,. . .                  
                         . ... .,,*/ ,*,(,.*.,,. .*., ,   .                     
                   ,       ,    .       *.,, ., ... ,..  .
  )" << endl;
  cout << "The portal guys leave through the portal" << endl;
  sleep(4);
  cout << "Wow, I can feel my eyebrows through my face...I guess this is it, huh" << endl;
  sleep(5);
  cout << "Well, I had a good life, I think. I had my moment." << endl;
  sleep(4);
  cout << "cout<<cout<<cou<PRESSTURN EXPC>TWHAT()MDJNEJNENFE" << endl;
  sleep(3);
  cout << "Oh, well at least now I know it\'s a simulation." << endl;
  sleep(4);
  cout << "Goodbye, world..." << endl;
  sleep(3);
  cout << "PROGRAM TERMINATED: SUPURORU" << endl;
  sleep(2);
  return true;
}

int main()
{

  int stage = 0;
  int loadGamestate;

  vector<Character *> Party;
  vector<Character *> Enemies;
  string playerName;

  srand(time(0));

  cout << R"(
                                                                                
           ########                                                                                 
          ##     ##+  ##    ##   ##  ##     ##    ##   #+ ##    ###-     #  ##  ##    ##            
           #####      ##    ##   ###   ##   ##    ##   #####  ###  ###   #####  ##    ##            
               ####-  ##    ##   ##     ##  ##    ##   ##    ##.    ##.  ##     ##    ##            
          ##      ##  ##    ##   ##     ##  ##    ##   ##    ##     ##   ##     ##    ##            
           ########   ########   ####-###   ###-####   ##     ###+####   ##     ###+####            
                                 ##                                                                 
                                 ##                                                                 
                                                                                                    
    )" << endl;

  cout << endl
       << endl;

  int userInput;

  cout << "                                   1. Play!" << endl;
  cout << "                                   2. About" << endl;
  cout << "                                   3. Exit" << endl;

  cout << "Enter number:" << endl;
  cin >> userInput;

  while ((userInput != 1) && (userInput != 2) && (userInput != 3))
  {
    cout << "Please pick valid number:" << endl;
    cin >> userInput;
  }

  if (userInput == 3)
  {
    cout << "Exiting game..." << endl;
    sleep(2);
    return 0;
  }
  else if (userInput == 2)
  {
    cout << "Sopuroru is a turn-based RPG that derives its battle system from" << endl;
    cout << "the Shin Megami Tensei series in which each character has specific weaknesses" << endl;
    cout << "and exploiting those weaknesses give extra turns to the party." << endl
         << endl;

    cout << "Supuroru also takes some influence from RPG Yakuza: Like A Dragon." << endl;
    cout << "Like Yakuza, RUS takes the traditional aspects of classic RPGs and freshes them up" << endl;
    cout << "by contextualizing battles in a modern setting. Similarly, Supuroru also incorporates" << endl;
    cout << "some of the surrealness of Yakuza, including supernatural/strange happenings." << endl
         << endl;

    cout << "Supuroru takes place in the span of 3 individual battles in which players gain new members" << endl;
    cout << "and must battle against strange citizens. In order to win, the player must utilize" << endl;
    cout << "each party member to their maximum potential and attack weaknesses in order to gain" << endl;
    cout << "in order to gain the upper hand." << endl
         << endl;

    cout << "I hope you enjoy the game!" << endl
         << endl;
  }

  cout << "1. Start New Game" << endl;
  cout << "2. Load Game" << endl;
  cin >> userInput;

  if (userInput == 2)
  {
    loadGamestate = loadGame(playerName, Party);
    if (loadGamestate == -1)
    {
      return -1;
    }
    else
    {
      stage = loadGamestate;
    }
  }

  if (userInput == 1)
  {
    cout << "Enter your character's name!" << endl;
    cin >> playerName;

    Character *userPlayer = new Player(playerName);

    Party.push_back(userPlayer);
  }

  switch (stage)
  {
  case 0:
    if (!firstEncounter(Party, Enemies))
    {
      return 0;
    }
    stage++;
    while (true)
    {
      cout << "Save game? (1.Yes/2.No)" << endl;
      cin >> userInput;
      if (userInput == 1)
      {
        saveGame(stage, Party);
        break;
      }
      else if (userInput == 2)
      {
        break;
      }
      else
      {
        cout << "Please enter valid number." << endl;
        continue;
      }
    }

  case 1:
    if (!secondEncounter(Party, Enemies))
    {
      return 0;
    }
    stage++;
    while (true)
    {
      cout << "Save game? (1.Yes/2.No)" << endl;
      cin >> userInput;
      if (userInput == 1)
      {
        saveGame(stage, Party);
        break;
      }
      else if (userInput == 2)
      {
        break;
      }
      else
      {
        cout << "Please enter valid number." << endl;
        continue;
      }
    }
  case 2:
    if (!thirdEncounter(playerName, Party, Enemies))
    {
      return 0;
    }
  }
  return 0;
}