#include <iostream>
using namespace std;

class coinNode
{
public:
  int coin;
  int count;
  coinNode *link;
};

class ChangeProducer
{
private:
  coinNode *head, *resultHead;
  int total;

public:
  ChangeProducer(int total)
  {
    this->head = NULL;
    this->resultHead = NULL;
    this->total = total;
  }
  void setUpChange();
  void sortChange();
  bool produceChange();
  void displayChange();
};

void ChangeProducer::setUpChange()
{
  int choice = 1;
  while (choice != 2)
  {
    cout << "\033[1;33m1. Add another coin." << endl;
    cout << "2. Stop adding.\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      int coin;
      while (1)
      {
        cout << "Enter the coin value: ";
        cin >> coin;
        if (coin > 0)
          break;
        cout << "\033[1;31mCoin Value Can't be 0 or Negetive\033[0m" << endl;
      }
      coinNode *current = new coinNode;
      current->coin = coin;
      current->link = NULL;
      if (this->head == NULL)
      {
        this->head = current;
      }
      else
      {
        coinNode *temp = this->head;
        while (temp->link != NULL)
          temp = temp->link;
        temp->link = current;
      }
      cout << "\033[1;34mCoin Added successfully\033[0m" << endl;
    }
    break;
    case 2:
      cout << "\033[1;31mStopped Adding\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31mInvalid Choice\033[0m" << endl;
      break;
    }
  }
  cout << "\033[1;34mChange setup successfully\033[0m" << endl;
}

void ChangeProducer::sortChange()
{
  for (coinNode *temp1 = this->head; temp1->link != NULL; temp1 = temp1->link)
  {
    for (coinNode *temp2 = temp1->link; temp2 != NULL; temp2 = temp2->link)
    {
      if (temp1->coin < temp2->coin)
      {
        int coin = temp1->coin;
        temp1->coin = temp2->coin;
        temp2->coin = coin;
      }
    }
  }
}

bool ChangeProducer::produceChange()
{
  coinNode *temp = this->head;
  int sum = 0;
  int leftTotal = this->total;
  while (temp != NULL && sum <= this->total)
  {
    if (leftTotal == 0)
      break;
    if (sum + ((leftTotal / temp->coin) * temp->coin) <= this->total)
    {
      coinNode *current = new coinNode;
      current->coin = temp->coin;
      current->count = leftTotal / temp->coin;
      current->link = NULL;
      if (this->resultHead == NULL)
        this->resultHead = current;
      else
      {
        coinNode *traveller = this->resultHead;
        while (traveller->link != NULL)
          traveller = traveller->link;
        traveller->link = current;
      }
      sum += (leftTotal / temp->coin) * temp->coin;
      leftTotal = this->total - sum;
    }
    temp = temp->link;
  }
  if (sum == this->total)
    return true;
  return false;
}

void ChangeProducer::displayChange()
{
  cout << "\033[1;32mYour change for amount " << this->total << " is:\033[1;34m" << endl;
  coinNode *temp = this->resultHead;
  while (temp != NULL)
  {
    cout << temp->coin << " rupees " << temp->count << " coins" << endl;
    temp = temp->link;
  }
  cout << "\033[0m" << endl;
}

int main()
{
  cout << "-----Program for coin change supplier through greedy algorithm-----" << endl;
  int x;
  cout << "Enter the amount you want a change for: ";
  cin >> x;
  ChangeProducer changeproducer(x);
  changeproducer.setUpChange();
  changeproducer.sortChange();
  if (changeproducer.produceChange())
    changeproducer.displayChange();
  else
    cout << "\033[1;31mYour amount can't be produced with given coin inputs\033[0m" << endl;
  return 0;
}