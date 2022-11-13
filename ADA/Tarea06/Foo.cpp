#include <iostream>

using namespace std;

template <typename T>
class Node {
    private:
        T *data;
        Node<T> *next;
    public:
        Node(T *data);
        setData(T *data);
        *getData();
        setNext(Node<T> *next);
        Node<T> *getNext();
};

template <typename T>
class LinkedList {
    private:
        Node<T> *root;
        int length;
    public:
        LinkedList();
        int getLength();
        bool isEmpty();
        void insertFirst(T *value);
        void insertLast(T *value);
        void removeFirst();
        void remove(T *value);
        void show();
};

int main() {
    long long myVariable = 10254579;
    cout << myVariable << endl; // 10254579
    cout << &myVariable << endl; // 0x1f3dfff7f8

// Primitive Data Types
bool condition = false;
char character = 'C';
int integer = 25;
float fdecimal = 79.89;
double decimal = 7989.5432;

// Type Modified Primite Data Types
long longInteger = 6798943;
long long longerInteger = 78345937894345;
long double aux = 34827399.23842;
unsigned int age = 20;
short int hamsterPopulation = 32000;

    return 0;
}