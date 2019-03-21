#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[101][101];

int solve(vector<int>& arr1, vector<int>& arr2, int n, int m, int x, int y) {
    if(x == n || y == m) {
        return 0;
    }
    if(cache[x + 1][y + 1] != -1) {
        return cache[x + 1][y + 1];
    }
    int result = 0;

    int last1 = (x == -1)? numeric_limits<int>::min() : arr1[x];
    int last2 = (y == -1)? numeric_limits<int>::min() : arr2[y];
    int maxN = max(last1, last2);
    for(int i = x + 1; i < n; i++) {
        if(maxN < arr1[i]) {
            result = max(result, 1 + solve(arr1, arr2, n, m, i, y));
            // cout << result << endl;
            cache[x + 1][y + 1] = result;
        }
    }

    for(int i = y + 1; i < m; i++) {
        if(maxN < arr2[i]) {
            result = max(result, 1 + solve(arr1, arr2, n, m, x, i));
            // cout << result << endl;
            cache[x + 1][y + 1] = result;   
        }
    }
    return result;
}

int jlis(vector<int>& arr1, vector<int>& arr2) {
    for(int i = 0; i <= arr1.size() ; i++) {
        for(int j = 0; j <= arr2.size(); j++) {
            solve(arr1, arr2, arr1.size(), arr2.size(), i - 1, j - 1);
        }
    }
    int maxN = 0;
    for(int i = 0; i <= arr1.size() ; i++) {
        for(int j = 0; j <= arr2.size(); j++) {
            maxN = max(maxN, cache[i][j]);
        }
    }
    return maxN;
}

int main() {
    int c, n, m, a;

    cin >> c;
    for(int i = 0; i < c; i++) {

        memset(cache, -1, sizeof(cache));
        cin >> n >> m;
        vector<int> arr1(n);
        vector<int> arr2(m);
        for(int j = 0; j < n; j++) {
            cin >> a;
            arr1[j] = a;
        }
        for(int j = 0; j < m; j++) {
            cin >> a;
            arr2[j] = a;
        }

        cout << jlis(arr1, arr2) << endl;
    }

    return 0;
}