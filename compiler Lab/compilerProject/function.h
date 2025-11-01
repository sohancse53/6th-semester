#include<bits/stdc++.h>
#include<math.h>
using namespace std;

//addition
long long JogKoro(long long a, long long b) {
    long long result = a + b;
    cout << "JogFol = " << result << endl;
    return result;
}
//sub
long long BiyogKoro(long long a, long long b) {
    long long result = a - b;
    cout << "BiyogFol = " << result << endl;
    return result;
}
//multiply
long long GunKoro(long long a, long long b) {
    long long result = a * b;
    cout << "GunFol = " << result << endl;
    return result;
}
//division
long long VagKoro(long long a, long long b) {
    long long result = (b != 0) ? a / b : 0;
    cout << "VagFol = " << result << endl;
    return result;
}
//remainder
long long BakiKoro(long long a, long long b) {
    long long result = (b != 0) ? a % b : 0;
    cout << "Vagshesh = " << result << endl;
    return result;
}
// sqaure root
long long BorgMul(long long n){
long long result = sqrt(n);
cout<<"BorgoMul holo :"<<result<<endl;
}
// print a value
void bolo(const string& message) {
    cout << message << endl;
}

void bolo(int value) {
    cout << value << endl;
}

void bolo(double value) {
    cout << value << endl;
}

// newline print
void NotunLine(){
cout<<endl;
}

//assigning value
void ManBoshao(int &var, int value) {
    var = value;
}

void ManBoshao(double &var, double value) {
    var = value;
}

void ManBoshao(std::string &var, std::string value) {
    var = value;
}

// increment by one
int Ekbarau(int &a){
    a++;

}
//decrement one
int EkKamao(int &a){
    a--;
}
//decrement two
int DuiJogKoro(int &a){
a+=2;
}

//decreament one
int EkBiyogKoro(int &a){
    a--;
}

//multiply 10
int DoshGunKoro(int &a){
    a=a*10;
}
// half a number
int ArdhekKoro(int &a){
    a=a/2;
}

//make the value reset to zero(0)
int ShunnoKoro(int &a){
    a=0;
}
//copy value stored in to
void CopyKoro(int from, int &to) {
    to = from;
}

void CopyKoro(double from, double &to) {
    to = from;
}

void CopyKoro(string from, string &to) {
    to = from;
}

// negation of a number;
void BiporitChihno(int &a) {
    a=-a;
}

//check if the number is zero
void ShunnoKi(int a) {
    if(a==0){
        cout<<"Ha Shunno!";
    }
    else{
        cout<<"Na Shunno Na!";
    }
}

//swapping
void BodolKoro(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void BodolKoro(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void BodolKoro(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

//floor
double NicherGol(double value) {
    return floor(value);   // rounds down
}
//ceil
double UporerGol(double value) {
    return ceil(value);    // rounds up
}
