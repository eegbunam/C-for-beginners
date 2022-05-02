#include "LL.h"
int main()
{

    LinkedList<int> ll;
    ll.appened(1);
    ll.appened(2);
    ll.appened(3);
    ll.appened(4);
    ll.printLL();

    ll.reverse();
    ll.printLL();

    ll.insert(20,3);
    ll.insert(12,3);


    ll.printLL();

    ll.reverse();

    ll.printLL();

    return 0;
}

// Output
// 1 -> 2 -> 3 -> 4 
// 4 -> 3 -> 2 -> 1 
// 4 -> 3 -> 2 -> 12 -> 20 -> 1 
// 1 -> 20 -> 12 -> 2 -> 3 -> 4 