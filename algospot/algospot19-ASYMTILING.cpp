#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[101];

int tiling(int n) {
    if(n <= 1) {
        return 1;
    }
    if(n == 2) {
        return 2;
    }
    if(arr[n] != -1) {
        return arr[n];
    }
    int result = (tiling(n - 2) + tiling(n - 1)) % 1000000007;
    arr[n] = result;
    return result;
}

int solve(int n) {
    if(n % 2 == 1) return (tiling(n) - tiling(n / 2) + 1000000007) % 1000000007;
    int result = tiling(n);
    result = (result - tiling(n / 2) + 1000000007) % 1000000007;
    result = (result - tiling(n / 2 - 1) + 1000000007) % 1000000007;
    return result;
}

int main() {
    int C, n;
    cin >> C;

    memset(arr, -1, sizeof(arr));
    while(C-- > 0) {
        cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}