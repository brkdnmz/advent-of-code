# way better optimization than i thought

import sys

sys.stdin = open("day11.txt", "r")
a = list(map(int, input().split()))

mem = {}


def f(x: int, cnt: int) -> int:
    if not cnt:
        return 1
    if (x, cnt) in mem:
        return mem[(x, cnt)]
    if not x:
        mem[(x, cnt)] = f(1, cnt - 1)
    elif len(str(x)) % 2:
        mem[(x, cnt)] = f(x * 2024, cnt - 1)
    else:
        x_str = str(x)
        l, r = x_str[: len(x_str) // 2], x_str[len(x_str) // 2 :].lstrip("0")
        if not len(r):
            r = "0"

        mem[(x, cnt)] = f(int(l), cnt - 1) + f(int(r), cnt - 1)

    return mem[(x, cnt)]


itr = 75
ans = sum(f(x, itr) for x in a)

print(ans)
