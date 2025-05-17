import numpy as np
from libs import solve_lyapunov, h2_norm

A = np.array(
    [
        [0, 1],
        [-10, -1],
    ]
)
B = np.array(
    [
        [0],
        [1],
    ]
)

C = np.array([[1, 0]])

print(solve_lyapunov(A, C.T @ C))

print(h2_norm(A, B, C))
