#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
template <typename E>
class  Node
{
public:
    E elem;
    Node* next;
};
template <typename E>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    bool isEmpty() const;
    const E& back() const;
    const E& front()const;
    void addFront(const E& e);
    void removeFront();
    void addBack(const E& s);
    void removeBack();
    friend ostream& operator<<(ostream& out, const LinkedList<E>& obj)
    {

    Node<E> *Temp = obj.head;
    if(Temp == NULL){out << "[]"; return out;}
    out << "[";
    while(Temp != NULL)
        {
            out << Temp->elem;
            if(Temp->next != NULL)
            out << "] --> [";
            Temp = Temp->next;

        }
        out << "]";
    return out;
}
private:
    Node<E> *head;

};
template <typename E>
LinkedList<E>::LinkedList(): head(NULL){}
template <typename E>
LinkedList<E>::~LinkedList(){
    while(!isEmpty())
        {
            removeBack();
        }

}
template <typename E>
bool LinkedList<E>::isEmpty()const
{
    return head == NULL;
}
template <typename E>
const E& LinkedList<E>::front()const
{
    if(head != NULL){
    return head->elem;}
}
template <typename E>
const E& LinkedList<E>::back()const
{
    if(head != NULL){
    Node<E>* tem = head;
    while(tem->next != NULL)
        {
            tem = tem->next;
        }
    return tem->elem;}

}
template <typename E>
void LinkedList<E>::addFront(const E &e)
{
    Node<E> *n = new Node<E>;
    n->elem = e;
    n->next = head;
    head = n;


}
template <typename E>
void LinkedList<E>::removeFront()
{
    if(head != NULL){
    Node<E> *oldhead = head;
    head = head->next;
    delete oldhead;}

}
template <typename E>
void LinkedList<E>::addBack(const E& s)
{
    Node<E> *back = new Node<E>;
    back->elem = s;
    back->next = NULL;
    if(isEmpty())
        { head = back; }
    else{
    Node<E> *T = head;
         while(T->next != NULL) {
               T = T->next; }
    T->next = back;
    back->next = NULL;
    }
    return;
}
template <typename E>
void LinkedList<E>::removeBack()
{
	if(head != NULL){
		if(head->next == NULL){
			delete head;
			head = NULL;
		}
	else{
		Node<E>* nextToEnd = head;
		Node<E>* end = head->next;
		while(end->next != NULL){
			nextToEnd = end;
			end = end->next;
		}
		delete end;
		nextToEnd->next = NULL;
	}
	}

}

int main()
{
    LinkedList<string>* myList = new LinkedList<string>();
    cout << *myList << endl;
    cout << myList->isEmpty() << endl;
    myList->addFront("Gandalf");
    cout << *myList << endl;
    myList->addFront("Aragorn");
    cout << *myList << endl;
    myList->addFront("Legolas");
    cout << *myList << endl;
    cout << "Front element: "   << myList->front() << endl;
    cout << "Back element: " << myList->back() << endl;
    myList->removeFront();
    cout << *myList << endl;
    myList->removeFront();
    cout << *myList << endl;
    myList->removeFront();
    cout << *myList << endl;
    myList->removeFront();
    myList->addBack("Gollum");
    cout << *myList << endl;
    myList->addBack("Bilbo Baggins");
    cout << *myList << endl;
    myList->addBack("Saruman");
    cout << *myList << endl;
    cout << "Front element: "   << myList->front() << endl;
    cout << "Back element: " << myList->back() << endl;
    myList->removeBack();
    cout << *myList << endl;
    myList->removeBack();
    cout << *myList << endl;
    myList->removeBack();
    cout << *myList << endl;


    return 0;
}

