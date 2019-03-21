#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[100][100];

bool solve(vector<vector<int> >& board, int n, int x, int y) {
    if(x >= n || y >= n) {
        return false;
    }
    if(cache[x][y] != -1) {
        return (cache[x][y] == 1)? true : false;
    }
    if(x == n - 1 && y == n - 1) {
        return true;
    }
    bool res = solve(board, n, x + board[x][y], y) || solve(board, n, x, y + board[x][y]);
    cache[x][y] = (res == true) ? 1 : 0;
    return res;
}

void jumpgame(vector<vector<int> >& board, int n) {
    bool res = solve(board, n, 0, 0);
    if (res == true) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int C, n, m;
    cin >> C;
    for(int i = 0; i < C; i++) {
        cin >> n;
        vector<vector<int> > board = vector<vector<int> > (n);
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cin >> m;
                board[k].push_back(m);
            }
        }
        memset(cache, -1, sizeof(cache));
        jumpgame(board, n);
    }

    return 0;
}