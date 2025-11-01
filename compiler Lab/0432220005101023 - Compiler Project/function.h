#include<bits/stdc++.h>
using namespace std;

long long jog_hobe(long long a, long long b) { 
    long long result = a + b;
    cout << "JogFol = " << result << endl;
    return result;
}

long long biyog_hobe(long long a, long long b) { 
    long long result = a - b;
    cout << "BiyogFol = " << result << endl;
    return result;
}

long long gun_hobe(long long a, long long b) { 
    long long result = a * b;
    cout << "GunFol = " << result << endl;
    return result;
}

long long vag_hobe(long long a, long long b) { 
    long long result = (b != 0) ? a / b : 0;
    cout << "VagFol = " << result << endl;
    return result;
}

long long vagshesh_hobe(long long a, long long b) { 
    long long result = (b != 0) ? a % b : 0;
    cout << "Vagshesh = " << result << endl;
    return result;
}

bool soman_check(long long a, long long b) { 
    bool result = a == b;
    cout << "Songkha duita soman? => " << (result ? "Hae\n" : "Na\n");
    return result;
}

bool boro_check(long long a, long long b) { 
    bool result = a > b;
    cout << "Prothom songkha ti boro? => " << (result ? "Hae\n" : "Na\n");
    return result;
}

bool choto_check(long long a, long long b) { 
    bool result = a < b;
    cout << "Prothom songkha ti choto? => " << (result ? "Hae\n" : "Na\n");
    return result;
}

bool bigORequal(long long a, long long b) { 
    bool result = a >= b;
    cout << "Prothom songkha ti boro othoba soman? => " << (result ? "Hae\n" : "Na\n");
    return result;
}

bool smallORequal(long long a, long long b) { 
    bool result = a <= b;
    cout << "Prothom songkha ti choto othoba soman? => " << (result ? "Hae\n" : "Na\n");
    return result;
}

long long abs_man(long long x) { 
    long long result = (x < 0) ? -x : x;
    cout << "Absolute man = " << result << endl;
    return result;
}

long long max_eta(long long a, long long b) { 
    long long result = (a > b) ? a : b;
    cout << "Sorboccho songkha = " << result << endl;
    return result;
}

long long min_eta(long long a, long long b) { 
    long long result = (a < b) ? a : b;
    cout << "Sorbonimno songkha = " << result << endl;
    return result;
}

long long Sqr(long long x) { 
    long long result = x * 1LL * x;
    cout << "Borgo er man = " << result << endl;
    return result;
}

long long cube(long long x) { 
    long long result = x * 1LL * x * x;
    cout << "Ghono er man = " << result << endl;
    return result;
}

bool AND(bool a, bool b) { 
    bool result = a && b;
    cout << "AND = " << result << endl;
    return result;
}

bool OR(bool a, bool b) { 
    bool result = a || b;
    cout << "OR = " << result << endl;
    return result;
}

bool NOT(bool a) { 
    bool result = !a;
    cout << "NOT = " << result << endl;
    return result;
}

bool XOR(bool a, bool b) { 
    bool result = a != b;
    cout << "XOR = " << result << endl;
    return result;
}

long long bitwiseAND(long long a, long long b) { 
    long long result = a & b;
    cout << "BitwiseAND = " << result << endl;
    return result;
}

long long bitwiseOR(long long a, long long b) { 
    long long result = a | b;
    cout << "BitwiseOR = " << result << endl;
    return result;
}

long long bitwiseXOR(long long a, long long b) { 
    long long result = a ^ b;
    cout << "BitwiseXOR = " << result << endl;
    return result;
}

long long bitwiseNOT(long long a) { 
    long long result = ~a;
    cout << "BitwiseNOT = " << result << endl;
    return result;
}

long long leftSHIFT(long long a, long long shift) { 
    long long result = a << shift;
    cout << "LeftSHIFT = " << result << endl;
    return result;
}

long long rightSHIFT(long long a, long long shift) { 
    long long result = a >> shift;
    cout << "RightSHIFT = " << result << endl;
    return result;
}

long long ek_beshi(long long &x) { 
    long long result = ++x;
    cout << "Ek baranu holo = " << result << endl;
    return result;
}

long long ek_kom(long long &x) { 
    long long result = --x;
    cout << "Ek komanu holo = " << result << endl;
    return result;
}

bool jor_check(long long x) { 
    bool result = x % 2 == 0;
    cout << "Eta ki jor songkha? => " << (result ? "Hae\n" : "Na\n");
    return result;
}

bool bijor_check(long long x) { 
    bool result = x % 2 != 0;
    cout << "Eta ki bijor songkha? => " << (result ? "Hae\n" : "Na\n");
    return result;
}