from scipy.optimize import linprog

# Коэффициенты целевой функции
c = [-2, 1]

# Коэффициенты ограничений
A = [[-3, 1], [1, -2]]
b = [9, 3]

# Границы переменных
x0_bounds = (0, None)  # x1 >= 0
x1_bounds = (0, None)  # x2 >= 0

res = linprog(c, A_ub=A, b_ub=b, bounds=[x0_bounds, x1_bounds], method='simplex')

print("Оптимальное значение целевой функции:", -res.fun)  # Меняем знак, так как linprog минимизирует функцию
print("Оптимальные значения переменных x1 и x2:", res.x)
