#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string str = "HELLO";
    stack<char> st;

    int jml = 0;

    for(char s : str) {
        st.push(s);
        jml++;
    }

    while(jml != 0) {
        cout << st.top();
        st.pop();
        jml--;
    }

    return 0;
}