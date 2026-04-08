#include <bits/stdc++.h>
using namespace std;

int prioritas(char op) {
    if(op == '^') {
        return 3;
    } else if(op == '*' || op == '/') {
        return 2;
    } else if(op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

bool isOp(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '^' || c == '*');
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    int i;
    for(i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if(isalnum(c)) {
            postfix += c;
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }

            if(!st.empty()) {
                st.pop();
            }
        } else if(isOp(c)) {
            while(!st.empty() && prioritas(st.top()) >= prioritas(c)) {
                postfix += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    } 

    return postfix;
}

int main(void) {
    string infix;

    cout << "Masukkan ekspresi infix: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix: " << postfix << endl;

    return 0;
}