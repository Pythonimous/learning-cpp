#include <iostream>
#include <cmath>

using namespace std;

int* bubbleSort(int *pArr, int n) {
  --n;
  for (n; n > 0; --n) {
    for (int i = 0; i < n; ++i) {
      if (*(pArr+n) < *(pArr+i)) {
        int temp = *(pArr+i);
        *(pArr+i) = *(pArr+n);
        *(pArr+n) = temp;
      }
    }
  }
  return pArr;
}

void printMatrix(int n)
{
  int matrix[5][5];

  for (int i = 0; i < 25; ++i) {
    matrix[i/5][i%5] = i+1;
  }
  
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
}

void diagMatrix(int n)
{
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      short o;
      if (i == j) { o = 0; }
      if (i < j)  { o = 1; }
      if (i > j)  { o = -1; }
      cout << o << " ";
      }
    cout << "\n";
  }
}

void printPascalTr(int size) {
  int *pRow = new int[size];
  pRow[0] = 1;
  for (int i = 0; i < size; ++i) {
    for (int j = i; j >= 0; --j) {
      if (j-1 >= 0) { pRow[j] += pRow[j-1]; }
    }
    for (int j = 0; j <= i; ++j) {
      cout << pRow[j] << " ";
    }
    cout << "\n";
  }
  delete[] pRow;
  pRow = NULL;
}

void printBoard(int**pBoard, int row, int col){
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      cout << pBoard[i][j] << " ";
    }
    cout << "\n";
  }
}

void makeBoard(int row, int col) {
  int **pBoard = new int*[row]; // declaring board and dynamically allocating row space in heap
  for (int i = 0; i < row; ++i) {
    pBoard[i] = new int[col]; // dynamically allocating columns
    for (int j = 0; j < col; ++j) {
      pBoard[i][j] = 1;
    }
  }
  printBoard(pBoard, row, col);
  delete[] pBoard;
  pBoard = NULL;
}

int main() {
  cout << "Matrix of numbers: \n";
  printMatrix(0);

  int d;
  cout << "Diagonal magrix of size: ";
  cin >> d;
  cout << endl;
  diagMatrix(d);

  int s;
  cout << "Enter the size of Pascal triangle: ";
  cin >> s;
  printPascalTr(s);
  return 0;
}
