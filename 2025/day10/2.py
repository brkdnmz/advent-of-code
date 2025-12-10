from scipy.optimize import linprog

# forced to use python for library access
# educative but not fun

with open("1.txt") as f:
    lines = f.read().splitlines()

ans = 0
for line in lines:
    parts = line.split(" ")
    buttons = parts[1:-1]
    target = parts[-1]
    target = list(map(int, target[1:-1].split(",")))
    Aeq = [[0] * len(buttons) for _ in range(len(target))]
    beq = []
    for button in buttons:
        machines = list(map(int, button[1:-1].split(",")))
        for machine in machines:
            Aeq[machine][buttons.index(button)] = 1

    beq = target
    c = [1] * len(buttons)
    bounds = [(0, None)] * len(buttons)
    res = linprog(c, A_eq=Aeq, b_eq=beq, bounds=bounds, integrality=True)

    ans += int(res.fun)

print(ans)
