/* Population states map */
#include<bits/stdc++.h>
#include<map>
using namespace std;

int main()
{
    string state;
    int population;
    map<string,int> m1;
    int ch;
    cout<<"Menu \n";
    cout<<"1. Enter state \n";
    cout<<"2. Display states \n";
    cout<<"3. Find state \n";
    cout<<"4. Exit \n";  
    map<string,int>::iterator it;   
    do
    {
        cout<<"Enter your choice \n";   
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter name of state: \n";
            cin>>state;
            cout<<"Enter population: \n";
            cin>>population;
            m1[state]=population;
            break;

            case 2:
            cout<<"States and their populations are:\n";
            for(it=m1.begin();it!=m1.end();it++)
            {
                cout<<it->first<<"->"<<it->second<<"\n";
            }
            break;

            case 3:
            cout<<"Enter state you want to find:\n";
            cin>>state;
            for(it=m1.begin();it!=m1.end();it++)
            {
                if(it->first == state)
                {
                    cout<<"State found!\n";
                    cout<<it->first<<"->"<<it->second<<"\n";
                }
            }
            break;

            case 4:
            cout<<"Thank you for using our program!";
            break;
        }
    }while(ch!=4);
}