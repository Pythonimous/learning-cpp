#include <iostream>
using namespace std;

int oddEvenTest(int number)
{
  int temp;
  cout << "Computing whether " << number << " is an even or odd integer" << endl;
  temp = (number % 2 == 1) ? 1 : 0;
  return temp;
}

float calculator(float num1, float num2, char Operator)
{
  cout << "Number 1 is: " << num1 << endl;
  cout << "Number 2 is: " << num2 << endl;
  cout << "Operator is: " << Operator <<endl;

  switch (Operator) {
    case '+':
      return num1 + num2;
    case '-':
      return num1 - num2;
    case '*':
      return num1 * num2;
    case '/':
      return num1 / num2;
  }
}
