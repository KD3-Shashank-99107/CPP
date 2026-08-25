#include<iostream>
using namespace std;

class Date{
  int date;
  int month;
  int year;

  public : 
    void initDate();
    void printDateOnConsole();
    void acceptDateFromConsole();
    bool isLeapYear();
};

void Date :: initDate()
{
    date = 15;
    month = 1;
    year = 2003;
}

void Date :: acceptDateFromConsole(){
    cout<<"Enter date : ";
    cin>>date;
    cout<<"Enter month : ";
    cin>>month;
    cout<<"Enter year :";
    cin>>year;
}
void Date :: printDateOnConsole(){
     cout<<date<<"/"<<month<<"/"<<year;
}

bool Date :: isLeapYear(){
    if(year%4==0){
        return true;
    }
    return false;
}

int main()
{
    Date d;
    int choice;

    do
    {
        cout << "1. Initialize Date" << endl;
        cout << "2. Print Date" << endl;
        cout << "3. Accept Date" << endl;
        cout << "4. Check Leap Year" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                d.initDate();
                cout << "Date initialized." << endl;
                break;

            case 2:
                d.printDateOnConsole();
                break;

            case 3:
                d.acceptDateFromConsole();
                break;

            case 4:
                if (d.isLeapYear())
                    cout << "It is a leap year." << endl;
                else
                    cout << "It is not a leap year." << endl;
                break;

            case 5:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}