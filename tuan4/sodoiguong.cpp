#include <bits/stdc++.h>
using namespace std;
bool doixung (int n) {
    string s = to_string(n);
    int i=0;
    int j= s.length()-1;
    while (i<j) {
        if (s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int countDoiXung (int A, int B) {
    int cnt=0;
    for (int i=A; i<=B; i++) {
        if (doixung(i)) cnt++;  }
    return cnt;
}
int main () {
    int T;
    cin >> T;
    for (int i=1; i<=T; i++) {
        int A, B;
        cin >> A >> B;
        int res = countDoiXung (A,B);
        cout << res << endl;
    }
    return 0;
}
