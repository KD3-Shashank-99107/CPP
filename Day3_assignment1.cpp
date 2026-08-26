#include<iostream>
using namespace std;

class Box
{
    private:
       float length;
       float width;
       float height;

     public:
        Box( void ) 
        {
            this->length = 10;
            this->width = 20;
            this->height =30;
            cout<<"volume = "<< volumeOfBox(length,width,height)<<endl;
        }
        
        Box( float sameValue)
        {
            this->length = sameValue;
            this->width = sameValue;
            this->height = sameValue;
            cout<<"volume = "<< volumeOfBox(length,width,height)<<endl;
        }

        Box( float l, float w, float h ){
            this->length = l;
            this->width = w;
            this->height = h;
            cout<<"volume = "<< volumeOfBox(length,width,height)<<endl;
        }

        float volumeOfBox(float length, float width, float height){
            float volumeofBox = length*width*height;
            return volumeofBox;
        }

        // float calculateWithSameValue(){
        //     cin>>
        // }
};

 int main()
        {

        Box d;
        Box s;
        Box diff;
        int choice;
        float sameValue;
        float length;
        float width;
        float height;
        
        
        do{

        cout << " Menu" << endl;
        cout << "1. Calculate with default values" << endl;
        cout << "2. Calculate with same values" << endl;
        cout << "3. Calculate with different values" << endl;
        cout << "4. To exit" << endl;

           cout << "Enter your choice: ";
           cin >> choice;
            switch(choice){
            
            case 1:
            {
                Box box;
                break;
            }
                case 2:
            {
                cout << "Enter one value to calculate volume" << endl;
                cin>>sameValue;
                Box box(sameValue);
                break;
            }
                case 3:
                {
                cout << "Enter one value to calculate volume" << endl;  
                cout << "Enter length" << endl;     
                cin>>length;
                cout << "Enter width" << endl; 
                cin>>width;
                cout << "Enter height" << endl;
                cin>>height;
                Box box(length, width, height);
                break;
            }
                default:
                {
                cout<<"EXIT"<<endl;
                }
           }

        } while (choice != 4); 
        

        }