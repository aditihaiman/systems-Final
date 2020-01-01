# systems-Final

Group Members: Aditi Haiman, Sowjanya Sritharasarma

Project Description:
- Our project is a step by step story-based game
- The player can choose from several different characters that have different strengths and abilities. 
- Based on the story, the player will have to battle and defeat different enemies (including solving riddles)
- The player can gain experience and power by winning battles and defeating increasingly harder enemies.
- The player can make decisions that lead to different game endings. Elements of randomness will also lead to different endings (eg. rolling dice during a battle to determine damage)

User Interface:
- The player gets to choose a character. Each character has a different storyline.
- In order to move the story forward, the user will have to make decisions for the character regarding where to go, how to confront other characters, etc. The user will get prompts such as “There is a door to your left and an open hallway to your right. Where would you like to go? [left /right]” The user will input their desired command, and the character will act accordingly.
- When fighting a monster, a new window/terminal process will open temporarily.
- The stories will sometimes have riddles that the user must answer in order to move forward. Here’s an example:
-       You meet a forest troll who refuses your passage unless you can answer his three riddles. If you pass, the troll will let you through. If you fail, the troll will eat you.
-       Riddle #1: In what year did Christmas Day and New Year's Day fall in the same year?
   -         Answer: every year

- Some monsters can only be defeated by rolling a twenty-sided dice that will determine how much damage you will do to the monster’s health. You and the monster will deal the dice until one of you dies. If you succeed, you will regain your health and immediately advance forward in the storyline.
- Whenever the user interacts with a monster, if they defeat it, they will automatically move forward in the story. The user will face a monster randomly in the game. The user will also find certain objects such as a sword or a bag of coins, which can be used as powerups when they are facing monsters.

Technical Design:
- Working with files
-       Information about characters will be stored in files that can be read/opened/accessed by the player
-       This will involve opening, reading, and writing to files
- Allocating memory
-       Each type of character that the player can choose will be a different struct with different variables depending on the character that determine its abilities (pointers/variables/structs for each type of character)
-       Example: health stat, player level, strength/amount of damage done, character name
- Processes/Forking
-       We will use forking to complete subprocesses (similar to the how shell commands were implemented in the last project) - for example, if the player uses certain commands we will fork to create a subprocess to execute that command and then return to the primary gameplay
-       These commands can include attacking enemies, getting information about current health/level
- Pipes
-       We would use pipes for communication between two main processes. When the player engages with an enemy, we would have a new process open with a new terminal window where the player could simultaneously view their stats (health, damage) in one window and the battle with the enemy in the other window.
- Signals (a minor part of our project)
-       If there are segmentation faults or other unexpected errors, we will want to catch them so as not to disrupt the gameplay
- Libraries: We might use the Ncurses library for having text/images/moving objects in the terminal

An Example Storyline
- Choose your character: [Villager]
-       “Oh no, your town was destroyed and everyone died. You have to leave your town to defeat the enemies in the surrounding area. Would you like to go through the forest or the desert?”
- If [desert] = You’re not prepared, smarty pants. You’re out of water. You die of thirst.
- If [forest] = You meet a forest troll who refuses your passage unless you can answer his three riddles. If you pass, you have defeated the troll and will move forward in the story. If you fail, the troll eats you.
-       “Congratulations. You passed all three riddles! There is a cave to your left, a lake in front, and more trees to your right. Where would you like to go?” [left / front / right]
-       If [front (lake)] = You meet a siren and you must fight her otherwise you will fall under her spell. Roll a dice (twenty sided) to see how much damage you do. You and the siren keep dealing random amounts of damage until one of you wins.
-           You die: return to start of game
-           You win: Congratulations, you have gained [] from the siren. You will advance forward in the game and must defeat four more monsters in order to win the game.

Timeline:

- By January 8: Have the basic outline for the different types of characters/enemies done. Finish the shell/model of our basic gameplay. We will have the backbone of our program finished (including memory allocation and file handling) so that we can start working on having a more complete storyline and interactions with enemies. 
- By January 11/12: Implement player vs. enemy interactions, including having a separate process open up and piping to have those processes communicate.
- By January 16: Finish debugging and final testing.
