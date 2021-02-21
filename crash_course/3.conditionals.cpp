#include <iostream>
using namespace std;

int oddEvenTest(int number)
{
    int temp; //set temp to 0 if number is even
              //set temp to 1 if number is odd
    cout << "Computing whether " << number << " is an even or odd integer"<<endl;
    temp = (number % 2 == 1) ? 1 : 0;
    return temp;
}

float calculator(float num1, float num2, char Operator)
{
    //temp will contain the final answer after the required operation is performed
    float temp; //return temp for each switch operation

    cout << "Number 1 is: " << num1 << endl;
    cout << "Number 2 is: " << num2 << endl;
    cout << "Operator is: " << Operator <<endl;

    switch (Operator) {
        case '+':
            temp = num1 + num2;
            break;
        case '-':
            temp = num1 - num2;
            break;
        case '*':
            temp = num1 * num2;
            break;
        case '/':
            temp = num1 / num2;

    }

    return temp;
}
