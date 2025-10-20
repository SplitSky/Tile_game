# Tile_game
C++ and Rust Solution to a tile based numerical game

The problem in question:
1. Suppose you have 9 tiles. They are numbered 1 to 9.
The tiles: [1,2,3,4,5,6,7,8,9]
The tiles can be flipped or not flipped. Once the tile is flipped it becomes unavaiable to be flipped later
2. You roll 2d6 and obtain a result which is a number binomially distributed between 2 and 12.
3. You choose the tiles to be flipped in such a way that they add up to that number.
Suppose you roll 3+4 = 7.
You can then flip these combinations:
Combination 1: 7
Combination 2: 6,1
Combination 3: 5,2
Combination 4: 4,3
Suppose you choose combination 3. This leaves you with these tiles available for next round:
Tiles available: [1,2,5,6,7,8,9]

You repeat steps 2-3 until you either: flip all tiles in which case you obtain the scope of 0 or you cannot make
the number from the tiles in which case you sum the tiles and add this to your score.

The proble is:
1. What is the most optimal strategy to obtain the lowest score after 10 rounds
2. What is the most optimal strategy to obtain the lowest score after N rounds
