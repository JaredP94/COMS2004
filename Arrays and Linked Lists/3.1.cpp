#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Animal {
    private:
        string name;
        string sound;

    public:
        Animal(const string& n = "", const string& s = ""): name(n), sound(s){};
        string getName()const{return name;}
        string makeSound()const{return sound;}
};

ostream& operator<<(ostream& out, Animal& obj)
{
    out << obj.getName() << " says " << obj.makeSound();
    return out;
}

int main()
{
    Animal* monkey = new Animal("Frank", "Sqeuak");
    Animal* tiger = new Animal("Simba", "chuff");
    Animal* Dog = new Animal("Petals", "Woof");
    cout << *monkey << endl;
    cout << *tiger << endl;
    cout << *Dog << endl;

    return 0;
}
