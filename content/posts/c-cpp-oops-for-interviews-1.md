---
title: C, C++ and OOPS for Interviews Part-1
date: "2020-07-07"
template: post
draft: true
slug: c-cpp-oops-for-interviews-1
category: "interviews"
tags:
  - "cpp"
  - "oops"
description: "A note on Features of OOP, Access Specifiers, Classes and Inheritance, Constructors and Destructors"
---

## Features of OOP

- **Abstraction**: We try to obtain abstract view, model or structure of real life problem, and reduce its unnecessary details. With definition of properties of problems, including the data which are affected and the operations which are identified, the model abstracted from problems can be a standard solution to this type of problems. It is an efficient way since there are nebulous real-life problems that have similar properties.
- **Encapsulation**: Encapsulation is the process of combining data and functions into a single unit called class. In Encapsulation, the data is not accessed directly; it is accessed through the functions present inside the class. In simpler words, attributes of the class are kept private and public getter and setter methods are provided to manipulate these attributes. Thus, encapsulation makes the concept of data hiding possible. (Data hiding: a language feature to restrict access to members of an object, reducing the negative effect due to dependencies. e.g. "protected", "private" feature in C++).
- **Inheritance**: A class is based on another class and uses data and implementation of the other class. The purpose of inheritance is Code Reuse.
- **Polymorphism**: It is the ability to present the same interface for differing underlying forms (data types). With polymorphism, each of these classes will have different underlying data. A point shape needs only two coordinates (assuming it's in a two-dimensional space of course). A circle needs a center and radius. A square or rectangle needs two coordinates for the top left and bottom right corners and (possibly) a rotation. An irregular polygon needs a series of lines.

## Access Specifiers

In C++ there are three access specifiers. It tells about who can access the members (attributes and methods).

- **public**: members can be accessed from outside the class
- **protected**: members can only be accessed inside the class and inherited classes (not outside the class)
- **private**: members can only be accessed inside the class (not inherited classes or or outside the class)

## Classes and Inheritance

It is the mechanism of basing a class upon another class retaining similar implementation.

```cpp
#include <iostream>
using namespace std;

class Vehicle {
    int id; // private by default
    string name;
public:
    void whoIAm() {
        cout << "I am a vehicle." << endl;
    }
};

class Car: public Vehicle {
public:
    void whoIAm() {
        cout << "I am a car." << endl;
    }
};


int main() {
    Car car;
    car.whoIAm(); // prints "I am a car."
    return 0;
}
```

Access specifiers can also be used in inheritance.

```cpp
class Base {
public:
    int x;
protected:
    int y;
private:
    int z;
};

class Derived1 : public Base {
    // x is public
    // y is protected
    // z is inaccessible from Derived1
}

class Derived2: protected Base {
    // x is protected
    // y is protected
    // z is inaccessible from Derived2
}

class Derived3: private Base { // default
    // x is private
    // y is private
    // z is inaccessible from Derived3
}
```

Constructors are called during the initialization of objects. A constructor is not specified C++ automatically created a constructor for us with no parameter and an empty body.

## Constructors

Destructors are called during destructions (deletion) of the objects. It is automatically called when the scope of an object ends.

```cpp
#include <iostream>
using namespace std;

class Vehicle {
    int id; // private by default
    string name;
public:
    void whoIAm() {
        cout << "I am a vehicle." << endl;
    }
    Vehicle(int id, string name) { // constructor
        this->id = id;
        this->name = name;
        cout << "Vehicle's id is " << id << " and name is " << name << endl;
    }
};


int main() {
    Vehicle vehicle(1, "BMW");
    vehicle.whoIAm(); // prints "I am a car."
    return 0;
}
```

The above constructor can also be written as:

```cpp
Vehicle(int x, string s) : id(x), name(s) {
    cout << "Vehicle's id is " << id << " and name is " << name << endl;
}
```

## Destructors

```cpp
#include <iostream>
using namespace std;

class Vehicle {
    int id; // private by default
    string name;
public:
    void whoIAm() {
        cout << "I am a vehicle." << endl;
    }
    ~Vehicle() {
        cout << "Vehicle is destroyed!" << endl;
    }
};


int main() {
    Vehicle vehicle;
    vehicle.whoIAm(); // prints "I am a car."
    return 0;
} // scope of vehicle ends here
```

In the next part, we will discuss virtual functions, virtual destructors, and polymorphism.
