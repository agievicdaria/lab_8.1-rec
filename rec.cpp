#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(const char *str, size_t i) {
    if (strlen(str) < 2 || str[i] == 0) {
        return 0;
    }
    if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n')) {
        return 1 + Count(str, i + 2);
    }
    else {
        return Count(str, i + 1);
    }
}

void Change(char *dest, const char *str, size_t i, size_t j) {
    if (str[i] == 0) {
        dest[j] = '\0';
        return;
    }

    if ((str[i] == 'n' && str[i + 1] == 'o')) {
        strcat(dest, "***");
        Change(dest, str, i + 2, j + 3);
    }
    else {
        dest[j] = str[i];
        dest[j + 1] = '\0';
        Change(dest, str, i + 1, j + 1);
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    
    cout << "String contains " << Count(str, 0) << " pairs of 'no' or 'on'" << endl;

    size_t len = strlen(str);
    char dest[len * 3 / 2 + 1];
    dest[0] = '\0';
    
    Change(dest, str, 0, 0);
    cout << "Modified string: " << dest << endl;

    return 0;
}
