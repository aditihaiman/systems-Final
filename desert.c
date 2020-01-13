#include "players.h"


int desert(struct player *PLAYER){
    srand(time(NULL));
    int random;
    int x;
    char input[100];
    printf("\nYou've just entered the desert. There is a plateau ahead, a canyon to your right, and a cave to your left. Where would you like to go? [plateau/ canyon/ cave]: ");
    fgetc(stdin);
    fgets(input, 10, stdin);
    if (strcmp(input,"canyon\n")==0){
        goto canyon;
    }
    if (strcmp(input,"plateau\n")==0){
        goto plateau;
    }
    else if (strcmp(input,"cave\n")==0){
        goto cave;
    }

    canyon:
        random = rand() % 3;
        //forking caves
        if (random == 0){
            printf("\nThe canyon leads to a cave and an oasis. Where would you like to go? [cave/ oasis]: ");
            fgets(input, 10, stdin);
            if (strcmp(input,"oasis\n")==0) goto oasis;
            if (strcmp(input,"cave\n")==0) goto cave;
        }
        //dead end
        if (random == 1){
            printf("\nYou have reached a dead end. You may move to the right or left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto canyon;
        }
        //battles monster
        if (random == 2){
          struct monster *MONSTER = randomMonster(PLAYER->level);
          x = battleMonster(MONSTER, PLAYER);
          if (x==1) return 1;
          goto canyon;
        }
    plateau:
        random = rand() % 3;
        //forking caves
        if (random == 0){
            printf("\nThe plateau leads to a small canyon and a cave. Where would you like to go [canyon/ cave]: ");
            fgets(input, 10, stdin);
            if (strcmp(input,"canyon\n")==0) goto canyon;
            if (strcmp(input,"cave\n")==0) goto cave;
        }
        //dead end
        if (random == 1){
            printf("\nYou have reached a dead end. You may move to the right to left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto plateau;
        }
        //battles monster
        if (random == 2){
            struct monster *MONSTER = randomMonster(PLAYER->level);
            x = battleMonster(MONSTER, PLAYER);
            if (x==1) return 1;
            goto plateau;
        }
    cave:
        random = rand() % 3;
        //forking caves
        if (random == 0){
            printf("\nThe cave leads to an oasis and a plateau. Where would you like to go? [oasis/ plateau]: ");
            fgets(input, 10, stdin);
            if (strcmp(input,"oasis\n")==0) goto oasis;
            if (strcmp(input,"plateau\n")==0) goto plateau;
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
    oasis:
        random = rand() % 3;
        //forking caves
        if (random == 0){
            printf("\nThe oasis leads to a plateau and another canyon. Where would you like to go? [plateau/ canyon]: ");
            fgets(input, 10, stdin);
            if (strcmp(input,"plateau\n")==0) goto plateau;
            if (strcmp(input,"canyon\n")==0) goto canyon;
        }
        //dead end
        if (random == 1){
            printf("\nYou have reached a dead end. You may move to the right or left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto oasis;
        }
        //battles monster
        if (random == 2){
          struct monster *MONSTER = randomMonster(PLAYER->level);
          x = battleMonster(MONSTER, PLAYER);
          if (x==1) return 1;
          goto oasis;

        }
    return x;
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
