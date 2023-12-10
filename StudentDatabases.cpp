/*Student Database*/
#include <bits/stdc++.h>
using namespace std;

class student {
    string name, studentClass, studentDivision, dateOfBirth, bloodGroup, address;
    int roll;
    long int telephoneNo, drivingLicenceNumber;
    static int count;

public:
    student() //Default Constructor
    {
        roll = 0;
        name = "";
        studentClass = "";
        studentDivision = "";
        dateOfBirth = "";
        bloodGroup = "";
        address = "";
        telephoneNo = 0;
        drivingLicenceNumber = 0;
    }

    student(string name, string studentClass, string studentDivision, string dateOfBirth, string bloodGroup, string address,
        long int telephoneNo, long int drivingLicenceNumber) //Parametrized constructor
    {
        count++;
        roll = count;
        this->name = name;
        this->studentClass = studentClass;
        this->studentDivision = studentDivision;
        this->dateOfBirth = dateOfBirth;
        this->bloodGroup = bloodGroup;
        this->address = address;
        this->telephoneNo = telephoneNo;
        this->drivingLicenceNumber = drivingLicenceNumber;
    }

    void getdata();
    void display();
    int showRoll() { return roll; }
    void getname() { cin >> name; }
    void getclass() { cin >> studentClass; }
    void getDivision() { cin >> studentDivision; }
    void getdateOfBirth() { cin >> dateOfBirth; }
    void getBloodGroup() { cin >> bloodGroup; }
    void getAddress() { cin >> address; }
    void getTelephoneNo();
    void getDrivingLicenceNumber();
};

int student::count = 0;

inline void student::getDrivingLicenceNumber() { cin >> drivingLicenceNumber; } //Using inline functions
inline void student::getTelephoneNo() { cin >> telephoneNo; } //Using inline functions

void student::getdata() {
    count++;
    roll = count;
    cout << "Enter Name : ";
    cin >> name;
    cout << "Enter Class : ";
    cin >> studentClass;
    cout << "Enter Division : ";
    cin >> studentDivision;
    cout << "Enter Date of birth : ";
    cin >> dateOfBirth;
    cout << "Enter Blood Group : ";
    cin >> bloodGroup;
    cout << "Enter address : ";
    cin >> address;
    cout << "Enter driving license number : ";
    cin >> drivingLicenceNumber;
    cout << "Enter phone number : ";
    cin >> telephoneNo;
}

void student::display() {
    cout << "Roll no is : " << roll << endl;
    cout << "Name is : " << name << endl;
    cout << "Class is : " << studentClass << endl;
    cout << "Division is : " << studentDivision << endl;
    cout << "Date Of Birth is : " << dateOfBirth << endl;
    cout << "Blood Group is : " << bloodGroup << endl;
    cout << "Address is : " << address << endl;
    cout << "Telephone no is : " << telephoneNo << endl;
    cout << "Driving License no is : " << drivingLicenceNumber << endl;
    cout << "\n-------------------------\n";
}

int main() {
    int i, n, choice, key, r, flag = 0, op; //creating essential variables
    cout << "\nEnter number of Students : ";
    cin >> n; //taking number of students
    student s[n]; //created n copies of class student

    if (n == 0) {
        cout << "thank you!";
        return 0;
    }

    for (i = 0; i < n; i++) {
        s[i].getdata();
        cout << "-------------------" << endl;
    }

    do {
        cout << "\nSelect choice -->\n1.Display \n2.Search \n3.Modify\n4.Delete\n5.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                for (i = 0; i < n; i++)
                    s[i].display();
                cout << "\n------------------\n";
                break;

            case 2:
                flag = 0;
                cout << "\nEnter roll number to search : ";
                cin >> key;

                for (i = 0; i < n; i++) {
                    r = s[i].showRoll();
                    if (r == key) {
                        cout << "Record found : " << endl;
                        s[i].display();
                        flag = 1;
                    }
                }

                if (flag == 0)
                    cout << "\nRecord not found";
                break;

            case 3:
                flag = 0;
                cout << "\nEnter roll whose record to modify : ";
                cin >> key;

                for (i = 0; i < n; i++) {
                    r = s[i].showRoll();
                    if (r == key) {
                        cout << "Record found" << endl;
                        flag = 1;
                        s[i].display();
                        cout << "\n Want to modify 1.Name 2.Class 3.Division 4.Date of Birth "
                             << "5.Blood Group 6.Address 7.Phone Number 8.Driving License no:";
                        cin >> op;

                        switch (op) {
                            case 1:
                                s[i].getname();
                                break;

                            case 2:
                                s[i].getclass();
                                break;

                            case 3:
                                s[i].getDivision();
                                break;

                            case 4:
                                s[i].getdateOfBirth();
                                break;

                            case 5:
                                s[i].getBloodGroup();
                                break;

                            case 6:
                                s[i].getAddress();
                                break;

                            case 7:
                                s[i].getTelephoneNo();
                                break;

                            case 8:
                                s[i].getDrivingLicenceNumber();
                                break;

                            default:
                                cout << "Invalid input";
                                break;
                        }
                    }
                }

                if (flag == 0)
                    cout << "\nRecord not found";
                break;

            case 4:
                int num; //taking roll number which we want to delete
                for (i = 0; i < n; i++)
                    s[i].display();

                cout << "which roll number do you want to delete : ";
                cin >> num;

                for (int k = num - 1; k < n; k++)
                    s[k] = s[k + 1]; //overwriting data of deleted roll no

                cout << "\nThis is updated list of students: \n";

                for (int m = 0; m < (n - 1); m++)
                    s[m].display();

                break;

            case 5:
                cout << "Thank you for using our program!";
                break;

            default:
                cout << "Invalid input";
                break;
        }
    } while (choice != 5);

    return 0;
}
