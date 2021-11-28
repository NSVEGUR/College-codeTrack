#include <iostream>
using namespace std;

class Shape
{
public:
	double area;
	// displaying area of the shape from parent function for all base classes
	void display()
	{
		cout << "->Area of the given shape is : \033[1;35m" << this->area << " \033[1;34msquare centimeters\033[0m" << endl;
	}
};

class Quadrilateral : public Shape
{
public:
	double side1, side2, side3, side4;
	// setting data for quadirlateral lenghts of side1, side2, side3, side4
	void setData()
	{
		cout << "-----Setting data for shape Quadrilateral-----" << endl;
		cout << "\033[1;32mEnter the size of side1: \033[0m";
		cin >> this->side1;
		cout << "\033[1;32mEnter the size of side2: \033[0m";
		cin >> this->side2;
		cout << "\033[1;32mEnter the size of side3: \033[0m";
		cin >> this->side3;
		cout << "\033[1;32mEnter the size of side4: \033[0m";
		cin >> this->side4;
		cout << "-----Data set for shape Quadrilateral-----" << endl;
	}
	// getting data for shape and side and display area from the parent class
	void getData()
	{
		cout << "\033[1;34m-----The shape is Quadirlateral-----" << endl;
		cout << "->side1: \033[1;35m" << this->side1 << "\033[1;34m" << endl;
		cout << "->side2: \033[1;35m" << this->side2 << "\033[1;34m" << endl;
		cout << "->side3: \033[1;35m" << this->side3 << "\033[1;34m" << endl;
		cout << "->side4: \033[1;35m" << this->side4 << "\033[1;34m" << endl;
		this->display();
	}
	// calculating the area of quadirateral
	void calculateArea()
	{
		this->area = this->side1 * this->side2 * this->side3 * this->side4;
	}
};

class Square : public Quadrilateral
{
public:
	// setting data for length of the square
	void setData()
	{
		cout << "-----Setting data for shape Square-----" << endl;
		cout << "\033[1;32mEnter the length of square: \033[0m";
		cin >> this->side1;
		this->side2 = this->side1;
		this->side3 = this->side1;
		this->side4 = this->side1;
		cout << "-----Data set for shape Square-----" << endl;
	}
	// getting data of shape and length of the square and area from its parent class
	void getData()
	{
		cout << "\033[1;34m-----The shape is Square-----" << endl;
		cout << "->length: \033[1;35m" << this->side1 << "\033[1;34m" << endl;
		this->display();
	}
	// calculating area using a2 formula
	void calculateArea()
	{
		this->area = this->side1 * this->side1;
	}
};

class Triangle : public Shape
{
public:
	double base, height;
	// setting data base and height of the triangle
	void setData()
	{
		cout << "-----Setting data for shape Triangle-----" << endl;
		cout << "\033[1;32mEnter the base length of triangle: \033[0m";
		cin >> this->base;
		cout << "\033[1;32mEnter the height of triangle: \033[0m";
		cin >> this->height;
		cout << "-----Data set for shape Triangle-----" << endl;
	}
	// getting data for shape, base and height of triangle and area from its parent class
	void getData()
	{
		cout << "\033[1;34m-----The shape is Triangle-----" << endl;
		cout << "->base: \033[1;35m" << this->base << "\033[1;34m" << endl;
		cout << "->height: \033[1;35m" << this->height << "\033[1;34m" << endl;
		this->display();
	}
	// calculating area of triangle using 1/2 *base*height
	void calculateArea()
	{
		this->area = 0.5 * this->base * this->height;
	}
};

// linked list for storing all shapes
class allShapes
{
public:
	Quadrilateral quadrilateral;
	Square square;
	Triangle triangle;
	allShapes *link;
};

// creating a new shape
allShapes *createShape(allShapes *head)
{
	allShapes *current = new allShapes();
	allShapes *temp = head;
	if (head == NULL)
	{
		cout << "occuring here...null?" << endl;
		head = current;
		cout << "while assigning.." << endl;
		temp = head;
	}
	else
	{
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = current;
	}
	return temp;
}

int main()
{
	allShapes *head = new allShapes();
	allShapes *temp;
	int choice = 1;
	bool createdShapes = false;
	bool calculatedArea = false;
	while (choice != 4)
	{
		cout << "\033[1;33m1. Create a Shape." << endl;
		cout << "2. Calculate area." << endl;
		cout << "3. Display details." << endl;
		cout << "4. Exit\033[0m" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			temp = createShape(head);
			temp->quadrilateral.setData();
			temp->square.setData();
			temp->triangle.setData();
			createdShapes = true;
			calculatedArea = false;
		}
		break;
		case 2:
		{
			try
			{
				if (!createdShapes)
					throw createdShapes;
				temp->quadrilateral.calculateArea();
				temp->square.calculateArea();
				temp->triangle.calculateArea();
				cout << "\033[1;34mArea of shapes calculated succefully\033[0m" << endl;
				calculatedArea = true;
			}
			catch (bool val)
			{
				cout << "\033[1;31mShapes are not created yet\033[0m" << endl;
			}
		}
		break;
		case 3:
		{
			try
			{
				if (!calculatedArea)
					throw calculatedArea;
				temp->quadrilateral.getData();
				temp->square.getData();
				temp->triangle.getData();
				calculatedArea = true;
			}
			catch (bool val)
			{
				cout << "\033[1;31mAreas are not calculted yet\033[0m" << endl;
			}
		}
		break;
		case 4:
			cout << "\033[1;31mProgram Exited By user\033[0m" << endl;
			break;
		default:
			cout << "\033[1;31mEnter a valid choice\033[0m" << endl;
			break;
		}
	}
	return 0;
}