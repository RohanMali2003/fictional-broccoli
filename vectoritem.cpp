/*
Write C++ program using STL for sorting and searching with user defined records
such as
person record(Name, DOB, Telephone number), Item record (Item code, name,
cost,quantity) using vector container
*/

#include<bits/stdc++.h>
using namespace std;

class Item
{
    public:
    string name;
    int price;
    long code;
    int quantity;
    bool operator==(const Item& i1);
    bool operator<(const Item& i1);
};

bool Item::operator==(const Item&i1)
{
    return price==i1.price;
}

bool Item::operator<(const Item&i1)
{
    return price<i1.price;
}

bool compare(const Item&i1, const Item&i2)
{
    return i1.price<i2.price;
}

void print(Item &i1)
{
    cout<<"Item code : "<<i1.code;
    cout<<"Item name : "<<i1.name;
    cout<<"Item price : "<<i1.price;
    cout<<"Item quantity : "<<i1.quantity;
}

int main()
{
    vector<Item> v1;
    vector<Item>::iterator it;
    Item i1;
    cout<<"MENU";    
    cout<<"\n 1. Enter new item";    
    cout<<"\n 2. Display inventory items";    
    cout<<"\n 3. Search item";    
    cout<<"\n 4. Sort items";    
    cout<<"\n 5. Delete item";    
    cout<<"\n 6. Exit";   
    int ch;
    do
    {
        cout<<"Enter your choice \n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter code of item: \n";
            cin>>i1.code;
            cout<<"Enter name of item: \n";
            cin>>i1.name;
            cout<<"Enter cost of item: \n";
            cin>>i1.price;
            cout<<"Enter quantity of item: \n";
            cin>>i1.quantity;
            v1.push_back(i1);
            break;
            
            case 2:
            for_each(v1.begin(), v1.end(), print);
            break;

            case 3:
            cout<<"\n Enter item code to be searched \n";
            cin>>i1.code;
            it=find(v1.begin(),v1.end(),i1);
            if(it==v1.end())
            {
                cout<<"Item not found";
            }
            else
            {
                cout<<"Item found with code "<<i1.code<<endl;
                print(i1);
            }
            break;

            case 4:
            cout<<"Sorting on basis of cost ";
            sort(v1.begin(),v1.end(),compare);
            for_each(v1.begin(),v1.end(),print);
            break;

            case 5:
            cout<<"Enter code you want to delete: ";
            cin>>i1.code;
            find(v1.begin(),v1.end(),i1);
            if(it==v1.end())
            cout<<"Item not found";
            else
            {
                v1.erase(it);
                cout<<"Deleted";
            }
            break;

            case 6:
            cout<<"Thank you for using the program!";
            exit(0);

            default:
            cout<<"Enter valid input!";
            break;
        }
    }while(ch!=6);
}