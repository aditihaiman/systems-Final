#include "players.h"

int battleFinalMonsters(struct monster* monster, struct player* player, int fd){ //returns 0 if player wins, 1 if player loses
    pipeForBattle("w", player, fd);
    char input[100];
    int output = 0;
    srand(time(NULL));
    printf("\nYou have encountered a %s. The %s has %d health and is capable of doing %d damage. You must defeat the %s before you can move on!\n", monster->type, monster->type, monster->health, monster->damage, monster->type);
    int turn = 0; //0 means it is players turn
    while (player->health > 0 && monster->health > 0) {
        if (turn == 0){
            printf("\nPress \"r\" to roll a dice to determine how much damage you do to the %s. You are capable of doing up to %d damage. ", monster->type, player->damage);
            if (output!=0) fgetc(stdin);
            fgets(input, 3, stdin);
            if (input[0]=='r'){
                int damage = rand() % player->damage;
                monster->health -= damage;
                printf("\nYou have done %d damage. The %s is now at %d health.\n", damage, monster->type, monster->health);
            }
        }
        if (turn == 1) {
            int damage = rand() % monster->damage;
            player->health -= damage;
            printf("\nThe %s has dealt %d damage to you. You are now at %d health.\n", monster->type, damage, player->health);
	          pipeForBattle("w", player, fd);
        }
        if (turn == 0) turn = 1;
        else turn = 0;
    }
    if (monster->health <= 0){
        if (strcmp(monster->type,"palpatine")==0) goto ending;
        printf("Congratulations! You have defeated the %s. Your health is restored to %d!\n\n", monster->type, player->baseHealth);
        player->health = player->baseHealth;
        //player->health += atoi(input);
        //printf("Your health is now at %d and your experience is at %d.\n\n", player->health, player->experience);
	      pipeForBattle("w", player, fd);
        return 0;
    }
    if (player->health <= 0){
        sleep(2);
        system("clear");
        printf("You have been defeated by the %s. Alas, after all your hard work, you could not save your village. Be reborn and try again.\n", monster->type);
        return 1;
    }
    ending:
        system("clear");
        printf("Congratulations! You have defeated all of the monsters and saved your village! You are named the village's defender, and the people love you. Hurrah! Your mission is now over. Take some rest and enjoy your glory, soldier.\n");
        player->health = 0;
        pipeForBattle("w", player, fd);
        return 1;
}


int village(struct player *player, int fd){
    printf("\nWelcome back to the village. Four more monsters await you. They will come at you one by one until you have defeated all of them. Whenever you're ready, type 'go' to begin your mission. ");
    system("clear");
    char input[100];
    fgets(input, 10, stdin);
    while(strcmp(input,"go\n")!=0){
        printf("Calm your nerves, soldier. Try again. [go]\n\t");
        fgets(input, 10, stdin);
    }
    int x = 0;
    x = battleFinalMonsters(createMedusa(), player, fd);
    if (x == 1) return 1;
    system("clear");
    x = battleFinalMonsters(createVoldemort(), player, fd);
    if (x == 1) return 1;
    system("clear");
    x = battleFinalMonsters(createDarthVader(), player, fd);
    if (x == 1) return 1;
    system("clear");
    x = battleFinalMonsters(createPalpatine(), player, fd);
    if (x == 1) return 1;
    return 0;
}
