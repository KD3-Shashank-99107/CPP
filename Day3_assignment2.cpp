#include<iostream>
using namespace std;
class TollBooth{
    private: 
     double totalMoney;
     unsigned int payingCars;
     unsigned int nonPayingCars;

    public:
    TollBooth() {
        totalMoney = 0;
        payingCars = 0;
        nonPayingCars = 0;
    }

    void payingCar(){
        payingCars++;
        totalMoney = totalMoney + 0.50;
    } 

    void noPayCar() {
        nonPayingCars++;
    }

    void printOnConsole(){
        cout<<"Total paying cars = "<<payingCars<<endl;
        cout<<"Total non paying cars = "<<nonPayingCars<<endl;
        cout<<"Total amount = "<<totalMoney<<endl;
    }
};

int main(){
    TollBooth t;
    int choice;

    do{
       cout<<"MENU"<<endl;
       cout<<"1.Paying car"<<endl;
       cout<<"2.Non paying car"<<endl;
       cout<<"3.All details"<<endl;
       cout<<"4.Exit"<<endl;


       cin>>choice;

       switch (choice)
       {
       case 1: 
        t.payingCar();
        break;

       case 2:
        t.noPayCar();
        
       case 3:
        t.printOnConsole(); 
       
       default:
       cout<<"EXIT"<<endl;
        break;
       }
    } while (choice!= 4); 
}