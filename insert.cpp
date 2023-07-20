#include<iostream>
#include<string.h>
using namespace std;
struct link
{
    char ch[20];
    int num;
    link *next;
};

link *getnode()
{
    link *p=new link;
    char ch[20];
    int num;
    cin>>num>>ch;
    if(!strcmp(ch,"#"))
    {
        return NULL;
    }
    strcpy(p->ch,ch);
    p->num=num;
    p->next=NULL;
    return p;
}
int create(link* &head)
{
    link *p1;
    head=getnode();
    link *p=head;
    if(head==NULL)
    {
        cout<<"empty list"<<endl;
        return 0;
    }
    while(p1=getnode())
    {
        p->next=p1;
        p=p1;
    }
    return 0;
}
int insertlist(link *&head,link &pnew)
{
    link *p=head;
    link *p1=new link;
    link *father;
    *p1=pnew;
    if(!strcmp(p->ch,"jone") || !p)
    {
        p1->next=head;
        head=p1;
        return 0;
    }
    p=p->next;
    while(p)
    {
        if(strcmp(p->ch,"jone"))
        {
            father=p;
            p=p->next;
        }
        else
        {
            p1->next=p;
            father->next=p1;
            return 0;
        }
    }
    father->next=p1;
    p1->next=NULL;
    return 0;
}
int show(link *&head)
{
    link *p=head;
    while(p)
    {
        cout<<p->ch<<'\t'<<p->num<<endl;
        p=p->next;
    }
    return 0;
}
int main()
{
    link *head=new link;
    link p1={"marit",20};
    create(head);
    show(head);
    cout<<endl;
    insertlist(head,p1);
    show(head);
}