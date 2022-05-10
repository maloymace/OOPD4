#include <iostream>
#include <random>
using namespace std;

double* giveMemory(double *newArr, int sizeOfArray);
void printArr(double *newArr, int sizeOfArray);
void fillArr(double *newArr, int sizeOfArray);
double* freeMem(double *newArr);

int main() {
    double* arr = 0;
    char userInput = 0;

    do {
        int sizeOfArray = 0;
        cout << "Enter array size: ";
        cin >> sizeOfArray;
        arr = giveMemory(arr, sizeOfArray);
        fillArr(arr, sizeOfArray);
        printArr(arr, sizeOfArray);
        arr = freeMem(arr);


        cout << "\nContinue?(1). Exit? (0): ";
        cin >> userInput;
    } while (userInput != '0');
    return 0;
}

double* giveMemory(double *newArr, int sizeOfArray) {
    newArr = new double[sizeOfArray];
    return newArr;
}

void fillArr(double *newArr, int sizeOfArray){
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0.00, 1000.00);
    for (int i = 0; i < sizeOfArray; i++) {
        newArr[i] = dist(mt);
    }
}

void printArr(double *newArr, int sizeOfArray){
    cout << "The array is: ";
    for (int i = 0; i < sizeOfArray; i++) {
        cout << newArr[i] << " ";
    }
}

double* freeMem(double *newArr){
    delete[] newArr;
    newArr = nullptr;

    return newArr;
}
