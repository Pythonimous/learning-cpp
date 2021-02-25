#include <iostream>
using namespace std;

// Exercise 1: Calculating Area

class Triangle {
  public:
    Triangle(float l, float h) { length = l; height = h; }
    Triangle() { length = 1; height = 1; }
    float area( );
  private:
    float length;
    float height;
};

float Triangle::area() { return length * height / 2; }


float testTriangle(float length, float height) {
  
  Triangle triangle = Triangle(length, height);
  
  float answer = triangle.area();
  cout <<"Area: "<<endl;
  return answer;
}

// Exercise 2: Students Average Marks

class Student {
  public:
    Student() { name = ""; mark1 = 0; mark2 = 0; }
    Student(string na, float ma1, float ma2) { name = na; mark1 = ma1; mark2 = ma2; }
    int GetMarks(int marknumber) { if (marknumber == 1) { return mark1; } else { return mark2; } }
    float calc_average(){ return (mark1 + mark2) / 2; }
  private:
    string name;
    float mark1;
    float mark2;
};
