def cantMakeScore(board,score):
    index = 0
    sum = 0
    for i in range(0,len(board)-1):
        if board[i] == 0:
            sum += (i+1)
    return not (sum > score)
