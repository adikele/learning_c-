//Polymorphism is taking advantage of one of the features of class inheritance:
// the fact that a pointer to a derived class is type-compatible with a pointer to its base class.
// To enable polymorphism, we need to have virutal functions in the base class

//case 1 Without using polymorphism -- using pointers to base class (but unable to access derived class functions through these pointers)
//case 2 Using polymorphism -- now again using pointers to base class (but able to access derived class functions through these pointers)
#include <iostream>
using namespace std;

class ManySidedFigure {
protected:
    int width, height;
public:
    void set_values(int a, int b)
    {
        width = a; height = b;
    }

    //case 2 function
    virtual int area_secondtry()
    {
        return 0;
    }

};

class Rectangle : public ManySidedFigure {
public:
    int area()
    
    {
        return width * height;
    }

    //case 2 function
    int area_secondtry()
    {
        return width * height;
    }

};

class Triangle : public ManySidedFigure {
public:
    int area()
    {
        return width * height / 2;
    }

    //case 2 function
    int area_secondtry()
    {
        return width * height / 2;
    }

};

int main() {
    Rectangle rect;
    Triangle trgl;

    //case 1: demonstrating the NEED for Polymorphism:
    // Without using polymorphism concept ..
    //By declaring a pointer to a base class
    // But in the base class, the important functions not defined
    // So how do we use the pointers? We need to use the derived class variables

    ManySidedFigure* ppoly1 = &rect;
    ManySidedFigure* ppoly2 = &trgl;
    
    ppoly1->set_values(4, 5);
    ppoly2->set_values(4, 5);
    
    // case 1: Cannot use ppoly to output area!
    cout << rect.area() << '\n';
    cout << trgl.area() << '\n';
    
    
    // case 2: Time to use polymorphism to output area!
    //A virtual member is a member function that can be redefined in a derived class 
    //Non - virtual members of derived classes cannot be accessed through a reference of the base class 

    ManySidedFigure poly;
    ManySidedFigure* ppoly3 = &rect;
    ManySidedFigure* ppoly4 = &trgl;
    ManySidedFigure* ppoly5 = &poly;
    ppoly3->set_values(4, 5);
    ppoly4->set_values(4, 5);
    ppoly5->set_values(4, 5);
    cout << ppoly3->area_secondtry() << '\n';
    cout << ppoly4->area_secondtry() << '\n';
    cout << ppoly5->area_secondtry() << '\n';

    
    return 0;
}
