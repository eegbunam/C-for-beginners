#include <string>
#include <iostream>
#include <vector>
using namespace std;
// contact object
struct Contact{
    string name;
    string phone;
    string email;
};

// contact list object

class ContactManager{

    public:
        ContactManager(){
            // default constructor
        }
        void addContact(string name, string phone, string email){
            Contact newContact;
            newContact.name = name;
            newContact.phone = phone;
            newContact.email = email;
            // chkec if contact is already in the list
            for(int i = 0; i < contactList.size(); i++){
                if(contactList[i].name == name){
                    cout << "Contact already exists" << endl;
                    return;
                }
            }   
            contactList.push_back(newContact);
            cout <<" You have sucessfully added " << name << " to your contact list" << endl;
        }
        void printContacts(){
            //check if contact size is zero
            if(contactList.size() == 0){
                cout << "You have no contacts" << endl;
                return;
            }
            cout << "These are your contacts:" << endl;
            for(int i = 0; i < contactList.size(); i++){
                cout << "Name: " << contactList[i].name;
                cout << ", Phone: " << contactList[i].phone;
                cout << ", Email: " << contactList[i].email << endl;
            }
        }
        void printContact(string name){
            for(int i = 0; i < contactList.size(); i++){
                if(contactList[i].name == name){
                    cout << "Name: " << contactList[i].name;
                    cout << ", Phone: " << contactList[i].phone;
                    cout << ", Email: " << contactList[i].email << endl;
                }
            }


        }
        void deleteContact(string name){
            for(int i = 0; i < contactList.size(); i++){
                if(contactList[i].name == name){
                    contactList.erase(contactList.begin() + i);
                     cout << "Contact: " << name << " has been deleted" << endl;
                     return;
                }
            }
            cout << "Contact: " << name << " does not exist" << endl;
           
        }
    private:
        vector<Contact> contactList;
       
    
        


};

class ContactListSimulation{
    public:
        void addContact(){
            string name;
            string phone;
            string email;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone: ";
            cin >> phone;
            cout << "Enter email: ";
            cin >> email;
            contactManager.addContact(name, phone, email);

        }
        void printContacts(){
           
            contactManager.printContacts();
        }
        void printContact(){
            cout << "Enter contact name: ";
            string name;
            cin >> name;
            contactManager.printContact(name);
        }
        void deleteContact(){
            cout << "Enter contact name: ";
            string name;
            cin >> name;
            contactManager.deleteContact(name);
        }


    private: 
        ContactManager contactManager;

};

class ConactGame{
    public:
        void play(){

            while (true){
                cout << "Welcome to Contact Manger" << endl;
                cout << "1. Add Contact" << endl;
                cout << "2. Print Contacts" << endl;
                cout << "3. Delete Contact" << endl;
                cout << "4. Print Contact" << endl;
                cout << "5. Exit" << endl;

                int choice;
                cout << "Enter your choice: ";
                cin >> choice;

                switch(choice){
                    case 1:
                        simulation.addContact();
                        break;
                    case 2:
                        simulation.printContacts();
                        break;
                    case 3:
                        simulation.deleteContact();
                        break;
                    case 4:
                        simulation.printContact();
                        break;
                    case 5:
                        return;
                    default:
                        cout << "Invalid choice" << endl;
                }


            }
        }
    private:
        ContactListSimulation simulation;
      
  
};
