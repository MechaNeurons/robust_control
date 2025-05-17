clc, clear

A = [0, 1; -10, -1];
B = [0; 1];
C = [1, 0];

disp(solve_lyapunov(A, C' * C))

disp(h2_norm(A, B, C))
