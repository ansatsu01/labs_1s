#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main() {

    cout << "Enter the max dimension of the array: ";
    int lng;
    cin >> lng;

    int *array = new int[lng];

    cout << "Choose the way of filling the array" << endl;
    cout << "Enter " << 1 << " to fill from the keyboard.Enter " << 2 << " for random filling " << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {

            for (int i = 0; i < lng; ++i) {
                cin >> array[i];
            }
            break;
        }
        case 2: {

            srand(time(NULL));
            cout << "THE ARRAY : " << endl;
            for (int i = 0; i < lng; ++i) {

                array[i] = rand() % 30 - 15;
                cout << array[i] << endl;
            }
            break;
        }
    }


    int minvalue = array[0];

    for (int k = 0; k < lng; ++k) {

        if (abs(array[k]) < abs(minvalue)) {

            minvalue = (array[k]);
        }
    }
    cout << "Minimal element of the array  " << minvalue << endl;


    int sum = 0;
    for (int i = lng - 1; i >= 0 && abs(array[i]) > 0; i--) {

        sum += array[i];
    }

    bool zeroExists;
    zeroExists = false;

    for (int i = 0; i < lng && !zeroExists; i++) {
        if (array[i] == 0) {
            zeroExists = true;
        }
    }

    if (zeroExists == true) {

        cout << "Sum after the last zero element :  " << sum << endl;
    } else {
        cout << " The array has no zero elements " << endl;
    }

    cout << "NEW ARR : " << endl;

    int begin = 0;

    int *new_arr =new int[10];

    for (int i = 0; i < lng; ++i) {
        if (i % 2 == 0) {
            new_arr[begin] = array[i];
            begin++;
        }
    }

    for (int i = 0; i < lng; ++i) {
        if (i % 2 != 0) {
            new_arr[begin] = array[i];
            begin++;
        }
    }

    for (int i = 0; i < lng; ++i) {
        cout <<new_arr[i] << " ";
    }

    return 0;
}
