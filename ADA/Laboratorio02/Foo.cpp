#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    try {
        LinkedList<long long> *list = new LinkedList<long long>();
        list->insertLast(0);
        list->insertLast(2);
        list->insertLast(0);
        list->insertLast(2);
        list->insertLast(2);
        list->insertLast(0);
        list->insertLast(1);
        list->remove(1);
        cout << list->getLength() << endl;
        list->show(false);
    } catch(...) {
    }
    return 0;
}