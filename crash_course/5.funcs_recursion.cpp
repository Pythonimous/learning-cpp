#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void computeCubes(int& num) {    // cubes with pass by reference
  num = pow(num, 3);
}

string testCubes(int num1, int num2, int num3){
  
  string ans="";
  
  computeCubes(num1);
  computeCubes(num2);
  computeCubes(num3);
  
  cout<< "Value of num1 is: "<< num1 <<endl;
  cout <<"Value of num2 is: " << num2 <<endl;
  cout<<"Value of num3 is: "<< num3<<endl;
  
  //the line of code below is for testing purposes. You don't need to change this
  ans = to_string(num1) + " " +to_string(num2) + " " + to_string(num3); //converting all three values to strings
 
  return ans;
}

int DigitSum(int n1) // sum of digits in a given number
{
    if (n1 == 0) { return 0; }
    else { return (n1%10) + DigitSum(n1/10); }
}

int fibonacci(int n) // fibonacci using recursion
{
    if (n == 0) { return 0; }
    else if ( n == 1 ) { return 1; }
    else { return fibonacci(n-2) + fibonacci(n-1); }
}

void testFibonacci (int n ){
  for (int i = 0 ; i < n ; i++){
    cout << fibonacci(i) << " ";
  }
}