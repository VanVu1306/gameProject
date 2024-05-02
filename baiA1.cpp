#include <bits/stdc++.h>
using namespace std;

char* concat(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int totalLen = len1 + len2;
    char* result = new char[totalLen + 1];
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main() {
    const char* str1 = "Hello";
    const char* str2 = "World";

    char* result = concat(str1, str2);
    cout << result << endl;
    delete[] result;

    return 0;
}

