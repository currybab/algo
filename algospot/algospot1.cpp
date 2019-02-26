#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void solve(int N, int L, vector<int> usages) {
    int sum = 0;
    float avg;
    float min = 1000.0;

    for(int i = L; i <= N; ++i) {
        for(int j = 0; j <= N - i ; ++j) {
            sum = 0;
            for(int k = j; k < i + j; ++k) {
                sum += usages[k];
            }

            avg = (double) sum / i;
            if(min > avg) {
                min = avg;
            }
        }
    }
    cout << fixed << setprecision(11) << min << endl;
}

int main() {
    int cases;
    cin >> cases;
    vector<int> days(100);
    vector<int> teams(100);
    vector<vector<int> > usages(100);

    int n, m;
    for(int i = 0; i < cases; i++) {
        cin >> n;
        days[i] = n;
        cin >> m;
        teams[i] = m;
        for(int j = 0; j < n; j++) {
            cin >> m;
            usages[i].push_back(m);
        }
    }

    for(int i = 0; i < cases; i++) {
        solve(days[i], teams[i], usages[i]);
    }

    return 0;
}