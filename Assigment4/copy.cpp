
#include "LL.h"

int main(){

    LinkedList list;
    list.appened(1);
    list.appened(2);
    list.appened(3);
    list.appened(4);

    LinkedList list2 = list;
    
    list.PrintLinkedAdress();
    list2.PrintLinkedAdress();

    list.printLL();
    list2.insert(1,0);
    list2.printLL();
     list.printLL();
 
    return 0;

}