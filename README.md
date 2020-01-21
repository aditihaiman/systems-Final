# systems-Final

Project Name: Cellars and Serpents
Project Members: Sowjan Sritharasarma and Aditi Haiman (both pd 10)

Project Description:


Instructions:
  - When you first begin your game, you will be prompted for a name for your player.
  - Once you've chosen a name for your player, you will be given the choice of either going through the forest or the desert. The two settings yield different storylines so choose wisely.
  
  - Throughout this game, you will be prompted to make decisions for your player until you reach the end of the game. You will encounter many monsters along your journey. The more monsters you defeat, the more experienced you become, and therefore the more you are able to move forward in the story. Remember, if you encounter more and more monsters, it means you're heading in the right direction. There are four levels to this game, and in each subsequent level you will encounter harder enemies that you must defeat to advance.

  - Once you have reached the last level of the game, you may return to your starting point to battle the last four monsters that will be waiting for you.

Known Bugs:
  - When asking for an input, sometimes the fgets() function fails to work and entirely skips over waiting for the user to enter an input. Instead it goes directly to the next part of the program.
  - Sometimes, the input provided by the user is changed by replacing the first character with a space (we think this is somehow an issue with fgets() as well). This impacts the ability of the program to continue because the input doesn't match what would advance the game.
