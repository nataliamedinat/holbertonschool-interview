#!/usr/bin/python3
''' Program to solve the NQueens problem '''
from sys import argv


def printBoard(board, size):
    ''' Function to print all the posible solutions '''
    res = []
    for i in range(size):
        for j in range(size):
            if board[i][j] == 1:
                res.append([i, j])
    print(res)


def validPosition(board, row, col, size):
    ''' Check if a position is able '''
    for i in range(col):
        if (board[row][i]):
            return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if(board[i][j]):
            return False
        i -= 1
        j -= 1
    i = row
    j = col
    while j >= 0 and i < size:
        if(board[i][j]):
            return False
        i = i + 1
        j = j - 1
    return True


def nQueen(board, col, size):
    ''' Place the posible position on a nQueen Board '''
    if (col == size):
        printBoard(board, size)
        return True

    res = False
    for i in range(size):
        if (validPosition(board, i, col, size)):
            board[i][col] = 1
            res = nQueen(board, col + 1, size) or res
            board[i][col] = 0
    return res


if __name__ == '__main__':
    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if not argv[1].isnumeric():
        print("N must be a number")
        exit(1)
    size = int(argv[1])
    if size < 4:
        print("N must be at least 4")
        exit(1)
    board = [[0 for j in range(size)] for i in range(size)]
    res = nQueen(board, 0, size)
