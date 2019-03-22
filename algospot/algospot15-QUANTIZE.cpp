#include <iostream> 
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int cache1[11][100][100];
int cache2[100][100];

int smallestSum(vector<int>& arr, int start, int end) {
    if(cache2[start][end] != -1) return cache2[start][end];
    int sum = 0;
    for(int i = start; i <= end; i++) {
        sum += arr[i];
    }
    int n = sum / (end - start + 1);
    int m = n + 1;

    int sum1 = 0;
    int sum2 = 0;
    for(int i = start; i <= end; i++) {
        sum1 = sum1 + (arr[i] - n) * (arr[i] - n);
        sum2 = sum2 + (arr[i] - m) * (arr[i] - m);
    }
    cache2[start][end] = min(sum1, sum2);
    return cache2[start][end];
}


int quantize(vector<int>& arr, int s, int start, int end) {
    if(end - start + 1 <= s) {
        return 0;
    }
    if(s == 1) {
        return smallestSum(arr, start, end);
    }
    if(cache1[s][start][end] != -1) {
        return cache1[s][start][end];
    }
    int result = 2147483647;
    for(int i = start; i <= end; i++) {
        result = min(result, quantize(arr, 1, start, i) + quantize(arr, s - 1, i + 1, end));
    }
    cache1[s][start][end] = result;
    return result;
}

int main() {
    int C, N, S;

    cin >> C;

    while(C-- > 0) {
        cin >> N >> S;
        vector<int> arr(N);
        for(int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        memset(cache1, -1, sizeof(cache1));
        memset(cache2, -1, sizeof(cache2));
        cout << quantize(arr, S, 0, N - 1) << endl;
    }
    return 0;
}