#include <iostream>
#include "tContainer_t.h"

using namespace std;

/* --------------------------------------------------------------- */

void RunContainer();
void RunContainerList();
void Run();

/* --------------------------------------------------------------- */

int main()
{
  Run();

  return 0;
}

/* --------------------------------------------------------------- */

void Run()
{
  int userInput;
  while(userInput != 3)
  {
    cout << "1. Test vector" << endl;
    cout << "2. Test list" << endl;
    cout << "3. Exit" << endl;

    cin >> userInput;
    switch(userInput)
    {
      case 1:
        RunContainer();
        break;
      case 2:
        RunContainerList();
        break;
      case 3:
        break;
      default:
        cout << "I didn't understand" << endl;
        break;
    }
  }
}

/* --------------------------------------------------------------- */

void RunContainer()
{
  tContainer_t<int, vector<int*> > g_cont;
  int choice, num;
  int* res;
  int* newNumber = new int();
  while(choice != 12)
  {
    cout << "1. Check if your container is empty" << endl
         << "2. Check the size of your container" << endl
         << "3. Insert an element into your container" << endl
         << "4. Get the first element for your container" << endl
         << "5. Get the last element for your container" << endl
         << "6. Find an element by value in your container" << endl
         << "7. Remove an element from your container" << endl
         << "8. Remove all elements from your container" << endl
         << "9. Remove and delete an element from your container" << endl
         << "10. Remove and delete all elements from your container" << endl
         << "11. Subscript" << endl
         << "12. Exit" << endl << endl;

    cin >> choice;

    switch(choice)
    {
      case 1:
        g_cont.isEmpty() ? cout << "Yep, it's empty." << endl : cout << "Not empty!" << endl;
        break;

      case 2:
        cout << "Number of elements: " << g_cont.countElements() << endl;
        break;

      case 3:
        cout << "Give me an integer: " << endl;
        cin >> *newNumber;
        g_cont.insertToEnd(newNumber);
        cout << "Success inserted!" << endl;
        break;

      case 4:
        res = (int*)g_cont.returnFirst();
        cout << "First element in your container: " << *res << endl;
        break;

      case 5:
        res = (int*)g_cont.returnLast();
        cout << "Last element in your container: " << *res << endl;
        break;

      case 6:
        cout << "Enter integer:" << endl;
        cin >> num;
        res = (int*)g_cont.findByValue(num);
        res ? cout << "Element found!!" << endl : cout << "Element not found" << endl;
        break;

      case 7:
        cout << "Enter integer: " << endl;
        cin >> num;
        res = (int*)g_cont.remove(num);
        if(res)
        {
          cout << "Value: " << *res << endl;
        }
        else
        {
          cout << "Nope, not found." << endl;
        }
        break;

      case 8:
        g_cont.removeAll();
        cout << "Done" << endl;
        break;

      case 9:
        cout << "Enter integer: " << endl;
        cin >> num;
        if(g_cont.removeAndDelete(num))
        {
          cout << "It worked." << endl;
        }
        else
        {
          cout << "It didn't work." << endl;
        }
        break;

      case 10:
        g_cont.removeAndDeleteAll();
        cout << "Done!" << endl;
        break;

      case 11:
        int i;
        cout << "Enter index: " << endl;
        cin >> i;
        res = (int*)g_cont[i];
        cout << "Integer at given index: " << *res << endl;
        break;

      case 12:
        break;

      default:
        cout << "I didn't catch that, try again!" << endl;
        break;
    }
  }
  delete newNumber;
}

/* --------------------------------------------------------------- */

void RunContainerList()
{
  tContainer_t<int, list<int*> > g_cont;
  int choice, num;
  int* res;
  int* newNumber = new int();
  while(choice != 12)
  {
    cout << "1. Check if your container is empty" << endl
         << "2. Check the size of your container" << endl
         << "3. Insert an element into your container" << endl
         << "4. Get the first element for your container" << endl
         << "5. Get the last element for your container" << endl
         << "6. Find an element by value in your container" << endl
         << "7. Remove an element from your container" << endl
         << "8. Remove all elements from your container" << endl
         << "9. Remove and delete an element from your container" << endl
         << "10. Remove and delete all elements from your container" << endl
         << "11. Subscript" << endl
         << "12. Exit" << endl << endl;

    cin >> choice;

    switch(choice)
    {
      case 1:
        g_cont.isEmpty() ? cout << "Yep, it's empty." << endl : cout << "Not empty!" << endl;
        break;

      case 2:
        cout << "Number of elements: " << g_cont.countElements() << endl;
        break;

      case 3:
        cout << "Give me an integer: " << endl;
        cin >> *newNumber;
        g_cont.insertToEnd(newNumber);
        cout << "Success inserted!" << endl;
        break;

      case 4:
        res = (int*)g_cont.returnFirst();
        cout << "First element in your container: " << *res << endl;
        break;

      case 5:
        res = (int*)g_cont.returnLast();
        cout << "Last element in your container: " << *res << endl;
        break;

      case 6:
        cout << "Enter integer:" << endl;
        cin >> num;
        res = (int*)g_cont.findByValue(num);
        res ? cout << "Element found!!" << endl : cout << "Element not found" << endl;
        break;

      case 7:
        cout << "Enter integer: " << endl;
        cin >> num;
        res = (int*)g_cont.remove(num);
        if(res)
        {
          cout << "Value: " << *res << endl;
        }
        else
        {
          cout << "Nope, not found." << endl;
        }
        break;

      case 8:
        g_cont.removeAll();
        cout << "Done" << endl;
        break;

      case 9:
        cout << "Enter integer: " << endl;
        cin >> num;
        if(g_cont.removeAndDelete(num))
        {
          cout << "It worked." << endl;
        }
        else
        {
          cout << "It didn't work." << endl;
        }
        break;

      case 10:
        g_cont.removeAndDeleteAll();
        cout << "Done!" << endl;
        break;

      case 11:
        int i;
        cout << "Enter index: " << endl;
        cin >> i;
        res = (int*)g_cont[i];
        cout << "Integer at given index: " << *res << endl;
        break;

      case 12:
        break;

      default:
        cout << "I didn't catch that, try again!" << endl;
        break;
    }
  }
  delete newNumber;
}
