#pragma once
#include <iostream>
#include <Eigen/Eigen>
#include <unsupported/Eigen/KroneckerProduct>

Eigen::MatrixXd solveLyapunov(const Eigen::MatrixXd &A, const Eigen::MatrixXd &Q);

double h2_norm(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B, const Eigen::MatrixXd &C);