#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s){
        int state = 0;
        for(int i =0;i<s.length();i++){
            if(state == 0 && s[i]=='a'){
                state = 1;
            }
            else if(state == 0 && s[i] != 'a'){
                state = 4;
                break;
            }
            else if(state == 1 && s[i]=='a'){
                state = 1;
            }
            else if(state == 1 && s[i]=='b'){
                state = 2;
            }
             else if(state == 1 && s[i]=='c'){
                state = 3;
            }
             else if(state == 1 && (s[i]!='a' || s[i]!='b' || s[i]!='c')){
                state = 4;
                break;
            }
             else if(state == 2 && s[i]=='b'){
                state = 2;
            }
             else if(state == 2 && s[i]=='c'){
                state = 3;
            }
             else if(state == 2 &&  s[i]!='b' || s[i]!='c'){
                state = 4;
                break;
            }
            else if(state == 3 && s[i]=='c'){
                state = 3;
            }
            else if(state == 3 && s[i]!='c'){
                state = 4;
                break;
            }

        }
        if(state == 3){
            cout<<"YES"<<endl;
        }
        else{
             cout<<"NO"<<endl;
        }

    }
}
