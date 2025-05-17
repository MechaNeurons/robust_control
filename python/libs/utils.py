import numpy as np
from numpy import ndarray
import math


def solve_lyapunov(A: ndarray, Q: ndarray) -> ndarray:
    """
    This Function will solve the following equation
    A.T @ X + X @ A = - Q

    Args:
        A (ndarray)
        Q (ndarray)

    Returns:
        X (ndarray): The solution of lyapunov equation
    """
    assert A.shape[0] == A.shape[1]
    assert Q.shape[0] == Q.shape[1]
    n = A.shape[0]
    S = np.kron(np.eye(n), A.T) + np.kron(A.T, np.eye(n))
    vec_x = -np.linalg.pinv(S) @ Q.reshape(-1, 1)
    return vec_x.reshape(n, n)


def h2_norm(A: ndarray, B: ndarray, C: ndarray) -> np.float64:
    """
    This function will compute the H2 norm of a system in the form
    dx/dt = Ax+Bu
    y = Cx

    Args:
        A (ndarray): state matrix
        B (ndarray): input matrix
        C (ndarray): output matrix

    returns:
        h2 (float64): H2 norm
    """
    Q = solve_lyapunov(A, C.T @ C)
    temp = np.trace(B.T @ Q @ B)
    h2 = np.sqrt(temp)
    return h2
