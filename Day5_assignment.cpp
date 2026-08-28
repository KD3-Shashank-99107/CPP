#include<iostream>
using namespace std;

class Time{
    private: 
    int hr;
    int min;
    int sec;

    public:
    Time() : hr(0),min(0),sec(0){}
    Time(int hr, int min, int sec) : hr(hr),min(min),sec(sec){}

    void getHour(){
        cout<<"Hour : "<<hr<<endl;
    }

    void getMinute(){
        cout<<"Minute : "<<min<<endl;
    }

    void getSeconds(){
        cout<<"Seconds : "<<sec<<endl;
    }

    void setHour(int hr){
        this->hr = hr;
    }

    void setMinute(int min){
        this->min = min;
    }

    void setSec(int sec){
        this->sec = sec;
    }

    void acceptTime( void ) {
        cout<<"Hour : ";
        cin>>hr;
        cout<<"Min : ";
        cin>>min;
        cout<<"Sec : ";
        cin>>sec;
    }

    void printRecord( void )
    {  
        cout<<"Time : "<<hr<<min<<sec<<endl; 
    }
};

int main(){
    int n;
    Time t;
    cout<<"Enter nuumber of objects";
    cin>>n;
    int choice;
    Time *arr = new Time[n];

    do{

        cout << " Menu" << endl;
        cout << "1. Add Time" << endl;
        cout << "2. Display All Time" << endl;
        cout << "3. Display only hrs of all time objects" << endl;
        cout << "4. To exit" << endl;

           cout << "Enter your choice: ";
           cin >> choice;
            switch(choice){
            
            case 1:
            {
                for(int i=0;i<n;i++){
                  arr[i].acceptTime();
                }
            }
            case 2: 
            {
                for(int i=0;i<n;i++){
                    arr[i].printRecord();
                }
            }
            case 3:
                for(int i=0;i<n;i++){
                    arr[i].getHour();
                }
            default:
            {
            cout<<"EXIT"<<endl;
            }
           }

        } while (choice != 4); 
        
        delete arr;
        arr = NULL;
}
