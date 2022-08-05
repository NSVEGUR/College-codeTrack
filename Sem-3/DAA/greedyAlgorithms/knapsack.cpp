#include <iostream>
using namespace std;
double totalProfit = 0;

class knapsackNode
{
public:
  string object;
  int weight;
  int profit;
  double alpha;
  knapsackNode *link;
};

class Knapsack
{
private:
  knapsackNode *head, *resultHead;
  int maxWeight;

public:
  Knapsack(int maxWeight)
  {
    this->head = NULL;
    this->resultHead = NULL;
    this->maxWeight = maxWeight;
  }
  void setUpKnapsack();
  void insert(knapsackNode *current);
  void calculateProfitables();
  void display();
};

void Knapsack::insert(knapsackNode *temp)
{
  int pw = temp->profit / temp->weight;
  if (this->head == NULL)
  {
    this->head = temp;
  }
  else
  {
    knapsackNode *current = this->head->link;
    knapsackNode *prev = this->head;
    if (current == NULL)
    {
      int pw1 = this->head->profit / this->head->weight;
      if (pw1 <= pw)
      {
        this->head->link = temp;
      }
      else
      {
        temp->link = this->head;
        this->head = temp;
        this->head->link->link = NULL;
      }
    }
    else
    {
      while (current != NULL)
      {
        int pw1 = prev->profit / prev->weight;
        int pw2 = current->profit / current->weight;
        if (pw >= pw2 && current->link == NULL)
        {
          current->link = temp;
          break;
        }
        else if (pw <= pw2 && pw >= pw1)
        {
          prev->link = temp;
          temp->link = current;
          break;
        }
        else if (pw <= pw1)
        {
          temp->link = this->head;
          this->head = temp;
          break;
        }
        else
        {
          prev = current;
          current = current->link;
        }
      }
    }
  }
}

void Knapsack::setUpKnapsack()
{
  int choice = 1;
  while (choice != 2)
  {
    cout << "\033[1;32m1. Insert Object" << endl;
    cout << "2. Exit\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
      knapsackNode *temp = new knapsackNode;
      cout << "Enter the object name: ";
      cin >> temp->object;
      cout << "Enter the weight of the object: ";
      cin >> temp->weight;
      cout << "Enter the profit gained from object: ";
      cin >> temp->profit;
      temp->alpha = 1;
      temp->link = NULL;
      this->insert(temp);
      cout << "\033[1;34mObject Inserted Succefully\033[0m" << endl;
    }
    else if (choice == 2)
      cout << "\033[1;31mExited creating Objects\033[0m" << endl;
    else
      cout << "\033[1;31mInvalid choice\033[0m" << endl;
  }
}

void Knapsack::display()
{
  cout << "\033[1;33mObjects in the knapsack" << endl;
  knapsackNode *temp = this->resultHead;
  int count = 1;
  while (temp != NULL)
  {
    cout << "\033[1;34m" << count << " . " << temp->object << " ,\033[1;33mAlpha: \033[1;34m" << temp->alpha << " ,\033[1;33mWeight: \033[1;34m" << temp->weight << " ,\033[1;33mProfit: \033[1;34m" << temp->profit << endl;
    count++;
    temp = temp->link;
  }
  temp = this->resultHead;
  cout << "\033[1;33mTOTAL PROFIT = \033[1;34m";
  while (temp->link != NULL)
  {
    cout << temp->alpha << " * " << temp->profit << " + ";
    temp = temp->link;
  }
  cout << temp->alpha << " * " << temp->profit << " = \033[1;33m " << totalProfit << "\033[0m" << endl;
}

void Knapsack::calculateProfitables()
{
  int currentWeight = 0;

  for (knapsackNode *temp = this->head; temp != NULL; temp = temp->link)
  {
    if (currentWeight + temp->weight <= this->maxWeight)
    {
      knapsackNode *current = new knapsackNode;
      current->object = temp->object;
      current->weight = temp->weight;
      current->profit = temp->profit;
      current->alpha = temp->alpha;
      currentWeight += current->weight;
      totalProfit += current->profit;
      if (this->resultHead == NULL)
        this->resultHead = current;
      else
      {
        knapsackNode *traveller = this->resultHead;
        while (traveller->link != NULL)
          traveller = traveller->link;
        traveller->link = current;
      }
    }
    else
    {
      int remain = this->maxWeight - currentWeight;
      double coefficient = (double)remain / temp->weight;
      knapsackNode *current = new knapsackNode;
      current->object = temp->object;
      current->weight = temp->weight;
      current->profit = temp->profit;
      current->alpha = coefficient;
      currentWeight += remain;
      totalProfit += current->profit * coefficient;
      if (this->resultHead == NULL)
        this->resultHead = current;
      else
      {
        knapsackNode *traveller = this->resultHead;
        while (traveller->link != NULL)
          traveller = traveller->link;
        traveller->link = current;
      }
      break;
    }
  }
}

int main()
{
  cout << "------Program for Fractional Knapsack Problem-----" << endl;
  int maxWeight;
handleError1:
  try
  {
    cout << "Enter the maximum weight of the Knapsack: ";
    cin >> maxWeight;
    if (maxWeight <= 0)
      throw maxWeight;
  }
  catch (...)
  {
    cout << "\033[1;31mError Can't be Negetive or 0\033[0m" << endl;
    goto handleError1;
  }
  Knapsack knapsack(maxWeight);
  knapsack.setUpKnapsack();
  knapsack.calculateProfitables();
  knapsack.display();
  return 0;
}