#!/usr/bin/python3

""" Solution of the pronlem"""


def canUnlockAll(boxes):
    """ Prototype """

    key = [0]

    for trav in key:
        for i in boxes[trav]:
            if (i not in key and i < len(boxes)):
                key.append(i)

    if (len(key) == len(boxes)):
        return True
    else:
        return False
