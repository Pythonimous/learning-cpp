#include <iostream>
#include <cmath>

using namespace std;

void passReference(int *a, int *b) {
    int temp = *a;
    *a = pow(*a, *b);
    *b = (temp % (*b));
}

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

int findFrequent(int arr[], int n) {
    arr = bubbleSort(arr, n);

    int mostFreq = 0;
    int freqMax = 0;
    int freqCurr = 1;

    for (int i = 1; i <= n; ++i) {
        if (arr[i] == arr[i-1]) {
            ++freqCurr;
        }
        else {
            if (freqCurr > freqMax) {
                mostFreq = arr[i-1];
                freqMax = freqCurr;
                freqCurr = 1;
            }
            else if (freqCurr == freqMax) {
                if (mostFreq > arr[i-1]) { mostFreq = arr[i-1]; }
            }
        }
    }
    return mostFreq;
}