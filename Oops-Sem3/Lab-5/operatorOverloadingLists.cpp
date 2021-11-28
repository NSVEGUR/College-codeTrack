#include <iostream>
using namespace std;

//object for nodal data
class node
{
public:
  int data;
  node *link;
};

//object for list
class List
{
private:
  node *head = NULL;
  bool isEmpty()
  {
    if (this->size == 0)
      return true;
    else
      return false;
  }

public:
  int size;
  //operator overloading with addition
  List operator+(List const &obj)
  {
    if (this->head == NULL)
    {
      this->head = obj.head;
      cout << "\033[1;34mMERGED SUCCESSFULLY\033[0m" << endl;
      return *this;
    }
    else
    {
      node *travel = this->head;
      while (travel->link != NULL)
        travel = travel->link;
      travel->link = obj.head;
      this->sort();
      cout << "\033[1;34mMERGED SUCCESSFULLY\033[0m" << endl;
      return *this;
    }
  }
  void insert(int data);
  void display();
  void sort();
  void reset();
};

//insert function which inserts a node based on its sorted position implicitly
void List::insert(int data)
{
  //at the intial stage
  if (this->head == NULL)
  {
    this->head = new node;
    this->head->data = data;
    this->head->link = NULL;
    this->size++;
  }
  else
  {
    node *temp = this->head;
    node *current = new node;
    current->data = data;
    while (temp != NULL)
    {
      //if data is less than the data in head
      if (data <= temp->data)
      {
        current->link = head;
        head = current;
        this->size++;
        break;
      }
      //nodes in between head and tail
      else if (temp->link != NULL)
      {
        if (data >= temp->data && data <= temp->link->data)
        {
          current->link = temp->link;
          temp->link = current;
          this->size++;
          break;
        }
      }
      //after the tail
      else if (temp->link == NULL)
      {
        if (data >= temp->data)
        {
          current->link = NULL;
          temp->link = current;
          this->size++;
          break;
        }
      }
      temp = temp->link;
    }
  }
  cout << "\033[1;34mINSERTED SUCCESSFULLY\033[0m" << endl;
}

//function to display nodes in the list
void List::display()
{
  //checking if list is empty or not
  if (this->isEmpty())
    cout << "\033[1;31mLIST IS EMPTY\033[0m" << endl;
  else
  {
    cout << "\033[1;34m-----LIST-----" << endl;
    node *temp = this->head;
    while (temp->link != NULL)
    {
      cout << temp->data << "->";
      temp = temp->link;
    }
    cout << temp->data << "\033[0m" << endl;
  }
}

//function to initialise the lists
void createList(List *list)
{
  cout << "-----LIST CREATION-----" << endl;
  int choice = 1, data;
  while (choice != 2)
  {
    cout << "\033[1;33m1. To add data to the List" << endl;
    cout << "2. To stop creation of the List\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      //taking user input of the data
      cout << "\033[1;35mEnter the data you need to pass into the list: \033[0m";
      cin >> data;
      list->insert(data);
    }
    break;
    case 2:
      cout << "\033[1;31m-----List creation ended by the user-----\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31mENTER A VALID CHOICE\033[0m" << endl;
      break;
    }
  }
}

void List::sort()
{
  for (node *temp_1 = this->head; temp_1->link != NULL; temp_1 = temp_1->link)
  {
    for (node *temp_2 = temp_1->link; temp_2 != NULL; temp_2 = temp_2->link)
    {
      if (temp_1->data > temp_2->data)
      {
        int store = temp_1->data;
        temp_1->data = temp_2->data;
        temp_2->data = store;
      }
    }
  }
}

inline void List::reset()
{
  this->head = NULL;
  this->size = 0;
}

int main()
{
  cout << "-----PROGRAM FOR IMPLEMENTATION OF LISTS USING CLASSES-----" << endl;
  //creating lists
  List list_1;
  List list_2;
  int choice = 1, data, location;
  //initialising lists
  createList(&list_1);
  createList(&list_2);
  //menu driven programming
  while (choice != 4)
  {
    cout << "\033[1;33m1.Insert" << endl;
    cout << "2.Display" << endl;
    cout << "3.Merge" << endl;
    cout << "4.Exit\033[0m" << endl;
    cout << "Enter your choice: ";
    //taking user input from the user
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      cout << "\033[1;32m1. Insert in List-1" << endl;
      cout << "2. Insert in List-2\033[0m" << endl;
      cout << "Choice: ";
      cin >> choice;
      if (choice != 1 && choice != 2)
      {
        cout << "\033[1;31mList doesn't exist\033[0m" << endl;
      }
      else
      {
        cout << "Enter the data you need to insert: ";
        cin >> data;
        //calling insert function based on choice
        choice == 1 ? list_1.insert(data) : list_2.insert(data);
      }
    }
    break;
    case 2:
    {
      cout << "\033[1;32m1. Display List-1" << endl;
      cout << "2. Display List-2\033[0m" << endl;
      cout << "Choice: ";
      cin >> choice;
      if (choice != 1 && choice != 2)
      {
        cout << "\033[1;31mList doesn't exist\033[0m" << endl;
      }
      else
        //calling display function based on choice
        choice == 1 ? list_1.display() : list_2.display();
    }
    break;
    case 3:
    {
      cout << "\033[1;32m1. Merge List-2 into List-1" << endl;
      cout << "2. Merge List-1 into List-2\033[0m" << endl;
      cout << "Choice: ";
      cin >> choice;
      if (choice != 1 && choice != 2)
      {
        cout << "\033[1;31mInvalid choice for merging\033[0m" << endl;
      }
      else
      {
        //merging lists using operator overloading
        if (choice == 1)
        {
          list_1 = list_1 + list_2;
          list_2.reset();
        }
        else
        {
          list_2 = list_1 + list_2;
          list_1.reset();
        }
      }
    }
    break;
    case 4:
      cout << "\033[1;31m-----PROGRAM TERMINATED BY THE USER-----\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31mENTER A VALID CHOICE\033[0m" << endl;
      break;
    }
  }
  return 0;
}
