#!/usr/bin/python3

def cal_fuel(i: int,l: list):
    s = 0
    for x in l:
        s += abs(i - x)
    return s

l = input()
l = [int(x) for x in l.split(",")]

min_fuel = cal_fuel(min(l), l)
for i in range(min(l)+1, max(l)):
    totalfuel = cal_fuel(i,l)
    if( totalfuel < min_fuel):
        min_fuel = totalfuel

print(min_fuel)
