#include <iostream>
#include <string>
using namespace std;

int findMax(int *arr , int size ){
    
    int currMax = arr[0];
    int currMaxIndex = 0;
    for(int i=1; i<size; i++){
        if(arr[i] > currMax){
            currMax = arr[i];
            currMaxIndex = i;
        }
    }
    return currMaxIndex;
}

int findMin(int *arr , int size)
{
    int currMin = arr[0];
    int currMinIndex = 0;
    
    for(int i=1; i<size; i++){
        if(arr[i] < currMin){
            currMin = arr[i];
            currMinIndex = i;
        }
    
    }
    return currMinIndex;
}


int main(){
    int findMin(int *arr , int size);
    int findMax(int *arr , int size );


    const int SIZE = 5;
    int numberOfEachSalsa[SIZE];
    string Salsa[SIZE] = {"mild", "medium", "sweet", "hot", "zesty"};


    for(int i = 0; i < SIZE; i++){
        int count;
        cout << "How many " << Salsa[i] << " salsa do you want?" << endl;
        cin >> count;
        numberOfEachSalsa[i] = count;
    }
    cout << endl;

    for(int i = 0; i < SIZE; i++){
        cout << numberOfEachSalsa[i] << " " << Salsa[i] << " salsa" << endl;
    }

    int maxIndex = findMax(numberOfEachSalsa, SIZE);
    int minIndex = findMin(numberOfEachSalsa, SIZE);
    cout << " The most popular salsa is " << Salsa[maxIndex] << endl;
    cout << " The least popular salsa is " << Salsa[minIndex] << endl;

    return 0;
}

