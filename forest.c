#include "players.h"


void forest(struct player PLAYER){
    srand(time(NULL));
    int rand;
    char input[100];
    char previnput[100];
    forest: printf("You've just entered the forest. There is a clearing ahead, a a muddy path to your right, and a cave to your left. Where would you like to go? [clearing/ cave/ path]: ");
    fgets(input, 10, stdin);
    if (strcmp(input,"clearing")==0) goto clearing;
    if (strcmp(input,"cave")==0) goto cave;
    if (strcmp(input,"path")==0) goto path;

    clearing:
        rand = rand() % 3;
        //forking paths
        if (rand == 0){
            printf("The clearing leads to a cave and muddy path. Where would you like to go [cave/ path]: ");
            fgets(input, 10, stdin);
            if (strcmp(input,"cave")==0) goto cave;
            if (strcmp(input,"path")==0) goto path;
        }
        //dead end
        if (rand == 1){
            printf("You have reached a dead end. You may move to the right to left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto clearing;
        }
        //battles monster
        if (rand == 2){
            struct monster *MONSTER = randomMonster(PLAYER->level);
            x = battleMonster(MONSTER, PLAYER);
            if (x==1) return 0;
        }
    cave:
        rand = rand() % 3;
        //forking paths
        if (rand == 0){
            printf("The cave leads to a muddy path and a lake. Where would you like to go? [path/ lake]: ");
            fgets(input, 10, stdin);
            if (strcmp(input,"lake")==0) goto lake;
            if (strcmp(input,"path")==0) goto path;
        }
        //dead end
        if (rand == 1){
            printf("You have reached a dead end. You may move to the right or left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto cave;
        }
        //battles monster
        if (rand == 2){
          struct monster *MONSTER = randomMonster(PLAYER->level);
          x = battleMonster(MONSTER, PLAYER);
          if (x==1) return 0;
        }
    path:
        rand = rand() % 3;
        //forking paths
        if (rand == 0){
            printf("The path leads to a lake and a clearing. Where would you like to go? [lake/ clearing]: ");
            fgets(input, 10, stdin);
            if (strcmp(input,"lake")==0) goto lake;
            if (strcmp(input,"clearing")==0) goto clearing;
        }
        //dead end
        if (rand == 1){
            printf("You have reached a dead end. You may move to the right or left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto path;
        }
        //battles monster
        if (rand == 2){
          struct monster *MONSTER = randomMonster(PLAYER->level);
          x = battleMonster(MONSTER, PLAYER);
          if (x==1) return 0;
        }
    lake:
        rand = rand() % 3;
        //forking paths
        if (rand == 0){
            printf("The lake leads to a clearing and another cave. Where would you like to go? [clearing/ cave]: ");
            fgets(input, 10, stdin);
            if (strcmp(input,"clearing")==0) goto clearing;
            if (strcmp(input,"cave")==0) goto cave;
        }
        //dead end
        if (rand == 1){
            printf("You have reached a dead end. You may move to the right or left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto path;
        }
        //battles monster
        if (rand == 2){
          struct monster *MONSTER = randomMonster(PLAYER->level);
          x = battleMonster(MONSTER, PLAYER);
          if (x==1) return 0;
        }

/*
    levelUp:
        for(int x = 0; x < 4; x++){
            if (PLAYER->experience >= 50){
                PLAYER->level += 1;
                PLAYER->health += 10;
                PLAYER->damage += 10;
                PLAYER->experience = 0;
                printf("Congratulations %s! You have leveled up to level %d. Your base health is now %d and you are now capable of doing %d damage.\n", PLAYER->name, PLAYER->level, PLAYER->health, PLAYER->damage);
            }
            if (PLAYER->level = 3){
                printtf("You have reached the last level of the game. You are now ready to go back to your village to deafeat the last few monsters. Whenever you're ready, type [go] to start level four and fulfill your purpose. [go]: ");
                village();
            }
            //struct monster *MONSTER = randomMonster(PLAYER->level);
            //x = battleMonster(MONSTER, PLAYER);
            //if (x==1) return 0;
        }
        */
}