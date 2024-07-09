import random
#flip = 1, notfliped = 0
#flip strat 1
def fliptile(flip,board):
    current_index= len(board) - 1
    tempscore = flip
    while current_index > 0:
        #flip logic
        if tempscore >= current_index + 1 and board[current_index] == 0:
            tempscore = tempscore - (current_index + 1)
            board[current_index] = 1
        current_index -= 1
    return board
def sumBoard(board):
    sum = 0
    sum2 = 0
    for i in range(0,len(board),1):
        sum += board[i]
        if board[i] == 0:
            sum2 += (i+1)
    return sum, sum2
def cantMakeScore(board,score):
    index = 0
    sum = 0
    for i in range(0,len(board)):
        if board[i] == 0:
            sum += (i+1)
    return not (sum > score)
def canflip(board,score):
    canflip = True
    # condition 1 out of tiles
    sum,sum2 = sumBoard(board)
    if sum == len(board):
        canflip = False
    # condition 2 cant reduce score
    if cantMakeScore(board,score):
        canflip = False
    return canflip
def playturn():
    board = [0,0,0,0,0,0,0,0,0]
    playerscore = 0
    roll = 0
    #print(board)
    #print(roll)
    #print(fliptile(roll,board)
    while canflip(board,roll):
        roll = random.randint(1,6) + random.randint(1,6)
        board = fliptile(roll,board)
    sum,playerscore = sumBoard(board)
    return playerscore
def main():
    print(playturn())



main()

