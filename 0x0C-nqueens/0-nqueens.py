#!/usr/bin/python3

""" Solve the NQueens problem """

from sys import argv


def printPositions(board, length):
    """ Print the posible solutions """

    solution = []

    for x in range(length):
        for y in range(length):
            if board[x][y] == 1:
                solution.append([x, y])
    print(solution)


def ableSpace(board, row, col, length):
    """ Check if a position is able """

    for x in range(col):
        if (board[row][x]):
            return False

    x = row
    y = col

    while x >= 0 and y >= 0:
        if(board[x][y]):
            return False
        x -= 1
        y -= 1

    x = row
    y = col

    while y >= 0 and x < length:
        if(board[x][y]):
            return False
        x = x + 1
        y = y - 1

    return True


def nQueenPlace(board, col, size):

    ''' Place the posible nQueen's position in a Board '''

    if (col == length):
        printPositions(board, length)
        return True

    response = False

    for x in range(length):
        if (ableSpace(board, x, col, length)):
            board[x][col] = 1
            response = nQueenPlace(board, col + 1, length) or response
            board[x][col] = 0

    return response

if __name__ == '__main__':

    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    if not argv[1].isnumeric():
        print("N must be a number")
        exit(1)

    length = int(argv[1])

    if length < 4:
        print("N must be at least 4")
        exit(1)

    board = [[0 for y in range(length)] for x in range(length)]
    response = nQueenPlace(board, 0, length)
