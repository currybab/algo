#include <iostream>
#include <vector>

using namespace std;

bool checkMap(vector<vector<char> > map, string str, int x, int y, int i) {
    if(i == str.length()) {
        return true;
    }
    if(x >= 5 || x < 0 || y >= 5 || y < 0) {
        return false;
    }
    if(map[y][x] != str[i]) {
        return false;
    }
    i++;
    return checkMap(map, str, x - 1, y - 1, i) 
        || checkMap(map, str, x - 1, y + 1, i)
        || checkMap(map, str, x - 1, y, i)
        || checkMap(map, str, x, y - 1, i)
        || checkMap(map, str, x, y + 1, i)
        || checkMap(map, str, x + 1, y - 1, i)
        || checkMap(map, str, x + 1, y, i)
        || checkMap(map, str, x + 1, y + 1, i);
}

void checkAll(vector<vector<char> > map, string str) {
    for(int j = 0; j < 5; j++) {
        for(int k = 0; k < 5; k++) {
            if(checkMap(map, str, j, k, 0)) {
                cout << str << " YES" << endl;
                return;
            }
        }
    }
    cout << str << " NO" << endl;
}

int main() {
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        char ch;
        vector<vector<char> > chmap(5);
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                cin >> ch;
                chmap[j].push_back(ch);
            }
        }

        int count;
        cin >> count;
        string str;
        for(int l = 0; l < count; l++) {
            cin >> str;
            checkAll(chmap, str);
        }
    }

    return 0;
}