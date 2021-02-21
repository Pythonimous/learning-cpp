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