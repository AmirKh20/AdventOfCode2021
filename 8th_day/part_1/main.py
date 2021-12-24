#!/usr/bin/python3

f = open("input.txt")
sum_num = 0
for line in f:
    l = line.split(" | ")[1].split()
    for x in l:
        length = len(x)
        if length == 2 or length == 3 or length == 7 or length == 4:
            sum_num += 1

print(sum_num)
