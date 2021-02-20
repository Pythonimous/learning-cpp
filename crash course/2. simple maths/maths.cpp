#include <iostream>
#include <cmath>
using namespace std;

double testSqrt(double a, double b) {
  
  double computeSqrt;
  a = pow(a,2);
  b = pow(b,2);
  computeSqrt = sqrt(a+b);
  return computeSqrt;
}

double testBinomial(double a, double b) {
  double computeSquares;
  double computeProduct;
  double answer;
  computeSquares = pow(a,2) + pow(b,2);
  computeProduct = 2*a*b;
  answer = computeSquares + computeProduct;
  return answer;
}

int main() {

    double a;
    double b;

    cout << "Enter a and b:" << endl;
    cin >> a;
    cin >> b;

    double computeSqrt = testSqrt(a, b);
    double computeBinomial = testBinomial(a, b);

    cout << "Answer for sqrt expression: " << computeSqrt << endl;
    cout << "Answer for binomial expression: " << computeBinomial << endl;
    return 0;
}