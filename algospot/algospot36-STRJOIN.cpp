#include <iostream>
#include <set>

using namespace std;

int strjoin(multiset<int>& lens) {
    int result = 0;
    while(lens.size() > 1) {
        int len1 = *(lens.begin());
        lens.erase(lens.begin());
        int len2 = *(lens.begin());
        lens.erase(lens.begin());
        int len3 = len1 + len2;
        // cout << "1,2,3," << len1 << len2 << len3 << endl;
        result += len3;
        lens.insert(len3);
    }

    return result;
}

int main() {
    int c, n, m;
    cin >> c;
    while(c-- > 0) {
        cin >> n;
        multiset<int> lens;
        while(n-- > 0) {
            cin >> m;
            lens.insert(m);
        }
        cout << strjoin(lens) << endl;
    }
    return 0;
}