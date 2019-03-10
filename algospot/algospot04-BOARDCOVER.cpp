#include <iostream>
#include <vector>
using namespace std;

const int shape[4][3][2] = {
    { {0, 0}, {1, 0}, {0, 1} },
    { {0, 0}, {1, 0}, {1, 1} },
    { {0, 0}, {0, 1}, {-1, 1} },
    { {0, 0}, {0, 1}, {1, 1} }
};

bool set(vector<vector<int> > &board, int x, int y, int type, int isSet) {
    bool res = true;
    for (int p = 0; p < 3; p++) {
        int px = x + shape[type][p][0];
        int py = y + shape[type][p][1];
        if(px < 0 || px >= board[0].size() || py < 0 || py >= board.size()) {
            res = false;
        } else if((board[py][px] -= isSet) < 0) {
            res = false;
        }
    }
    return res;
}

int cal(vector<vector<int> >& board, int x, int y) {
    int i, j;
    for(i = 0; i < y; i++) {
        for(j = 0; j < x; j++) {
            if(board[i][j] == 1) break;
        }
        if(board[i][j] == 1) break;
    }
    if(i == y && j == x) {
        return 1;
    }

    int res = 0;
    for(int t = 0; t < 4; t ++) {
        if(set(board, j, i, t, 1)) {
            res += cal(board, x, y);
        }
        set(board, j, i, t, -1);
    } 

    return res;
}

int main() {
    int cases;
    cin >> cases;

    int x, y;
    char c;
    for(int i = 0; i < cases; i++) {
        cin >> y;
        cin >> x;
        vector<vector<int> > board = vector<vector<int> > (y);
        int n = 0;
        for(int j = 0; j < y; j++) {
            vector<int> row = vector<int>(x);
            for(int k = 0; k < x; k++) {
                cin >> c;
                if(c == '#') row[k] = 0;
                else {
                    row[k] = 1;
                    n++;
                }
            }
            board[j] = row;
        }
        if (n % 3 == 0) cout << cal(board, x, y) << endl;
        else cout << 0 << endl;
    }

    return 0;
}