
#include "LL.h"

int main(){

    LinkedList<int> ll;

    ll.appened(1);
    ll.appened(2);
    ll.appened(3);

    LinkedList<double> ll2;
    ll2.appened(1.1);
    ll2.appened(2.2);
    ll2.appened(3.3);

    ll.printLL();
    ll2.printLL();
    
    return 0;

}