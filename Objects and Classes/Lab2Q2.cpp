#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Monster{
    public:
        Monster(const string n="Fred",int h=300, int a=50, int d=80): name(n), health(h), attack(a), defense(d) {};
        ~Monster();
        void setName(string n);
        void setHealth(int h);
        void setAttack(int a);
        void setDefense(int d);
        string getName(){return name;}
        int getHealth(){return health;}
        int getAttack(){return attack;}
        int getDefense(){return defense;}

    private:
        string name;
        int health;
        int attack;
        int defense;
};

    ostream& operator<<(ostream& out, Monster& obj)
    {
        out << "{" << obj.getName() << "," << obj.getHealth() << "," << obj.getAttack() << "," << obj.getDefense() << "}";
        return out;
    }

int main(void){
    Monster* m1 = new Monster("Ritso", 3000, 60, 100);
    cout << *m1 << endl; //{Ritso ,3000,60,100}

}
