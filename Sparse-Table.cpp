#include <bits/stdc++.h>
#define MAX 500
 
// lookup[i][j] is going to store GCD of
// arr[i..j]. Ideally lookup table
// size should not be fixed and should be
// determined using n Log n. It is kept
// constant to keep code simple.
int table[MAX][MAX];
 
// it builds sparse table.
void buildSparseTable(int arr[], int n)
{
    // GCD of single element is element itself
    for (int i = 0; i < n; i++)
        table[i][0] = arr[i];
 
    // Build sparse table
    for (int j = 1; j <= log2(n); j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = __gcd(table[i][j - 1],
                    table[i + (1 << (j - 1))][j - 1]);
}
 
// Returns GCD of arr[L..R]
int query(int L, int R)
{
    // Find highest power of 2 that is smaller
    // than or equal to count of elements in given
    // range.For [2, 10], j = 3
    int j = (int)log2(R - L + 1);
 
    // Compute GCD of last 2^j elements with first
    // 2^j elements in range.
    // For [2, 10], we find GCD of arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    return __gcd(table[L][j], table[R - (1 << j) + 1][j]);
}