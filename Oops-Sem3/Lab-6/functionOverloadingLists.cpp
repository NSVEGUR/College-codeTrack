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
  int size;
  List()
  {
    this->head = NULL;
    this->size = 0;
  }
  void insert(int data);
  void insert(int data, int target);
  int deleteNode();
  int deleteNode(int target);
  void display();
};

//function to insert at the last of the list
void List::insert(int data)
{
  node *temp = NULL;
  node *current = new node;
  current->data = data;
  current->link = NULL;
  //adding at the start of the node
  if (this->isEmpty())
  {
    this->head = current;
    this->size++;
  }
  else
  {
    temp = this->head;
    //iterating node upto end
    while (temp->link != NULL)
      temp = temp->link;
    temp->link = current;
    this->size++;
  }
  cout << "\033[1;34mINSERTED SUCCESSFULLY\033[0m" << endl;
}

//function to insert at a specific location
void List::insert(int data, int target)
{
  node *temp = NULL;
  node *current = new node;
  current->data = data;
  current->link = NULL;
  //if list is empty adds at start
  if (this->isEmpty())
  {
    this->head = current;
    this->size++;
  }
  else
  {
    temp = this->head;
    //inserting before head
    if (target == 0)
    {
      current->link = this->head;
      this->head = current;
    }
    //inserting after the last node
    else if (target == this->size)
    {
      while (temp->link != NULL)
        temp = temp->link;
      temp->link = current;
    }
    //inserting in between
    else
    {
      int location = 1;
      //iterating upto the mentioned target location
      while (location != target && temp != NULL)
      {
        temp = temp->link;
        ++location;
      }
      current->link = temp->link;
      temp->link = current;
    }
    this->size++;
  }
  cout << "\033[1;34mINSERTED SUCCESSFULLY\033[0m" << endl;
}

//function to delete node at the last of the list
int List::deleteNode()
{
  node *temp;
  node *prev;
  //checking if the list is empty
  if (this->isEmpty())
  {
    cout << "\033[1;31mLIST IS EMPTY\033[0m" << endl;
    return 0;
  }
  temp = this->head;
  prev = this->head;
  //iterating upto last node
  while (temp->link != NULL)
  {
    prev = temp;
    temp = temp->link;
  }
  prev->link = NULL;
  //deleting the node using delete keyword
  delete temp;
  this->size--;
  cout << "\033[1;34mDELETED SUCCESSFULLY\033[0m" << endl;
  return 1;
}

//function to delete node at a speicific location
int List::deleteNode(int target)
{
  node *temp;
  node *prev;
  //checking if the list is empty
  if (this->isEmpty())
  {
    cout << "\033[1;31mLIST IS EMPTY\033[0m" << endl;
    return 0;
  }
  //deleting the head
  if (target == 1)
  {
    temp = this->head;
    this->head = this->head->link;
    delete temp;
  }
  //deleting the tail
  else if (target == this->size)
  {
    temp = this->head;
    prev = this->head;
    while (temp->link != NULL)
    {
      prev = temp;
      temp = temp->link;
    }
    prev->link = NULL;
    delete temp;
  }
  //deleting in between node
  else
  {
    int location = 1;
    temp = this->head;
    prev = this->head;
    while (location != target && temp != NULL)
    {
      prev = temp;
      temp = temp->link;
      ++location;
    }
    prev->link = temp->link;
    delete temp;
  }
  this->size--;
  cout << "\033[1;34mDELETED SUCCESSFULLY\033[0m" << endl;
  return 1;
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

int main()
{
  cout << "-----Program to implement linked lists using function overload-----" << endl;
  int choice = 1;
  int data, location;
  List list;
  //menu driven programming
  while (choice != 6)
  {
    cout << "\033[1;33m1.Insert" << endl;
    cout << "2.Insert at a specific location" << endl;
    cout << "3.Delete" << endl;
    cout << "4.Delete a specific node" << endl;
    cout << "5.Display" << endl;
    cout << "6.Exit\033[0m" << endl;
    cout << "Enter your choice: ";
    //taking user input from the user
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      cout << "Enter the data you wanna insert: ";
      cin >> data;
      list.insert(data);
    }
    break;
    case 2:
    {
      cout << "Enter the data you wanna insert: ";
      cin >> data;
      //loop which breaks if correct location is entered
      while (1)
      {
        cout << "Enter the location where you wanna insert node from 0 to " << list.size << " :";
        cin >> location;
        if (location >= 0 && location <= list.size)
          break;
        cout << "\033[1;31mLOCATIONS ARE ONLY AVAILABLE FROM 0 TO " << list.size << " :(\033[0m" << endl;
      }
      list.insert(data, location);
    }
    break;
    case 3:
      list.deleteNode();
      break;
    case 4:
    {
      //loop which breaks if correct location is entered
      while (1)
      {
        if (list.size == 0)
        {
          cout << "\033[1;31mLIST IS EMPTY\033[0m" << endl;
          break;
        }
        cout << "Enter the node which you wanna delete from 1 to " << list.size << " :";
        cin >> location;
        if (location > 0 && location <= list.size)
          break;
        cout << "\033[1;31mNODES ARE ONLY AVAILABLE FROM 1 TO " << list.size << " :(\033[0m" << endl;
      }
      if (list.size != 0)
        list.deleteNode(location);
    }
    break;
    case 5:
      list.display();
      break;
    case 6:
      cout << "\033[1;31m-----PROGRAM TERMINATED BY THE USER-----\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31mENTER A VALID CHOICE\033[0m" << endl;
      break;
    }
  }

  return 0;
}