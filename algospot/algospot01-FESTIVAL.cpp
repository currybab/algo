#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void solve(int N, int L, vector<int> usages) {
    int sum = 0;
    double avg;
    double min = 1000.0;

    for(int i = 0; i <= N - L; ++i) {
        sum = 0;
        for(int j = i; j < i + L - 1; ++j) {
            sum += usages[j];
        }

        for (int j = i + L - 1; j < N; j++) {
            sum += usages[j];
            double avg = (double) sum / (j - i + 1);
            if(min > avg) {
                min = avg;
            }
        }
    }
    
    // printf("%.11f\n", min);
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
        solve(days[i], teams[i], usages[i]);
    }

    return 0;
}