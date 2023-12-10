/* Selection sort template */
#include<bits/stdc++.h>
using namespace std;

template <class T>
void accept(T arr[], int n)
{
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

template <class T>
void selsort(T arr[], int n)
{
    int i, j, minIndex;
    for(i=0;i<n-1;i++)
    {
        minIndex=i;
        for(j=i;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                T temp=arr[minIndex];
                arr[minIndex]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

template <class T>
void display(T arr[], int n)
{
    cout<<"Elements are: \n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int flag=0;
    int n;
    int ch;
    cout<<"Menu\n";
    cout<<"1. Integers\n 2. Floating point decimals\n 3. Exit\n";
    while(flag==0)
    {
        cout<<"Enter your choice\n";
        cin>>ch;
        cout<<"Enter number of elements in array";
        cin>>n;
        int arr1[n];
        float arr2[n];
        switch(ch)
        {
            case 1:
            accept(arr1,n);
            selsort(arr1,n);
            display(arr1,n);
            break;

            case 2:
            accept(arr2,n);
            selsort(arr2,n);
            display(arr2,n);
            break;

            case 3:
            flag=1;
            cout<<"Thank you for using our program!";
        }
    }
    return 0;
}