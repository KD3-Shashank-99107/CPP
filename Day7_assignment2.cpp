#include<iostream>
using namespace std;

class Employee{
    private:
    int id;
    double salary;

    public:
    Employee(void) : id(0),salary(0.0) {}
    Employee(int id, double salary) : id(id) , salary(salary){}

    void setId(int id){
        this->id=id;
    }
    
    int getId(){
        return this->id;
    }

    void setSalary(double salary){
        this->salary=salary;
    }

    double getSalary() {
        return salary;
    }

    void accept(){
        cout<<"Enter id : ";
        cin>>id;
        cout<<"Enter salary : ";
        cin>>salary;
    }

    void display(){
        cout<<"ID : "<<id<<endl;
        cout<<"Salary : "<<salary<<endl;
    }
};

class Manager : virtual public Employee{
    private:
    double bonus;

    public:
    Manager(void) : bonus(0.0) {}
    Manager(double bonus) : bonus(bonus) {}
    Manager(int id, double salary ,double bonus) : Employee(id, salary), bonus(bonus) {}

    void setBonus(double bonus){
        this->bonus=bonus;
    }

    double getBonus() {
        return bonus;
    }

    void accept(){
       Employee::accept();
       acceptManager();
    }

    void display(){
        Employee::display();
        display();
    }

    protected:
    void acceptManager(){
        cout<<"Enter bonus : ";
        cin>>bonus;
    }

    void displayManager() {
        cout<<"Bonus : "<<bonus<<endl;
    }
};

 class Salesman : virtual public Employee{
    private: 
    double commission;

    public:
    Salesman(void) : commission(0.0) {}
    Salesman(int id, double salary, double commission) :  Employee(id, salary) , commission(commission){}
    Salesman(double commission) : commission(commission) {}

    void setCommission(double commission){
        this->commission=commission;
    }

    double getCommission() {
        return commission;
    }

    void accept(){
       Employee::accept();
       acceptSalesman();
    }

    void display(){
        Employee::display();
        display();
    }

    protected:
    void acceptSalesman(){
       cout<<"Enter commission : ";
       cin>>commission;
    }

    void displaySalesman() {
        cout<<"Commission : "<<commission<<endl;
    }
};

class SalesManager : public Manager, public Salesman{
    private:
    public:
    SalesManager() : Manager(), Salesman() {}
    
    SalesManager(int id, double salary, double bonus, double commission) : Employee(id, salary), Manager(bonus), Salesman(commission){}

    void accept(){
        Employee::accept();
        Manager::accept();
        Salesman::accept();
    }

    void display(){
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};
int menu() {
    int choice;
    cout<<"Enter choice"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"1. Salesman"<<endl;
    cout<<"2. Manager"<<endl;
    cin>>choice;
    return choice;
}

int main(){
    // int choice;
    // cin>>choice;
    // Salesman s;
    // Manager m;
    // ::menu();
    //     switch (choice)
    //     {
    //     case 1:
    //         s.accept();
    //         s.display();
    //         break;
    //     case 2:
    //         m.accept();
    //         m.display();
    //         break;
    //     }

    SalesManager sm;
    sm.accept();
    sm.display();
}