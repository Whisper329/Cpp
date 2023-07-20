#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

struct Student
{
    long number;
    float score;
    Student * next;
};


int create(Student* &head)
{
    long number;
    float score;
    cin>>number>>score;
    Student *p=new Student;
    p=head;
    if(number == 0)
    {
        head = NULL;
        return 0;
    }
    while(number != 0)
    {
        p->number=number;
        p->score=score;
        Student *p1=new Student;
        cin>>number>>score;
        if(number==0)
        {
            p1=NULL;
            p->next=p1;
            return 0;
        }
        p->next=p1;
        p=p1;
    }
    return 0;
}


Student* getnode()
{
    long number;
    float score;
    cin>>number>>score;
    if(number == 0)
    {
        return NULL;
    }
    Student* p=new Student;
    p->number=number;
    p->score=score;
    p->next=NULL;
    return p;
}
int create2(Student* &head)
{
    head = getnode();
    Student* p=head;
    if(head == NULL)
    {
        return NULL;
    }
    Student* p1;
    while(p1=getnode())
    {
        p->next=p1;
        p=p1;
    }
    return 0;
}

int deletelist(Student* &head, int n)
{
    Student *p;
    Student *father;
    p=head;
    if(!p)
    {
        cout<<"empty list"<<endl;
        return 0;
    }
    if(p->number == n)
    {
        head=head->next;
        return 0;
    }
    p=p->next;
    while(p)
    {
        if(p->number!=n)
        {
            father = p;
            p=p->next;
        }
        else
        {
            father->next=p->next;
            delete p;
            return 0;
        }
        
    }
    cout<<"can't find "<<n<<endl;
    return 0;
}
int insertlist(Student* &head, Student &p1)
{
    Student *p=head;
    Student *father;
    Student *pnew=new Student;  //放在堆区
    *pnew=p1;  //初始化
    if(!p || p->number > pnew->number)
    {
        pnew->next=head;
        head=pnew;
        return 0;
    }
    p=p->next;
    while(p)
    {
        if(p->number < pnew->number)
        {
            father=p;
            p=p->next;
        }
        else
        {
            pnew->next=father->next;
            father->next=pnew;
            return 0;
        }
    }
    father->next=pnew;
    pnew->next=NULL;
    return 0;
}
int showlist(Student* &head)
{
    Student *p=head;
    int n=0;
    cout<<fixed<<setprecision(1);
    while(p)
    {
        cout<<p->number<<'\t'<<p->score<<endl;
        p=p->next;
        n++;
    }
    cout<<n<<endl;
    return 0;
}
int main()
{
    Student *head=new Student;
    Student p={77,2.1};
    create2(head);
    showlist(head);
    // deletelist(head,54);
    insertlist(head,p);
    showlist(head);
}