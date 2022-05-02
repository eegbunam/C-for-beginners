// #include "LL.h"

// LinkedList::LinkedList(){
//     head = NULL;
//     tail = NULL;
//     size = 0;
// }

// Node* LinkedList::create(int data){

//     Node* newNode = new Node;
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;

// }


// LinkedList::LinkedList(const LinkedList &other) 
// : head(NULL), tail(NULL), size(0) {
//     cout << "Copy constructor called" << endl;
//     Node* curr = head;
//     Node* otherCurr = other.head;
//     while (otherCurr != NULL) {
//         if (curr == NULL) {
//             curr = create(otherCurr->data);
//             head = curr;
//         } else {
//             curr->next = create(otherCurr->data);
//             curr = curr->next;
//         }
//         otherCurr = otherCurr->next;
//     }
// }

// void LinkedList::appened(int data){
//     Node* newNode = create(data);
//     if(head == NULL){
//         head = newNode;
//         tail = newNode;
//     }
//     else{
//         tail->next = newNode;
//         tail = tail->next;
//     }
//     ++size;

// }

// void LinkedList::insert(int data, int pos){
//     // insert a node at a position in a linked list
//     Node* newNode = create(data);
//     if(pos > size){
//         cout << "Invalid position" << endl;
//         return;
//     }
//     if(pos == 0){
//         newNode->next = head;
//         head = newNode;
//     }else{
//         Node* prev = NULL;
//         Node* temp = head;
//         while(pos > 0){
//             prev = temp;
//             temp = temp->next;
//             pos--;
//         }
//         prev->next = newNode;
//         newNode->next = temp;

//     }
//     ++size;
// }

// int LinkedList::getValueAt(int pos){
//     // get the value at a position in a linked list
//     if(pos > size){
//         cout << "Invalid position" << endl;
//         return 99999999999999;
//     }
//     Node* temp = head;
//     while(pos > 0){
//         temp = temp->next;
//         pos--;
//     }
//     return temp->data;

// }

// void LinkedList::deleteNodeAt(int pos){
//     // delete Node at a position in the linked list
//     if(pos > size){
//         cout << "Invalid position" << endl;
//         return;
//     }
//     Node* temp = head;
//     Node* prev = NULL;
//     if(pos == 0){
//         prev = head;
//         prev = NULL;
//         head = head->next;
//     }else{
//         while(pos > 0){
//             prev = temp;
//             temp = temp->next;
//             pos--;
//         }
//         prev->next = temp->next;
//     }
//     --size;
// }
// LinkedList::~LinkedList(){
//     // destroy linked list
//     Node* temp = head;
//     while(temp != NULL){
//         head = head->next;
//         delete temp;
//         temp = head;
//     }
//     --size;
// }

// void LinkedList::printLL(){
//     //print the linked list
//     Node* temp = head;
//     while(temp != NULL){
//         cout << temp->data;
//         if( temp->next != NULL){ cout << " -> "; }
//         temp = temp->next;
//     }
//     cout << " "<< endl;
// }


// void LinkedList::PrintLinkedAdress(){

//     Node* temp = head;
//     while(temp != NULL){
//         cout << temp;
//           if( temp->next != NULL){ cout << " -> "; }
//         temp = temp->next;
//     }
//     cout << " "<< endl;
// }

// int LinkedList::len(){

//     int count = 0;
//     if(head == NULL){return count; }
       
//     Node* temp = head;

//     while(temp != NULL)
//     {
//         count++;
//         temp = temp->next;
//     }
//     return count;
// }