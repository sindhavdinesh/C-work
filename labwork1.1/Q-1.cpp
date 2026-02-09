#include <iostream>
using namespace std;

int main()
{
	int size;
	
	cout << "Enter array size: ";
	cin >> size;
	
	int a[size];

   
    // Array input
	for (int i = 0; i < size; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	 } 
	 
	 cout << "Even Elements of an array:";
	 
	 // Even Elements number check
	 for (int i = 0; i < size; i++)
	 {
	 	
	 	if(a[i] % 2 == 0)
		{
			cout << a[i] << " ";
		  }  
	 }
	 
	 return 0;
  }
  
  
  // output //
  
  Enter array size: 5
a[0] = 12
a[1] = 42
a[2] = 15
a[3] = 55
a[4] = 26
Even Elements of an array:12 42 26
--------------------------------
Process exited after 16.26 seconds with return value 0
Press any key to continue . . .