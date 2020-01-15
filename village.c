#include "players.h"

int village(struct player *player){
    printf("\nWelcome back to the village. Four more monsters await you. They will come at you one by one until you have defeated all of them. Whenever you're ready, type 'go' to beging your mission. ");
    char input[100];
    fgets(input, 10, stdin);
    while(strcmp(input,"go\n")!=0){
        printf("Calm your nerves, soldier. Try again. [go]\n\t");
        fgets(input, 10, stdin);
    }
    int x = 0;
    x = battleMonster(createMedusa(), player);
    printf("Done\n");
    if (x == 1) return 1;
    x = battleMonster(createVoldemort(), player);
    if (x == 1) return 1;
    x = battleMonster(createDarthVader(), player);
    if (x == 1) return 1;
    x = battleMonster(createPalpatine(), player);
    if (x == 1) return 1;
    return 0;
}
