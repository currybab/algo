#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int cal(vector<unordered_set<int> > friends) {
    int count = friends.size();
    vector<int> pair();

    return 0;
}

int main() {
    int cases;
    cin >> cases;

    int num, num1, num2;
    for(int i = 0; i < cases; i++) {
        cin >> num;
        vector<unordered_set<int> > friends(num);
        cin >> num;
        for(int j = 0; j < num; j++) {
            cin >> num1;
            cin >> num2;
            friends[num1].insert(num2);
            friends[num2].insert(num1);
        }
        cout << cal(friends) << endl;
    }
}