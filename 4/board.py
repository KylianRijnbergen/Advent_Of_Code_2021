import pprint

pp = pprint.PrettyPrinter(indent=4)
class Board:
    __new_id = 0
    
    def __init__(self, board_arr):
        self.board = board_arr
        self.id = Board.__new_id
        Board.__new_id += 1
        
        
    def mark(self, number):
        for lineid, line in enumerate(self.board):
            if number in line:
                self.board[lineid][line.index(number)] = "X"
    
    def check_bingo(self):
        #Check lines
        for line in self.board:
            if set(line) == set("X"):
                return True
            
        #Check columns
        for col in range(len(self.board[0])):
            coldigs = []
            for line in range(len(self.board)):
                coldigs.append(self.board[line][col])
            if set(coldigs) == set("X"):
                return True
        return False
    
    def get_score(self):
        digits = [digit for line in self.board for digit in line]
        tot = 0
        for digit in digits:
            if digit != "X":
                tot += int(digit)
        return tot
            
    def show(self):
        pp.pprint(self.board)
        
        
if __name__ == "__main__":
    arr = [[1, 3, 5], [2, 10, 4], [11, 12, 13]]
    b1 = Board(arr)
    
    b1.mark(1)
    b1.mark(3)
    b1.mark(5)
    print(b1.check_bingo())
    print(b1.get_score())
        