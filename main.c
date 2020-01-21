#include "players.h"
#include <stdio.h>
#include <stdlib.h>

struct player* createPlayer(char *name){
    struct player *player = malloc(sizeof(struct player));
    player->name = name;
    player->health = 20;
    player->damage = 5;
    player->baseHealth = 20;
    player->experience = 0;
    player->level = 0;
    return player;
}

void openInstructions(){
    int fd = open("instructions", O_RDONLY);
    if (fd < 0){
        printf("errno: %d error %s\n", errno, strerror(errno));
        printf("fd: %d\n", fd);
    }

    //fix this so that it returns a string or something i don't know how it works
    char buff[10000];
    memset(buff, 0, 10000);
    int rd = 0;
    rd = read(fd, buff, sizeof(buff));
    if (rd < 0){
        printf("errno: %d error %s\n", errno, strerror(errno));
        printf("rd: %d\n", rd);
    }
    printf("%s\n", buff);
    close(rd);
    close(fd);
    //return buff;

}

//reminder: have a file with player stats


int main(){
    //system("./battle.sh");
    int fd;

    char * myfifo = "/tmp/myfifo";

    mkfifo(myfifo, 0666);
    fd = open(myfifo, O_WRONLY);

    char input[100];
    system("clear");
    printf("Welcome to Cellars and Serpents!\nWould you like to view the instructions? (y/n): ");
    fgets(input, 3, stdin);
    if (input[0] == 'y'){
        openInstructions();
    }
    printf("\n\nWould you like to begin? (y/n): ");
    fgets(input, 3, stdin);
    if (input[0] == 'y'){
        system("clear");
        printf("Type in your character name: ");
        fgets(input, 100, stdin);
        strtok(input, "\n"); //removes newline
        char name[100];
        strcpy(name, input);
        struct player *PLAYER = createPlayer(name);
        pipeForBattle("w", PLAYER, fd);
        printf("Oh no, %s! your town was destroyed and everyone died. You have to leave your town to defeat the enemies in the surrounding area. Would you like to go through [forest] or [desert]? ", PLAYER->name);
        fgets(input, 10, stdin);
        while(strcmp(input,"forest\n")!=0 && strcmp(input,"desert\n")!=0){
            printf("Invalid choice. Valid choices: [forest/ desert]\n\t");
            fgets(input, 10, stdin);
        }
        if (strcmp(input,"forest\n")==0) forest(PLAYER, fd);
        if (strcmp(input,"desert\n")==0) desert(PLAYER, fd);
    }
    if (input[0] == 'n'){
        close(fd);
        return 0;
    }
    end:
        close(fd);
        return 0;
}

//system("chmod 755 battle.sh");
//int exit_status = system("open -a Terminal \"`pwd`\"");
//system("./battle.sh");
