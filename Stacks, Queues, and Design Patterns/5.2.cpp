#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class RuntimeException
{
private:
    string errorMsg;
public:
    RuntimeException(const string &err){errorMsg = err;}
    string getMessage()const {return errorMsg;}
};

class LinkedListEmpty: public RuntimeException
{
public:
    LinkedListEmpty(const string& err): RuntimeException(err){};
};

template <typename E>
class Node
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
    const E& back() const throw(LinkedListEmpty);
    const E& front()const throw(LinkedListEmpty);
    void addFront(const E& e);
    void removeFront() throw(LinkedListEmpty);
    void addBack(const E& s);
    void removeBack() throw(LinkedListEmpty);
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
const E& LinkedList<E>::front()const throw(LinkedListEmpty)
{
	try{
		if(head != NULL){
			return head->elem;
		}
		else {
			throw LinkedListEmpty("Accessing the front of an empty linked list.");
		}
	}
	catch(LinkedListEmpty& e){
		cout << e.getMessage() << endl;
	}

}
template <typename E>
const E& LinkedList<E>::back()const throw(LinkedListEmpty)
{
	try{
		if(head != NULL){
	    		Node<E>* tem = head;
	   		while(tem->next != NULL)
				{
			    	tem = tem->next;
				}
    			return tem->elem;
		}
		else{
			throw LinkedListEmpty("Accessing the back of an empty linked list.");
		}
	}
	catch(LinkedListEmpty& e){
		cout << e.getMessage() << endl;
	}

}
template <typename E>
void LinkedList<E>::addFront(const E &e)
{
    Node<E> *N = new Node<E>;
    N->elem = e;
    N->next = head;
    head = N;


}
template <typename E>
void LinkedList<E>::removeFront() throw(LinkedListEmpty)
{
	try{
	    if(head != NULL){
	    Node<E> *oldhead = head;
	    head = head->next;
	    delete oldhead;
	    }
	    else{
			throw LinkedListEmpty("Removing the front of an empty linked list");
	    }
	}
	catch(LinkedListEmpty& e){
		cout << e.getMessage() << endl;
	}		

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
void LinkedList<E>::removeBack() throw(LinkedListEmpty)
{
    try
    {
        bool a;
        if(isEmpty())
            {
                a = true;
                throw(a);
            }
    }
    catch(bool a)
    {
        LinkedListEmpty L("Removing the back of an empty linked list");
        cout << L.getMessage() << endl;
        return;

    }

    Node<E> *Q = head;
    Node<E> *C;
    if(head->next == NULL)
        {
           C = head;
           delete C;
           head = NULL;
        }
else{
    C = head->next;
    while(C->next != NULL)
        {
            Q = C;
            C = C->next;
        }
    Q->next = NULL;
    delete C;

}

return;

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
     myList->removeBack();
    cout << *myList << endl;


    return 0;
}








