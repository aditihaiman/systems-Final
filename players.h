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
    int level;
};

struct monster {
    char *type;
    int health;
    int damage;
    int level;
    int status; //0 for defeated, 1 for undefeated
};
