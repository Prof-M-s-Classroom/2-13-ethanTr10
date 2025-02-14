#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }

    ~LinkedList() { // DESTRUCTOR the tilde is what signifies the destructor
        Node<T> * current = this->head;
        while (head) { //if head was null then it will NOT run...so while it has something it runs
            head=head->next;
            delete current;
            current=head;
        }
    }

    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T> *temp = head;
        while (temp->next!=NULL)
            temp = temp->next;
        delete temp;
        length--;
    }

    Node<T>* get(int index) {
        if (index<0 || index>=length) {
            return nullptr;
        }
        Node<T>* temp =head;
        for (int i=0; i<index; i++) {
            temp=temp->next;
        }
        return temp;
    }

    void deleteNode(int index) {
       //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
        if (length==0) {
            cout<< "The list is already empty, cannot delete anything." <<endl;
        }

        if (length<=0) {
            cout<< "The index cannot be negative" <<endl;
        }

        //edge cases if you delete the beginning
        if (index==0) {
            delfirst();
        }

        //if you delete the last one
        if (index==(length-1)) {
            dellast();
        }

        //if deleting one in between two
        else {
            Node<T>* temp = head;
            temp=get(index-1);
            Node<T>* theOneToDelete= temp->next;
            temp->next=temp->next->next; //sets the current node's next to be the second node right of it
            delete theOneToDelete;
            length--;
        }
    }

   void insert(int index, T *value) {
        //TODO:Write a function to insert a new node at a give index. Reuse the pre-written functions for edge cases. Account for missing index
        if (index<0 || index>length) {
            cout<< "Index is invalid" <<endl;
            return;
        }
        if (index==0) {
            addhead(value);
        }
        if (index==length) {
            add(value);
        }
        else {
            Node<T>* newNode= new Node<T> (value);
            Node<T>* temp=get(index-1);// -1 because we need the previous node
            newNode->next= temp->next;
            temp->next= newNode;
            length++;
        }
    }

   void reverselist(){
        //TODO:Write a function to reverse the list using the logic from the slide.
       Node<T>* prev=NULL;
        Node<T>* curr=NULL;
        Node<T>* next=NULL;

    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    student *s4 = new student("D", 23);

    LinkedList<student> *ll = new LinkedList<student>(s1);

    ll->insert(1,s1);//doing the addnode if there is an empty linkedlist
    ll->print();

    ll->insert(0,s2); //adding at beginning when there is already something there
    ll->print();

    ll->insert(2,s3); //adding at the end
    ll->print();

    ll->insert(1,s4); //adding in between
    ll-> print();

    ll->deleteNode(0);//deleting the first
    ll->print();

    ll->deleteNode(1); //deleting between two nodes
    ll->print();
}