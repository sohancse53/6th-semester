//Convert The Expression: a+(b-c) into prefix operation.

#include <bits/stdc++.h>
using namespace std;

int prec(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return -1;
}

string toPrefix(string exp) {
    stack<char> s;
    string ans = "";

    reverse(exp.begin(), exp.end());

    for(int i=0; i<exp.size(); i++){
        char c = exp[i];

        if(isalnum(c)){
            ans += c;
        } else if(c==')'){
            s.push(c);
        } else if(c=='('){
            while(!s.empty() && s.top()!=')'){
                ans += s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();
        } else {
            while(!s.empty() && prec(s.top()) > prec(c)){
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

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string exp = "a+(b-c)";
    cout << "Prefix: " << toPrefix(exp) << endl;
    return 0;
}
