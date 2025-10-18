// Write a program to recognize a string under the rule „a+b*c+‟.

#include<bits/stdc++.h>
using namespace std;
int main()
{

string s;
while(cin>>s){
    int stage =0;
    for(int i=0; i<s.length();i++){
        if(stage == 0 && s[i]=='a'){
            stage =1;
        }
        else if(stage == 0 && s[i]!='a')
        {
            stage = 4;
            break;
        }
        else if(stage == 1 && s[i]=='a'){
            stage =1;
        }
        else if(stage == 1 && s[i]=='b'){
            stage =2;
        }
         else if(stage == 1 && s[i]=='c'){
            stage =3;
        }
        else if(stage ==1 && (s[i]!='a' || s[i]!='b' || s[i]!='c')){
            stage = 4;
            break;
        }
        else if(stage == 2 && s[i]=='b'){
            stage =2;
        }
        else if(stage == 2 && s[i]=='c'){
            stage =3;
        }
        else if(stage == 2 && (s[i]!='b' || s[i]!='c')){
            stage =4; break;
        }
        else if(stage ==3 && s[i]=='c'){
            stage =3;
        }
        else if(stage ==3 && s[i]!='c'){
            stage =4; break;
        }

    }
    if(stage==3){
        cout<<s<<" is recognized"<<endl;
    }
    else{
        cout<<s<<" is not recognized"<<endl;
    }
}
    return 0;
}
