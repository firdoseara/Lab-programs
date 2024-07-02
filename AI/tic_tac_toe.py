import sys
def print_board(board):
    for row in board:
        print("|".join(row))
        print("-"*5)
def check_winner(board,player):
    for i in range(3):
        if all(board[i][j]==player for j in range(3)):
            return True
        if all(board[j][i]==player for j in range(3)):
            return True
    if all(board[i][i]==player for i in range(3)):
        return True
    if all(board[i][2-i]==player for i in range(3)):
        return True
    return False
def board_full(board):
    return all(board[i][j]!=" " for i in range(3) for j in range(3))
def make_move(board,player,row,col):
    if board[row][col]==" ":
        board[row][col]=player
        return True
    else:
        return False
def play_game():
    board=[[" "for _ in range(3)]for _ in range(3)]
    current_player="X"
    while True:
        print_board(board)
        row=int(input("Enter row(0,1,or 2)for player {}:".format(current_player)))
        col=int(input("Enter column(0,1,or 2)for player {}:".format(current_player)))
        if row<0 or row>2 or col<0 or col>2:
            print("Invalid input! Row and column must be between 0 and 2.")
            continue
        if not make_move(board,current_player,row,col):
            print("Invalid move!That position is already taken.")
            continue
        if check_winner(board,current_player):
            print_board(board)
            print("Player {} wins!".format(current_player))
            break
        if board_full(board):
            print_board(board)
            print("Its a tie!")
            break
        current_player="O"if current_player=="X"else"X"
if __name__=="__main__":
    play_game()
