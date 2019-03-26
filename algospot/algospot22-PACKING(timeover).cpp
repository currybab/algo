#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef struct {
    string name;
    int volume;
    int imp;
} item;

typedef struct {
    int sum_imp;
    list<int> arr;
} load;

load cache[1001][101];

load zero;
load newCache;

load maxLoad(load load1, load load2) {
    return (load1.sum_imp >= load2.sum_imp) ? load1 : load2;
}

load backing(int weight, int x, vector<item>& itemList) {
    if(weight == 0 || x >= itemList.size()) {
        return zero;
    }
    if(cache[weight][x].sum_imp != -1) {
        return cache[weight][x];
    }
    load result = backing(weight, x + 1, itemList);
    //result.list = vector<int>(0);
    if(weight - itemList[x].volume >= 0) {
        load result1 = backing(weight - itemList[x].volume, x + 1, itemList);
        result1.sum_imp += itemList[x].imp;
        result1.arr.push_back(x);
        result = maxLoad(result, result1);
    }
    cache[weight][x] = result;
    return result;
}

int main() {
    zero.sum_imp = 0;
    newCache.sum_imp = -1;
    int C, N, W;
    string name;
    cin >> C;
    while(C-- > 0) {
        cin >> N >> W;
        for(int i = 0; i < 1001; i++) {
            for(int j = 0; j < 101; j++) {
                //newLoad.list = vector<int>(0);
                cache[i][j] = newCache;
            }
        }

        vector<item> itemList(N);
        for(int i = 0; i < N; i++) {
            cin >> name;
            itemList[i].name = name;
            cin >> itemList[i].volume >> itemList[i].imp;
        }

        load answer = backing(W, 0, itemList);
        cout << answer.sum_imp << " " << answer.arr.size() << endl;
        auto iter = answer.arr.begin();
        while(iter != answer.arr.end()) {
            cout << itemList[*iter].name << endl;
            iter++;
        }
    }
    return 0;
}