/*Complex numbers*/
#include <iostream>
using namespace std;

class complex
{
    int real;
    int img;
    public:
    complex()
    {
        cout<<"default constructor"<<endl;
    }
    complex(int a, int b)
    {
        cout<<"parmeterised constructor"<<endl;
    }
    complex(complex &c)
    {
        cout<<"copy constructor"<<endl;
        real=c.real;
        img=c.img;
    }
    void getdata()
    {
        cout<<"enter real part : ";
        cin>>real;
        cout<<"enter img part : ";
        cin>>img;
    }
    complex operator+(complex obj)
    {
        complex temp;
        temp.real=real+obj.real;
        temp.img=img+obj.img;
        return temp;
    }
    friend complex operator*(complex obj1,complex obj2);

    friend ostream & operator<<(ostream &o,complex &c1);
    friend istream & operator>>(istream &ii,complex &c1);
};

ostream & operator<<(ostream &o,complex &c1)
{
    cout<<"("<<c1.real<<")"<<"+i"<<"("<<c1.img<<")"<<endl;
    return o;
}

istream & operator>>(istream &ii,complex &c1)
{
    cout<<"enter real and img part : ";
    cin>>c1.real>>c1.img;
    return ii;
}

complex operator*(complex obj1,complex obj2)
{
    complex temp;
    temp.real=((obj1.real)*(obj2.real))-((obj1.img)*(obj2.img));
    temp.img=((obj1.real)*(obj2.img))+((obj1.img)*(obj2.real));
    return temp;
}

int main()
{
    complex obj1,obj2;
    complex obj3,obj4;
    cin>>obj1;
    cin>>obj2;
    int ch, flag=0;
    while(flag==0)
    {
        cout<<"Enter your choice: \n 1. Addition \n 2. Multiplication \n 3. Exit \n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            obj3=obj1+obj2;
            cout<<obj3;
            break;
        case 2:
            obj4=obj1*obj2;
            cout<<obj4;
            break;
        case 3:
            flag=1;
            break;
        };
    }
    return 0;
}