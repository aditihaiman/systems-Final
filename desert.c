#include "players.h"


int desert(struct player *PLAYER, int fd){
    srand(time(NULL));
    int random;
    int x;
    char input[100];
    printf("\nYou've just entered the desert. There is a plateau ahead, a canyon to your right, and a cave to your left. Where would you like to go? [plateau/ canyon/ cave]: ");
    fgets(input, 100, stdin);
    while(strcmp(input,"canyon\n")!=0 && strcmp(input,"cave\n")!=0 && strcmp(input,"plateau\n")!=0){
        printf("Invalid choice. Valid choices: [canyon/ cave/ plateau]\n\t");
        fgets(input, 100, stdin);
    }
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
        random = rand() % 6;
        //forking caves
        if (random == 0 || random == 1){
            printf("\nThe canyon leads to a cave and an oasis. Where would you like to go? [cave/ oasis]: ");
            fgets(input, 100, stdin);
            while(strcmp(input,"cave\n")!=0 && strcmp(input,"oasis\n")!=0){
                printf("Invalid choice. Valid choices: [cave/ oasis]\n\t");
                fgets(input, 100, stdin);
            }
            if (strcmp(input,"oasis\n")==0) goto oasis;
            if (strcmp(input,"cave\n")==0) goto cave;
        }
        //dead end
        else if (random == 2){
            printf("\nYou have reached a dead end. You may move to the right or left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto canyon;
        }
        //battles monster
        else{
          struct monster *MONSTER = randomMonster(PLAYER->level);
          x = battleMonster(MONSTER, PLAYER, fd);
          if (x==1) return 1;
          goto canyon;
        }
    plateau:
        random = rand() % 6;
        //forking caves
        if (random == 0 || random == 1){
            printf("\nThe plateau leads to a small canyon and a cave. Where would you like to go [canyon/ cave]: ");
            fgets(input, 100, stdin);
            while(strcmp(input,"cave\n")!=0 && strcmp(input,"canyon\n")!=0){
                printf("Invalid choice. Valid choices: [cave/ canyon]\n\t");
                fgets(input, 100, stdin);
            }
            if (strcmp(input,"canyon\n")==0) goto canyon;
            if (strcmp(input,"cave\n")==0) goto cave;
        }
        //dead end
        else if (random == 2){
            printf("\nYou have reached a dead end. You may move to the right to left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto plateau;
        }
        //battles monster
        else{
            struct monster *MONSTER = randomMonster(PLAYER->level);
            x = battleMonster(MONSTER, PLAYER, fd);
            if (x==1) return 1;
            goto plateau;
        }
    cave:
        random = rand() % 6;
        //forking caves
        if (random == 0 || random ==1 ){
            printf("\nThe cave leads to an oasis and a plateau. Where would you like to go? [oasis/ plateau]: ");
            fgetc(stdin);
            fgets(input, 100, stdin);
            while(strcmp(input,"plateau\n")!=0 && strcmp(input,"oasis\n")!=0){
                printf("Invalid choice. Valid choices: [plateau/ oasis]\n\t");
                fgets(input, 100, stdin);
            }
            if (strcmp(input,"oasis\n")==0) goto oasis;
            if (strcmp(input,"plateau\n")==0) goto plateau;
        }
        //dead end
        else if (random == 2){
            printf("\nYou have reached a dead end. You may move to the right or left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto cave;
        }
        //battles monster
        else {
          struct monster *MONSTER = randomMonster(PLAYER->level);
          x = battleMonster(MONSTER, PLAYER, fd);
          if (x==1) return 1;
          goto cave;
        }
    oasis:
        random = rand() % 6;
        //forking caves
        if (random == 0 || random == 1){
            printf("\nThe oasis leads to a plateau and another canyon. Where would you like to go? [plateau/ canyon]: ");
            fgets(input, 100, stdin);
            while(strcmp(input,"canyon\n")!=0 && strcmp(input,"plateau\n")!=0){
                printf("Invalid choice. Valid choices: [canyon/ plateau]\n\t");
                fgets(input, 100, stdin);
            }
            if (strcmp(input,"plateau\n")==0) goto plateau;
            if (strcmp(input,"canyon\n")==0) goto canyon;
        }
        //dead end
        else if (random == 2){
            printf("\nYou have reached a dead end. You may move to the right or left. [r/ l]: ");
            fgets(input, 10, stdin);
            goto oasis;
        }
        //battles monster
        else{
          struct monster *MONSTER = randomMonster(PLAYER->level);
          x = battleMonster(MONSTER, PLAYER, fd);
          if (x==1) return 1;
          goto oasis;

        }
    return x;
}
