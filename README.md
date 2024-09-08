A classic tic tac toe game, it has only a single player mode, and two difficulities. 
On easy You play against a random number generator, on hard you play against a minimaxing algorithm. 
The game keeps track of Victories, Losses and Draws, while it's running.

Compilation order
Map.cpp->Ai.cpp->Helpers.cpp->main.cpp

"Aggregator" contains all of the used global variables and libraries.

"Map" Handles the game map, and the logic map (this is a 2d array of pointers that changes certain positions on the game map)

"AI" takes care of movements (Both by the player and the CPU), checks for viktory conditions and updates the map

"Helpers" contain functions whiuch help with the handling of user input.

And main is where all of it comes together.
