#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

int main() {
    // Input
    int n, A[MAX];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // Kadane's Algorithm finds the maximum subarray sum in O(n)
    int ans = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }

    // Output
    printf("%d\n", ans);
}