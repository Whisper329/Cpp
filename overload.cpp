#include<iostream>
using namespace std;

class Person
{
public:
    friend Person operator+(Person &a,Person &b);
    friend Person& operator++(Person &p);
    friend Person operator++(Person &p,int);
    friend ostream &operator<<(ostream &cout,const Person& p);
    // friend ostream &operator<<(ostream &cout,Person p);   //Person& p无法输出 cout<<p++<<endl; const Person& p也可以输出
    Person(int a,int b);

    void get()
    {
        // cout<<num1<<"    "<<endl;
        cout<<num1<<"    "<<num2<<endl;
    }
private:
    int num1;
    int num2;
// private:
    
};

Person::Person(int a=0,int b=0)
{
    num1=a;
    num2=b;
}

ostream &operator<<(ostream &cout, const Person& p)
{
    cout<<p.num1<<"    "<<p.num2;
    return cout;
}

Person operator+(Person &a,Person &b)
{
    Person temp;
    temp.num1=a.num1+b.num1;
    temp.num2=a.num2+b.num2;
    return temp;
}

Person& operator++(Person &p)
{
    p.num1++;
    p.num2++;
    return p;
}

Person operator++(Person &p,int)
{
    Person temp=p;
    ++p;
    return temp;
}
int main()
{
    Person p1;
    Person p2;
    Person p3=p1+p2;
    cout<<p3<<endl;
    cout<<++p3<<endl;
    cout<<p3++<<endl;
    cout<<p3<<endl;
}
