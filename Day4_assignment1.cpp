#include<iostream>
using namespace std;
class Cylinder{
    private:
    static double pi;
    double radius;
    double height;

    public:
    Cylinder() : radius(0),height(0){}
    Cylinder(double radius, double height) : radius(radius), height(height){}

    void setRadius(double radius){
        this->radius=radius;
    }
    float getRadius(){
        return this->radius;
    }
     void setHeight(double height){
        this->height=height;
    }
    float getHeight(){
        return this->height;
    }
    void calculateVolume(){
     cout<<"volume : "<<pi*radius*radius*height<<endl;
    
    }
};

double Cylinder :: pi = 3.14;

int main(){
    Cylinder c1;
    c1.calculateVolume();
    Cylinder c(2,3);
    c.calculateVolume();
    c1.setRadius(3);
    c1.setHeight(4);
    // cout<<"Radius :"<<c.getRadius()<<endl;
    c1.calculateVolume();
    c.calculateVolume();
}