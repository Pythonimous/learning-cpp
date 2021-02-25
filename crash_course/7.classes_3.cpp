#include <iostream>
using namespace std;

// 4. Displaying Message Using Virtual Functions

class Mammal {
  public:
    Mammal(int a) { age = a; }
    virtual void Eat() { cout << "Mammal eats food" << endl; }
    virtual void Speak() { cout << "Mammal speaks mammalian!!" << endl; }
    int get_Age() { return age; }
  protected:
    int age;    
};

class Dog : public Mammal {
  public:
    Dog(int a) : Mammal(a) {}
    void Eat() { cout << "Dog eats meat" << endl; }
    void Speak() { cout << "Dog barks: ruff! ruff!" << endl; }
};

class Cat : public Mammal {
  public:
    Cat(int a) : Mammal(a) {}
    void Eat() { cout << "Cat eats meat" << endl; }
    void Speak() { cout << "Cat meows: Meow! Meow!" << endl; }
};

int main() {
  Dog d(5);
  Cat c(4);
  
  cout << "Calling Dog class functions"<<endl;
  d.Eat();
  d.Speak();
  cout << "Dog's age is: " << d.get_Age() << endl;
 
  cout << "Calling Cat class functions" << endl;
  c.Eat();
  c.Speak();
  cout << "Cat's age is: " << c.get_Age() << endl;
  
  return 0;
}