#include <iostream>

using namespace std;

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int sum;
    int cnt;
} path;

path cache[100][100];

path solve(vector<vector<int> >& board, int n, int x, int y) {
    if(y == n - 1) {
        // cout << board[y][x] << endl;
        path newPath;
        newPath.sum = board[y][x];
        newPath.cnt = 1;
        return newPath;
    }
    if(cache[y][x].sum != -1) {
        return cache[y][x];
    }
    cache[y][x].sum = board[y][x];
    path path1 = solve(board, n, x, y + 1);
    path path2 = solve(board, n, x + 1, y + 1);
    if(path1.sum > path2.sum) {
        cache[y][x].sum += path1.sum;
        cache[y][x].cnt = path1.cnt;
    } else if(path1.sum < path2.sum) {
        cache[y][x].sum += path2.sum;
        cache[y][x].cnt = path2.cnt;
    } else {
        cache[y][x].sum += path1.sum;
        cache[y][x].cnt = path1.cnt + path2.cnt;
    }
    // cout << cache[y][x] << endl;
    return cache[y][x];
}

int trianglepath(vector<vector<int> >& board, int n) {
    return solve(board, n, 0, 0).cnt;
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

