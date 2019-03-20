#include <iostream>
#include <vector>
using namespace std;

int solveFence(vector<int> arr) {
    int max = 1;
    for(int i = 0; i < arr.size(); i++) {
        int h = arr[i];
        int w = 1;
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < h) break;
            w++;
        }
        for(int j = i - 1; j >= 0; j--) {
            if(arr[j] < h) break;
            w++;
        }
        int s = w * h;
        max = (s > max)? s : max;
    }
    return max;
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
        cout << solveFence(arr) << endl;
    }
    return 0;
}
