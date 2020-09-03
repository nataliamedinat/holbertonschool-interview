#!/usr/bin/python3
"""0_rain"""

def rain(walls):
    """rain function"""
    if type(walls) is not list:
        return 0
    if len(walls) is 0:
        return 0
    # To store the maximum water 
    # that can be stored 
    res = 0
    n = len(walls)
     
    # For every element of the array 
    for i in range(1, n - 1) : 
         
        # Find the maximum element on its left 
        left = arr[i]; 
        for j in range(i) :
            left = max(left, arr[j]); 
         
        # Find the maximum element on its right 
        right = arr[i]; 
         
        for j in range(i + 1 , n) : 
            right = max(right, arr[j]);
             
        # Update the maximum water
        res = res + (min(left, right) - arr[i]); 
 
    return res; 
