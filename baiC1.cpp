#include <bits/stdc++.h>
using namespace std;

char* reverse(const char* a) {
    int length = 0;
    while (a[length] != '\0') {
        length++;
    }
    char* result = new char[length + 1];
    for (int i = 0; i < length; i++) {
        result[i] = a[length - i - 1];
    }
    result[length] = '\0';
    return result;
}

char* delete_char(const char* a, char c) {
    int length = 0;
    while (a[length] != '\0') {
        length++;
    }
    char* result = new char[length + 1];
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (a[i] != c) {
            result[index] = a[i];
            index++;
        }
    }
    result[index] = '\0';
    return result;
}

char* pad_right(const char* a, int n) {
    int length = 0;
    while (a[length] != '\0') {
        length++;
    }
    if (length >= n) {
        char* result = new char[length + 1];
        for (int i = 0; i < length; i++) {
            result[i] = a[i];
        }
        result[length] = '\0';
        return result;
    }
    else {
        char* result = new char[n + 1];
        int i;
        for (i = 0; i < length; i++) {
            result[i] = a[i];
        }
        for (; i < n; i++) {
            result[i] = ' ';
        }
        result[n] = '\0';
        return result;
    }
}

char* pad_left(const char* a, int n) {
    int length = 0;
    while (a[length] != '\0') {
        length++;
    }
    if (length >= n) {
        char* result = new char[length + 1];
        for (int i = 0; i < length; i++) {
            result[i] = a[i];
        }
        result[length] = '\0';
        return result;
    }
    else {
        char* result = new char[n + 1];
        int i;
        for (i = 0; i < n - length; i++) {
            result[i] = ' ';
        }
        for (int j = 0; j < length; j++, i++) {
            result[i] = a[j];
        }
        result[n] = '\0';
        return result;
    }
}

char* truncate(const char* a, int n) {
    int length = 0;
    while (a[length] != '\0') {
        length++;
    }
    if (length <= n) {
        char* result = new char[length + 1];
        for (int i = 0; i < length; i++) {
            result[i] = a[i];
        }
        result[length] = '\0';
        return result;
    }
    else {
        char* result = new char[n + 1];
        for (int i = 0; i < n; i++) {
            result[i] = a[i];
        }
        result[n] = '\0';
        return result;
    }
}

char* trim_left(const char* a) {
    int length = 0;
    int start = 0;
    while (a[length] != '\0') {
        if (a[length] != ' ') {
            start = length;
            break;
        }
        length++;
    }
    int newLength = 0;
    while (a[start] != '\0') {
        newLength++;
        start++;
    }
    char* result = new char[newLength + 1];
    for (int i = 0; i < newLength; i++) {
       result[i] = a[start++];
    }
    result[newLength] = '\0';
    return result;
}

char* trim_right(const char* a) {
    int length = 0;
    while (a[length] != '\0') {
        length++;
    }
    int newLength = length;
    while (newLength > 0 && a[newLength - 1] == ' ') {
        newLength--;
    }
    char* result = new char[newLength + 1];
    for (int i = 0; i < newLength; i++) {
        result[i] = a[i];
    }
    result[newLength] = '\0';
    return result;
}

int main() {
    const char* input = "Hello, World!";

    char* reversed = reverse(input);
    cout << reversed << endl;
    delete[] reversed;

    char* deleted = delete_char(input, 'l');
    cout << deleted << endl;
    delete[] deleted;

    char* paddedRight = pad_right(input, 20);
    cout << paddedRight << endl;
    delete[] paddedRight;

    char* paddedLeft = pad_left(input, 20);
    cout << paddedLeft << endl;
    delete[] paddedLeft;

    char* truncated = truncate(input, 5);
    cout << truncated << endl;
    delete[] truncated;

    const char* trimmedLeft = trim_left("  Hello");
    cout << trimmedLeft << endl;
    delete[] trimmedLeft;

    const char* trimmedRight = trim_right("Hello  ");
    cout << trimmedRight << endl;
    delete[] trimmedRight;

    return 0;
}
