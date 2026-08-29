#include<iostream>
using namespace std;

class Date
{
   private:
   int day;
   int month;
   int year;

   public:
   Date(void) : day(0), month(0), year(0)
   {}
   Date(int day,int month,int year) : day(day),month(month), year(year)
   {}

   void accept(void){
    cout<<"day : ";
    cin>>day;
    cout<<"month : ";
    cin>>month;
    cout<<"year ; ";
    cin>>year;
   }

   void print(void){
    cout<<"day : "<<day<<endl;
    cout<<"month : "<<month<<endl;
    cout<<"year : "<<year<<endl;
   }
};

class Student
{
    private:
    int id;
    double marks;
    string course;
    Date joiningDate;
    Date endDate;

    public:
    Student(void) : id(0), marks(0.0),course("") {}
    Student(int id,double marks,string course, int day, int month, int year ,int day1, int month1, int year1) : id(id), marks(marks),course(course),joiningDate(day, month, year),endDate(day1, month1, year1) {}

    void accept(void){
        cout<<"id :";
        cin>>id;
        cout<<"marks :";
        cin>>marks;
        cout<<"course :";
        cin>>course;
        cout<<"Joining date : ";
        this->joiningDate.accept();
        cout<<"End date : ";
        this->endDate.accept();
    }

    void printStudentdetails(void) {
        cout<<"id : "<<id<<endl;
        cout<<"marks : "<<marks<<endl; 
        cout<<"course : "<<course<<endl;
        cout<<"JoinDate : ";  
        this->joiningDate.print( ); 
        cout<<"EndDate :";
        this->endDate.print();
    }
};

class Person{
    private:
        string name;
        string address;
        Date birthDate;

    public:
        Person(void) : name(""),address("") {}
        Person(string name, string address,Date birthDate) : name(name), address(address), birthDate(birthDate) {} 
        
        void accept(void){
        cout<<"name :";
        cin>>name;
        cout<<"address :";
        cin>>address;
        cout<<"Birth Date : ";
        this->birthDate.accept();
    }

    void printPersonDetails(void) {
        cout<<"id : "<<name<<endl;
        cout<<"marks : "<<address<<endl; 
        cout<<"Birth Date : ";  
        this->birthDate.print( );
    }
};


int main() {
    // Date d(15,01,2003);
    // Date d1(1,1,2022);
    Student s(1,100,"CDAC",15,01,2003,1,1,2022);
    s.printStudentdetails();

    return 0;
}

// int main() {
//     Date d(15,01,2003);
//     Date d1(1,1,2022);
//     Student s(1,100,"CDAC",d,d1);
//     s.printStudentdetails();

//     return 0;
// }
// int main3(){
//     Person p;
//     p.accept();
//     p.printPersonDetails();
// }

// int main2(){
//     Student s;
//     s.accept();
//     s.printStudentdetails();
// }

// int main1(){
//     Date d;
//     d.accept();
//     d.print();
// }