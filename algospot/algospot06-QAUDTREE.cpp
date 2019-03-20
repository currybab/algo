#include <iostream>

using namespace std;

string reverseQuad(string::iterator &it) {
    char head = *it;  
    ++it;  
    if (head != 'x') return string(1,head);  
    string upperLeft = reverseQuad(it);  
    string upperRight = reverseQuad(it); 
    string lowerLeft = reverseQuad(it);  
    string lowerRight = reverseQuad(it);  
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight; 
}

int main() {
    string s;  
    int n; 
    cin >> n; 
    for (int i = 0; i < n; ++i)
    {
        cin >> s; 
        auto it = s.begin();  
        cout << reverseQuad(it) << endl; 
    }
    return 0;  
}