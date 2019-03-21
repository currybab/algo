#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[500];

int solve(vector<int>& arr, int n, int x) {
    if(x == n) {
        return 0;
    }
    if(cache[x] != -1) {
        return cache[x];
    }
    int result = 1;
    for(int i = x + 1; i < n; i++) {
        if(arr[x] < arr[i]) {
            result = max(result, 1 + solve(arr, n, i));
            cache[x] = result;
        } 
    }
    return result;
}

int lis(vector<int>& arr, int n) {
    for(int i = 0; i < n ; i++) {
        solve(arr, n, i);
    }
    int maxN = 0;
    for(int i = 0; i < n ; i++) {
        // cout << cache[i] << endl;
        maxN = max(maxN, cache[i]);
    }
    return maxN;
}

int main() {
    int C, N, m;

    cin >> C;
    for(int i = 0; i < C; i++) {
        cin >> N;
        vector<int> arr(N);
        for(int j = 0; j < N; j++) {
            cin >> m;
            arr[j] = m;
        }
        memset(cache, -1, sizeof(cache));
        cout << lis(arr, N) << endl;
    }

    return 0;
}