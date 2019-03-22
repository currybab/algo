#include <iostream>
#include <iomanip>

using namespace std;

double cache[1001][1001];

double snail(int n, int m) {
    if(n <= 0) {
        return 1.0;
    }
    if(m == 1) {
        if(n == 2) return 0.75;
        if(n == 1) return 1.0;
        return 0.0;
    }
    if(cache[n][m] >= 0.0) {
        return cache[n][m];
    }
    double result = 0.75 * snail(n - 2, m - 1) + 0.25 * snail(n - 1, m - 1);
    cache[n][m] = result;
    return result;
}

int main() {
    int C, n, m;
    cin >> C;
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) {
            cache[i][j] = -1.0;
        }
    }
    while(C-- > 0) {
        cin >> n >> m;
        cout << fixed << setprecision(11) << snail(n, m) << endl;
    }
    return 0;
}