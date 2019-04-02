#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
}

int lunchBox(vector<int>& m, vector<int>& e, int N) {
    if(N < 1) return 0;
    vector<pair<int, int> > arr;
    for(int i = 0; i < N; i++) {
        arr.push_back(make_pair(e[i], m[i]));
    }
    sort(arr.begin(), arr.end(), compare);

    int result = arr[0].first + arr[0].second;
    int mSum = arr[0].second;
    for(int i = 1; i < N; i++) {
        mSum += arr[i].second;
        result = max(result, mSum + arr[i].first);
    }
    return result;
}

int main() {
    int T, N;
    cin >> T;
    while(T-- > 0) {
        cin >> N;
        vector<int> m(N);
        vector<int> e(N);
        for(int i = 0; i < N; i++) {
            cin >> m[i];
        }
        for(int i = 0; i < N; i++) {
            cin >> e[i];
        }
        cout << lunchBox(m, e, N) << endl;
    }
    return 0;
}