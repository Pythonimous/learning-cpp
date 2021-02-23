#include <iostream>
#include <cmath>
using namespace std;

double testSqrt(double a, double b) {
  return sqrt(pow(a,2)+pow(b,2));
}

double testBinomial(double a, double b) {
  return pow(a,2) + 2*a*b + pow(b,2);
}

int main() {
  double a;
  double b;

  cout << "Enter a and b:" << endl;
  cin >> a;
  cin >> b;

  double computeSqrt = testSqrt(a,b);
  double computeBinomial = testBinomial(a,b);

  cout << "Answer for sqrt expression: " << computeSqrt << endl;
  cout << "Answer for binomial expression: " << computeBinomial << endl;
  return 0;
}