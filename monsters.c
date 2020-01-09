#include "players.h"

struct monster* randomMonster(){

}

int battleMonster(struct monster* monster, struct player* player){ //returns 0 if player wins, 1 if player loses
    if (strcmp(monster->type, "troll")==0) {
        return battleTroll(monster, player);
    }
//    if (strcmp(monster->type, "siren")==0) {
//        battleSiren(monster, player);
//  }
    else {
        while (player->health > 0) {
            
        }
    }
    return 0;
}


//------------Level 0--------------//
struct monster* createTroll(){
    struct monster *troll = malloc(sizeof(struct monster));
    troll->type = "troll";
    troll->health = 30;
    troll->damage = 5;
    troll->level = 0;
    troll->status = 1;
    troll->initialmessage = "You meet a forest troll who refuses your passage unless you can answer his three riddles. Would you like to answer them or run away? [answer] or [run]";
    return troll;
}

int battleTroll(struct monster* monster, struct player* player){ //returns 0 if player wins, 1 if player loses
    char *input;
    printf("%s", monster->initialmessage);
    fgetc(stdin);
    fgets(input, 7, stdin);
    if (strcmp(input,"answer")==0) {
        int x = 1;
        while (x <= 3){
            if (player->health <= 0) {
                printf("%s\n", monster->defeatmessage);
                return 1;
            }
            int damage = 0;
            printf("Riddle #%d: [0]\n", x);
            fgetc(stdin);
            fgets(input, 3, stdin);
            if (input[0] == '0'){
                printf("You answered correctly. The troll is impressed.\n");
            }
            else{
                printf("You answered wrong. Your health is now %d.\n", player->health);
                player->health = player->health - (monster->damage + damage);
                damage += monster->damage;
            }
            x++;
        }
        printf("You have answered all of the riddles correctly! The troll will let you pass. You have gained %d points in experience!\n", monster->damage);
        player->experience += monster->damage;
        printf("%s\n", monster->victorymessage);
        return 0;
    }
    if (strcmp(input,"run\n")==0) {
        printf("You try to run but the troll catches up to you and eats you whole.\n");
        return 1;
    }
}


struct monster* createSkeleton(){
    struct monster *skeleton = malloc(sizeof(struct monster));
    skeleton->type = "skeleton";
    skeleton->health = 20;
    skeleton->damage = 10;
    skeleton->level = 0;
    skeleton->status = 1;
    return skeleton;
}

struct monster* createSiren(){
    struct monster *siren = malloc(sizeof(struct monster));
    siren->type = "siren";
    siren->health = 5;
    siren->damage = 15;
    siren->level = 0;
    siren->status = 1;
    return siren;
}

struct monster* createStormTrooper(){
    struct monster *stormtrooper = malloc(sizeof(struct monster));
    stormtrooper->type = "stormtrooper";
    stormtrooper->health = 5;
    stormtrooper->damage = 1;
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
    dementor->health = 5;
    dementor->damage = 15;
    dementor->level = 1;
    dementor->status = 1;
    return dementor;
}

//-----------Level 2-------------//

struct monster* createCerberus(){
    struct monster *cerberus = malloc(sizeof(struct monster));
    cerberus->type = "cerberus";
    cerberus->health = 35;
    cerberus->damage = 25;
    cerberus->level = 2;
    cerberus->status = 1;
    return cerberus;
}

struct monster* createChimera(){
    struct monster *chimera = malloc(sizeof(struct monster));
    chimera->type = "chimera";
    chimera->health = 30;
    chimera->damage = 30;
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
    palpatine->health = 75;
    palpatine->damage = 40;
    palpatine->level = 3;
    palpatine->status = 1;
    return palpatine;
}


//============================================//

void defeated(struct monster* monster, struct player* player){
}

