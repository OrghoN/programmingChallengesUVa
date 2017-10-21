#!/usr/bin/env python3

import sys

global cache
cache = [0] * 1000000

def cyclesCache(number):
    cycles = 1
    numbers = []
    while number > 1:
        if cache[number] != 0:
            for index, num in enumerate(numbers):
                cache[num] = cache[number] + len(numbers) - index + 1
            return cache[number]
        numbers.append(number)
        cycles+=1
        if number % 2 ==0:
            number = number //2
        else:
            number = (number*3) + 1
    numbers.append(1)
    for index, num in enumerate(numbers):
        cache[num] = cycles - index
    return cycles

def cycles(number):
    cycles = 1
    while number >1:
        cycles+=1
        if number % 2 ==0:
            number = number //2
        else:
            number = ((number*3) + 1)//2
            cycles+=1
    return cycles


def cyclesRange(num1, num2):
    cycleLengths = []

    if num1 > num2:
        start = num2
        stop = num1
    elif num2>num1:
        start = num1
        stop = num2
    else:
        return cycles(num1)

    for i in range(start,stop):
        cycleLengths.append(cycles(i))

    return max(cycleLengths)
    # return (cycleLengths)

for i in sys.stdin:
    numbers = i.split()
    numbers = list(map(int, numbers))
    print(numbers[0],numbers[1], cyclesRange(numbers[0], numbers[1]))
#     print(cyclesRange(numbers[0], numbers[1]))
