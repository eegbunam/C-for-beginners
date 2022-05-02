#include <iostream>
#include "stats.h"

using namespace std;
using namespace main_savitch_2C;
int main ()
{
    cout << " The Application is running " << endl;

    statistician s;
    s.next(1.1);
    s.next(2.8);
    s.next(-0.9);

     cout << s.mean( ) << endl;


    return 0;


}



