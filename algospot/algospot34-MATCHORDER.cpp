#include <iostream>
#include <vector>
#include <set>

using namespace std;

int matchOrder(vector<int>& opponent, multiset<int>& ourscore) {
    int result = 0;
    for(int i = 0; i < opponent.size(); i++) {
        if(*ourscore.rbegin() < opponent[i]) {
            ourscore.erase(ourscore.begin());
        } else {
            result++;
            ourscore.erase(ourscore.lower_bound(opponent[i]));
        }
    }
    return result;
}

int main() {
    int C, n, m;

    cin >> C;
    while(C-- > 0) {
        cin >> n;
        vector<int> opponent(n);
        for(int i = 0; i < n; i++) {
            cin >> opponent[i];
        }
        multiset<int> ourscore;
        for(int i = 0; i < n; i++) {
            cin >> m;
            ourscore.insert(m);
        }

        cout << matchOrder(opponent, ourscore) << endl;
    }
    

    return 0;
}