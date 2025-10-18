//Convert The Expression: a+(b-c) into postfix operation.

#include <bits/stdc++.h>
using namespace std;

int prec(char op){
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    return -1;
}

string toPostfix(string exp){
    stack<char> s;
    string ans = "";

    for(int i=0; i<exp.size(); i++){
        char c = exp[i];

        if(isalnum(c)){
            ans += c; // operand goes to result
        } else if(c=='('){
            s.push(c);
        } else if(c==')'){
            while(!s.empty() && s.top()!='('){
                ans += s.top();
                s.pop();
            }
            if(!s.empty()) s.pop(); // pop '('
        } else {
            while(!s.empty() && prec(s.top()) >= prec(c)){
                ans += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while(!s.empty()){
        ans += s.top();
        s.pop();
    }

    return ans;
}

int main(){
    string exp = "a+(b-c)";
    cout << "Postfix: " << toPostfix(exp) << endl;
    return 0;
}
