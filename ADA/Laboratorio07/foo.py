from ortools.linear_solver import pywraplp
from ortools.init import pywrapinit


def main():
    # Create the linear solver with the GLOP backend.
    solver = pywraplp.Solver.CreateSolver('GLOP')
    if not solver:
        return

    # Create the variables x and y.
    vv = [solver.NumVar(0, 1, 'x'), solver.NumVar(0, 2, 'y')]

    print('Number of variables =', solver.NumVariables())

    # Create a linear constraint, 0 <= x + y <= 2.
    ct = solver.Constraint(0, 2, 'ct')
    ct.SetCoefficient(vv[0], 1)
    ct.SetCoefficient(vv[1], 1)

    print('Number of constraints =', solver.NumConstraints())

    # Create the objective function, 3 * x + y.
    objective = solver.Objective()
    objective.SetCoefficient(vv[0], 3)
    objective.SetCoefficient(vv[1], 1)
    objective.SetMaximization()

    solver.Solve()

    for x in vv:
        print(f"{x} = {x.solution_value()}")

if __name__ == '__main__':
    pywrapinit.CppBridge.InitLogging('basic_example.py')
    cpp_flags = pywrapinit.CppFlags()
    cpp_flags.logtostderr = True
    cpp_flags.log_prefix = False
    pywrapinit.CppBridge.SetFlags(cpp_flags)

    main()