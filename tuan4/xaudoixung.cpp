#include <bits/stdc++.h>
using namespace std;
bool doixung (string s) {
    int i=0;
    int j= s.length()-1;
    while (i<j) {
        if (s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main () {
    string n;
    cin >> n;
    if (doixung(n)) cout << "Yes" << endl;
    else {cout << "No" << endl;}
    return 0;
}
