#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class StringNode{
	public:
		string elem;
		StringNode* next;
		StringNode* prev;
        friend class StringLinkedList;
};

class StringLinkedList{
	public:
		StringLinkedList();
		~StringLinkedList();
		bool isEmpty() const;
		const string& front() const;
		const string& back() const;
		void addFront(const string& e);
		void addBack(const string& e);
		void removeFront();
		void removeBack();
		friend ostream& operator<<(ostream& out, const StringLinkedList& obj);
	private:
		StringNode* head;
		StringNode* tail;
    protected:
        void add(StringNode* v, const string& e);
        void remove(StringNode* v);
};

StringLinkedList::StringLinkedList(){
    head = new StringNode;
    tail = new StringNode;
    head->next = tail;
    tail->prev = head;
}

StringLinkedList::~StringLinkedList(){
	while(!isEmpty()){
		removeFront();
	}
	delete head;
	delete tail;
}

bool StringLinkedList::isEmpty() const{
	return (head->next == tail);
}

const string& StringLinkedList::front() const{
	return head->next->elem;
}

const string& StringLinkedList::back() const{
    return tail->prev->elem;
}

void StringLinkedList::add(StringNode* v, const string& e){
    StringNode* u = new StringNode; u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

void StringLinkedList::addFront(const string& e){
	add(head->next, e);
}

void StringLinkedList::addBack(const string& e){
    add(tail, e);
}

void StringLinkedList::remove(StringNode* v){
    StringNode* u = v->prev;
    StringNode* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

void StringLinkedList::removeFront(){
	remove(head->next);
}

void StringLinkedList::removeBack(){
    remove(tail->prev);
}

ostream& operator <<(ostream& out, const StringLinkedList& obj)
{
    for ( StringNode *temp = obj.head->next; temp != obj.tail; temp = temp->next )
    {
        out << temp->elem << ' ';
    }

    return out;
}

int main(void){
	StringLinkedList* myList = new StringLinkedList();
	myList->addFront("Massi");
	myList->addFront("Prince");
	cout<< *myList << endl;
	myList->addFront("Conrad");
	myList->addFront("David");
	myList->addFront("Joel");
	cout<< *myList << endl;
	myList->addFront("Ernest");
	myList->addFront("Lindo");
	myList->addFront("Nic");
	cout<< *myList << endl;
	myList->addFront("Sasha");
	myList->removeFront();
	cout<< *myList << endl;
	myList->removeFront();
	cout<< *myList << endl;
	myList ->addBack("Jesse");
    myList ->addBack("Shane");
    myList ->addBack("Richard");
    cout << *myList << endl;
    myList -> removeBack ();
    cout << *myList << endl;
    myList -> removeBack ();
    cout << *myList << endl;
    myList -> removeBack ();
    cout << *myList << endl;
    myList -> removeBack ();
    cout << *myList << endl;
	return 0;
}
