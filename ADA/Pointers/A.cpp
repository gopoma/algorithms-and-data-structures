#include <iostream>

using namespace std;

int *getNums() {
    int *p = new int[100];
    for(int i = 0; i < 100; i++) {
        p[i] = i;
    }
    return p;
}

int main() {
    int *ptr = getNums();
    for(int i = 0; i < 100; i++) {
        cout << *(ptr+i) << " ";
    }
    cout << endl;

    return 0;
}