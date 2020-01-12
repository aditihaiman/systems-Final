#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

struct player {
    char *name;
    int health;
    int baseHealth;
    int damage; //how much damage you could potentially deal to an enemy
    int experience;
    int level;
};

struct monster {
    char *type;
    int health;
    int damage; //damage dealt to player, also amount of experience gained when defeated
    int level;
    int status; //0 for defeated, 1 for undefeated
    char *initialmessage; //message given when the monster is first encountered
    char *defeatmessage; //message given when the player is defeated
    char *victorymessage;//message given when the player wins
};

struct monster* createTroll();
struct monster* createSkeleton();
struct monster* createStormTrooper();
struct monster* createSiren();
struct monster* createChupacabra();
struct monster* createWerewolf();
struct monster* createSasquatch();
struct monster* createDementor();
struct monster* createCerberus();
struct monster* createChimera();
struct monster* createCyclops();
struct monster* createGiant();
struct monster* createMedusa();
struct monster* createVoldemort();
struct monster* createDarthVader();
struct monster* createPalpatine();
int forest(struct player *PLAYER);
int desert(struct player *PLAYER);

int battleMonster(struct monster*, struct player*);
struct monster* randomMonster(int level);
