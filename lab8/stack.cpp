#include "stack.h"

template<class T>

void Stack<T>::push(T value) {

    if (NeedToResize()){ Resize();}
    data[top] = value;
    top++;
}

template<class T>
T Stack<T>::peek() {
    if (top <= 0){
        throw std::out_of_range ("stack is empty");
    }
    return data[top - 1];
}

template<class T>
T Stack<T>::pop() {
    if (top <= 0) {
        throw std::out_of_range("stack is empty");
    }
    top--;
    return data[top];
}
    template<class T>
bool Stack<T>::NeedToResize() {
        return (size == top);
}

template<class T>
void Stack<T>::Resize() {

    T* newdata = new T[size*2];
    for (int i = 0; i < size; ++i)

        newdata[i] = data[i];
    data = newdata;
    size*=2;
}