function P = solve_lyapunov(A, Q)
    assert(size(A, 1) == size(A, 2))
    assert(size(Q, 1) == size(Q, 2))
    n = size(A, 1);
    I = eye(size(A));
    S = kron(A', I) + kron(I, A');
    q = reshape(Q, [n * n, 1]);
    p = pinv(S) * q;
    P = reshape(p, [n, n]);
    P = -P;
end
