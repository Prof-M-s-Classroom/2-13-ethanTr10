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
        while (temp->next->next!=nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
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

        //if the linkedlist is empty
        if (length==0) {
            cout<< "The list is empty, cannot delete anything" << endl;
            return;
        }

        //if index is too low or too high
        else if (index<0 || index>=length) {
            cout<< "The index does not exist" <<endl;
            return;
        }

        //if you delete the beginning
        else if (index==0) {
            delfirst();
        }

        //if you delete the last one
        else if (index==(length-1)) {
            dellast();
        }

        //if deleting one in between two
        else {
            Node<T>* temp = get(index-1);
            Node<T>* theOneToDelete= temp->next;
            temp->next=theOneToDelete->next; //sets the current node's next to be the second node right of it
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
        else if (index==0) {
            addhead(value);
        }
        else if (index==length) {
            add(value);
        }
        else {
            Node<T>* newNode= new Node<T> (value);
            Node<T>* temp=get(index-1);
            newNode->next= temp->next;
            temp->next= newNode;
            length++;
        }
    }

   void reverselist(){
        //TODO:Write a function to reverse the list using the logic from the slide.
        Node<T> * prev=nullptr;
        Node<T>* curr=head;
        Node<T>* next= nullptr;
        while (curr!=nullptr) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
        cout << "Length: " <<this->length<<endl;
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    student *s4 = new student("D", 23);

    LinkedList<student> *ll = new LinkedList<student>(s1);

    ll->insert(-1,s2); //adding at negative index
    ll->print();

    ll->insert(7,s2); //adding at too large index
    ll->print();

    ll->insert(0,s2); //adding at beginning when there is already something there
    ll->print();

    ll->insert(2,s3); //adding at the end
    ll->print();

    ll->insert(1,s4); //adding in between
    ll-> print();

    cout<< "Reversing List" << endl;

    ll->reverselist(); //reversing
    ll->print();

    ll->deleteNode(-1);//deleting at index too low
    ll->print();

    ll->deleteNode(4);//deleting at index too high
    ll->print();

    ll->deleteNode(0);//deleting the first
    ll->print();

    ll->deleteNode(1); //deleting between two nodes
    ll->print();

    ll->deleteNode(1);//deleting the last
    ll->print();

    ll->deleteNode(0);
    ll->deleteNode(0);// need to see if the correct message pops up when there is nothing left
    ll->print();



}