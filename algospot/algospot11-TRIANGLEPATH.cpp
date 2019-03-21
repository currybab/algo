#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int cache[100][100];

int solve(vector<vector<int> >& board, int n, int x, int y) {
    if(y == n - 1) {
        // cout << board[y][x] << endl;
        return board[y][x];
    }
    if(cache[y][x] != -1) {
        return cache[y][x];
    }
    cache[y][x] = board[y][x] + max(solve(board, n, x, y + 1), solve(board, n, x + 1, y + 1));
    // cout << cache[y][x] << endl;
    return cache[y][x];
}

int trianglepath(vector<vector<int> >& board, int n) {
    return solve(board, n, 0, 0);
}

int main() {
    int C, n, m;
    cin >> C;
    for(int i = 0; i < C; i++) {
        cin >> n;
        vector<vector<int> > board = vector<vector<int> > (n);
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < j + 1; k++) {
                cin >> m;
                board[j].push_back(m);
            }
        }
        memset(cache, -1, sizeof(cache));
        cout << trianglepath(board, n) << endl;
    }
    return 0;
}
