/*

Nama: Hadryan Rizky Dimas Saputra
NRP: 5025251027
Kelas: Struktur Data (D)
Soal: ETS Nomor 3 (Infix to Postfix menggunakan Stack)

*/

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

    for(int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if(c == ' ') continue;

        if(isalnum(c)) {
            postfix += c;
            postfix += " ";
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                postfix += " ";
                st.pop();
            }
            if(!st.empty()) {
                st.pop();
            }
        } else if(isOp(c)) {
            while(!st.empty() && prioritas(st.top()) >= prioritas(c)) {
                postfix += st.top();
                postfix += " ";
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        postfix += " ";
        st.pop();
    } 

    return postfix;
}

int main(void) {
    string ekspresiSoal;
    
    cout << "Masukkan ekspresi Infix: ";
    getline(cin, ekspresiSoal);
    
    string hasilAlgoritma = infixToPostfix(ekspresiSoal);
    
    cout << "Postfix = " << hasilAlgoritma << endl;

    return 0;
}