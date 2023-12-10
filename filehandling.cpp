/*
Write a C++ program that creates an output file, writes information to it, closes
the file, and opens it again as an input file and reads the information from the file.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int op;
    string data;
    string line;
    ofstream o;
    ifstream i;

    cout << "************************MENU************************" << endl;
    cout << "1. Write to the file" << endl;
    cout << "2. Read from the file" << endl;
    cout << "3. Exit" << endl;
    cout << endl;

    do
    {
        cout << "Enter your choice: " << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Enter your data:" << endl;
            o.open("myfile.txt", ios::out);
            cin.get();
            getline(cin, line);
            o << line << endl;
            o.close();
            cout << "Data entered successfully" << endl;
            break;

        case 2:
            cout << "Contents of file are:" << endl;
            i.open("myfile.txt", ios::in);
            if (i.is_open())
            {
                while (i.good())
                {
                    getline(i, line);
                    cout << line;
                }
            }
            i.close();
            break;

        case 3:
            cout << "Thanks for using our program" << endl;
            exit(1);
            break;

        default:
            cout << "INVALID CHOICE" << endl;
            break;
        }

    } while (op != 3);

    return 0;
}
