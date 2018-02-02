#include <iostream>
using namespace std;
/* Praneet Nandan 1711096 */

/* Node class that defines what a node is shaped like */
class Node
{
  public:
  int data;
  Node* next;
  Node()
  {
    data=0;
    next=NULL;
  }
};


/*   Stack via Linked list   */
class Stack
{
  public:
  Node* head;
  Stack()
  {
    head=NULL;
  }
  void push(int num);
  void pop();
  void display();
};



/* Implementing Stack by Array */
class StackArr
{
             int stk[50];
             int top;
      public:
             StackArr()
              {
                top=-1;
              }
             void push(int x)
              {
                 if(top >  49)
                       {
                           cout <<"\nStack full";
                           return;
                       }
                 stk[++top]=x;
                 cout <<"\nInserted " <<x<<endl;
               }
             void pop()
               {
                  if(top <0)
                   {
                         cout <<"\nStack empty";
                         return;
                    }
                    cout <<"\nDeleted" <<stk[top--]<<endl;
                }
             void display()
               {
                   cout<<"\n";
                   if(top<0)
                    {
                            cout <<" Empty";
                            return;
                    }
                    for(int i=top;i>=0;i--)
                    cout <<stk[i] <<" -> ";
                    cout<<"NULL";
                }
};


/* Implementing Queue via Array */
class QueueArr
{
              int q[50];
              int rear,front;
      public:
              QueueArr()
                {
                     rear=-1;
                     front=-1;
                }
              void add(int x)
               {
                   if(rear >  49)
                    {
                       cout <<"\nQueue full";
                       return;
                    }
                    q[++rear]=x;
                    cout <<"\nInserted " <<x<<endl;
               }
              void remov()
               {
                   if(front==rear)
                     {
                         cout <<"\nEmpty";
                         return;
                     }
                     cout <<"\nDeleted " <<q[++front];
                }
              void display()
               {
                   cout<<"\n";
                   if(rear==front)
                     {
                          cout <<"\nEmpty!";
                          return;
                     }
                   for(int i=front+1;i<=rear;i++)
                   cout <<q[i]<<" -> ";
                   cout<<"NULL";
               }
};

/*  Queue via linked list  */
class Queue
{
  public:
  Node* head;
  Node* tail;
  Queue()
  {
    head=NULL;
    tail=NULL;
  }
  void add(int num);
  void remov();
  void display();
};


/*  pushing in a stack node  */
void Stack::push(int num)
{
  Node* temp=new Node;
  temp->data=num;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
    return;
  }
  temp->next=head;
  head=temp;
}


/*  popping in a stack node  */
void Stack::pop()
{
  Node* temp;
  if(head==NULL)
  { 
   cout<<"\nThe stack is empty";
   return;
  }
  temp=head;
  head=head->next;
  temp->next=NULL;
  cout<<"\n"<<temp->data<<" is deleted";
  delete temp;
}


/*  displaying a stack  */
void Stack::display()
{
  Node *locate = head;
  cout<<"\n";
  while (locate!=NULL)
  {
    cout << locate->data << "->" ;
    locate = locate->next;
  }
  cout << "NULL" <<endl;
}


/*  adding in a queue  */
void Queue::add(int num)
{
  Node *temp=new Node;
  temp->data=num;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp; 
  }
  else
  {
    tail->next=temp;
  }
  tail=temp;
}


/*  removing in a queue   */
void Queue::remov()
{
  Node* temp;
  if(head==NULL)
  {
   cout<<"\nQueue is empty";
   return;
  }
  temp=head;
  head=head->next;
  cout<<"\n"<<temp->data<<" is being deleted";
  temp->next=NULL;
  delete temp;
}


/*  displaying the queue   */
void Queue::display()
{
 {
  Node *temp = head;
  cout<<"\n";
  while (temp!=NULL)
  {
    cout << temp->data << "->" ;
    temp = temp->next;
  }
  cout << "NULL" <<endl;
 }
}

/* main function to test the codes */
int main()
{
  Stack Sll;
  Queue Qll;
  StackArr Sarr;
  QueueArr Qarr;
  cout<<"\n Linked list stack \n";
  
  /*Checking for stack and queue by linked list*/
  Sll.push(1);
  Sll.push(3);
  Sll.push(7);
  Sll.display();
  Sll.pop();
  Sll.display();
  cout<<"\n Linked list queue \n";
  Qll.add(45);
  Qll.add(3);
  Qll.add(62);
  Qll.display();
  Qll.remov();
  Qll.display();
  
  /*Checking for stack and queue by Array*/
  cout<<"\n Array stack \n";
  Sarr.push(342);
  Sarr.push(3);
  Sarr.push(45);
  Sarr.display();
  Sarr.pop();
  Sarr.push(3);
  Sarr.pop();
  Sarr.display();
  cout<<"\n Array queue \n";
  Qarr.add(24);
  Qarr.add(2);
  Qarr.add(44);
  Qarr.display();
  Qarr.remov();
  Qarr.display();
  
  return 0;
}
