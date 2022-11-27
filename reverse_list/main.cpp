#include <iostream>

using namespace std;

typedef struct listElem {
  int data;
  struct listElem *next;
} listElem;

typedef listElem *LISTPTR;


LISTPTR l_free(LISTPTR)
{
  // Complete this
  // 
  return NULL;
}

void l_print(LISTPTR l)
{
  while (l) {

    cout << l->data << endl;

    l=l->next;

  } 

  return;
}

LISTPTR l_insert(LISTPTR l, int data)
{
  listElem *n = new listElem;

  n->data = data;

  n->next = l;

  l = n;

  return l;
}

LISTPTR reverseList(LISTPTR inp)
{

  LISTPTR ret = NULL;

  // reverse the input list
  //
  
  while (inp) {

    cout << "In reverseList" << endl;

    LISTPTR temp = inp;

    inp=inp->next;

    temp->next = ret;

    ret = temp;

  }

  return ret;
}


int main (int argc, char **argv, char **envp)
{
  LISTPTR inpList = NULL;

  inpList = l_insert(inpList, 4);
  inpList = l_insert(inpList, 3);
  inpList = l_insert(inpList, 5);
  inpList = l_insert(inpList, 6);

  LISTPTR retList = reverseList(inpList);

  l_print(retList);

  retList = l_free(retList);
   
  return(0);
}
