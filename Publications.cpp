/* Publication: books and tapes */
#include<bits/stdc++.h>
using namespace std;

class publications {
protected:
    string title;
    double price;

public:
    virtual void getData() = 0;
    virtual void putData() = 0;
};

class book : public publications {
protected:
    double pagecount;

public:
    void getData(void) {
        cout << "Enter title of publication :" << endl;
        try {
            cin >> title;
            if (title == " ")
                throw title;
        } catch (...) {
            cout << "Invalid name" << endl;
            title = "NULL";
        }

        cout << "Enter price of publication : " << endl;
        try {
            cin >> price;
            if (price <= 0)
                throw price;
        } catch (...) {
            cout << "Negative value not supported" << endl;
            price = 0.0;
        }

        cout << "Enter Book Page count: " << endl;
        try {
            cin >> pagecount;
            if (pagecount <= 0)
                throw pagecount;
        } catch (double x) {
            cout << "Negative value not supported" << endl;
            pagecount = 0.0;
        }
    }

    void putData(void) {
        cout << "Publication title :" << title << endl;
        cout << "Publication price : " << price << endl;
        cout << "Book page count : " << pagecount << endl;
    }
};

class tape : public publications {
protected:
    double play_time;

public:
    void getData(void) {
        cout << "Enter title of publication :" << endl;
        try {
            cin >> title;
            if (title == " ")
                throw title;
        } catch (string x) {
            cout << "Enter valid name " << endl;
            title = "NULL";
        }

        cout << "Enter price of publication : " << endl;
        try {
            cin >> price;
            if (price <= 0)
                throw (1.0);
        } catch (double x) {
            cout << "Negative value not supported" << endl;
            price = 0.0;
        }

        cout << "Enter tape's playing time (in min): " << endl;
        try {
            cin >> play_time;
            if (play_time <= 0)
                throw play_time;
        } catch (double x) {
            cout << "Negative value not supported" << endl;
            play_time = 0.0;
        }
    }

    void putData(void) {
        cout << "Publication title :" << title << endl;
        cout << "Publication price : " << price << endl;
        cout << "Tape's playing time : " << play_time << endl;
    }
};

int main(void) {
    publications *p[10];
    book *b[10];
    tape *t[10];

    int ch, i, n = 0;
    do {
        cout << "\n******PUBLICATION DATA SYSTEM******";
        cout << "\n-----------------Menu-----------------";
        cout << "\n1.Add Information to books:";
        cout << "\n2.Add Information to tapes : ";
        cout << "\n3.Display Information : ";
        cout << "\n4.Exit : ";
        cout << "\nEnter your choice :";
        cin >> ch;
        static int no = 0;

        switch (ch) {
            case 1:
                cout << "Enter Number of books you want to get:";
                cin >> n;
                for (i = 0; i < n; i++) {
                    b[i] = new book;
                    p[no] = b[i];
                    p[no]->getData();
                    no++;
                }
                break;

            case 2:
                cout << "Enter Number of tapes you want to get:";
                cin >> n;
                for (i = 0; i < n; i++) {
                    t[i] = new tape;
                    p[no] = t[i];
                    p[no]->getData();
                    no++;
                }
                break;

            case 3:
                n = sizeof(p);
                for (int no = 0; no < n; no++)
                    {
                        p[no]->putData();
                    }
                break;

            case 4:
                cout << "*****Program completed successfully******";
                break;
        }
    } while (ch != 4);

    return 0;
}
