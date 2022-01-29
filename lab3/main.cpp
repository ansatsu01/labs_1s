#include <iostream>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

const int maxSize(10);

int getValue(vector < vector <int> > &vec, int i, int j, int size) {

    if (i + j + 1 < size) {
        return 0;
    }
    else {
        return vec[i][j];
    }
}

void fillingWithConsole(vector<vector<int>>& vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; i + j < size; j++)
        {

            cin >> vec[i][j];
        }
    }
}

void FillingWithRand(vector<vector<int>>& vec, int size) {

    srand(time(NULL));
    for (int i = size - 1; i >= 0; i--) {
        for (int j = size - 1 - i; j < size; j++) {
            vec[i][j] = rand() % 20 - 10;
        }
    }
}


void FillingMatrix(vector<vector<int>>& vec, const int size) {

    cout << "Choose the way of filling matrix" << endl;
    cout << "Enter 1 for filling with console" << endl;
    cout << "Enter 2 for filling with random" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {

            fillingWithConsole(vec, size);
            return;
        }
        case 2:
            FillingWithRand(vec, size);
            return;
        default:
            cout << "wrong data";
            return;
    }
}


void showMatrix(vector<vector<int>>& vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            getValue(vec, i, j, size);
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}


void ShowSum(vector<vector<int>>& vec, int size)
{
    int sum = 0;
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            getValue(vec, j, i, size);

            if (vec[i][j] >= 0) {

                sum += vec[i][j];
            }
            else {
                k = k + 1;
            }
        }

        if (k > 0) {

            cout << "There is a negative element in " << i << " line";
            cout << endl;
        }

        else {
            cout << "The sum of elements in line " << i << " = " << sum;
            cout << endl;
        }
        sum = 0;
        k = 0;
    }

}


int SearchMinInDia(vector<vector<int>>& vec, int size) {

    int min = getValue(vec, 1, 0, size);
    for (int i = 1; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size() - i; ++j) {

            if (getValue(vec, i + j, j, size) < min)
                min = getValue(vec, i + j, j, size);
            if (getValue(vec, j, i + j, size) < min)
                min = getValue(vec, j, i + j, size);
        }
    }
    return min;
}





int main() {

    cout << "Enter the size of your matrix, it should be less than 10" << endl;
    int size;
    cin >> size;
    if (size > maxSize) {
        cout << "Error! Start again and enter the appropriate size" << endl;
        return 0;
    }
    vector < vector <int> > vec(size, vector <int>(size));

    FillingMatrix(vec, size);
    showMatrix(vec, size);
    ShowSum(vec, size);
    cout << SearchMinInDia(vec, size);
}
