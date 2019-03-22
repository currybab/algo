#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[10000];
int maxNum = 20000;

int count(string str, int start, int end) {
    char ch = str[start];
    bool allSame = true;
    for(int i = start + 1; i <= end; i++) {
        if(ch != str[i])  {
            allSame = false;
            break;
        }
    }
    if(allSame) return 1;
    int diff = str[start + 1] - str[start];
    allSame = true;
    for(int i = start + 2; i <= end; i++) {
        if(str[i] - str[i - 1] != diff)  {
            allSame = false;
            break;
        }
    }
    if(allSame) {
        if(diff == 1 || diff == -1) {
            return 2;
        } else {
            return 5;
        }
    }
    allSame = true;
    for(int i = start + 2; i <= end; i++) {
        if(str[i] != str[i - 2])  {
            allSame = false;
            break;
        }
    }
    
    return allSame ? 4 : 10;
}

int solve(string str, int x) {
    if(x == str.size()) {
        return 0;
    }
    if(cache[x] != -1) {
        return cache[x];
    }
    int result = maxNum;
    for(int i = 2; i < 5; i++) {
        if(x + i < str.size()) {
            result = min(result, solve(str, x + i + 1) + count(str, x, x + i));
        }
    }
    cache[x] = result;
    return result;
}

int pi(string str) {
    return solve(str, 0);
}

int main() {
    int C;
    string str;
    cin >> C;
    while (C-- > 0) {
        cin >> str;
        memset(cache, -1, sizeof(cache));
        cout << pi(str) << endl;
    }

    return 0;
}