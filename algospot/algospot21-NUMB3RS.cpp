#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;
double cache1[101][50];
int cache2[50][50];

int calp(int i, int j, vector<vector<int> >& board) {
    if(i >= board.size() || j >= board.size()) return 0;
    if(cache2[i][j] != -1) {
        return cache2[i][j];
    }
    if(board[i][j] == 0) {
        cache2[i][j] = 0;
        return 0;
    }
    int result = 0;
    for(int k = 0; k < board.size(); k++) {
        if(board[i][k] == 1) result++;
    }
    for(int k = 0; k < board.size(); k++) {
        if(board[i][k] == 1) cache2[i][k] = result;
        else cache2[i][k] = 0;
    }
    return result;
}

void cal(vector<vector<int> >& board, int b, int n) {
    for(int i = 0; i < board.size(); i++) {
        int p = calp(i, b, board);
        if(p != 0) {
            cache1[n][b] += ((double) 1 / p) * cache1[n - 1][i];
        }
    }
}


void numbers(vector<vector<int> >& board, int d, int n, int p) {
    for(int i = 0; i < board.size(); i++) {
        cal(board, i, n);
    }
    if(d == n) return;
    numbers(board, d, n + 1, p);
}

int main() {
    int c, b, d, p, t, n;

    cin >> c;

    while(c-- > 0) {
        memset(cache2, -1, sizeof(cache2));
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 50; j++) {
                cache1[i][j] = 0;
            }
        }
        cin >> b >> d >> p;
        vector<vector<int> > board(b);
        cache1[0][p] = 1;
        for(int i = 0; i < b; i++) {
            board[i] = vector<int>(b);
        }
        for(int i = 0; i < b; i++) {
            for(int j = 0; j < b; j++) {
                cin >> board[i][j];
            }
        }
        numbers(board, d, 1, p);
        cin >> t;
        for(int i = 0; i < t; i++) {
            cin >> n;
            cout << fixed << setprecision(11) << cache1[d][n];
            if(i == t - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }


    return 0;
}