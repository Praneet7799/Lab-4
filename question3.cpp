#include <iostream>
#include <string.h>
using namespace std;
/*top and front are defined as global variables*/


int top, front;


class Issue
{
    public:
    char name[30];
    long int ph;
    char desc[100];
    Issue* link;
    Issue(){link=NULL;};
};

class StkPal
{
    public:
    char NM[30];
    /* push a character into stack */
    void push(char a)
   {
      top++;
      NM[top]  =  a;
   }
/* delete an element in stack */
   void pop()
   {
      top--;
   }
}stack;

class CustomerService
{
    public:
    Issue* head;
    Issue* tail;
    CustomerService()
    {
        head=NULL;
        tail=NULL;
    }
    int chkPalindrome(char nm[30]);
    void addIssue(char nm[30], long int p, char desc[]);
    void displayIssue();
};

/*Checking Palindrome Using Array STACK*/
int CustomerService::chkPalindrome(char nm[30])
{
   top=-1;
   front=0;
   char b;
   for (int i = 0;nm[i] != '\0';i++)
    {
          b = nm[i];
          stack.push(b);
    }
   for (int i = 0;i < (signed)(strlen(nm) / 2);i++)
    {
          if (stack.NM[top] == stack.NM[front])
          {
                stack.pop();
                front++;
          }
          else
          {
                return 0;
          }
    }
    int x=front;
    front  =  0;
    top  =  -1;
    if ((signed)(strlen(nm) / 2)==x)
      {    return 1;}
      return -1;
}


void CustomerService::addIssue(char nm[],long int p, char des[])
{
    Issue* temp=new Issue;
    temp->ph=p;
    strcpy(temp->name,nm);
    strcpy(temp->desc,des);
    if(head==NULL)
    {
      head=temp;
      tail=temp;
      return;
      
    }
    if(chkPalindrome(nm)==1)
    {
        temp->link=head;
        head=temp;
        
    }
    else
    {
        tail->link=temp;
        tail=temp;
        
    }
};
    
    

void CustomerService::displayIssue()
{
    Issue* iss;
    iss=head;
    if(iss==NULL)
    {
        cout<<"There is no registration done"<<endl;
    }
    else
    {
        cout<<"\nNAME \t \t PHONE \t \t\t Description \n";
        while(iss!=NULL)
        {
            cout<<"\n"<<iss->name<<" \t \t "<<iss->ph<<" \t \t "<<iss->desc;
            iss=iss->link;
        }
    }
    cout<<"\n \n \n";
}

int main()
{
    CustomerService issue;
    issue.displayIssue();
    issue.addIssue("Error141",9997689777,"A really good issue");
    issue.displayIssue();
    issue.addIssue("Wot?",9897678635,"This one's nice as well");
    issue.displayIssue();
    issue.addIssue("wow",6666666666,"Oh, the first palindrome");
    issue.displayIssue();
    issue.addIssue("nice",9653408725,"This one's just lame");
    issue.displayIssue();
    issue.addIssue("Youre lame",99999635417,"whoa! calm down");
    issue.displayIssue();
    issue.addIssue("cattac",8726391726,"putting in anything just for the palindrome");
    issue.displayIssue();
    issue.addIssue("stupidiputs",81726459173,"That one was clever");
    issue.displayIssue();
    issue.addIssue("Agreed",9273816492,"just two more to go");
    issue.displayIssue();
    issue.addIssue("*one",9241691827,"this assignment was challenging, man");
    issue.displayIssue();
    issue.addIssue("end",7812681627,"easier assignments pls");
    issue.displayIssue();
    return 0;   
}

