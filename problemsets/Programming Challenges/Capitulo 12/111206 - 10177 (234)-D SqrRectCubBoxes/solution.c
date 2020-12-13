
Solution table:
    
D:  |        S[d][n         |              R[d][n]                  |
    |                       |                                       |
____|_______________________|_______________________________________|
2   |     n^2 + S[2][n-1]   |  (2*n)*sum(PA(n-1)) + R[2][n-1]  (ou) |
    |                       |     (n^2)*(n-1) + R[2][n-1]           |
____|_______________________|_______________________________________|
3   |     n^3 + S[3][n-1]   |                                       |
    |                       |                                       |
____|_______________________|_______________________________________|
4   |     n^4 + S[4][n-1]   |                                       |
    |                       |                                       |
____|_______________________|_______________________________________|

n > 1

Trivial:
S[2][1] = 1     S[3][1] = 1     S[4][1] = 1
R[2][1] = 0     R[3][1] = 0     R[4][1] = 0
