
#include <iostream>
using namespace std;
#include <numeric>
#include <vector>

template<typename T> void total() {
    vector<T> currentStack;
    cout << "Enter numbers and we will accumlate the total: ";
    while(true){
        int number;
        char ans;
        cout << "Enter a number: " << endl;
        cin >> number;
        currentStack.push_back(number);
        cout << "Do you want to enter another number? Y or N" << endl;
        
        cin >> ans;
        if (ans == 'N'){
            break;
        }

    }
    cout << " Thank you for enterring Numbers your total is: ";
    cout << accumulate(currentStack.begin(), currentStack.end(), 0) << endl;
}

template<typename T> T maxTemplate(T a, T b) {
    return a > b ? a : b;
}

template<typename T> T minTemplate(T a, T b) {
    return a < b ? a : b;
}


int main(){

    cout << "Enter a bunch of numbers in this program: " << endl;
    int prevNumber = -1;
    while(true){
        int number;
        cout << "Enter a Number and we will tell you the current min and max: " << endl;
       
        cin >> number;
         int maxNumber = maxTemplate<int>(prevNumber, number);
         int minNumber = minTemplate<int>(prevNumber, number);
        cout << "Current Max = " << maxNumber << endl;
        cout << "Current Min = " << minNumber << endl;

        cout << "Do you want to enter another number? Y or N" << endl;
        char answer;
        cin >> answer;
        if(answer == 'N'){
            break;
        }

        prevNumber = number;


    }
    cout << "Thank you for playing" << endl;
    cout << endl;

    total<int>();


    return 0;



}


