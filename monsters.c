#include "players.h"

struct monster* randomMonster(){
    
}

void battleMonster(struct monster*, struct player*){
    
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

void battleTroll(){
    
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
