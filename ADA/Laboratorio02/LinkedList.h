// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio02 - Importancia de los algoritmos en la solución de problemas
// Fecha: 6/10/2022

#include "Node.h"

template <typename T>
class LinkedList {
    private:
        Node<T> *root;
        int length;
    public:
        LinkedList();
        int getLength();
        bool isEmpty();
        void insertFirst(T value);
        void insertLast(T value);
        void removeFirst();
        void show(bool reverse);
        T getLast();
        void remove(T value);
};

template <typename T>
LinkedList<T>::LinkedList() {
    root = nullptr;
    length = 0;
}

template <typename T>
int LinkedList<T>::getLength() {
    return length;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    return getLength() == 0;
}

template <typename T>
void LinkedList<T>::insertFirst(T value) {
    if(isEmpty()) {
        root = new Node<T>(value);
    } else {
        Node<T> *aux = new Node<T>(value);
        aux->setNext(root);
        root = aux;
    }
    length++;
}

template <typename T>
void LinkedList<T>::insertLast(T value) {
    if(isEmpty()) {
        insertFirst(value);
    } else {
        Node<T> *aux = root;
        while(aux->getNext() != nullptr) {
            aux = aux->getNext();
        }
        aux->setNext(new Node(value));
        length++;
    }
}

template <typename T>
void LinkedList<T>::removeFirst() {
    if(isEmpty()) {
        std::cout << "No hay Elementos disponibles" << std::endl;
        return;
    } else if(getLength() == 1) {
        root = nullptr;
    } else {
        root = root->getNext();
    }
    length--;
}

template <typename T>
void LinkedList<T>::show(bool reverse) {
    T *result = new T[getLength()];
    int counter = 0;
    Node<T> *aux = root;
    while(aux != nullptr) {
        result[counter++] = aux->getData();
        aux = aux->getNext();
    }

    for(int i = 0; i < getLength(); i++) {
        T value = reverse ? result[getLength() - i - 1] : result[i];
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T LinkedList<T>::getLast() {
    if(isEmpty()) {
        throw "There aren't any Elements";
    }
    Node<T> *aux = root;
    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
    }
    return aux->getData();      
}

template <typename T>
void LinkedList<T>::remove(T value) {
    if(isEmpty()) {
        throw "There aren't any Elements";
    } else {
        Node<T> *aux = root;
        while(aux->getNext() != nullptr) {
            if(aux->getNext()->getData() == value) {
                aux->setNext(aux->getNext()->getNext());
                length--;
            } else {
                aux = aux->getNext();
            }
        }
        if(root->getData() == value) {
            removeFirst();
        }
    }
}