import numpy as np
from scipy.optimize import linear_sum_assignment

efficiency_matrix = np.array([
    [5, 0, 1, 0, 6],
    [11, 0, 3, 0, 6],
    [11, 7, 5, 7, 9],
    [9, 1, 4, 0, 1],
    [8, 9, 10, 3, 4],
])

# венгерский метод
row_indices, col_indices = linear_sum_assignment(-efficiency_matrix)


for i in range(len(row_indices)):
    print (f"Кандидат {row_indices[i] + 1} назначен на задачу {col_indices[i] + 1}")