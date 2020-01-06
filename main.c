#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

int main(){
    int x = 1;
    while(x){
        char *input;
        printf("Welcome to <game>!\nWould you like to begin? (y/n) ");
        fgets(input, 3, stdin);
        if (input[0] == 'y'){
            printf("Oh no, your town was destroyed and everyone died. You have to leave your town to defeat the enemies in the surrounding area. Would you like to go through [forest] or [desert]? ");
            fgets(input, 7, stdin);
            if (strcmp(input,"forest")==0){
                printf("You meet a forest troll who refuses your passage unless you can answer his three riddles. Would you like to answer them or run away? [answer] or [run] ");
                fgets(input, 7, stdin);
                //printf("errno: %d, error:\n", errno, strerror(errno));
                //printf("%s\n", input);
                if (strcmp(input,"answer")==0) {
                    printf("The first riddle: \n");
                }
                if (strcmp(input,"run")==0) {
                    printf("You try to run but the troll catches up to you and eats you whole.\n");
                    return 0;
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
    
    //return 0;
}

void chooseCharacter(){
    printf("Choose a character: [Villager] [Wizard]\n");
}
