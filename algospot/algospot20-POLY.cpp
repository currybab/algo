#include <iostream>
#include <cstring>

using namespace std;

int cache1[101][101];
// int cache2[101];

int solve(int n, int t) {
    if(t == 0) return 0;
    if(n == t || n <= 1) return 1;
    if(cache1[n][t] != -1) return cache1[n][t];
    int result = 0;
    for(int i = 1; i <= n - t; i++) {
        result += (t + i - 1) * solve(n - t, i);
        result %= 10000000;
    }
    cache1[n][t] = result;
    return result;
}


int poly(int n) {
    if (n == 1) {
        return 1;
    }
    // if(cache2[n] != -1) return cache2[n];

    int result = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            result += (i + j - 1)* solve(n - i, j);
            result %= 10000000;
        }
    }
    return result;
}

int main() {
    int C, n;
    cin >> C;

    memset(cache1, -1, sizeof(cache1));
    // memset(cache2, -1, sizeof(cache2));
    while(C-- > 0) {
        cin >> n;
        cout << poly(n) << endl;
    }

    return 0;
}