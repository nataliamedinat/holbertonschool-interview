#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    """Minimum Operations"""
    ans = 0
    oper = 2
    while (oper <= n):
        while (n % oper == 0):
            ans += oper
            n = n / oper
        oper += 1
    return ans