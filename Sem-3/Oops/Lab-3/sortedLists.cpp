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
  node *head;
  bool isEmpty()
  {
    if (this->size == 0)
      return true;
    else
      return false;
  }

public:
  int size, listNumber;
  List(int list)
  {
    this->size = 0;
    this->head = NULL;
    this->listNumber = list;
  }
  void insert(int data);
  int deleteNode(int location);
  void display();
  void merge(List *list_1, List *list_2, int list);
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
}

int List::deleteNode(int location)
{
  if (this->isEmpty())
  {
    cout << "\033[1;31mTHE LIST IS EMPTY\033[0m" << endl;
    return 0;
  }
  //invalid location
  if (location > this->size || location <= 0)
  {
    cout << "\033[1;31mThe lists locations are only available between 1 and " << this->size << " \033[0m" << endl;
    return 0;
  }
  node *current = this->head;  //to store current node
  node *previous = this->head; //to store previous node
  for (int i = 1; i <= location; ++i)
  {
    if (i == location)
    {
      //deleting the head
      if (i == 1)
      {
        this->head = this->head->link;
        delete current;
        this->size--;
        break;
      }
      //deleting the tail
      else if (i == this->size)
      {
        previous->link = NULL;
        delete current;
        this->size--;
        break;
      }
      //deleting the inbetween nodes
      else
      {
        previous->link = current->link;
        delete current;
        this->size--;
        break;
      }
    }
    else
    {
      //changing the previous and current if node at location is not found
      previous = current;
      current = current->link;
    }
  }
  cout << "\033[1;34mData at location - " << location << " is deleted succefully\033[0m" << endl;
  return 1;
}

//function to display nodes in the list
void List::display()
{
  //checking if list is empty or not
  if (this->isEmpty())
    cout << "\033[1;31mLIST " << this->listNumber << " IS EMPTY\033[0m" << endl;
  else
  {
    cout << "\033[1;34m-----LIST - " << this->listNumber << " -----" << endl;
    node *temp = this->head;
    while (temp->link != NULL)
    {
      cout << temp->data << "->";
      temp = temp->link;
    }
    cout << temp->data << "\033[0m" << endl;
  }
}

//function to merge the lists
void List::merge(List *list_1, List *list_2, int list)
{
  node *temp = list_1->head;
  if (list_1->isEmpty())
  {
    list_1->head = list_2->head;
    list_2->head = NULL;
  }
  else
  {
    while (temp->link != NULL)
      temp = temp->link;
    if (list == 1)
    {
      //merging both into list-1
      temp->link = list_2->head;
      list_2->head = NULL;
      list_1->size = list_1->size + list_2->size;
      list_2->size = 0;
      cout << "\033[1;34mList-2 is succefully merged to List-1" << endl;
      //to sort the merged lists
      for (node *temp_1 = list_1->head; temp_1->link != NULL; temp_1 = temp_1->link)
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
    else if (list == 2)
    {
      //merging both into list-2
      temp->link = list_2->head;
      list_2->head = list_1->head;
      list_1->head = NULL;
      list_2->size = list_1->size + list_2->size;
      list_1->size = 0;
      cout << "\033[1;34mList-1 is succefully merged to List-2" << endl;
      //to sort the merged lists
      for (node *temp_1 = list_2->head; temp_1->link != NULL; temp_1 = temp_1->link)
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
  }
}

//function to initialise the lists
void createList(List *list)
{
  cout << "-----LIST - " << list->listNumber << " CREATION-----" << endl;
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

int main()
{
  cout << "-----PROGRAM FOR IMPLEMENTATION OF LISTS USING CLASSES-----" << endl;
  //creating lists
  List list_1(1);
  List list_2(2);
  int choice = 1, data, location;
  //initialising lists
  createList(&list_1);
  createList(&list_2);
  //menu driven programming
  while (choice != 5)
  {
    cout << "\033[1;33m1.Insert" << endl;
    cout << "2.Delete" << endl;
    cout << "3.Display" << endl;
    cout << "4.Merge" << endl;
    cout << "5.Exit\033[0m" << endl;
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
      cout << "\033[1;32m1. Delete in List-1" << endl;
      cout << "2. Delete in List-2\033[0m" << endl;
      cout << "Choice: ";
      cin >> choice;
      if (choice != 1 && choice != 2)
      {
        cout << "\033[1;31mList doesn't exist\033[0m" << endl;
      }
      else
      {
        cout << "Enter the location you need to delete at: ";
        cin >> location;
        //calling delete function based on choice
        choice == 1 ? list_1.deleteNode(location) : list_2.deleteNode(location);
      }
    }
    break;
    case 3:
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
    case 4:
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
        list_1.merge(&list_1, &list_2, choice);
      }
    }
    break;
    case 5:
      cout << "\033[1;31m-----PROGRAM TERMINATED BY THE USER-----\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31mENTER A VALID CHOICE\033[0m" << endl;
      break;
    }
  }
  return 0;
}
