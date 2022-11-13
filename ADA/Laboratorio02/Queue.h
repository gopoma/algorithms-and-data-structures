// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio02 - Importancia de los algoritmos en la solución de problemas
// Fecha: 6/10/2022

#include "LinkedList.h"

template <typename T>
class Queue {
    private:
        LinkedList<T> *list;
    public:
        Queue();
        int getLength();
        bool isEmpty();
        void enqueue(T value);
        void dequeue();
        void show();
};

template <typename T>
Queue<T>::Queue() {
    list = new LinkedList<T>();
}

template <typename T>
int Queue<T>::getLength() {
    return list->getLength();
}

template <typename T>
bool Queue<T>::isEmpty() {
    return list->isEmpty();
}

template <typename T>
void Queue<T>::enqueue(T value) {
    list->insertLast(value);
}

template <typename T>
void Queue<T>::dequeue() {
    list->removeFirst();
}

template <typename T>
void Queue<T>::show() {
    list->show(false);
}