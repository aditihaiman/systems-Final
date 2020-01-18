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
    
    char monster[100] = "\0";
    char mHealth[3] = "\0";
    char mDamage[3] = "\0";

    fd = open(myfifo, O_RDONLY);
    
    while(1){
        read(fd, playerName, sizeof(playerName));
        system("clear");
        printf("Player: %s\n", playerName);
        //read(fd, pBHealth, sizeof(pBHealth));
        read(fd, pHealth, sizeof(pHealth));
        if(atoi(pHealth)<=0) break;
        printf("\tCurrent Health [%s]\n", pHealth);
        read(fd, pDamage, sizeof(pDamage));
        printf("\tMaximum Damage [%s]\n", pDamage);
        read(fd, pExp, sizeof(pExp));
        printf("\tCurrent Experience [%s]\n", pExp);
        read(fd, pLev, sizeof(pLev));
        printf("\tCurrent Level [%s]\n", pLev);
//        read(fd, status, sizeof(status));
//        printf("b: %s\n", status);
//        if(strcmp(status, "b")==0){ //b for battle
//            read(fd, monster, sizeof(monster));
//            printf("\nMonster: %s\n", monster);
//            read(fd, mHealth, sizeof(mHealth));
//            printf("\tCurrent Health [%s]\n", mHealth);
//            read(fd, mDamage, sizeof(mDamage));
//            printf("\tMaximum Damage [%s]\n", mDamage);
//        }
        
        
        //sleep(1);
    }
    
    
    close(fd);
    
    return 0;
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
