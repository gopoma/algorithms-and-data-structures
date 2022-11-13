// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio02 - Importancia de los algoritmos en la solución de problemas
// Fecha: 6/10/2022

template <typename T>
class Node {
    private:
        T data;
        Node<T> *next = nullptr;
    public:
        Node(T _data);
        void setData(T _data);
        T getData();
        void setNext(Node<T> *next);
        Node<T> *getNext();
};

template <typename T>
Node<T>::Node(T _data) {
    setData(_data);
}

template <typename T>
void Node<T>::setData(T _data) {
    data = _data;
}

template <typename T>
T Node<T>::getData() {
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