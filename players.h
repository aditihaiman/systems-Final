#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#define READ 0
#define WRITE 1

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
int forest(struct player *PLAYER, int);
int desert(struct player *PLAYER, int);
int village(struct player *player, int);

int battleMonster(struct monster*, struct player*, int);
int battleTroll(struct monster*, struct player*, int);
struct monster* randomMonster(int level);

int pipeForBattle(char *, struct player*, int);
int closePipeBattle(struct player* );
