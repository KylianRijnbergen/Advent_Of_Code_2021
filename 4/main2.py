from board import Board

#Store bingo boards in list
boards = []
bingo_order = []
board_scores = []

if __name__ == "__main__":
    #Open file
    f = open("input.txt", "r")
    
    #Initialize empty vars    
    line_id = 0
    drawing_numbers = []
    curr_board = []
    
    #Loop over all lines
    for line in f.readlines():
        #First line is drawn numbers
        if line_id == 0:
            drawing_numbers = line.replace("\n", "").split(",")
        
        #Every 6 lines, a new board is created
        if (line_id - 1) % 6 == 0:
            curr_board = []
        else: 
            curr_board.append(line.replace("\n", "").split())
        
        #If a board is complete, create an instance of class Board
        if len(curr_board) == 5:
            boards.append(Board(curr_board))
        
        #Increment line id
        line_id += 1
        
    #Close file
    f.close()    
    
    for number in drawing_numbers:
        for board in boards:
            board.mark(number)
            if board.check_bingo():
                if board.id not in bingo_order:
                    bingo_order.append(board.id)
                    board_scores.append(board.get_score() * int(number))
    
    print(bingo_order[-1], board_scores[-1])
    