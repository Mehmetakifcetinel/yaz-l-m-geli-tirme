#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 10000000;
vector<bool> is_prime(LIMIT + 1, true);
vector<int> primes;

void make_sieve() {
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i <= LIMIT; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    make_sieve();
    int max_minp = 0;
    int max_n = 0;
    for (int n = 4; n <= LIMIT; n += 2) {
        int minp = -1;
        for (int p : primes) {
            if (p > n / 2) break;
            if (is_prime[n - p]) {
                minp = p;
                break;
            }
        }
        if (minp > max_minp) {
            max_minp = minp;
            max_n = n;
            cout << "Yeni rekor: n = " << n << ", en kucuk p = " << minp << endl;
        }
    }
    cout << "10^7 araliginda en buyuk en-kucuk p: " << max_minp << " (n = " << max_n << " icin)" << endl;
    return 0;
}
