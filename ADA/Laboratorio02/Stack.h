// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio02 - Importancia de los algoritmos en la solución de problemas
// Fecha: 6/10/2022

#include "LinkedList.h"

template <typename T>
class Stack {
    private:
        LinkedList<T> *list;
    public:
        Stack();
        int getLength();
        bool isEmpty();
        void push(T value);
        void pop();
        void show();
};

template <typename T>
Stack<T>::Stack() {
    list = new LinkedList<T>();
}

template <typename T>
int Stack<T>::getLength() {
    return list->getLength();
}

template <typename T>
bool Stack<T>::isEmpty() {
    return list->isEmpty();
}

template <typename T>
void Stack<T>::push(T value) {
    list->insertFirst(value);
}

template <typename T>
void Stack<T>::pop() {
    list->removeFirst();
}

template <typename T>
void Stack<T>::show() {
    list->show(true);
}