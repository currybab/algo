#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[101];

int tiling(int n) {
    if(n == 1) {
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

int main() {
    int C, n;
    cin >> C;

    memset(arr, -1, sizeof(arr));
    while(C-- > 0) {
        cin >> n;
        cout << tiling(n) << endl;
    }

    return 0;
}