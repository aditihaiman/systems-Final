#include "players.h"

int pipeForBattle(struct monster* monster, struct player* player){
    int fd;
    
    char * myfifo = "/tmp/myfifo";
   
    mkfifo(myfifo, 0666);
    
    char monsterType[100], playerName[100], pBHealth[1], pHealth[1], pDamage[1], pExp[1], pLev[1];
    strcpy(monsterType, monster->type);
    strcpy(playerName, player->name);
    itoa(player->baseHealth, pBHealth, 10);
    //strcpy(pBHealth, itoa(player->baseHealth));
//    strcpy(pHealth, itoa(player->health));
//    strcpy(pDamage, itoa(player->damage));
//    strcpy(pExp, itoa(player->experience));
//    strcpy(pLev, itoa(player->level));
    
    fd = open(myfifo, O_WRONLY);
    write(fd, monsterType, sizeof(monsterType));
    write(fd, playerName, sizeof(playerName));
    write(fd, pBHealth, sizeof(pBHealth));
    write(fd, pHealth, sizeof(pHealth));
    write(fd, pDamage, sizeof(pDamage));
    write(fd, pExp, sizeof(pExp));
    write(fd, pLev, sizeof(pLev));
    
    close(fd);
    unlink(myfifo);
    return 0;
}

int main(){
//    printf("A\n");
//    int x;
//    x = execlp("chmod", "chmod", "755", "battle.sh");
//    //int exit_status = system("open -a Terminal \"`pwd`\"");
//    printf("x: %d\n, errno: %d, error: %s", x, errno, strerror(errno));
//    x = execlp("ls", "ls");
//    printf("x: %d\n", x);

    //battleMonsters();
    
//    system("chmod 755 battle.sh");
//    system("./battle.sh");
    
    int fd;
    
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    
    char monsterType[100], playerName[100], pBHealth[1], pHealth[1], pDamage[1], pExp[1], pLev[1];
    
    fd = open(myfifo, O_RDONLY);
    read(fd, monsterType, sizeof(monsterType));
    read(fd, playerName, sizeof(playerName));
    read(fd, pBHealth, sizeof(pBHealth));
    read(fd, pHealth, sizeof(pHealth));
    read(fd, pDamage, sizeof(pDamage));
    read(fd, pExp, sizeof(pExp));
    read(fd, pLev, sizeof(pLev));
    
    struct player* PLAYER = createPlayer(playerName);
    PLAYER->baseHealth = atoi(pBHealth);
    PLAYER->health = atoi(pHealth);
    PLAYER->damage = atoi(pDamage);
    PLAYER->experience = atoi(pExp);
    PLAYER->level = atoi(pLev);

    struct monster* MONSTER;
    if (strcmp(monsterType, "troll")) MONSTER = createTroll();
    if (strcmp(monsterType, "siren")) MONSTER = createSiren();
    if (strcmp(monsterType, "stormtrooper")) MONSTER = createStormTrooper();
    if (strcmp(monsterType, "skeleton")) MONSTER = createSkeleton();
    if (strcmp(monsterType, "troll")) MONSTER = createTroll();
    if (strcmp(monsterType, "troll")) MONSTER = createTroll();
    if (strcmp(monsterType, "troll")) MONSTER = createTroll();
    if (strcmp(monsterType, "troll")) MONSTER = createTroll();

    close(fd);
    
    
    
    
}
