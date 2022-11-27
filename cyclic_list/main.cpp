#include <iostream>
#include <string>

using namespace std;

typedef struct listElem {
  int data;
  struct listElem *next;
} listElem;

typedef listElem* LISTPTR;

bool is_cyclic(LISTPTR l)
{
  LISTPTR slow = l, fast = l;

  while (fast && slow) {

    fast = fast->next;

    if (slow == fast) return true;

    if (fast) fast = fast->next;

    if (slow == fast) return true;

    slow = slow->next; 
  }

  return false;
}

int main(int argc, char **argv, char **envp)
{
  LISTPTR l = NULL;

  // Create list l
  //

  bool cyclic = is_cyclic(l);

  string result = cyclic ? "Cyclic" : "Non-cyclic";

  cout << result << endl;

  return 0;
}
