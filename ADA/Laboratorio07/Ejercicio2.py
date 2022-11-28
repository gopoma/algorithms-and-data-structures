from math import floor, ceil
from ortools.linear_solver import pywraplp

def dfs(current, level, base, L, patterns):
    if level < len(base):
        for i in range(len(base)):
            current.append(base[i])

            partial = [*current]
            partial.sort()
            if sum(partial) <= L and L - sum(partial) < base[0] and not patterns.count(partial):
                patterns.append(partial)

            dfs(current, level+1, base, L, patterns)
            current.pop()

def generateMatrix(amountRows, amountColumns, initializer):
    mtx = []
    for i in range(amountRows):
        mtx.append([])
        for j in range(amountColumns):
            mtx[i].append(initializer)
    return mtx

def showMatrix(mtx):
    for i in range(len(mtx)):
        for j in range(len(mtx[i])):
            print(mtx[i][j], end=" ")
        print()

def solve(dp, q, patterns):
    solver = pywraplp.Solver.CreateSolver("GLOP")
    if not solver:
        return

    infinity = solver.infinity()
    vv = [solver.NumVar(0, infinity, f"x{j+1}") for j in range(len(dp[0]))]

    for i in range(len(dp)-1):
        solver.Add(sum([dp[i][j]*vv[j] for j in range(len(dp[i]))]) >= q[i])

    goal = solver.Objective()
    for j in range(len(dp[0])):
        goal.SetCoefficient(vv[j], dp[n][j])
    goal.SetMinimization()

    solver.Solve()

    solutions = [ceil(v.solution_value()) for v in vv]
    print("Frecuencia de los Patrones de Corte:")
    for j in range(len(solutions)):
        print(f"Patrón: {patterns[j]}")
        print(f"Frecuencia: {solutions[j]}")
        print()

    print()
    print(f"Desperdicio Mínimo: {ceil(solver.Objective().Value())}")

if __name__ == "__main__":
    L = 12
    n = 4
    d = [7, 8, 3, 5]
    q = [200, 85, 100, 150]

    print("Datos del problema:")
    print(f"L {L}")
    print(f"n: {n}")
    print(f"d (Dimensiones [m]): {d}")
    print(f"q (Demandas): {q}")
    print()
    print()

    for i in range(n):
        for j in range(n-i-1):
            if d[j] > d[j+1]:
                tmp = d[j]
                d[j] = d[j+1]
                d[j+1] = tmp

                tmp = q[j]
                q[j] = q[j+1]
                q[j+1] = tmp
    
    levels = floor(L/d[0])
    patterns = []
    dfs([], 0, d, L, patterns)

    dp = generateMatrix(n+1, len(patterns), 0)
    for j in range(len(patterns)):
        cc = 0
        for i in range(n):
            for k in range(len(patterns[j])):
                if d[i] == patterns[j][k]:
                    dp[i][j] = dp[i][j] + 1
    
    for j in range(len(patterns)):
        dp[n][j] = L - sum(patterns[j])
    
    solve(dp, q, patterns)