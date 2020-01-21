# systems-Final

Project Name: Cellars and Serpents

Project Members: Sowjan Sritharasarma and Aditi Haiman (both pd 10)

Project Description:
  - Our project is a step by step story-based game (like a simplified version of Dungeons and Dragons)
  - Based on the story, the player will have to battle and defeat different enemies (including solving riddles)
  - The player can gain experience by winning battles and defeating increasingly harder enemies.
  - The player can make decisions that lead to different game endings. Elements of randomness will also lead to different endings (eg. randomly determining how much damage is done during a battle)
  - In order to move the story forward, the user will have to make decisions for the character regarding where to go, how to confront other characters, etc. The user will get prompts such as “There is a door to your left and an open hallway to your right. Where would you like to go? [left /right]” The user will input their desired command, and the character will act accordingly.
  - A separate window in the terminal will open up once the game has started which will display player stats (including health, damage, level, etc.) throughout the game
  - The stories will sometimes have riddles that the user must answer in order to move forward. Here’s an example:
    - You meet a forest troll who refuses your passage unless you can answer his three riddles. If you pass, the troll will let you through. If you fail, the troll will eat you.
    - Riddle #1: In what year did Christmas Day and New Year's Day fall in the same year?
    - Answer: every year

Instructions:
  - When you first begin your game, you will be prompted for a name for your player.
  - Once you've chosen a name for your player, you will be given the choice of either going through the forest or the desert. The two settings yield different storylines so choose wisely.
  
  - Throughout this game, you will be prompted to make decisions for your player until you reach the end of the game. You will encounter many monsters along your journey. The more monsters you defeat, the more experienced you become, and therefore the more you are able to move forward in the story. Remember, if you encounter more and more monsters, it means you're heading in the right direction. There are four levels to this game, and in each subsequent level you will encounter harder enemies that you must defeat to advance.

  - Once you have reached the last level of the game, you may return to your starting point to battle the last four monsters that will be waiting for you.

Other Information/Known Bugs:
  - When asking for an input, sometimes the fgets() function fails to work and entirely skips over waiting for the user to enter an input. Instead it goes directly to the next part of the program.
  - Sometimes, the input provided by the user is changed by replacing the first character with a space (we think this is somehow an issue with fgets() as well). This impacts the ability of the program to continue because the input doesn't match what would advance the game.
  - We recommend not using Control C to exit the program because the separate process running in the window (that displays player stats) will enter an infinite loop. Instead, first exit the other process before exiting the main process.
