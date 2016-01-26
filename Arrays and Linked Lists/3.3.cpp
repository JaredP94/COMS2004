#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Animal{
    private:
        string name;
        string sound;

    public:
        Animal(const string& n = "", const string& s = ""): name(n), sound(s){};
        string getName()const{return name;}
        string makeSound()const{return sound;}
};

ostream& operator<<(ostream& out, Animal& obj){
    out << obj.getName() << " says " << obj.makeSound();
    return out;
}

class Exhibit{
    public:
        Exhibit(int maxEnt = 10);
        ~Exhibit();
        void add(const Animal& e);
        void removeLast();
        Animal& operator [](size_t i){return entries[i];};
        friend ostream& operator<<(ostream& out, Exhibit& obj);

    private:
        int MaxNumberOfAnimals;
        int CurrentNumberOfAnimals;
        Animal* entries;
};

Exhibit::Exhibit(int maxEnt){
    MaxNumberOfAnimals = maxEnt;
    CurrentNumberOfAnimals = 0;
    entries = new Animal[MaxNumberOfAnimals];
}

Exhibit::~Exhibit(){
    delete [] entries;
}

void Exhibit::add(const Animal& e){
    string name = e.getName();
	if(CurrentNumberOfAnimals == MaxNumberOfAnimals){
		if(name <= entries[MaxNumberOfAnimals-1].getName()){
			return;
		}
	}
	else{
		CurrentNumberOfAnimals++;
	}

	int i = CurrentNumberOfAnimals-2;
	entries[i+1] = e;
}

void Exhibit::removeLast(){
    CurrentNumberOfAnimals--;
}

ostream& operator<<(ostream& out, Exhibit& obj){
    out << "{ ";
    for(int i=0; i < obj.CurrentNumberOfAnimals; i++){
        out << obj.entries[i].getName() << " ";
    }
    out << "}";
    return out;
}

int main()
{
    Animal* monkey = new Animal("Frank", "Squeak");
    Animal* tiger = new Animal("Simba", "Chuff");
    Animal* Dog = new Animal("Petals", "Woof");
    cout << *monkey << endl;
    cout << *tiger << endl;
    cout << *Dog << endl;
    Exhibit cage(10);
    cage.add(*monkey);
    cage.add(*tiger);
    cage.add(Animal("Batty","Screech"));
    cage.add(Animal("Sheepy","Bleat Bleat"));
    cage.add(Animal("Hippopotamusesy","growl"));
    cage.add(Animal("Turkey","Gobble"));
    cout << cage << endl;
    cage.removeLast();
    cout << cage << endl;
    cage.removeLast();
    cout << cage << endl;

    return 0;
}
