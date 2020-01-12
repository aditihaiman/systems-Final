#include "players.h"
#include <stdio.h>
#include <stdlib.h>

struct player* createPlayer(char *name){
    struct player *player = malloc(sizeof(struct player));
    player->name = name;
    player->health = 20;
    player->damage = 5;
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


int main(){
    int x = 0;
    while(!x){
        char input[100];
        printf("Welcome to <game>!\nWould you like to view the instructions? (y/n): ");
        fgets(input, 3, stdin);
        if (input[0] == 'y'){
            openInstructions();
        }
        printf("Would you like to begin? (y/n): ");
        fgets(input, 3, stdin);
        if (input[0] == 'y'){
            printf("Type in your character name: ");
            fgets(input, 100, stdin);
            strtok(input, "\n"); //removes newline
            struct player *PLAYER = createPlayer(input);
            printf("Oh no, %s! your town was destroyed and everyone died. You have to leave your town to defeat the enemies in the surrounding area. Would you like to go through [forest] or [desert]? ", PLAYER->name);
            fgets(input, 7, stdin);
            if (strcmp(input,"forest")==0){
                for(int x = 0; x < 4; x++){
                    if(PLAYER->experience >= 50){
                        PLAYER->level += 1;
                        PLAYER->health += 10;
                        PLAYER->damage += 10;
                        printf("Congratulations %s! You have leveled up to level %d. Your base health is now %d and you are now capable of doing %d damage.\n", PLAYER->name, PLAYER->level, PLAYER->health, PLAYER->damage);
                    }
                    struct monster *MONSTER = randomMonster(PLAYER->level);
                    x = battleMonster(MONSTER, PLAYER);
                    /*
                     //SEPARATE FUNCTION FOR
                     */
                }
            }
            if (strcmp(input,"desert")==0){
                printf("You’re not prepared, smarty pants. You’re out of water. You die of thirst.\n");
                return 0;
            }
        }
        if (input[0] == 'n'){
            return 0;
        }

    }
    end: return 0;
}
