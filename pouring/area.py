#!/usr/bin/env python

"""
For each bar in the array, the amount of water that can be held in
that location is the minimum of the maximum heights of all the bars
that come before and the maximum heights of all the bars that come
after that location in the area minus the bar itself.
"""

def find_maximum_left_linear(input_array):
    max_array = [input_array[0]] * len(input_array)
    for k in xrange(1, len(input_array)):
        max_array[k] = max(max_array[k-1], input_array[k])
    return max_array

def find_maximum_right_linear(input_array):
    max_array = [input_array[-1]] * len(input_array)
    for k in xrange(len(input_array)-2,-1,-1):
        max_array[k] = max(max_array[k+1], input_array[k])
    return max_array

def find_area(input_array):
    max_left = find_maximum_left_linear(input_array)
    max_right = find_maximum_right_linear(input_array)
    heights = list() # not necessary
    area = 0
    for ind, val in enumerate(input_array):
        # we add the max comparison, because the height of the water can
        # not be negative
        height = max(min(max_left[ind], max_right[ind]) - val,0)
        heights.append(height)
        area = area + height
    return area

def main():
    pass

if __name__ == "__main__":
    main()


    
