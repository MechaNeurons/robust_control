#include "robust_control.h"

/// @brief Solve the continuous-time Lyapunov equation:
/// A * X + X * A^T = -Q
/// for X, given square matrices A and Q.
/// This implementation uses vectorization and Kronecker products:
/// vec(X) = (I \otimes A + A \otimes I)^{-1} vec(Q)
/// @param A
/// @param Q
/// @return
Eigen::MatrixXd solveLyapunov(const Eigen::MatrixXd &A, const Eigen::MatrixXd &Q)
{
    /**
     * Solve the continuous-time Lyapunov equation:
     *     A * X + X * A^T = Q
     * for X, given square matrices A and Q.
     * This implementation uses vectorization and Kronecker products:
     * vec(X) = (I \otimes A + A \otimes I)^{-1} vec(Q)
     */
    assert(A.rows() == A.cols());
    assert(Q.rows() == Q.cols());
    int n = A.rows();
    Eigen::MatrixXd I = Eigen::MatrixXd::Identity(n, n);
    Eigen::MatrixXd S = Eigen::kroneckerProduct(A.transpose(), I) + Eigen::kroneckerProduct(I, A.transpose());
    Eigen::VectorXd q = Eigen::Map<const Eigen::VectorXd>(Q.data(), n * n);

    Eigen::VectorXd x = S.fullPivLu().solve(q);

    Eigen::MatrixXd X = Eigen::Map<const Eigen::MatrixXd>(x.data(), n, n);
    return -X;
}

double h2_norm(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B, const Eigen::MatrixXd &C)
{
    Eigen::MatrixXd Q = solveLyapunov(A, C.transpose() * C);
    double temp = (B.transpose() * Q * B).trace();
    return sqrt(temp);
}