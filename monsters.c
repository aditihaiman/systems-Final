#include "players.h"

int pipeForBattle(char* status, struct player* player, int fd){

    char playerName[100], pBHealth[3], pHealth[3], pDamage[3], pExp[3], pLev[3], status1[3];
    strcpy(playerName, player->name);
    strcpy(status1, "n");
    //sprintf(pBHealth, "%d", player->baseHealth);
    sprintf(pHealth, "%d", player->health);
    sprintf(pDamage, "%d", player->damage);
    sprintf(pExp, "%d", player->experience);
    sprintf(pLev, "%d", player->level);

    write(fd, playerName, sizeof(playerName));
    write(fd, pHealth, sizeof(pHealth));
    write(fd, pDamage, sizeof(pDamage));
    write(fd, pExp, sizeof(pExp));
    write(fd, pLev, sizeof(pLev));
    //write(fd, status1, sizeof(status1));

    return 0;
}

int pipeForBattle2(char* status, struct player* player, struct monster* monster, int fd){

    char playerName[100], pBHealth[3], pHealth[3], pDamage[3], pExp[3], pLev[3], monsterType[100], mHealth[3], mDamage[3];
    strcpy(playerName, player->name);
    strcpy(monsterType, monster->type);
    //sprintf(pBHealth, "%d", player->baseHealth);
    sprintf(pHealth, "%d", player->health);
    sprintf(pDamage, "%d", player->damage);
    sprintf(pExp, "%d", player->experience);
    sprintf(pLev, "%d", player->level);
    sprintf(mHealth, "%d", monster->health);
    sprintf(mDamage, "%d", monster->damage);
    printf("health: %s\n", pHealth);
    write(fd, playerName, sizeof(playerName));
    write(fd, pHealth, sizeof(pHealth));
    write(fd, pDamage, sizeof(pDamage));
    write(fd, pExp, sizeof(pExp));
    write(fd, pLev, sizeof(pLev));
    write(fd, "b", sizeof("b"));
    write(fd, monsterType, sizeof(monsterType));
    write(fd, mHealth, sizeof(mHealth));
    write(fd, mDamage, sizeof(mDamage));

    return 0;
}

struct monster* randomMonster(int level){
    srand(time(NULL));
    struct monster *MONSTERS[16];
    MONSTERS[0] = createTroll();
    MONSTERS[1] = createSkeleton();
    MONSTERS[2] = createStormTrooper();
    MONSTERS[3] = createSiren();
    MONSTERS[4] = createChupacabra();
    MONSTERS[5] = createWerewolf();
    MONSTERS[6] = createSasquatch();
    MONSTERS[7] = createDementor();
    MONSTERS[8] = createCerberus();
    MONSTERS[9] = createChimera();
    MONSTERS[10] = createCyclops();
    MONSTERS[11] = createGiant();
    //Level 3
    MONSTERS[12] = createMedusa();
    MONSTERS[13] = createVoldemort();
    MONSTERS[14] = createDarthVader();
    MONSTERS[15] = createPalpatine();
    int random = rand() % 4 + (level * 4);
    return MONSTERS[random];
}

int levelUp(struct player* PLAYER, int fd){
  if (PLAYER->level < 3){
      PLAYER->level += 1;
      PLAYER->baseHealth += 10;
      PLAYER->health = PLAYER->baseHealth;
      PLAYER->damage += 10;
      PLAYER->experience = 0;
      printf("\nCongratulations %s! You have leveled up to level %d. Your base health is now %d and you are now capable of doing %d damage.\n", PLAYER->name, PLAYER->level, PLAYER->health, PLAYER->damage);
  }
  if (PLAYER->level == 3){
      printf("\nYou have reached the last level of the game. You are now ready to go back to your village to deafeat the last few monsters. You are transported back to the village to fulfill your destiny.\n");
      village(PLAYER, fd);
      return 1;
  }
  return 0;
}

int battleTroll(struct monster* monster, struct player* player, int fd){ //returns 0 if player wins, 1 if player loses
    system("clear");
    pipeForBattle("w", player, fd);
    char input[100];
    printf("You meet a troll who refuses your passage unless you can answer his riddles. Would you like to answer them or run away? [answer] or [run] ");
    fgetc(stdin);
    fgets(input, 7, stdin);
    if (strcmp(input,"answer")==0) {
        int x = 1;
        int damage = monster->damage;
        printf("Instructions: The troll will ask you three questions. You must pass at least two of them to pass. Answer only in lowercase letters.\n\n");
        while (x <= 3){
            if(x==1)printf("\nRiddle #%d: What two-digit number equals two times the result of multiplying its digits? ", x);
            if(x==2)printf("\nRiddle #%d: What word becomes shorter when you add two more letters to it? ", x);
            if(x==3)printf("\nRiddle #%d: What gets wetter the more it dries? ", x);
            //fgetc(stdin);
            fgets(input, 100, stdin);
            printf("%s", input);
            if (x==1 && atoi(input)==36){
                printf("You answered correctly. The troll is impressed.\n");
            }
            else if (x==2 && strcmp(input,"short")==0){
                printf("You answered correctly. The troll is impressed.\n");
            }
            else if (x==3 && (strcmp(input,"a towel")==0 || strcmp(input,"towel")==0)){
                printf("You answered correctly. The troll is impressed.\n");
            }
            else{
                if(x==3) damage = player->health;
                player->health = player->health - damage;
                pipeForBattle("w", player, fd);
                printf("You answered wrong. The troll did %d damage to you. Your health is now %d.\n", damage, player->health);
                damage += monster->damage;

            }
            x++;
            if (player->health <= 0) {
                printf("%s\n", monster->defeatmessage);
                pipeForBattle("l", player, fd);
                return 1;
            }
        }
        printf("You have answered all of the riddles correctly! The troll will let you pass. You have gained %d points in experience!\n\n", monster->damage);
        player->experience += monster->damage;
        if (player->experience >= ((player->level+1)*10)+10) levelUp(player, fd);
        //printf("%s\n", monster->victorymessage);
        pipeForBattle("w", player, fd);
        return 0;
    }
    if (strcmp(input,"run\n")==0) {
        printf("You try to run but the troll catches up to you and eats you whole.\n");
        return 1;
    }
    return 0;
}

int battleMonster(struct monster* monster, struct player* player, int fd){ //returns 0 if player wins, 1 if player loses
    system("clear");
    pipeForBattle("w", player, fd);
    char input[100];
    int output = 0;
    //printf("A\n");
    if (strcmp(monster->type, "troll")==0) {
        output = battleTroll(monster, player, fd);
    }
//    if (strcmp(monster->type, "siren")==0) {
//        battleSiren(monster, player);
//  }
    else {
        srand(time(NULL));
        printf("\nOh no! You have encountered a %s. The %s has %d health and is capable of doing %d damage. You must defeat the %s before you can move on!\n", monster->type, monster->type, monster->health, monster->damage, monster->type);
        int turn = 0; //0 means it is players turn
        while (player->health > 0 && monster->health > 0) {
            if (turn == 0){
                printf("\nPress \"r\" to roll a dice to determine how much damage you do to the %s. You are capable of doing up to %d damage. ", monster->type, player->damage);
                if (output!=0) fgetc(stdin);
                fgets(input, 3, stdin);
                if (input[0]=='r'){
                    int damage = rand() % player->damage;
                    monster->health -= damage;
                    printf("\nYou have done %d damage. The %s is now at %d health.\n", damage, monster->type, monster->health);
                }
            }
            if (turn == 1) {
                int damage = rand() % monster->damage;
                player->health -= damage;
                printf("\nThe %s has dealt %d damage to you. You are now at %d health.\n", monster->type, damage, player->health);
                pipeForBattle("w", player, fd);
            }
            if (turn == 0) turn = 1;
            else turn = 0;
        }
        if (monster->health <= 0){
            sleep(1);
            system("clear");
            printf("\nCongratulations! You have defeated the %s. You have gained %d points in experience! You may continue in your journey.\n\n", monster->type, monster->damage*2);
            sleep(2);
            player->experience += monster->damage * 2;
            pipeForBattle("w", player, fd);
            if ((player->experience >= ((player->level+1)*10)+10) && player->level < 3){ levelUp(player, fd);
                pipeForBattle("w", player, fd);
                sleep(3);
            }
            if (player->level == 3) return 1;
            else if (player->health != player->baseHealth){
                int XP_to_health = player->baseHealth - player->health;
                if (XP_to_health > player->experience) XP_to_health = player->experience;
                printf("Your health is at %d, but it could be at %d. Would you like to expend some of the experience you earned to regain some health? Enter a number from 0 to %d: ", player->health, player->baseHealth, XP_to_health);
                fgets(input, 3, stdin);
                while(atoi(input) > XP_to_health || input[0]=='-'){
                    printf("Please enter a number between 0 and %d: ", XP_to_health);
                    fgetc(stdin);
                    fgets(input, 3, stdin);
                }
                player->experience -= atoi(input);
                player->health += atoi(input);
                printf("Your health is now at %d and your experience is at %d.\n\n", player->health, player->experience);
                pipeForBattle("w", player, fd);
                return 0;
              }
        }
        if (player->health <= 0){
            printf("\nYou have been defeated by the %s. Better luck next time.\n", monster->type);
            pipeForBattle("l", player, fd);
            return 1;
        }
    }
    return output;
}


//------------Level 0--------------//
struct monster* createTroll(){
    struct monster *troll = malloc(sizeof(struct monster));
    troll->type = "troll";
    troll->health = 30;
    troll->damage = 5;
    troll->level = 0;
    troll->status = 1;
    return troll;
}

struct monster* createSkeleton(){
    struct monster *skeleton = malloc(sizeof(struct monster));
    skeleton->type = "skeleton";
    skeleton->health = 10;
    skeleton->damage = 7;
    skeleton->level = 0;
    skeleton->status = 1;
    return skeleton;
}

struct monster* createSiren(){
    struct monster *siren = malloc(sizeof(struct monster));
    siren->type = "siren";
    siren->health = 5;
    siren->damage = 10;
    siren->level = 0;
    siren->status = 1;
    return siren;
}

struct monster* createStormTrooper(){
    struct monster *stormtrooper = malloc(sizeof(struct monster));
    stormtrooper->type = "stormtrooper";
    stormtrooper->health = 5;
    stormtrooper->damage = 5;
    stormtrooper->level = 0;
    stormtrooper->status = 1;
    return stormtrooper;
}


//-----------Level 1--------------//
struct monster* createChupacabra(){
    struct monster *chupacabra = malloc(sizeof(struct monster));
    chupacabra->type = "chupacabra";
    chupacabra->health = 10;
    chupacabra->damage = 25;
    chupacabra->level = 1;
    chupacabra->status = 1;
    return chupacabra;
}

struct monster* createWerewolf(){
    struct monster *werewolf = malloc(sizeof(struct monster));
    werewolf->type = "werewolf";
    werewolf->health = 25;
    werewolf->damage = 10;
    werewolf->level = 1;
    werewolf->status = 1;
    return werewolf;
}

struct monster* createSasquatch(){
    struct monster *sasquatch = malloc(sizeof(struct monster));
    sasquatch->type = "sasquatch";
    sasquatch->health = 22;
    sasquatch->damage = 7;
    sasquatch->level = 1;
    sasquatch->status = 1;
    return sasquatch;
}

struct monster* createDementor(){
    struct monster *dementor = malloc(sizeof(struct monster));
    dementor->type = "dementor";
    dementor->health = 13;
    dementor->damage = 13;
    dementor->level = 1;
    dementor->status = 1;
    return dementor;
}

//-----------Level 2-------------//

struct monster* createCerberus(){
    struct monster *cerberus = malloc(sizeof(struct monster));
    cerberus->type = "cerberus";
    cerberus->health = 30;
    cerberus->damage = 15;
    cerberus->level = 2;
    cerberus->status = 1;
    return cerberus;
}

struct monster* createChimera(){
    struct monster *chimera = malloc(sizeof(struct monster));
    chimera->type = "chimera";
    chimera->health = 25;
    chimera->damage = 20;
    chimera->level = 2;
    chimera->status = 1;
    return chimera;
}

struct monster* createCyclops(){
    struct monster *cyclops = malloc(sizeof(struct monster));
    cyclops->type = "cyclops";
    cyclops->health = 35;
    cyclops->damage = 20;
    cyclops->level = 2;
    cyclops->status = 1;
    return cyclops;
}

struct monster* createGiant(){
    struct monster *giant = malloc(sizeof(struct monster));
    giant->type = "giant";
    giant->health = 40;
    giant->damage = 25;
    giant->level = 2;
    giant->status = 1;
    return giant;
}

//-----------Level 3-------------//
struct monster* createMedusa(){
    struct monster *medusa = malloc(sizeof(struct monster));
    medusa->type = "medusa";
    medusa->health = 40;
    medusa->damage = 25;
    medusa->level = 3;
    medusa->status = 1;
    return medusa;
}

struct monster* createVoldemort(){
    struct monster *voldemort = malloc(sizeof(struct monster));
    voldemort->type = "voldemort";
    voldemort->health = 60;
    voldemort->damage = 30;
    voldemort->level = 3;
    voldemort->status = 1;
    return voldemort;
}

struct monster* createDarthVader(){
    struct monster *darthvader = malloc(sizeof(struct monster));
    darthvader->type = "darth vader";
    darthvader->health = 50;
    darthvader->damage = 25;
    darthvader->level = 3;
    darthvader->status = 1;
    return darthvader;
}

struct monster* createPalpatine(){
    struct monster *palpatine = malloc(sizeof(struct monster));
    palpatine->type = "palpatine";
    palpatine->health = 65;
    palpatine->damage = 40;
    palpatine->level = 3;
    palpatine->status = 1;
    return palpatine;
}


//============================================//
