/*
Created by  : Vaisakh Dileep
Date        : 30, September, 2023
Description : This program helps to understand Liskov substitution principle in C++.
*/

#include<iostream>

using namespace std;

// Liskov Substitution Principle states that if an interface takes an object of type Parent, it should equally take an object of type Child without anything breaking.

class Rectangle {
public:
    unsigned int width, height;

    Rectangle(unsigned int width, unsigned int height): width {width}, height {height}{
    }

    void set_width(unsigned int width) {
        this->width = width;
    }

    void set_height(unsigned int height) {
        this->height = height;
    }

    unsigned int get_width() const {
        return width;
    }

    unsigned int get_height() const {
        return height;
    }

    unsigned int area() const {
        return width * height;
    }
};

class Square: public Rectangle {
public:
    Square(unsigned int size): Rectangle(size, size) {
    }

    void set_width(unsigned int width) {
        this->width = this->height = width;
    }

    void set_height(unsigned int height) {
        this->height = this->width = height;
    }
};

void make_rectangle_height_10_ver_1(Rectangle &r) { // This breaks Liskov Substitution Principle since taking child of rectangle class, breaks the logic.
    cout << "r.get_height(): " << (r.get_height()) << "\n";
    cout << "r.get_width() : " << (r.get_width())  << "\n";

    r.set_height(10);

    cout << "r.get_height(): " << (r.get_height()) << "\n";
    cout << "r.get_width() : " << (r.get_width())  << "\n";
}

void make_rectangle_height_10_ver_2(Rectangle &r) {
    
}

int main() {
    Rectangle r {5, 5};
    Square s {5};

    make_rectangle_height_10_ver_1(r);
    cout<<"\n";
    make_rectangle_height_10_ver_1(s); // Notice here even though we have passed Square which is a type of rectangle, only the height was changed, not the width.

    return 0;
}