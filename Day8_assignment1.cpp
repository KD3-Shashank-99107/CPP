#include<iostream>
using namespace std;

class InvalidSalary{
    private:
    string message;
    public:
    InvalidSalary(string message){
        this->message = message;
    }
    string getMessage(void){
        return this->message;
    }
};
class Employee{
    protected:
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

    virtual void accept(){
        cout<<"Enter id : ";
        cin>>id;
        cout<<"Enter salary : ";
        cin>>salary;
        try
        {
            if(salary < 0)
            throw InvalidSalary("Salary cannot be less then 0");
        }
        catch(InvalidSalary e)
        {
            cout<<e.getMessage();
        }
        
    }

    virtual void display(){
        cout<<"ID : "<<id<<endl;
        cout<<"Salary : "<<salary<<endl;
    }
};

class Manager : virtual public Employee{
    protected:
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
        displayManager();
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
    protected: 
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
        displaySalesman();
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
    protected:
    public:
    SalesManager() : Manager(), Salesman() {}
    
    SalesManager(int id, double salary, double bonus, double commission) : Employee(id, salary), Manager(bonus), Salesman(commission){}

    void accept(){
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }

    void display(){
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};
int menu() {
    int choice;
    cout<<"0. Exit"<<endl;
    cout<<"1. Add Salesman"<<endl;
    cout<<"2. Add Manager"<<endl;
    cout<<"3. Add SalesManager"<<endl;
    cout<<"4. Display count"<<endl;
    cout<<"5. Display All Managers"<<endl;
    cout<<"6. Display All Salesman"<<endl;
    cout<<"7. Display All SalesManager"<<endl;
    cout<<"Enter choice"<<endl;
    cin>>choice;
    return choice;
}

int main(){
    Employee *emp[5];
    int choice;
    int index =0;
    while((choice = ::menu()) != 0) {
        switch (choice)
        {
        case 1: 
        if(index < 5){
            emp[index] = new Salesman();
            emp[index]->accept();
            index++;
        }
        break;
        case 2:
        if(index < 5){
            emp[index]= new Manager();
            emp[index]->accept();
            index++;
        }
        break;
        case 3:
        if(index < 5){
            emp[index] = new SalesManager();
            emp[index]->accept();
            index++;
        }
        break;
        case 4:
        {
        int ManagerCount = 0;
        int SalesmanCount = 0;
        int SalesMangerCount = 0;

        for(int i=0;i<index;i++){
            if (dynamic_cast<SalesManager*>(emp[i]) != NULL) {
                SalesMangerCount++;
            }
            else if (dynamic_cast<Manager*>(emp[i]) != NULL) {
                ManagerCount++;
            }
            else if (dynamic_cast<Salesman*>(emp[i]) != NULL) {
                SalesmanCount++;
            }
            cout << "Managers: " << ManagerCount << endl;
            cout << "Salesmen: " << SalesmanCount << endl;
            cout << "Sales Managers: " << SalesMangerCount << endl;
        }
    }
        break;
        case 5:
        for(int i=0;i<index;i++){
            if(dynamic_cast<Manager*>(emp[i]) != NULL) {
                cout<<"Manager : "<<endl;
                emp[i]->display();
            }
        }
        break;
        case 6:
        for(int i=0;i<index;i++){
            if(dynamic_cast<Salesman*>(emp[i]) != NULL) {
                cout<<"Salesman : "<<endl;
                emp[i]->display();
            }
        }
        break;
        case 7:
        for(int i=0;i<index;i++){
            if(dynamic_cast<SalesManager*>(emp[i]) != NULL) {
                cout<<"SalesManager : "<<endl;
                emp[i]->display();
            }
        }
        }
    }
}