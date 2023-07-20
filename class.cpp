#include<iostream>
#include<string>
using namespace std;
class Name
{
    private:
    string name;
    static int count;

    public:
    Name(string na);
    ~Name();
    void ChangeName(string na);
    string dis();
    static int discount();
};

int Name::count=0;

Name::Name(string na="no name")
{
    name=na;
    count++;
    cout<<"\\\\constructing\\ "<<name<<endl;
    cout<<"there are "<<discount()<<" people are created."<<endl;
}

Name::~Name()
{
    // cout<<"    destructing     "<<name<<endl;
    count--;
    cout<<"destroying 1 person:"<<name<<endl;
    // cout<<"there are still "<<discount()<<" people."<<endl;
}
void Name::ChangeName(string na)
{
    name=na;
}

string Name::dis()
{
    return name;
}

int Name::discount()
{
    return count;
}
class Employee
{
protected:
    // string name;
    Name name;
    string address;
    string pro;
    string city;
    string code;
public:
    Employee(string na,string add,string p,string ci,string co);
    ~Employee();
    void Display();
    void Changename(string na);
};

Employee::Employee(string na="no name",string add="hunan university",string p="hunan",string ci="changsha",string co="00700"):name(na)
    {
        // name=na;
        address=add;
        pro=p;
        city=ci;
        code=co;
        cout<<"construing  "<<name.dis()<<endl;
    }
    
Employee::~Employee()
{
    cout<<"Destructing  "<<name.dis()<<endl;
}

void Employee::Display()
{
    cout<<name.dis()<<"  "<<pro<<"  "<<city<<"  "<<address<<"  "<<code<<endl;
}

void Employee::Changename(string na)
{
    name.ChangeName(na);
    // name=na;
}
class E:protected Employee
{
    public:
    using Employee::code;
};

int main()
{
    // Employee e1;
    // Employee e2(" ","lanzhou university","gansu","lanzhou","730020");
    // Employee e3={"lzy","hohai university","gansu","lanzhou","730020"};
    // e1.Display(); 
    // e2.Display();
    // e3.Display();
    // e1.Changename("xxj");
    // e1.Display();
    // Name *n1=new Name("juyi");
    // Name n2;
    // Name n3={"lzy"};
    // cout<<"there are still "<<Name::discount()<<" people."<<endl;
    // delete n1;
    // cout<<"there are still "<<Name::discount()<<" people."<<endl;
    E mm;
    cout<<mm.code<<endl;
}