#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

int main(){
    //while(true){
    char *input;
    printf("Welcome to <game>!\nWould you like to begin? (y/n) ");
    fgets(input, 3, stdin);
    if (input[0] == 'y'){
        printf("Oh no, your town was destroyed and everyone died. You have to leave your town to defeat the enemies in the surrounding area. Would you like to go through [forest] or [desert]? ");
        fgets(input, 7, stdin);
        if (strcmp(input,"forest")==0){
            printf("A\n");
        }
        if (strcmp(input,"desert")==0){
            printf("You’re not prepared, smarty pants. You’re out of water. You die of thirst.\n");
        }
    }
    if (input[0] == 'n'){
        return 0;
    }
        
        
        
        
    //}
    
    //return 0;
}

void chooseCharacter(){
    printf("Choose a character: [Villager] [Wizard]\n");
}
