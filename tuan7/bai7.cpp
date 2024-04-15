#include <bits/stdc++.h>
using namespace std;

int countOccurrences(const char* str1, const char* str2) {
    int count = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 0; i <= len2 - len1; i++) {
        if (strncmp(str1, str2 + i, len1) == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    const char* str1 = "apple";
    const char* str2 = "pineapple";

    int occurrences = countOccurrences(str1, str2);

    cout << occurrences << endl;

    return 0;
}
