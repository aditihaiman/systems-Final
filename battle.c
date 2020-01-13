#include "players.h"

int main(){
//    printf("A\n");
//    int x;
//    x = execlp("chmod", "chmod", "755", "battle.sh");
//    //int exit_status = system("open -a Terminal \"`pwd`\"");
//    printf("x: %d\n, errno: %d, error: %s", x, errno, strerror(errno));
//    x = execlp("ls", "ls");
//    printf("x: %d\n", x);

    //battleMonsters();
    
    system("chmod 755 battle.sh");
    system("./battle.sh");
    
    
}
