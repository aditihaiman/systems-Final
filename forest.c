#include "players.h"


int forest(struct player *PLAYER){
    srand(time(NULL));
    int random;
    int x = 0;
    char input[100];
    printf("\nYou've just entered the forest. There is a clearing ahead, a muddy path to your right, and a cave to your left. Where would you like to go? [clearing/ cave/ path]: ");
    fgets(input, 100, stdin);
    while(strcmp(input,"clearing\n")!=0 && strcmp(input,"cave\n")!=0 && strcmp(input,"path\n")!=0){
        printf("Invalid choice. Valid choices: [clearing/ cave/ path]\n\t");
        fgets(input, 100, stdin);
    }
    if (strcmp(input,"clearing\n")==0) goto clearing;
    if (strcmp(input,"cave\n")==0) goto cave;
    if (strcmp(input,"path\n")==0) goto path;

    clearing:
        random = rand() % 3;
        //forking paths
        if (random == 0){
            printf("\nThe clearing leads to a cave and muddy path. Where would you like to go [cave/ path]: ");
            fgets(input, 100, stdin);
            while(strcmp(input,"cave\n")!=0 && strcmp(input,"path\n")!=0){
                printf("Invalid choice. Valid choices: [cave/ path]\n\t");
                fgets(input, 100, stdin);
            }
            if (strcmp(input,"cave\n")==0) goto cave;
            if (strcmp(input,"path\n")==0) goto path;
        }
        //dead end
        if (random == 1){
            printf("\nYou have reached a dead end. You may move to the right to left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto clearing;
        }
        //battles monster
        if (random == 2){
            struct monster *MONSTER = randomMonster(PLAYER->level);
            x = battleMonster(MONSTER, PLAYER);
            if (x==1) return 1;
            goto clearing;
        }
    cave:
        random = rand() % 3;
        //forking paths
        if (random == 0){
            printf("\nThe cave leads to a muddy path and a lake. Where would you like to go? [path/ lake]: ");
            fgets(input, 100, stdin);
            while(strcmp(input,"lake\n")!=0 && strcmp(input,"path\n")!=0){
                printf("Invalid choice. Valid choices: [lake/ path]\n\t");
                fgets(input, 100, stdin);
            }
            if (strcmp(input,"lake\n")==0) goto lake;
            if (strcmp(input,"path\n")==0) goto path;
        }
        //dead end
        if (random == 1){
            printf("\nYou have reached a dead end. You may move to the right or left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto cave;
        }
        //battles monster
        if (random == 2){
          struct monster *MONSTER = randomMonster(PLAYER->level);
          x = battleMonster(MONSTER, PLAYER);
          if (x==1) return 1;
          goto cave;
        }
    path:
        random = rand() % 3;
        //forking paths
        if (random == 0){
            printf("\nThe path leads to a lake and a clearing. Where would you like to go? [lake/ clearing]: ");
            fgets(input, 100, stdin);
            while(strcmp(input,"clearing\n")!=0 && strcmp(input,"lake\n")!=0){
                printf("Invalid choice. Valid choices: [clearing/ lake]\n\t");
                fgets(input, 100, stdin);
            }
            printf("%s\n", input);
            if (strcmp(input,"lake\n")==0) goto lake;
            if (strcmp(input,"clearing\n")==0) goto clearing;
        }
        //dead end
        if (random == 1){
            printf("\nYou have reached a dead end. You may move to the right or left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto path;
        }
        //battles monster
        if (random == 2){
          struct monster *MONSTER = randomMonster(PLAYER->level);
          x = battleMonster(MONSTER, PLAYER);
          if (x==1) return 1;
          goto path;
          //if level up go to level up otherwise go back to path
        }
    lake:
        random = rand() % 3;
        //forking paths
        if (random == 0){
            printf("\nThe lake leads to a clearing and another cave. Where would you like to go? [clearing/ cave]: ");
            fgets(input, 100, stdin);
            while(strcmp(input,"clearing\n")!=0 && strcmp(input,"cave\n")!=0){
                printf("Invalid choice. Valid choices: [clearing/ cave]\n\t");
                fgets(input, 100, stdin);
            }
            if (strcmp(input,"clearing\n")==0) goto clearing;
            if (strcmp(input,"cave\n")==0) goto cave;
        }
        //dead end
        if (random == 1){
            printf("\nYou have reached a dead end. You may move to the right or left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto lake;
        }
        //battles monster
        if (random == 2){
          struct monster *MONSTER = randomMonster(PLAYER->level);
          x = battleMonster(MONSTER, PLAYER);
          if (x==1) return 1;
          goto lake;
        }
    return x;
}
