# systems-Final

Project Name: Cellars and Serpents

Project Members: Sowjanya Sritharasarma and Aditi Haiman (both pd 10)

Project Description:
  - Our project is a step by step story-based game (like a simplified version of Dungeons and Dragons).
  - The player is embodying the character of villager whose mission is to gain the experience needed to defeat the monsters invading their village. The player will have to battle enemies in the surrounding area (in either the forest or the desert) until they are strong enough to return and have a chance at defeating the monsters in their village.
  - The player will be prompted to move along the story by either by choosing which paths to take (such as cave, lake, oasis, etc.), and by defeating the enemies they encounter. Most of the monsters they encounter they must incur damage onto, which is determined randomly. The player has a limit to how much damage they can do to a monster, and the monster will also have this limit. The player and the monster each get a turn where they do a random number of damage to each other's health until one them has a health stat of 0 or below. The troll is an exception to this. The troll will ask the player three riddles, two of which the player must answer correctly in order to defeat him. (see bug 2)
  - Whenever the player gains enough experience, they will level up and will encounter harder monsters until they reach the last level, in which they return to the village to defeat the final four monsters. Each time the player defeats a monster, they will regain their health so as to face the next bigger monster.
  - A separate window in the terminal will open up once the game has started which will display player stats (including health, damage, level, etc.) for the entirety of the game. The stats will change whenever the player's health, experience, or level changes.

Technical Design:
    Working with files
    - The player has the option to open a file that includes the instructions to the game before they begin playing.

    Allocating memory
    - The player is created as a struct with variables that determine their name, game level, health stat, amount of damage they can do, and experience points.
    - The monsters are also created with structs. Instead of a variable for a name like the player struct, the monster struct has a type variable which is the identifying characteristic of each type of monster. They also have variables indicating their status (defeated or alive), game level (how hard are they to defeat), health, and damage (how much they can do to the player).

    Processes/Forking
    - We used the function system() in order to clear the the terminal after the player defeats a monster in order to decrease clutter and make the terminal easier to read. We also used it to open a new terminal window on linux machines, which will be used to convey player stats.

    Pipes
    - We used pipes between the two terminal windows. One of the windows is where the user directly interacts with the game and can input decisions. The second terminal window is used to display information about the player (stats such as health, experience, etc.) and is constantly updating as the player battles with the monsters. Each time a monster does damage to the player, and each time the player defeats a monster and gains experience or levels up, etc., the stat terminal window updates and displays the current stats of the player.


Instructions:
  - When you first begin your game, you will be prompted to create a name for your player. You will then to be told the basic premise of the storyline and given the choice of either the forest or the desert as your main setting.
  - Throughout this game, you will be prompted to make decisions for your player until you reach the end of the game. Here is an example format:
      You are in a cave that leads to a muddy path and a lake. Where would you like to go? [path/ lake]:
  - Choose and type in one of the choices to move forward. (ex. path)
  - If you encounter a troll, remember to answer all words in lower case letters, and all numbers in numerical digits.
  - You will encounter many monsters along your journey. Although most of the battles you must engage in are based on luck, you are able to give yourself some advantage by keeping your health as high as you can. After you've won a battle with a monster, if your health is lower than its original number, you can decide to transfer the points you earned in experience and to your health points.
  - There are four levels to this game, and in each subsequent level you will encounter harder enemies that you must defeat to advance. Once you have reached the last level of the game, you may return to your starting point to battle the last four monsters that will be waiting for you.


Other Information/Known Bugs:
  1. When asking for an input, sometimes the fgets() function fails to work and entirely skips over waiting for the user to enter an input. Instead it goes directly to the next part of the program. This only happens sometimes, and usually does not affect the game's outcome.
  2. The fgets() function also does not work properly when encountering the troll. When the answer to the troll's riddles are words, the function always omits the very first letter of the word, causing it to be read as incorrect even if it is the right answer.
  3. Sometimes, the input provided by the user is changed by replacing the first character with a space (we think this is somehow an issue with fgets() as well). This impacts the ability of the program to continue because the input doesn't match what would advance the game.
  4. We recommend not using Control C to exit the program because the separate process running in the window (that displays player stats) will enter an infinite loop. Instead, first exit the other process before exiting the main process.
  5. Sometimes, it will seem that the game is lagging and is slow to put up the next few messages in the game. This is not a bug. Whenever an excessive amount of text is displayed on screen that does not prompt an input from the player, the program sleeps in order to let the player read the text.
