#include <iostream>
using namespace std;

class Area
{
private:
  float length, breadth, radius;

public:
  //friend functions with default parameters as units which returns area of the specified shape
  friend float rectangle(float length, float breadth);
  friend float circle(float radius);
};

//function which returns the area of the rectangle
inline float rectangle(float length = 1.0, float breadth = 1.0)
{
  return length * breadth;
}
inline float circle(float radius = 1.0)
{
  return 3.14 * radius * radius;
}

class Volume
{
private:
  float length, breadth, height, radius;

public:
  float cuboid(float length, float breadth, float height);
  float sphere(float radius);
  void compareCuboid();
  void compareSphere();
};

inline float Volume::cuboid(float length = 1.0, float breadth = 1.0, float height = 1.0)
{
  return rectangle(length, breadth) * height;
}

inline float Volume::sphere(float radius = 1.0)
{
  return (4 * circle(radius) * radius) / 3;
}

inline void Volume::compareCuboid()
{
  float lengthCompare, breadthCompare, heightCompare;
  cout << "Enter the length of first cubiod: ";
  cin >> this->length;
  cout << "Enter the breadth of first cubiod: ";
  cin >> this->breadth;
  cout << "Enter the height of first cubiod: ";
  cin >> this->height;
  cout << "Enter the length of second cubiod: ";
  cin >> lengthCompare;
  cout << "Enter the breadth of second cubiod: ";
  cin >> breadthCompare;
  cout << "Enter the height of second cubiod: ";
  cin >> heightCompare;
  if (this->length >= 0 && this->breadth >= 0 && this->height >= 0 && lengthCompare >= 0 && breadthCompare >= 0 && heightCompare >= 0)
  {
    float volumeFirst = rectangle(this->length, this->breadth) * this->height;
    float volumeSecond = rectangle(lengthCompare, breadthCompare) * heightCompare;
    if (volumeFirst == volumeSecond)
      cout << "Both the cubiods have same volume " << volumeFirst << endl;
    else if (volumeFirst > volumeSecond)
      cout << "First cubiod ( " << volumeFirst << " ) has greater volume than second cuboid ( " << volumeSecond << " )" << endl;
    else
      cout << "Second cubiod ( " << volumeSecond << " ) has greater volume than first cuboid ( " << volumeFirst << " )" << endl;
  }
  else
  {
    cout << "ENTER ONLY POSITIVE MEASUREMENTS" << endl;
  }
}

inline void Volume::compareSphere()
{
  float radiusCompare;
  cout << "Enter the radius of the first sphere: ";
  cin >> this->radius;
  cout << "Enter the radius of the second sphere: ";
  cin >> radiusCompare;
  if (this->radius >= 0 && radiusCompare >= 0)
  {
    float volumeFirst = (4 * circle(this->radius) * this->radius) / 3;
    float volumeSecond = (4 * circle(radiusCompare) * radiusCompare) / 3;
    if (volumeFirst == volumeSecond)
      cout << "Both the sphere have same volume " << volumeFirst << endl;
    else if (volumeFirst > volumeSecond)
      cout << "First sphere ( " << volumeFirst << " ) has greater volume than second sphere ( " << volumeSecond << " )" << endl;
    else
      cout << "Second sphere ( " << volumeSecond << " ) has greater volume than first sphere ( " << volumeFirst << " )" << endl;
  }
  else
  {
    cout << "ENTER ONLY POSITIVE MEASUREMENTS" << endl;
  }
}

int main()
{
  float length, breadth, height, radius;
  int choice = 1;
  Volume volume;
  while (choice != 11)
  {
    cout << "1. Area of Rectangle" << endl;
    cout << "2. Area of Circle" << endl;
    cout << "3. Unit Area of Rectangle" << endl;
    cout << "4. Unit Area of Circle" << endl;
    cout << "5. Unit Volume of Cubiod" << endl;
    cout << "6. Unit Volume of Sphere" << endl;
    cout << "7. Volume of Cubiod" << endl;
    cout << "8. Volume of Sphere" << endl;
    cout << "9. Compare volume of two cubiods" << endl;
    cout << "10. Compare volume of two spheres" << endl;
    cout << "11. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      cout << "Enter the length of the rectangle: ";
      cin >> length;
      cout << "Enter the breadth of the rectangle: ";
      cin >> breadth;
      if (length >= 0 && breadth >= 0)
        cout << "Area of rectangle: " << rectangle(length, breadth) << endl;
      else
      {
        cout << "ENTER ONLY POSITIVE MEASUREMENTS" << endl;
      }
    }
    break;
    case 2:
    {
      cout << "Enter the radius of the circle: ";
      cin >> radius;
      if (radius >= 0)
        cout << "Area of circle: " << circle(radius) << endl;
      else
      {
        cout << "ENTER ONLY POSITIVE MEASUREMENTS" << endl;
      }
    }
    break;
    case 3:
      cout << "Unit area of rectangle(default parameter check): " << rectangle() << endl;
      break;
    case 4:
      cout << "Unit area of circle(default parameter check): " << circle() << endl;
      break;
    case 5:
      cout << "Unit volume of cubiod(default parameter check): " << volume.cuboid() << endl;
      break;
    case 6:
      cout << "Unit volume of sphere(default parameter check): " << volume.sphere() << endl;
      break;
    case 7:
    {
      cout << "Enter the length of the cubiod: ";
      cin >> length;
      cout << "Enter the breadth of the cubiod: ";
      cin >> breadth;
      cout << "Enter the height of the cubiod: ";
      cin >> height;
      if (length >= 0 && breadth >= 0 && height >= 0)
        cout << "volume of cubiod: " << volume.cuboid(length, breadth, height) << endl;
      else
      {
        cout << "ENTER ONLY POSITIVE MEASUREMENTS" << endl;
      }
    }
    break;
    case 8:
    {
      cout << "Enter the radius of the sphere: ";
      cin >> radius;
      if (radius >= 0)
        cout << "volume of sphere: " << volume.sphere(radius) << endl;
      else
      {
        cout << "ENTER ONLY POSITIVE MEASUREMENTS" << endl;
      }
    }
    break;
    case 9:
      volume.compareCuboid();
      break;
    case 10:
      volume.compareSphere();
      break;
    case 11:
      break;
    default:
      cout << "Enter a valid choice😬" << endl;
      break;
    }
  }
  return 0;
}