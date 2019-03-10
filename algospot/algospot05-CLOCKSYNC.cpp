#include <iostream>
#include <vector>

using namespace std;

int turn(int n) {
    int m = n % 12;
    if(m == 3) {
        return 3;
    } else if (m == 6) {
        return 2;
    } else if (m == 9) {
        return 1;
    }
    return 0;
}

int cal(vector<int>& row) {
    if(row[8] != row[12] || row[14] != row[15]) {
        return -1;
    }
    int t1 = turn(row[11]);
    int t4 = turn(row[12]);
    int t9 = turn(row[13]);
    if((row[9] + t1 * 3 + t9 * 3) % 12 != 0) {
        return -1;
    }

    int t3 = turn(row[6] + t4 * 3);
    int t2 = turn(row[10] + t4 * 3);

    if((row[4] + 3 * t2) % 12 != row[5] % 12) {
        return -1;
    }

    int t7 = turn(row[7] + t1 * 3 + t3 * 3 + t4 * 3);
    int t8 = turn(row[5] + 3 * (t3 + t7 + t9));
    int t0 = turn(row[1] + 3 * t8);
    int t6 = turn(row[3] + 3 * (t1 + t8 + t9));

    int r = (row[0] + 3 * (t0 + t3)) % 12;
    if(r != (row[2] + 3 * (t0 + t8)) % 12 || r != (row[14] + 3 * (t2 + t6 + t7)) % 12) {
        cout << r << (row[2] + 3 * (t0 + t8)) % 12 << (row[14] + 3 * (t2 + t6 + t7)) % 12 << endl;
        return -1;
    }
    int t5 = turn(r);
    
    return t0 + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9;
}

int main() {
    int cases, n;
    cin >> cases;

    for(int i = 0; i < cases; i++) {
        vector<int> row = vector<int>(16);
        
        for(int j = 0; j < 16; j++) {
            cin >> n;
            row[j] = n;
        }

        cout << cal(row) << endl;
        // printf("%d\n", cal(row));
    }

    return 0;
}

