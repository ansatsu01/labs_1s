#pragma once

#include <iostream>

using namespace std;
template <typename T>
class Stack {

private:
    T *data;
    int top;
    int size;


    void Resize();
    bool NeedToResize();

public:

    Stack() {
        top = 0;
        size = 10;
        data = new T[size];
    }

    bool IsEmpty() {
        return top == 0;
    }

    void push(T value);


    T pop();

    T peek();




    bool operator<(Stack const &eq) {

        return this->size < eq.size;
    }

    bool operator==(Stack const &eq) {

        return  this->size == eq.size;
    }


    T operator[](int index) {

        if (index > top) {

            throw runtime_error ("incorrect index");
        }

        return data[index];
    }

    Stack &operator=(Stack const &eq) {

        if (*this == eq) {

            for (int i = 0; i < eq.size; ++i) {

                this->st[i] = eq.st[i];
            }
            return *this;
        } else {

            this->size = eq.size;
            delete[] this->st;
            this->st = new int[eq.size];

            for (int i = 0; i < eq.size; ++i) {

                this->st[i] = eq.st[i];
            }
            this->top = eq.top;
            return *this;
        }
    }



    void print(ostream &out) {

        if (IsEmpty()) {
            throw runtime_error("Stack is empty");
        } else {

            for (int i = size - 1; i >= 0; i--) {

                out << data[i] << " ";
            }

        }

    }
    void operator<<(T value) {
        if (size == top) { Resize(); }

        data[top] = value;
        top++;
    }

};
