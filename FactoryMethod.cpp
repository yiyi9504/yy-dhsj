#include<bits/stdc++.h>
using namespace std;

class Leifeng{
public:
    Leifeng(){}
    ~Leifeng(){}
    void Sweep(){ cout << "Sweep!" << endl; }
    void Wash(){ cout << "Wash!" << endl; }
    void BuyRice(){ cout << "BuyRice!" << endl; }
};

class Student: public Leifeng{
public:
    using Leifeng::Leifeng;
};

class Volunteer: public Leifeng{
public:    
    using Leifeng::Leifeng;
};

class LeifengFactory{
public:
    LeifengFactory(){}
    ~LeifengFactory(){}
    virtual Leifeng* createLeifeng()=0;
};

class StudentFactory: public LeifengFactory{
public:
    using LeifengFactory::LeifengFactory;
    Leifeng* createLeifeng(){
        cout << "I am a student." << endl;
        return new Student();
    }
};

class VolunteerFactory: public LeifengFactory{
public:
    using LeifengFactory::LeifengFactory;
    Leifeng* createLeifeng(){
        cout << "I am a volunteer." << endl;
        return new Volunteer();
    }
};

int main(){
    LeifengFactory* leifengFactory = new StudentFactory();
    Leifeng* leifeng = leifengFactory->createLeifeng();
    leifeng->Sweep();
    leifeng->Wash();
    LeifengFactory* leifengFactory1 = new VolunteerFactory();
    Leifeng* leifeng1 = leifengFactory1->createLeifeng();
    leifeng1->BuyRice(); 
    return 0;
}