// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio02 - Importancia de los algoritmos en la solución de problemas
// Fecha: 7/10/2022

#include <iostream>
#include "Client.h"

using namespace std;

ostream& operator<<(ostream &os, Client *c) {
    os << "Fullname: " << c->getFirstname() << " " << c->getLastname() << endl;
    os << "DNI: " << c->getDNI() << endl;
    os << "Account Number: " << c->getAccountNumber() << endl;
    os << "Balance: " << c->getBalance() << endl;
    return os;
}

template <typename T>
class Node {
    private:
        T *data;
        Node<T> *next;
    public:
        Node(T *_data);
        void setData(T *_data);
        T *getData();
        void setNext(Node<T> *_next);
        Node<T> *getNext();
};

template <typename T>
Node<T>::Node(T *_data) {
    setData(_data);
    setNext(nullptr);
}

template <typename T>
void Node<T>::setData(T *_data) {
    data = _data;
}

template <typename T>
T *Node<T>::getData() {
    return data;
}

template <typename T>
void Node<T>::setNext(Node<T> *_next) {
    next = _next;
}

template <typename T>
Node<T> *Node<T>::getNext() {
    return next;
}

template <typename T>
class Queue {
    private:
        Node<T> *root;
        int length;
    public:
        Queue();
        int getLength();
        bool isEmpty();
        void enqueue(T *value);
        void dequeue();
        void show();
};

template <typename T>
Queue<T>::Queue() {
    root = nullptr;
    length = 0;
}

template <typename T>
int Queue<T>::getLength() {
    return length;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return getLength() == 0;
}

template <typename T>
void Queue<T>::enqueue(T *value) {
    if(isEmpty()) {
        root = new Node<T>(value);
    } else {
        Node<T> *aux = root;
        while(aux->getNext() != nullptr) {
            aux = aux->getNext();
        }
        aux->setNext(new Node<T>(value));
    }
    length++;
}

template <typename T>
void Queue<T>::dequeue() {
    if(isEmpty()) {
        cout << "No hay Elementos en la Cola" << endl;
    } else {
        root = root->getNext();
        length--;
    }
}

template <typename T>
void Queue<T>::show() {
    if(isEmpty()) {
        cout << "No hay Clientes para mostrar" << endl;
        return;
    }
    int counter = 0;
    Node<T> *aux = root;
    while(aux != nullptr) {
        cout << "Cliente #" << ++counter << ": " << endl;
        cout << aux->getData() << endl;
        aux = aux->getNext();
    }
}

int main() {
    char input;
    string firstname, lastname, dni, password, accountNumber;
    double balance;
    Queue<Client> *q = new Queue<Client>();
    do {
        cout << "Banco 'El Lagarto'" << endl;
        cout << "Operaciones disponibles:" << endl;
        cout << "[1] Agregar un Cliente" << endl;
        cout << "[2] Desencolar un Cliente" << endl;
        cout << "[3] Mostrar todos los Clientes" << endl;
        cout << "[4] Salir" << endl;
        cout << "Introduzca una opcion: ";
        cin >> input;
        switch(input) {
            case '1':
                cout << "Firstname: ";
                cin >> firstname;
                cout << "Lastname: ";
                cin >> lastname;
                cout << "DNI: ";
                cin >> dni;
                cout << "Password: ";
                cin >> password;
                cout << "Account Number: ";
                cin >> accountNumber;
                cout << "Balance: ";
                cin >> balance;
                q->enqueue(new Client(firstname, lastname, dni, password, accountNumber, balance));
                break;
            case '2':
                q->dequeue();
                break;
            case '3':
                q->show();
                break;
            case '4':
                break;
            default:
                cout << "Entrada invalida" << endl;
        }
        cout << endl;
    } while(input != '4');

    return 0;
}