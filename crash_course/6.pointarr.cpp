#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int *sortAsc(int *arr, int n) {
    n--;
    for ( n; n > 0; n-- ) {
        for (int i = 0; i < n; i++ ) {
            if (*(arr+n) < *(arr+i)) {
                int temp = *(arr+i);
                *(arr+i) = *(arr+n);
                *(arr+n) = temp;
           }
       }
   }
   return arr;
}

void printMatrix(int n) //you dont have to use "int n" anywhere in the code, it's passed for testing purposes
{
  int matrix[5][5];

  for (int i = 0; i < 25; i++) {
      matrix[i/5][i%5] = i+1;
  }
  
  for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
          cout << matrix[i][j] << " ";
      }
      cout << "\n";
  }
}

void diagMatrix(int n) //you dont have to use "int n" anywhere in the code, it's passed for testing purposes
{
   // int matrix[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            short o;
            if (i == j) { o = 0; }
            if (i < j)  { o = 1; }
            if (i > j)  { o = -1; }
            cout << o << " ";
        }
        cout << "\n";
    }
}

void printPascalTr(int size) { //define your function
    int *row = new int[size];
    row[0] = 1;
    for (int i = 0; i < size; i++) {
        for (int j = i; j >= 0; j--) {
            if (j-1 >= 0) { row[j]+=row[j-1]; }
        }
        for (int j = 0; j <= i; j++) {
            cout << row[j] << " ";
        }
        cout << "\n";
    }
    delete[] row;
    row = NULL;
}

int main() {
    cout << "Matrix of numbers: \n";
    printMatrix(0);
    cout << "Diagonal magrix: \n";
    diagMatrix(0);
    int s;
    cout << "Enter the size of Pascal triangle: ";
    cin >> s;
    printPascalTr(s);
    return 0;
}
