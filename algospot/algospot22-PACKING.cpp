#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct {
    string name;
    int volume;
    int imp;
} item;

int cache[1001][101];

int packing(int weight, int x, vector<item>& itemList) {
    if(weight <= 0 || x >= itemList.size()) {
        return 0;
    }
    if(cache[weight][x] != -1) {
        return cache[weight][x];
    }
    int result = packing(weight, x + 1, itemList);
    //result.list = vector<int>(0);
    if(weight - itemList[x].volume >= 0) {
        result = max(result, packing(weight - itemList[x].volume, x + 1, itemList) + itemList[x].imp);
    }
    cache[weight][x] = result;
    return result;
}

void findList(vector<string>& answers, int x, int answer, int weight, vector<item>& itemList) {
    if(answer == 0 || x == itemList.size()) return;
    if(packing(weight, x, itemList) == packing(weight, x + 1, itemList)) {
        findList(answers, x + 1, answer, weight, itemList);
    } else {
        answers.push_back(itemList[x].name);
        findList(answers, x + 1, answer - itemList[x].imp, weight - itemList[x].volume, itemList);
    }
}

int main() {
    int C, N, W;
    string name;
    cin >> C;
    while(C-- > 0) {
        cin >> N >> W;
        memset(cache, -1, sizeof(cache));
        vector<item> itemList(N);
        for(int i = 0; i < N; i++) {
            cin >> name;
            itemList[i].name = name;
            cin >> itemList[i].volume >> itemList[i].imp;
        }

        int answer = packing(W, 0, itemList);
        vector<string> answers = vector<string>();
        findList(answers, 0, answer, W, itemList);
        cout << answer << " " << answers.size() << endl;
        for(int i = 0; i < answers.size(); i++) {
            cout << answers[i] << endl;
        }
    }
    return 0;
}