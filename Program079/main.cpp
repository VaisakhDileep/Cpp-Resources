/*
Created by  : Vaisakh Dileep
Date		: 21, January, 2021
Description : This program helps to understand abstract classes in C++.
*/

#include<iostream>

#include<vector>

using namespace std;

// ------------------------------ Abstract Classes ------------------------------

class Shape
{
private:
	// Attributes common to all shapes.
public:
	virtual void draw() = 0; // This is a pure virtual function.
	virtual void rotate() = 0; // This is a pure virtual function.

	virtual ~Shape() { } // This is a virtual destructor.
};

class Open_Shape: public Shape
{
public:
	virtual ~Open_Shape() {}
};

class Closed_Shape: public Shape
{
public:
	virtual ~Closed_Shape() {}
};

// ------------------------------ Concrete Classes ------------------------------

class Line: public Open_Shape
{
public:
	virtual void draw() override
	{
		cout<<"Drawing a Line.\n";
	}

	virtual void rotate() override
	{
		cout<<"Rotating a Line.\n";
	}

	virtual ~Line() {}
};

class Circle: public Closed_Shape
{
public:
	virtual void draw() override
	{
		cout<<"Drawing a Circle.\n";
	}

	virtual void rotate() override
	{
		cout<<"Rotating a Circle.\n";
	}

	virtual ~Circle() {}
};

class Square: public Closed_Shape
{
public:
	virtual void draw() override
	{
		cout<<"Drawing a Square.\n";
	}

	virtual void rotate() override
	{
		cout<<"Rotating a Square.\n";
	}

	virtual ~Square() {}
};

void draw_all(const vector<Shape*> &shape_vector)
{
	cout<<"\nDrawing all shapes:\n";

	for(const auto shape : shape_vector)
	{
		shape->draw();
	}
}

int main()
{
/*
Abstract classes vs Concrete classes:
Abstract class: Abstract classes cannot instantiate objects. These classes are used as Base classes in the inheritance hierarchy. They are often referred as Abstract Base classes.

Concrete class: Concrete classes can instantiate objects. All their member functions should be defined(All the classes we worked with till now).
*/

/*
Pure virtual functions: The are used to make a class abstract. They are specified with "= 0" in its declaration.
Syntax for pure virtual functions:
	virtual void function() = 0; // Pure virtual function, typically do not provide implementation.
*/

/*
Note: In order to create Abstract classes, it should contain at least one pure virtual function.

Note: If the Derived class does not override then the Derived class is also abstract.
*/

	// Shape *shape_object = new Shape(); // This will generate an error because "Shape" is an abstract class.

	// Open_Shape *open_shape_object = new Open_Shape(); // This will generate an error because "Open_Shape" is also an abstract class.

	// Closed_Shape *closed_shape_object = new Closed_Shape(); // This will generate an error because "Closed_Shape" is also an abstract class.

	Shape *shape_line = new Line();
	Shape *shape_circle = new Circle();
	Shape *shape_square = new Square();

	vector<Shape*> shape_vector {shape_line, shape_circle, shape_square};

	for(auto shape : shape_vector)
	{
		shape->draw();
	}

	cout<<"\n";

	for(auto shape : shape_vector)
	{
		shape->rotate();
	}

	draw_all(shape_vector);

	delete shape_line;
	delete shape_circle;
	delete shape_square;

	return 0;
}