# yes python cuz its cool with big ints 🐍

import sys

# https://stackoverflow.com/questions/16582194/python-version-of-freopen
sys.stdin = open("day11.txt", "r")
a = list(map(int, input().split()))

itr = 25
while itr:
    itr -= 1
    na = []
    for x in a:
        if not x:
            na.append(1)
        elif len(str(x)) % 2:
            na.append(x * 2024)
        else:
            x = str(x)
            l, r = x[: len(x) // 2], x[len(x) // 2 :].lstrip("0")
            if not len(r):
                r = "0"
            na.append(int(l))
            na.append(int(r))
    a = na

print(len(a))
