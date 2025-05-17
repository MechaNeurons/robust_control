function norm = h2_norm(A, B, C)
    Q = solve_lyapunov(A, C' * C);
    temp = trace(B' * Q * B);
    norm = sqrt(temp);
end
