#include <iostream>
using namespace std;

// Exercise 3: Displaying Message Using Inheritance

class Animal {
  public:
    void set_data (int a, string n) { name = n; age = a; }
  protected:
    string name;
    int age;
};

//define base class named "Zebra" here
class Zebra:public Animal {
  public:
    string message_zebra(string str) {
      str += "The zebra named " + name + " is " + to_string(age) + " years old. The zebra comes from Africa.";
      return str;
    }
};

//define base class named "Dolphin" here 

class Dolphin: public Animal {
  public:
    string message_dolphin(string str) {
      str += "The dolphin named " + name + " is " + to_string(age) + " years old. The dolphin comes from New Zealand.";
      return str;
    }
};