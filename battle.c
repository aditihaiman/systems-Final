#include "players.h"



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
    
    char *status = "w";
    
    char playerName[100] = "\0";
    char pBHealth[3]= "\0";
    char pHealth[3]= "\0";
    char pDamage[3]= "\0";
    char pExp[3]= "\0";
    char pLev[3]= "\0";

    fd = open(myfifo, O_RDONLY);
    
    while(1){
    
        
        read(fd, playerName, sizeof(playerName));
        read(fd, pBHealth, sizeof(pBHealth));
        read(fd, pHealth, sizeof(pHealth));
        read(fd, pDamage, sizeof(pDamage));
        read(fd, pExp, sizeof(pExp));
        read(fd, pLev, sizeof(pLev));
        read(fd, status, sizeof(status));
        if(strcmp(status,"l")==0) return 0;
        
        printf("Player Stats: \n");
        printf("\tCurrent Level [%s]\n", pLev);
        printf("\tCurrent Health [%s]\n", pHealth);
        printf("\tMaximum Damage [%s]\n", pDamage);
        printf("\tCurrent Experience [%s]\n", pExp);
        
        sleep(1);
        system("clear");
    }
    
    
    close(fd);
    
    
    //int x = battleMonsters(MONSTER, PLAYER);
    
    
    //----------------//
//    myfifo = "/tmp/myfifo2";
//
//    mkfifo(myfifo, 0666);
//
//    char status[1];
//    sprintf(pBHealth, "%d", PLAYER->baseHealth);
//    sprintf(pHealth, "%d", PLAYER->health);
//    sprintf(pDamage, "%d", PLAYER->damage);
//    sprintf(pExp, "%d", PLAYER->experience);
//    sprintf(pLev, "%d", PLAYER->level);
//    sprintf(status, "%d", x);
//
//    fd = open(myfifo, O_WRONLY);
//    write(fd, pBHealth, sizeof(pBHealth));
//    write(fd, pHealth, sizeof(pHealth));
//    write(fd, pDamage, sizeof(pDamage));
//    write(fd, pExp, sizeof(pExp));
//    write(fd, pLev, sizeof(pLev));
//    write(fd, status, sizeof(status));
//
//    close(fd);
//    unlink(myfifo);
}
