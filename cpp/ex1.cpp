#include <iostream>
#include "robust_control.h"
#include <Eigen/Eigen>

using namespace std;
using namespace Eigen;

int main(int argc, char const **argv)
{
    MatrixXd A{
        {0, 1},
        {-10, -1},
    };
    MatrixXd B{
        {0},
        {1},
    };
    MatrixXd C{
        {1, 0},
    };
    auto Q = solveLyapunov(A, C.transpose() * C);
    cout << Q << endl;
    cout << h2_norm(A, B, C) << endl;
    return 0;
}
