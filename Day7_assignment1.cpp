#include<iostream>
using namespace std;

class Product{
    protected:
     string id;
    string title;
    double price;

    public:
    Product(void) : id(""),title(""),price(0){}
    Product(string id, string title,double price): id(id), title(title), price(price){}

    virtual void accceptRecord( void ){
        cout<<"Enter id";
        cin>>id;
        cout<<"Enter title";
        cin>>title;
        cout<<"Price :";
        cin>>price;
    }

    virtual void printRecord(void){ 
        cout<<"id : "<<id;
        cout<<"title : "<<title;
        cout<<"price : "<<price;
    }

    virtual double calculateDiscount() = 0;
};

class Book : public Product{
    private:
    string author;

    public:

    Book(void) : author(""){}
    Book( string id,string title,double price,string author) : author(author),Product(id,title,price) {}
    void accceptRecord( void ){
        Product::accceptRecord();
        cout<<"Enter author";
        cin>>author;
    }

     void printRecord(void){
        Product::printRecord();
        cout<<"author : "<<author;
    }

    double calculateDiscount(){
        return price - (price * 0.05);
    }

};

class Tape : public Product{
    private:
    string artist;

    public:
    Tape(void) : artist(""){}
    Tape( string id,string title,double price,string artist) : artist(artist),Product(id,title,price) {}
    void accceptRecord( void ){
        Product::accceptRecord();
        cout<<"Enter artist";
        cin>>artist;
    }

    void printRecord(void){
        Product::printRecord();
        cout<<"artist : "<<artist;
    }

     double calculateDiscount(){
        return price - (price * 0.10);
    }
};

int menuList(){
    int choice;
    cout<<"0. Exit"<<endl;
    cout<<"1. Book"<<endl;
    cout<<"2. Tape"<<endl;
    cout<<"3. Calculate Bill"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    return choice;
}

int main(){
    Product *ptr[3];
    int choice;
    int index = 0;
    float total = 0;


    while((choice =menuList()) != 0){
        switch (choice)
        {
        case 1:
        if(index < 3){
            ptr[index] = new Book();
            ptr[index]->accceptRecord();
            index++;
        }
        else{
            cout<<"Array is full";
        }
        break;
        case 2:
        if(index < 3){
            ptr[index] = new Tape();
            ptr[index]->accceptRecord();
            index++;
        }
        break;
        }
    }
    for(int i = 0;i<3;i++){
            total+=ptr[i]->calculateDiscount();
            cout<<"Total : "<<total<<endl;
        }
    return 0;
    }