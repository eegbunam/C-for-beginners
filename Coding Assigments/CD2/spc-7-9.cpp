// Chapter 7, Programming Challenge 9: Payroll
#include "LL.h"
#include <iostream>
#include <iomanip>
using namespace std;


const int invalidPosition = 9999;
// // Function Prototypes
template<typename T1 , typename T2 , typename T3 , typename T4> void getEmployeeInfo(LinkedList<T1> **emp , LinkedList<T2> **hours, LinkedList<T3> **rate,  LinkedList<T4> **pay);
template<typename T1 , typename T2 > void displayWages(LinkedList<T1> **emp , LinkedList<T2> **pay);
template<typename T>  LinkedList<T>* enterEmployeeInfo();

int main()
{
	
	LinkedList<long>* EmployeeListID =  enterEmployeeInfo<long>();
    LinkedList<int>* hours = new LinkedList<int>;
    LinkedList<double>* payRate = new LinkedList<double>;
    LinkedList<double>* wages = new LinkedList<double>;





    getEmployeeInfo(&EmployeeListID, &hours, &payRate, &wages);
	displayWages(&EmployeeListID, &wages);

	EmployeeListID->printLL();
	hours->printLL();
	payRate->printLL();
	wages->printLL();
    



	return 0;
}

// ********************************************************
// Function: getEmployeeInfo
// Description: Gets the employee ID and stores it
// in a linked list
// ********************************************************
template<typename T> LinkedList<T>* enterEmployeeInfo()
{

    LinkedList<T>* list = new LinkedList<T>();
    int numberOfEmployees = 0;

    cout << " How many Employees Do you want to add?" << endl;
    cin >> numberOfEmployees;

    for(int i = 0; i < numberOfEmployees; i++){
        int employeeId;
        cout << "Enter Employee #" << i+1 << " ID" << endl;
        cin >> employeeId;
        list->appened(employeeId);
    }
    return list;
}


template<typename T1 , typename T2 , typename T3 , typename T4>
void getEmployeeInfo(LinkedList<T1> **emp , LinkedList<T2> **hours, LinkedList<T3> 
                **rate,  LinkedList<T4> **pay)
{

    LinkedList<T1> *tempEmp = *emp;
    LinkedList<T2> *tempHours = *hours;
    LinkedList<T3> *tempRate = *rate;
    LinkedList<T4> *tempPay = *pay;

    int hoursNumber;
    double rateNumber;
    int numberOfEmployees = tempEmp->len();

    	cout << "Enter the requested information "
		 << "for each employee.\n";
  

    for(int i = 0; i < numberOfEmployees; i++)
    {
        cout << "\nEmployee #" << tempEmp->getValueAt(i) << endl;

        cout << "\tHours worked: ";
		cin  >> hoursNumber;

        while (hoursNumber < 0)
        {
            cout << "Hours worked must be 0 or more. "
				 << "Please re-enter: ";
			cin  >> hoursNumber;
        
        }
        tempHours->appened(hoursNumber);

        cout << "\tPay rate: $";
		cin  >> rateNumber;
		while (rateNumber < 15.00)
		{  
			cout << "Pay rate must be 15.00 or more. "
				 << "Please re-enter: $";
			cin  >> rateNumber;
		}
        tempRate->appened(rateNumber);

        double grossWage = hoursNumber * rateNumber;
        tempPay->appened(grossWage);

    }

    
    
}
template<typename T1 , typename T2>
void displayWages(LinkedList<T1> **emp , LinkedList<T2> **pay)
{
    LinkedList<T1> *tempEmp = *emp;
    LinkedList<T2> *tempPay = *pay;    


    cout << "----------------------------\n";
	cout << "Employee               Wages\n";
	cout << "----------------------------\n\n";

    int numberOfEmployees = tempEmp->len();
    for(int i = 0; i < numberOfEmployees; i++)
    {

        cout << "Employee #" << tempEmp->getValueAt(i) << ": \t\t$";
        cout << fixed << setprecision(2) << tempPay->getValueAt(i) << endl;
		
	
	
    
    }

}




