#include "LL.h"

template<typename T>

LinkedList<T>::LinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

template<typename T>
Node<T>* LinkedList<T>::create(T data){

    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;

}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) 
: head(NULL), tail(NULL), size(0) {
    cout << "Copy constructor called" << endl;
    Node<T>* curr = head;
    Node<T>* otherCurr = other.head;
    while (otherCurr != NULL) {
        if (curr == NULL) {
            curr = create(otherCurr->data);
            head = curr;
        } else {
            curr->next = create(otherCurr->data);
            curr = curr->next;
        }
        otherCurr = otherCurr->next;
    }
}
template<typename T>
void LinkedList<T>::appened(T data){
    Node<T>* newNode = create(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = tail->next;
    }
    ++size;

}

template<typename T>
void LinkedList<T>::insert(T data, int pos){
    // insert a node at a position in a linked list
    Node<T>* newNode = create(data);
    if(pos > size){
        cout << "Invalid position" << endl;
        return;
    }
    if(pos == 0){
        newNode->next = head;
        head = newNode;
    }else{
        Node<T>* prev = NULL;
        Node<T>* temp = head;
        while(pos > 0){
            prev = temp;
            temp = temp->next;
            pos--;
        }
        prev->next = newNode;
        newNode->next = temp;

    }
    ++size;
}

template<typename T>
void LinkedList<T>::deleteNodeAt(int pos){
    // delete Node at a position in the linked list
    if(pos > size){
        cout << "Invalid position" << endl;
        return;
    }
    Node<T>* temp = head;
    Node<T>* prev = NULL;
    if(pos == 0){
        prev = head;
        prev = NULL;
        head = head->next;
    }else{
        while(pos > 0){
            prev = temp;
            temp = temp->next;
            pos--;
        }
        prev->next = temp->next;
    }
    --size;
}
template<typename T>
LinkedList<T>::~LinkedList(){
    // destroy linked list
    Node<T>* temp = head;
    while(temp != NULL){
        head = head->next;
        delete temp;
        temp = head;
    }
    --size;
}
template<typename T>
void LinkedList<T>::printLL(){
    //print the linked list
    Node<T>* temp = head;
    while(temp != NULL){
        cout << temp->data;
        if( temp->next != NULL){ cout << " -> "; }
        temp = temp->next;
    }
    cout << " "<< endl;
}

template<typename T>
void LinkedList<T>::PrintLinkedAdress(){

    Node<T>* temp = head;
    while(temp != NULL){
        cout << temp;
          if( temp->next != NULL){ cout << " -> "; }
        temp = temp->next;
    }
    cout << " "<< endl;
}
template<typename T>
int LinkedList<T>::len(){

    int count = 0;
    if(head == NULL){return count; }
       
    Node<T>* temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
template<typename T>
void LinkedList<T>::reverse(){
    // reverse the linked list
    Node<T>* prev = NULL;
    Node<T>* curr = head;
    Node<T>* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
    }
    head = prev;
}
    