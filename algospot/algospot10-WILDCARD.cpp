#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int cache[100][100];

bool solve(string fileName, string word, int x, int y) {
    if(fileName.size() == x && word.size() == y) {
        return true;
    }
    if(fileName.size() == x || word.size() == y) {
        if(y == word.size() - 1) return word[y] == '*';
        return false;
    }
    if(cache[x][y] != -1) {
        return (cache[x][y] == 1) ? true : false;
    }
    bool result = false;
    if(word[y] == '*') {
        result = solve(fileName, word, x, y + 1) || solve(fileName, word, x + 1, y + 1) || solve(fileName, word, x + 1, y);
    } else if(word[y] == '?') {
        result = solve(fileName, word, x + 1, y + 1);
    } else {
        result = (word[y] == fileName[x])? solve(fileName, word, x + 1, y + 1) : false;
    }

    cache[x][y] = (result) ? 1 : 0;
    return result;
}

int main() {
    int C, N;
    string word, fileName;
    cin >> C;
    while(C-- > 0) {
        cin >> word;
        cin >> N;
        vector<string> result = vector<string>();
        while(N-- > 0) {
            cin >> fileName;
            memset(cache, -1, sizeof(cache));
            if(solve(fileName, word, 0, 0)) result.push_back(fileName);
        }
        sort(result.begin(), result.end());
        for(int i = 0; i < result.size(); i++) {
            cout << result[i] << endl;
        }
    }
    
    return 0;
}