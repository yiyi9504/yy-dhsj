#include<bits/stdc++.h>
using namespace std;

class Ichange{
public:
    virtual void ChangeThing() = 0;
};

class Animal{
protected:
    string _name;
    int _shoutnum=2;

public:
    Animal():_name("xxx"){}
    Animal(string name):_name(name){}

    void SetShoutNum(int n){
        if(n>5) n=5;
        _shoutnum=n;
    }    
    int GetShoutNum(){
        return _shoutnum;
    }

    void Shout(){
        cout << _name;
        for(int i=0;i<_shoutnum;i++) cout << ' ' << GetShoutSound();
        cout << endl;
    }
    virtual string GetShoutSound() = 0;
};

class Cat: public Animal{
public:
    using Animal::Animal;
    string GetShoutSound(){return "Miao~";}

};

class Dog: public Animal{
public:
    using Animal::Animal;
    string GetShoutSound(){return "Miao~";}
};

class Cattle: public Animal{
public:
    using Animal::Animal;
    string GetShoutSound(){return "Mo~";}
};

class Sheep: public Animal{
public:
    using Animal::Animal;
    string GetShoutSound(){return "Mie~";}
};

class MachineCat: public Cat,public Ichange{
public:
    using Cat::Cat;
    using Cat::GetShoutSound;
    void ChangeThing(){cout << "I can change anything." << endl;}
};

class MachineDog: public Dog,public Ichange{
public:
    using Dog::Dog;
    using Dog::GetShoutSound;
    void ChangeThing(){cout << "I can change something." << endl;}
};

int main(){
    vector<Animal*> animal;
    animal.push_back(new Cat("mimi"));
    animal.push_back(new Dog("doudou"));
    animal.push_back(new Cattle("koukou"));
    animal.push_back(new Sheep("baibai"));
    for(int i=0;i<animal.size();i++){
        animal[i]->Shout();
    }

    MachineCat* mcat = new MachineCat("xiaodingdang");
    MachineDog* mdog = new MachineDog("regou");
    Ichange* ichchge[2] = {mcat,mdog};
    for(int i=0;i<2;i++){
        ichchge[i]->ChangeThing();
    }
    return 0;
}