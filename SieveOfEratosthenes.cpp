#include<bits/stdc++.h>
using namespace std;

const long long int MAX = 1000001;
bool prime[MAX];

void Sieve() {
    memset(prime, true, sizeof(prime));

    for(long long int i = 2; i <= MAX; i++) {
        if(prime[i] == true) {
            for(long long int j = i*i; j <= MAX; j += i)
                prime[j] = false;
        }
    }

}

int main() {
    Sieve();
    for(int i = 1; i <= 20; i++){
        if(prime[i])
            cout << i << endl;              // prints all prime numbers from 1 - 20
    }
}
