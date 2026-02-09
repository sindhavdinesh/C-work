#include <iostream>
using namespace std;

int main()
{
	int start, end;
	
	cout << "Enter first number: ";
	cin >> start;

    cout << "Enter Second number: ";
    cin >> end;
    
    cout << "The leap years are: ";
    
    for (int year = start; year <= end;year++)
    {
    	 if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
	         cout << year << " ";
			 
			    }
    }

    return 0;
} 

// outtput //

Enter first number: 2020
Enter Second number: 2040
The leap years are: 2020 2024 2028 2032 2036 2040
--------------------------------
Process exited after 51.45 seconds with return value 0
Press any key to continue . . .