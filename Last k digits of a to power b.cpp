#include <bits/stdc++.h> 
using namespace std;
int power(long long int x, long long int y, long long int p) 
{ 
    long long int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) 
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p; 
    } 
    return res; 
}
int numberOfDigits(int x) 
{ 
    int i = 0; 
    while (x) { 
        x /= 10; 
        i++; 
    } 
    return i; 
}
void printLastKDigits(int a, int b, int k) 
{ 
    cout << "Last " << k; 
    cout << " digits of " << a; 
    cout << "^" << b << " = ";
    int temp = 1; 
    for (int i = 1; i <= k; i++) 
        temp *= 10;
    temp = power(a, b, temp);
    for (int i = 0; i < k - numberOfDigits(temp); i++) 
        cout << 0;
    if (temp) 
        cout << temp; 
}
int main() 
{ 
    int a; 
    int b; 
    int k;
    cin>>a>>b>>k;
    printLastKDigits(a, b, k);
    return 0; 
} 
