#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

struct player {
    char *name;
    int health;
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
int battleMonster(struct monster*, struct player*);
