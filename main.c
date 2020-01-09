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

void battleMonster(struct monster*, struct player*){
    if (strcmp(monster->type, "troll")==0)
        battleTroll(struct monster*, struct player*);
    if (strcmp(monster->type, "siren")==0)
        battleSiren(struct monster*, struct player*);
    else battle(struct monster*, struct player*);
}

void battleTroll(struct monster*, struct player*){
  //You meet a forest troll who refuses your passage unless you can answer his three riddles. Would you like to answer them or run away? [answer] or [run]
  printf("%s", moster->initialmessage);
  fgetc(stdin);
  fgets(input, 7, stdin);
  if (strcmp(input,"answer")==0) {
      int x = 1;
      while (x <= 3){
          if (player->health == 0) deafeated(struct monster*, stuct player*);
          int damage = 0;
          printf("Riddle #%d: [0]\n", x);
          fgetc(stdin);
          fgets(input, 3, stdin);
          if (intput[0] == '0'){
              printf("You answered correctly. The troll is impressed.\n")
          }
          else{
              printf("You answered wrong. Your health is now %d.\n", player->health);
              player->health = player->health - (monster->damage + damage);
              damage += monster->damage;
          }
          x++;
      }
      printf("You have answered all of the riddles correctly! The troll will let you pass. You have gained %d points in experience!\n", monster->damage);
      void victory(struct monster*, struct player*);
      return 0;
  }
  if (strcmp(input,"run\n")==0) {
      printf("You try to run but the troll catches up to you and eats you whole.\n");
      return 0;
  }

}


void deafeated(struct monster*, struct player*){
    printf(monster->defeatmessage);
    goto end;
}

void victory(struct monster*, struct player*){
    player->experience += monster->damage;
    printf(monster->victorymessage);
}
