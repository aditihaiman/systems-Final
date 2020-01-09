#include "players.h"

struct player* createPlayer(char *name){
    struct player *name = malloc(sizeof(struct player));
    //player->name;
    player->health = 20;
    player->damage = 5;
    player->level = 0;
}

int main(){
    int x = 1;
    while(x){
        char *input;
        printf("Welcome to <game>!\nWould you like to begin? (y/n) ");
        fgets(input, 3, stdin);
        if (input[0] == 'y'){
            printf("Type in your character name: ");
            fgets(input, 7, stdin);
            struct player *PLAYER = createPlayer(input);
            printf("Oh no, your town was destroyed and everyone died. You have to leave your town to defeat the enemies in the surrounding area. Would you like to go through [forest] or [desert]? ");
            fgets(input, 7, stdin);

            if (strcmp(input,"forest")==0){
                struct monster *MONSTER = randomMonster();
                battleMonster(MONSTER, PLAYER);
                /*
                //SEPARATE FUNCTION FOR

                */
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
