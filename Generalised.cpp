#include<iostream>
using namespace std;
#pragma pack(1)

template<class T>
struct Snode
{
    T Data;
    struct Snode* Next;
};

template<class T>
struct Dnode
{
    T Data;
    struct Dnode* prev;
    struct Dnode* Next;
};
/////////////////////////Singly Linear Linked List/////////////////////////////
template<class T>
class SinglyLL
{
    public:
    struct Snode<T>* First;
    int Count;

    SinglyLL();
    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPosition(T No,int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int iPos);

    void Display();
    int CountNodes();
};
/////////////////////////Singly Circular Linked List/////////////////////////////
template<class T>
class SinglyCL
{
   public:
   struct Snode<T>* First;
   struct Snode<T>* Last;
   int Count; 

   SinglyCL();
   void InsertFirst(T No);
   void InsertLast(T No);
   void InsertAtPosition(T No,int iPos);

   void DeleteFirst();
   void DeleteLast();
   void DeleteAtPosition(int iPos);

   void Display();
   int CountNodes();
};
/////////////////////////Doubly Linear Linked List/////////////////////////////
template<class T>
class DoublyLL
{
    public:
    struct Dnode<T>* First;
    int Count;

    DoublyLL();
    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPosition(T No,int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int iPos);

    void Display();
    int CountNodes();
};
/////////////////////////Doubly Circular Linked List/////////////////////////////
template<class T>
class DoublyCL
{
   public:
   struct Dnode<T>* First;
   struct Dnode<T>* Last;
   int Count; 

   DoublyCL();
   void InsertFirst(T No);
   void InsertLast(T No);
   void InsertAtPosition(T No,int iPos);

   void DeleteFirst();
   void DeleteLast();
   void DeleteAtPosition(int iPos);

   void Display();
   int CountNodes();
};
/////////////////////////Stack/////////////////////////////
template <class T>
class Stack
{
    public:
    struct Snode<T>* First;
    int Count;

    Stack();
    bool IsStackEmpty();
    void push(T No);
    int pop();
    void Display();

};
/////////////////////////Queue/////////////////////////////
template <class T>
class Queue
{
    public:
    struct Snode<T>* First;
    int Count;

    Queue();
    bool IsQueueEmpty();
    void EnQueue(T No);
    int DeQueue();
    void Display();

};

/////////////////////////Singly Linear Linked List Functions/////////////////////////////
template<class T>
SinglyLL<T>::SinglyLL()
{
  First=NULL;
  Count=0;
}
template<class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct Snode<T> * newn = new Snode<T>; 
    newn->Data=No;
    newn->Next=NULL;
    if(First==NULL)
    {
      First=newn;
    }
    else
    {
        newn->Next=First;
        First=newn;
    }
    Count++;
}
template<class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct Snode<T> * newn = new Snode<T>; 
    newn->Data=No;
    newn->Next=NULL;
    if(First==NULL)
    {
     First=newn;
    }
    else
    {
        struct Snode<T>* temp=First;
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        temp->Next=newn;
    }
    Count++;

}
template<class T>
void SinglyLL<T>::InsertAtPosition(T No,int iPos)
{
    if((iPos<1)||(iPos>Count+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos==1)
    {
      InsertFirst(No);
    }
    else if(iPos==Count+1)
    {
        InsertLast(No);
    }
    else
    {
        struct Snode<T>* temp=First;
        struct Snode<T> * newn = new Snode<T>; 
        newn->Data=No;
        newn->Next=NULL;
        int i=0;
        for(i=1;i<iPos-1;i++)
        {
            temp=temp->Next;
        }
        newn->Next=temp->Next;
        temp->Next=newn;
        Count++;
    }

}
template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(First==NULL)
    {
        cout<<"Linked List is Empty"<<"\n";
        return;
    }
    else if(First->Next==NULL)
    {
      delete(First);
      First=NULL;
      Count--;
    }
    else
    {
        struct Snode<T>* temp=First;
        First=First->Next;
        delete(temp);
        Count--;
    }

    
}
template<class T>
void SinglyLL<T>::DeleteLast()
{
   if(First==NULL)
    {
        cout<<"Linked List is Empty"<<"\n";
        return;
    }
    else if(First->Next==NULL)
    {
      delete(First);
      First=NULL;
      Count--;
    }
    else
    {
        struct Snode<T>* temp=First;
        while(temp->Next->Next!=NULL)
        {
            temp=temp->Next;
        }
        delete(temp->Next->Next);
        temp->Next=NULL;
        Count--;
    }

}
template<class T>
void SinglyLL<T>::DeleteAtPosition(int iPos)
{
     if((iPos<1)||(iPos>Count))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==Count)
    {
        DeleteLast();
    }
    else
    {
        struct Snode<T>* temp1=First;
        struct Snode<T>* temp2=First;
        int i=0;
        for(i=1;i<iPos-1;i++)
        {
            temp1=temp1->Next;
        }
        temp2=temp1->Next;
        temp1->Next=temp2->Next;
        delete(temp2);
        Count--;
    }

}
template<class T>
void SinglyLL<T>::Display()
{
    struct Snode<T>* temp=First;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->Data<<"|->";
        temp=temp->Next;
    }
    cout<<"NULL"<<"\n";
}
template<class T>
int SinglyLL<T>::CountNodes()
{
    struct Snode<T>* temp=First;
    int Ncount=0;
    while(temp!=NULL)
    {
        Ncount++;
        temp=temp->Next;
    }
    return Ncount;
}
/////////////////////////Singly Circular Linked List Functions/////////////////////////////
template<class T>
SinglyCL<T>::SinglyCL()
{
    First=NULL;
    Last=NULL;
    Count=0;
}
template<class T>
void SinglyCL<T>::InsertFirst(T No)
{
    struct Snode<T> * newn = new Snode<T>; 
    newn->Data=No;
    newn->Next=NULL;
    if((First==NULL)&&(Last==NULL))
    {
      First=Last=newn;
      Last->Next=First;
    }
    else
    {
      newn->Next=First;
      First=newn;
      Last->Next=First;
    }
    Count++;
}
template<class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct Snode<T> * newn = new Snode<T>; 
    newn->Data=No;
    newn->Next=NULL;
    if((First==NULL)&&(Last==NULL))
    {
      First=Last=newn;
      Last->Next=First;
    }
    else
    {
      newn->Next=First;
      Last->Next=newn;
      Last=newn;
      Last->Next=First;
    }
    Count++;

}
template<class T>
void SinglyCL<T>::InsertAtPosition(T No,int iPos)
{
    if((iPos<1)||(iPos>Count+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos==1)
    {
        InsertFirst(No);
    }
    else if(iPos==Count+1)
    {
        InsertLast(No);
    }
    else
    {
        struct Snode<T>* temp=First;
        struct Snode<T> * newn = new Snode<T>; 
        newn->Data=No;
        newn->Next=NULL;
        int i=0;
        for(i=1;i<iPos-1;i++)
        {
            temp=temp->Next;
        }
        newn->Next=temp->Next;
        temp->Next=newn;
        Last->Next=First;
        Count++;
    }

}
template<class T>
void SinglyCL<T>::DeleteFirst()
{
    if((First==NULL)&&(Last==NULL))
    {
        cout<<"Linked List is empty"<<"\n";
        return;
    }
    else
    {
      First=First->Next;
      delete(Last->Next);
      Last->Next=First;
      Count--;
    }
   
}
template<class T>
void SinglyCL<T>::DeleteLast()
{
    if((First==NULL)&&(Last==NULL))
    {
        cout<<"Linked List is empty"<<"\n";
        return;
    }
    else
    {
      struct Snode<T>* temp=First;
      while(temp->Next!=Last)
      {
        temp=temp->Next;
      }
      Last=temp;
      delete(temp->Next);
      Last->Next=First;
      Count--;
    }
    

}
template<class T>
void SinglyCL<T>::DeleteAtPosition(int iPos)
{
    if((iPos<1)||(iPos>Count))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==Count)
    {
        DeleteLast();
    }
    else
    {
        struct Snode<T>* temp1=First;
        struct Snode<T>* temp2=First;
        int i=0;
        for(i=1;i<iPos-1;i++)
        {
            temp1=temp1->Next;
        }
        temp2=temp1->Next;
        temp1->Next=temp2->Next;
        delete(temp2);
        Last->Next=First;
        Count--;
    }

}
template<class T>
void SinglyCL<T>::Display()
{
    struct Snode<T>* temp=First;
    
    do
    {
        cout<<"|"<<temp->Data<<"|->";
        temp=temp->Next;
    }while(temp!=Last->Next);
    cout<<"\n";

}
template<class T>
int SinglyCL<T>::CountNodes()
{   
    int Count=0;
    struct Snode<T>* temp=First;
    
    do
    {   
        Count++;
        temp=temp->Next;
    }while(temp!=Last->Next);
    return Count;
}
/////////////////////////Doubly Linear Linked List Functions/////////////////////////////
template<class T>
DoublyLL<T>::DoublyLL()
{
    First=NULL;
    Count=0;
}
template<class T>
void  DoublyLL<T>::InsertFirst(T No)
{
    struct Dnode<T> * newn = new Dnode<T>; 
    newn->prev=NULL;
    newn->Next=NULL;
    newn->Data=No;

    if(First==NULL)
    {
      First=newn;
    }
    else
    {
      newn->Next=First;
      First->prev=newn;
      First=newn;
    }
    Count++;
}
template<class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct Dnode<T> * newn = new Dnode<T>; 
    newn->prev=NULL;
    newn->Next=NULL;
    newn->Data=No;
    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        struct Dnode<T>* temp=First;
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        newn->prev=temp;
        temp->Next=newn;
    }
    Count++;
}
template<class T>
void DoublyLL<T>::InsertAtPosition(T No,int iPos)
{
    if((iPos<1)||(iPos>Count+1))
    {
      cout<<"Invalid Position"<<"\n";
    }
    if(iPos==1)
    {
        InsertFirst(No);
    }
    else if(iPos==Count+1)
    {
        InsertLast(No);
    }
    else
    {
        struct Dnode<T> * newn = new Dnode<T>; 
        newn->prev=NULL;
        newn->Next=NULL;
        newn->Data=No;
        struct Dnode<T>* temp=First;
        int i=0;
        for(i=1;i<iPos-1;i++)
        {
            temp=temp->Next;
        }
        newn->Next=temp->Next;
        newn->prev=temp;
        temp->Next=newn;
        newn->Next->prev=newn;
        Count++;
    }

}
template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First==NULL)
    {
        cout<<"Linked List is empty"<<"\n";
        return;
    }
    else
    {
       First=First->Next; 
       delete(First->prev);
       First->prev=NULL;
        Count--;
    }
   
}
template<class T>
void DoublyLL<T>::DeleteLast()
{
    if(First==NULL)
    {
       cout<<"Linked List is empty"<<"\n";
       return; 
    }
    else
    {
        struct Dnode<T>* temp=First;
        while(temp->Next->Next!=NULL)
        {
            temp=temp->Next;
        }
        delete(temp->Next);
        temp->Next=NULL;
        Count--;
    }
    
}
template<class T>
void DoublyLL<T>::DeleteAtPosition(int iPos)
{
    if((iPos<1)||(iPos>Count))
    {
      cout<<"Invalid Position"<<"\n";
    }
    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==Count)
    {
        DeleteLast();
    }
    else
    {
        struct Dnode<T>* temp=First;
        int i=0;
        for(i=1;i<iPos-1;i++)
        {
            temp=temp->Next;
        }
        temp->Next=temp->Next->Next;
        delete(temp->Next->prev);
        temp->Next->prev=temp;
        Count--;
    }

}
template<class T>
void DoublyLL<T>::Display()
{
    struct Dnode<T>* temp=First;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->Data<<"|<=>";
        temp=temp->Next;
    }
    cout<<"NULL"<<"\n";
}
template<class T>
int DoublyLL<T>::CountNodes()
{
    int Count=0;
    struct Dnode<T>* temp=First;
    while(temp!=NULL)
    {
        Count++;
        temp=temp->Next;
    }
    return Count;
}
/////////////////////////Doubly Circular Linked List Functions/////////////////////////////
template<class T>
DoublyCL<T>::DoublyCL()
{
   First=NULL;
   Last=NULL;
   Count=0;
}
template<class T>
void  DoublyCL<T>::InsertFirst(T No)
{
  struct Dnode<T> * newn = new Dnode<T>;
  newn->Data=No;
  newn->prev=NULL;
  newn->Next=NULL;
  if((First==NULL)&&(Last==NULL))
  {
    First=Last=newn;
    newn->Next=First;
    newn->prev=Last;
    Last->Next=First;
  }
  else
  {
    newn->prev=Last;
    newn->Next=First;
    First=newn;
    Last->Next=First;
  }
  Count++;
}
template<class T>
void  DoublyCL<T>::InsertLast(T No)
{
    struct Dnode<T> * newn = new Dnode<T>;
    newn->Data=No;
    newn->prev=NULL;
    newn->Next=NULL;
    if((First==NULL)||(Last==NULL))
    {
        First=Last=newn;
        newn->prev=Last;
        newn->Next=First;
        Last->Next=First;
    }
    else
    {
        newn->prev=Last;
        newn->Next=First;
        Last->Next=newn;
        Last=newn;
        Last->Next=First;
    }
    Count++;
}
template<class T>
void  DoublyCL<T>::InsertAtPosition(T No,int iPos)
{
    if((iPos<1)||(iPos>Count+1))
    {
        cout<<"Invalid Position";
        return;
    }
    if(iPos==1)
    {
        InsertFirst(No);
    }
    else if(iPos==Count+1)
    {
        InsertLast(No);
    }
    else
    {
        struct Dnode<T> * newn = new Dnode<T>;
        newn->Data=No;
        newn->prev=NULL;
        newn->Next=NULL;
        struct Dnode<T>* temp=First;
        int i=0;
        for(i=1;i<iPos-1;i++)
        {
            temp=temp->Next;
        }
        newn->prev=temp;
        newn->Next=temp->Next;
        temp->Next=newn;
        Last->Next=First;
        Count++;
    }

}
template<class T>
void  DoublyCL<T>::DeleteFirst()
{
    if((First==NULL)&&(Last==NULL))
    {
        cout<<"Linked List is empty"<<"\n";
        return;
    }
    else
    {
        First=First->Next;
        First->prev=Last;
        Last->Next=First;
        Count--;
    }

}
template<class T>
void  DoublyCL<T>::DeleteLast()
{
    if((First==NULL)&&(Last==NULL))
    {
        cout<<"Linked List is empty"<<"\n";
        return;
    }
    else
    {
        Last=Last->prev;
        delete(Last->Next);
        First->prev=Last;
        Last->Next=First;
        Count--;
    }

}
template<class T>
void  DoublyCL<T>::DeleteAtPosition(int iPos)
{
    if((iPos<1)||(iPos>Count))
    {
        cout<<"Invalid Position";
        return;
    }
    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==Count)
    {
        DeleteLast();
    }
    else
    {
        struct Dnode<T>* temp1=First;
        struct Dnode<T>* temp2=First;
        int i=0;
        for(i=1;i<iPos-1;i++)
        {
            temp1=temp1->Next;
        }
        temp2=temp1->Next;
        temp1->Next=temp2->Next;
        temp2->Next->prev=temp1;
        delete(temp2);
        Last->Next=First;
        Count--;
    }

}
template<class T>
void  DoublyCL<T>::Display()
{   
    struct Dnode<T>* temp=First;
     do
    {
      cout<<"|"<<temp->Data<<"|<=>";
      temp=temp->Next;
    }while(temp!=First);
    cout<<"\n";
}
template<class T>
int  DoublyCL<T>::CountNodes()
{
    int Count=0;
    struct Dnode<T>* temp=First;
    do 
    {
        Count++;
        temp=temp->Next;

    }while(temp!=Last->Next);
    return Count;
}
/////////////////////////Stack/////////////////////////////
template <class T>
Stack<T>::Stack()
{
  First=NULL;
  Count=0;
}
template <class T>
bool Stack<T>::IsStackEmpty()
{
  if(Count==0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
template <class T>
void Stack<T>::push(T No)//insert first
{
    struct Snode<T>*newn=new Snode<T>;
    newn->Data=No;
    newn->Next=NULL;
    if(First==NULL)
    {
      First=newn;
    }
    else
    {
      newn->Next=First;
      First=newn;
    }
    cout<<No<<" pushed Successfully\n";
    Count++;
}
template <class T>
int Stack<T>::pop()//delete first
{
  int iNo=0;
  if(First==NULL)
  {
    return -1;
  }
  else
  {
    iNo=First->Data;
    struct Snode<T>*temp=First;
    First=First->Next;
    delete temp;
    Count--;
  }
  return iNo;
}
template <class T>
void Stack<T>:: Display()
{
  struct Snode<T>*temp=First;
  while(temp!=NULL)
  {
    cout<<"|"<<temp->Data<<"|->";
    temp=temp->Next;
  }
  cout<<"\n";
}
/////////////////////////Queue/////////////////////////////
template <class T>
Queue<T>::Queue()
{
  First=NULL;
  Count=0;
}
template <class T>
bool Queue<T>::IsQueueEmpty()
{
  if(Count==0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
template <class T>
void Queue<T>:: EnQueue(T No)//insert last
{
    struct Snode<T>*newn=new Snode<T>;
    newn->Data=No;
    newn->Next=NULL;
    if(First==NULL)
    {
        First=newn;
    }
    else
    {
      struct Snode<T>*temp=First;
      while(temp->Next!=NULL)
      {
        temp=temp->Next;
      }
      temp->Next=newn;
    }
    Count++;
}
template <class T>
int Queue<T>::DeQueue()//delete first
{
  int iNo=0;
  if(First==NULL)
  {
    return -1;
  }
  else
  {
    iNo=First->Data;
    struct Snode<T>*temp=First;
    First=First->Next;
    delete temp;
    Count--;
  }
  return iNo;
}
template <class T>
void Queue<T>:: Display()
{
  struct Snode<T>*temp=First;
  while(temp!=NULL)
  {
    cout<<"|"<<temp->Data<<"|->";
    temp=temp->Next;
  }
  cout<<"\n";
}
///////////////////////////////////////////////////


