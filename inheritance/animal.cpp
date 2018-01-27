#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal {
public:
    virtual string make_sound(){
        return "sound";
    }
};

class Dog : public Animal {
public: 
    string make_sound(){
        return "woof";
    }
};

class Cat : public Animal {
public: 
    string make_sound() {
        return "meow";
    }
};

class Tiger : public Cat {
public: 
    string make_sound() {
        return "roar";
    }
};

int main(){
    Animal a;
    Dog d;
    Cat c;

    cout << a.make_sound() << " " 
         << d.make_sound() << " " 
         << c.make_sound() << endl;


    Animal *ad = new Dog();
    cout << ad->make_sound() << endl;

    vector<Animal> v;

    v.push_back(a);
    v.push_back(d);
    v.push_back(c);
    v.push_back(*ad);

    for (int i = 0; i < v.size(); i++){
        cout << v[i].make_sound() << endl;
    }

    cout << "pointers" << endl;


    vector<Animal*> b;
    b.push_back(&a);
    b.push_back(&d);
    b.push_back(&c);
    b.push_back(ad);


    for (int i = 0; i < v.size(); i++){
        cout << v[i].make_sound() << endl;
    }

    Cat *t = new Tiger();

    cout << t->make_sound() << endl;

    return 0;
}


