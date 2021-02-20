#include <iostream>
using namespace std;

string multiples(int num) {
  string ans = ""; //return the correct value in this string
  int multiplier = 1;
  while (multiplier <= 10) {
      ans += (to_string(num*multiplier) + " ");
      multiplier++;
  }
  return ans;
}

void fibonacciSeq(int range) {    
    int prev = 0;
    int fibonacci = 1;
    int temp;
    cout << prev << " ";
    range--;
    while (range >= 0) {
        cout << fibonacci << " ";
        temp = fibonacci;
        fibonacci += prev;
        prev = temp;
        range--;
    }
}

void pyramid(int rows) {
    int width = 1;
    for (rows ; rows > 0; --rows ) {
        for (int w = width; w > 0; --w) {
            cout << "a" << " ";
        }
        cout << "\n";
        width ++;
    }
}