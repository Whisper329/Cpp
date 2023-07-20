#include<iostream>

using namespace std;
// class Vehicle
// {
// public:
//     Vehicle()
//     {
//         cout<<"constructing Vehicle"<<endl;
//     }
//     ~Vehicle()
//     {
//         cout<<"destructing Vehicle"<<endl;
//     }
// };

// class Car:public Vehicle
// {
// public:
//     Car()
//     {
//         cout<<"constructing Car"<<endl;
//     }
//     ~Car()
//     {
//         cout<<"destructing Car"<<endl;
//     }
// };

// class Truck:public Car
// {
// public:
//     Truck()
//     {
//         cout<<"constructing Truck"<<endl;
//     }
//     ~Truck()
//     {
//         cout<<"destructing Truck"<<endl;
//     }
// };

class A
{
private:
    int pa;
public:
    A(/* args */);
    ~A();
    int Getpa()
    {
        return pa;
    }
    void Setpa(int a)
    {
        pa=a;
    }
    void On()
    {
        cout<<"On A"<<endl;
    }
};

A::A(/* args */)
{
    cout<<"constructing A"<<endl;
}

A::~A()
{
    cout<<"destructing A"<<endl;
}

class B:virtual public A
{

public:
    B(/* args */);
    ~B();
    void On()
    {
        cout<<"On B"<<endl;
    }
};

B::B(/* args */)
{
    cout<<"constructing B"<<endl;
}

B::~B()
{
    cout<<"destructing B"<<endl;
}

class C:public B,virtual public A
{
private:
    /* data */
public:
    C(/* args */);
    ~C();
};

C::C(/* args */)
{
    cout<<"constructing C"<<endl;
}


C::~C()
{
    cout<<"destructing C"<<endl;
}

void o(B &a)
{
    a.On();
}

int main()
{
    // Truck t1;
    // C c1;
    // c1.Setpa(6);
    // cout<<c1.Getpa()<<endl;
    // c1.OnB();
    B b;
    A a;
    // o(a);
}