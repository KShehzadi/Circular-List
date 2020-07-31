#include <iostream>
#include "Node.cpp"

using namespace std;

class CCircList
{
public:
  Node* head;
  int count;

  CCircList();
  CCircList(Node* &ptr);
  CCircList(const CCircList &src);
  ~CCircList();
  void Insert(Node* &ptr);
  Node* Remove();
  void InsertAt(Node* &ptr, int index);
  void Print();
  CCircList& Reverse();
  CCircList& Flip();
  CCircList& Rotate(int steps, bool forward = true);

};

CCircList::CCircList():head(NULL), count(0)
{

}

CCircList::CCircList(Node* &ptr):head(ptr), count(1)
{
  ptr = NULL;
}

CCircList::CCircList(const CCircList &src)
{
  Node* dptr;
  Node* sptr;
  Node* sourceHead = src.head;
  this->count = src.count;

  dptr = sptr = this->head = src.head;

  if(src.head)
  {
    dptr = this->head = new Node(*sptr);
    sptr = sptr->next;
    while(sptr != sourceHead)
    {
      dptr->next = new Node(*sptr);
      sptr = sptr->next;
      dptr = dptr->next;
    }
    dptr->next = this->head;
  }
}

CCircList::~CCircList()
{
  Node* sourceHead = this->head;
  Node* sptr = this->head;
  if(this->head)
  {
    this->head = this->head->next;
    delete sptr;
    sptr = this->head;
    while(this->head != sourceHead)
    {
      this->head = this->head->next;
      delete sptr;
      sptr = this->head;
    }
  }
}

void CCircList::Insert(Node* &ptr)
{
  if(head)
  {
    ptr->next = this->head->next;
  }
  else
  {
    head = ptr;
  }
    this->head->next = ptr;
    count++;
    ptr = NULL;
}

Node* CCircList::Remove()
{
  Node* ptr = NULL;
  if(head)
  {
    ptr = head;
    if(head != head->next) // if there are more than 1 nodes i.e not only head
    {
      ptr = this->head->next;
      this->head->next = ptr->next;
    }
    else
    {
      head = NULL;
    }
    count--;
    ptr->next = NULL;
  }
  return ptr;
}

void CCircList::Print()
{
  Node* sptr = this->head->next;
  Node* sourceHead = this->head->next;
  if(sptr)
  {
    cout<<sptr->data;
    sptr = sptr->next;
    while(sptr != sourceHead)
    {
      cout<<sptr->data;
      sptr = sptr->next;
    }
  }
}

void CCircList::InsertAt(Node* &ptr, int index)
{
  if(index < 0) index = 0;
  if(index > count) index = index % (count + 1);
  if(index == 0 || index == count)
  {
    Insert(ptr);
    if(index == count)
    {
      head = head->next;
    }
  }
  else
  {
    Node* rp = head; // correction head->next ??
    for(int i = 0; i < index; i++)
    {
      rp = rp->next;
    }
    ptr->next = rp->next;
    rp->next = ptr;
    count++;
    ptr = NULL;
  }
}

CCircList& CCircList::Reverse()
{
  if(count < 2) return *this;
  if(count == 2)
  {
    head = head->next;
    return *this;
  }
  Node** arr = new Node*[this->count];
  int i;

  for(i = 0; i < this->count; i++) // correction i = 1 ??
  {
    head = head->next;
    arr[i] = head;
  }
  for(int i = 1; i < this->count; i++)
  {
    arr[i]->next = arr[i - 1];
  }
  arr[0]->next = arr[count - 1];
  head = arr[0];
  delete[] arr;
  return *this;
}

CCircList& CCircList::Flip()
{
  if(count < 3) return *this;
  Node** arr = new Node*[count];
  int i, j, sw = (count - 1) / 2;
  for(i = 0; i < count; i++)
  {
    head = head->next;
    arr[i] = head;
  }
  for(int i = 0, j = count - 2; i < sw; i++, j--)
  {
    head = arr[i]; // swaving step
    arr[i] = arr[j]; // first movement
    arr[j] = head; // restore movement
  }
  for(i = 1; i < count; i++)
  {
    arr[i - 1]->next = arr[i];
  }
  arr[count - 1]->next = arr[0];
  head = arr[count - 1];
  delete[] arr;
  return *this;
}

CCircList& CCircList::Rotate(int steps, bool forward)
{
  steps = steps % count;
  if(steps == 0) return *this;
  if(forward)
  {
    steps = count - steps;
  }
  for(int i = 0; i < steps; i++)
  {
    head = head->next;
  }
  return *this;
}

int main()
{
  Node* ptr1 = new Node(1);
  Node* ptr2 = new Node(2);
  Node* ptr3 = new Node(3);
  Node* ptr4 = new Node(4);
  Node* ptr5 = new Node(5);

  CCircList C1;

  C1.Insert(ptr1);
  C1.Insert(ptr2);
  C1.Insert(ptr3);
  C1.Insert(ptr4);
  C1.Insert(ptr5);

  CCircList C2(C1);

  C1.Reverse();
  C1.Print();
  C1.Flip();
  C1.Print();
  C1.Rotate(2);
  C1.Print();
  C2.Remove()->print();
  C2.Remove()->print();
  C2.Remove()->print();
  C2.Remove()->print();
  return 0;
}
