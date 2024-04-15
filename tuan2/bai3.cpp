#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a + b <= c || b + c <= a || c+a <= b){
        cout << "NO" << endl;
    }
    else if(a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b){
        cout << a+b+c << endl;
        cout << "vuong" << endl;
    }
    else if(a == b && b == c){
        cout << a+b+c << endl;
        cout << "deu" << endl;
    }
    else if(a == b || b == c || c == a){
        cout << a+b+c << endl;
        cout << "can" << endl;
    }
    else if(a*a > b*b + c*c || b*b > c*c + a*a || c*c > a*a + b*b){
        cout << a+b+c << endl;
        cout << "tu" << endl;
    }
    else {
        cout << a+b+c << endl;
        cout << "nhon" << endl;
    }
    return 0;
}
