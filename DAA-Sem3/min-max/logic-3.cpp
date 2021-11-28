#include <iostream>
using namespace std;

class min_max
{
public:
  int size, size_of_removed, MIN, MAX, Second_MIN, Second_MAX;
  void input_array_size();
  void create_array(int *arr);
  void print_array(int *arr);
  void remove_duplicate_array(int *arr, int *removed_arr);
  int gaurd(int *arr);
  void find_min_max(int *arr);
  void program(int *arr, int *removed_arr);
};

void min_max::input_array_size()
{
  cout << "Enter the size of the array: " << endl;
  cin >> this->size;
  if (this->size <= 0)
  {
    cout << endl
         << "\033[1;31mSIZE OF THE ARRAY IS NOT VALID!!\033[0m\n"
         << endl;
    exit(0);
  }
}

void min_max::create_array(int *arr)
{
  cout << "Enter the elements of the array" << endl;
  for (int i = 0; i < this->size; ++i)
  {
    cout << "Enter element " << i + 1 << " :" << endl;
    cin >> *(arr + i);
  }

  this->MIN = this->MAX = this->Second_MAX = this->Second_MIN = *(arr);
}

void min_max::print_array(int *arr)
{
  int i;

  cout << endl
       << "The created array is: " << endl;
  cout << "[ ";
  for (i = 0; i < this->size - 1; ++i)
  {
    cout << *(arr + i) << " ,";
  }

  cout << *(arr + i) << " ]" << endl
       << endl;
}

void min_max::remove_duplicate_array(int *arr, int *removed_arr)
{
  int i, j, k = 0;
  for (i = 0; i < this->size; ++i)
  {
    for (j = 0; j < k; ++j)
    {
      if (*(removed_arr + j) == *(arr + i))
        break;
    }
    if (j == k)
    {
      *(removed_arr + k) = *(arr + i);
      k++;
    }
  }
  this->size_of_removed = k;
}

int min_max::gaurd(int *arr)
{
  switch (this->size_of_removed)
  {
  case 1:
    cout << "\033[1;31mMin and Max both are = " << *(arr) << " and second Max and second Min are not possible\033[0m" << endl
         << endl;
    return 0;
    break;
  case 2:
  {
    if (*(arr) > *(arr + 1))
      cout << "\033[1;31mMin = " << *(arr + 1) << " and Max = " << *(arr) << " and second Max and second Min are not possible\033[0m" << endl
           << endl;
    else
      cout << "\033[1;31mMin = " << *(arr) << " and Max = " << *(arr + 1) << " and second Max and second Min are not possible\033[0m" << endl
           << endl;
  }
    return 0;
    break;
  case 3:
  {
    for (int i = 1; i < 3; ++i)
    {
      if (this->MIN > *(arr + i))
        this->MIN = *(arr + i);
      if (this->MAX < *(arr + i))
        this->MAX = *(arr + i);
    }
    for (int i = 1; i < 3; ++i)
    {
      if (*(arr + i) != this->MAX && *(arr + i) != this->MIN)
        this->Second_MAX = *(arr + i);
    }
    cout << "\033[1;31mMin = " << this->MIN << " and Max = " << this->MAX << " and second Max and second Min both are = " << this->Second_MAX << "\033[0m" << endl
         << endl;
  }
    return 0;
    break;
  default:
    return 1;
    break;
  }
}

void min_max::find_min_max(int *arr)
{
  this->MIN = *(arr);
  this->MAX = *(arr + this->size - 1);
  for (int i = 1; i < this->size; ++i)
  {
    if (this->MIN > *(arr + i))
      this->MIN = *(arr + i);
    if (this->MAX < *(arr + i))
      this->MAX = *(arr + i);
  }
  this->Second_MAX = this->MIN;
  this->Second_MIN = this->MAX;
  for (int i = 0; i < this->size; i++)
  {
    if (*(arr + i) < this->MAX && *(arr + i) > this->Second_MAX)
    {
      this->Second_MAX = *(arr + i);
    }
    if (*(arr + i) > this->MIN && *(arr + i) < this->Second_MIN)
    {
      this->Second_MIN = *(arr + i);
    }
  }
}

void min_max::program(int *arr, int *removed_arr)
{
  this->create_array(arr);
  this->print_array(arr);
  this->remove_duplicate_array(arr, removed_arr);
  if (!this->gaurd(removed_arr))
    exit(1);
  this->find_min_max(arr);

  cout << endl
       << "\033[1;34mMax is: " << this->MAX << " and Min is: " << this->MIN << endl;
  cout << "Second Max is: " << this->Second_MAX << " and Second Min is: " << this->Second_MIN << "\033[0m" << endl
       << endl;
}

int main()
{
  min_max min_max_class;
  cout << "-----Program to find MIN, MAX, Second MIN & Second Max in given array-----" << endl;
  min_max_class.input_array_size();
  int arr[min_max_class.size];
  int removed_arr[min_max_class.size];
  min_max_class.program(arr, removed_arr);
  return 0;
}