#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
  T data;
  Node *link;
};

template <class T>
class Stack
{
private:
  Node<T> *top;
  bool isEmpty();

public:
  Stack()
  {
    this->top = NULL;
  }
  void push(T data);
  void pop();
  void display();
};

template <class T>
bool Stack<T>::isEmpty()
{
  if (this->top == NULL)
    return true;
  return false;
}

template <class T>
void Stack<T>::push(T data)
{
  Node<T> *current = new Node<T>;
  current->data = data;
  current->link = NULL;
  if (top == NULL)
    top = current;
  else
  {
    Node<T> *temp = this->top;
    while (temp->link != NULL)
      temp = temp->link;
    temp->link = current;
  }
  cout << "\033[1;34mPUSH OPERATION DONE SUCCESSFULLY\033[0m" << endl;
}

template <class T>
void Stack<T>::pop()
{
  if (this->isEmpty())
    cout << "\033[1;31mSTACK IS EMPTY\033[0m" << endl;
  else
  {
    Node<T> *temp = this->top;
    if (temp->link == NULL)
    {
      top = NULL;
      delete temp;
    }
    else
    {
      while (temp->link->link != NULL)
        temp = temp->link;
      temp->link = NULL;
      delete temp->link;
    }
    cout << "\033[1;34mPOP OPERATION DONE SUCCESSFULLY\033[0m" << endl;
  }
}

template <class T>
void Stack<T>::display()
{
  if (this->isEmpty())
    cout << "\033[1;31mSTACK IS EMPTY\033[0m" << endl;
  else
  {
    cout << "\033[1;33m-----STACK-----" << endl;
    Node<T> *temp = this->top;
    cout << "\033[1;34m";
    while (temp->link != NULL)
    {
      cout << " " << temp->data << " ->";
      temp = temp->link;
    }
    cout << " " << temp->data << "\033[0m" << endl;
  }
}

int main()
{
  cout << "-----Program to implement stack using template-----" << endl;
  int choice = 1;
  Stack<int> intTop;
  Stack<char> charTop;
  while (choice != 7)
  {
    cout << "\033[1;32m1. Push to integer stack" << endl;
    cout << "2. Push to character  stack" << endl;
    cout << "3. Pop from integer stack" << endl;
    cout << "4. Pop from character stack" << endl;
    cout << "5. Display integer stack" << endl;
    cout << "6. Display character stack" << endl;
    cout << "7. Exit\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      int data;
      cout << "Enter integer data to push to integer stack: ";
      cin >> data;
      intTop.push(data);
    }
    break;
    case 2:
    {
      char data;
      cout << "Enter character data to push to character stack: ";
      cin >> data;
      charTop.push(data);
    }
    break;
    case 3:
      intTop.pop();
      break;
    case 4:
      charTop.pop();
      break;
    case 5:
      intTop.display();
      break;
    case 6:
      charTop.display();
      break;
    case 7:
      cout << "\033[1;31m-----USER EXITED THE PROGRAM-----\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31m-----INVALID CHOICE-----\033[0m" << endl;
      break;
    }
  }
  return 0;
}