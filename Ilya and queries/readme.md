# problem
given a binary string A of n symbols in {a,b}, and a set Q of q queires such that:
query(i,j) reports the number of positions in S[i,j] such that S[k] = S[k+1]

- doesn't matter if the value is a or b, just that the position has the same value as its successor.

example: 
A = a b b a b b a
q(1,4) = 2   // two consecutive b in positions 1,2