# Robust control exercises

In this repository I plan to solve my robust control class exercises in 4 different environment to enforce my knowledge in both the theory and the implementation of them. This exercises are based on [Dr. Rajesh Joseph Abraham](https://youtube.com/playlist?list=PLkq3XsX6LXRLyGb0vzpfAeF_LSuVpLE78&si=mzz9rEv_FLa981-i) Youtube videos.

## The 3rd party libs that i used for this project

### Python

1. numpy
2. scipy

### C++

1. eigen

## Exercises  

### Exercise 1

Find the $H_2 \ norm$ of the this system:

$$
\dot{x} = \begin{bmatrix}
    0 & 1 \\
    -10 & -1
\end{bmatrix} x + \begin{bmatrix}
    0 \\
    1
\end{bmatrix}u
$$
$$
y = \begin{bmatrix}
    1 & 0
\end{bmatrix} x
$$
