/*************************************************************************
* Authored by BalkanBasileus
*
* The following C++ program was created during the Covid-19 pandemic as
* a warm up to get back into programming with the C++ language. The
* program utilizes functions, structs, pointers, sorting, and reference
* parameters. The program is menu driven and will ask the user for input
* regarding different options. If the user wishes to continue they are 
* taken back to the main menu. Sample output provided at bottom.
*
**************************************************************************/
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include "bankAccount.h"

using namespace std;

//Struct
struct Stat
{
	short *array; 	
	short avg;
	short min;
	short max;
	short med;
	int sum;
	short size;
	
};

//Function Declerations
void powerFunc(char &proceed);
void sqrtFunc(char &proceed);
void readFile(vector<bankAccount> &accountList, char &proceed);
void statFunc(Stat &theArray);
void printArray(Stat &theArray, char &proceed);
static void selectionSort(Stat &theArray);
static void swapping(short &a, short &b);


//Main
int main(int argc, char const *argv[])
{
	//Variables
	short choice;
	char proceed;
	bool quit = false;
	Stat theArray;
  vector<bankAccount> accountList;

	cout << "/////////////////Welcome/////////////////" << endl;
	do{

	//Prompt
	cout << endl;
	cout << "Options: " << endl;
	cout << "1) Raise to power" << endl;
	cout << "2) Square Root" << endl;
	cout << "3) Read File" << endl;
	cout << "4) Random Array" << endl;
	cout << "5) Quit" << endl;
	cout << endl;

  cout << "Enter: ";
	cin >> choice;

  //Error Check
  while(choice < 1 || choice > 5){

    cin.clear();
		cin.ignore(100,'\n');
    
    cout << "Enter: ";
	  cin >> choice;
  }

		switch(choice){

			case 1:
				powerFunc(proceed);
				break;

			case 2:
				sqrtFunc(proceed);
				break;

			case 3:
				readFile(accountList, proceed);
				break;

			case 4:
				statFunc(theArray);
				selectionSort(theArray);
				printArray(theArray,proceed);
				delete [] theArray.array;
				break;
			case 5:
				cout << "Goodbye." << endl;
				return -1;
				break;
		}

		//Will user exit or continue
		if(proceed == 'n'){
			cout << "Goodbye." << endl;
			quit = true;
		}
	

	}while(!quit);
	

	return 0;
}

//Functions
//////////////////////////////////////////////////////////////////////////////////
void powerFunc(char &proceed){
	/*
	 * Function description here...
	 */

	//Variables
	short base, power;

	//Prompt
	cout << "Enter base and power: ";
	cin >> base >> power;

		//Error Check
		while( cin.fail() ){

			cin.clear();
			cin.ignore(100,'\n');

			cout << "Enter base and power: ";
			cin >> base >> power;
		}

	//Display Result
	cout << "Answer = "<< pow(base,power) << endl;
	cout << "Would you like to continue [y/n]: ";
	cin >> proceed;

	tolower(proceed);
		
		//Error Check
		while( proceed != 'y' && proceed != 'n' ){

			cin.clear();
			cin.ignore(100,'\n');

			cout << "Would you like to continue [y/n]: ";
			cin >> proceed;
		}

}

void sqrtFunc(char &proceed){
	/*
	 * Function description here...
	 */

	//Variables
	short number;

	//Prompt
	cout << "Enter number [0 < n < 1000]: ";
	cin >> number;

	//Error Check
		while( cin.fail() || number < 1 || number > 1000 ){

			cin.clear();
			cin.ignore(100,'\n');

			cout << "Enter number [0 < n < 1000]: ";
			cin >> number;
		}

		//Display Result
	cout << "Answer = "<< sqrt(number) << endl;
	cout << "Would you like to continue [y/n]: ";
	cin >> proceed;

	tolower(proceed);
		
		//Error Check
		while( proceed != 'y' && proceed != 'n' ){

			cin.clear();
			cin.ignore(100,'\n');

			cout << "Would you like to continue [y/n]: ";
			cin >> proceed;
		}
}

void readFile(vector<bankAccount> &accountList, char &proceed){
	/*
	 * Function description here...
	 */

	//File input variables
	ifstream inFile;
	ofstream outFile;
	string fileName;
	string line;

  //bank account vars
  string fname, lname;
  int acct;
  float bal;
  short pin;


	do{//open file
	cout << "Type 'BankData.txt' " << endl;
    cout << "Enter the input file: "; 
    cin >> fileName;
    inFile.open(fileName.c_str());
  } while(!inFile.is_open());

  //File content prompt
  cout << endl;
  cout << "File Contents: " << endl;
  cout << endl;
  cout << setw(10) << "FIRST" << setw(10) << "LAST"<< setw(10);
  cout << "ACCOUNT" << setw(10) << "PIN" << setw(10) << "BALANCE" << endl;

  // Read file. Initialize accounts. Display.
  while (inFile >> fname >> lname >> acct >> pin >> bal)
    { 
      bankAccount account(fname, lname, acct, pin, bal);
      account.display();
      accountList.push_back( account ); 
    }
  inFile.close(); //Close file.
}

void statFunc(Stat &theArray){
	/*
	 * Function description here...
	 */

	//Variables
	short size; 
   srand (time(NULL));						//Initialize random

	//Prompt
	cout << "Enter the size of array[less than 300]: ";
	cin >> size;

	//Error Check
		while( cin.fail() || size < 0 || size > 300 ){

			cin.clear();
			cin.ignore(100,'\n');

			cout << "Enter the size of array[less than 300]: ";
			cin >> size;
		}
	cout << endl;

	theArray.size = size;
	theArray.array = new short[size];

	//Initialize array and obtain data
	for (int i = 0; i < size; i++)
	{
		//initialize rand element
		short randNum = rand() % 250 + 1;	//Rand 1-250
		theArray.array[i] = randNum;

		//sum
		theArray.sum += static_cast<int>(theArray.array[i]);

		//get min
		if(theArray.min > theArray.array[i]){

			theArray.min = theArray.array[i];
		}
		//get max
		if(theArray.max < theArray.array[i]){

			theArray.max = theArray.array[i];
		}
	}


	//Calculate avg / median.
	theArray.avg = static_cast<short>(theArray.sum) / size;

}

void printArray(Stat &theArray,char &proceed){
	/*
	 * Function description here...
	 */

	//Display
	cout << "Array Contents: " << endl;
	
	for (int i = 0; i < theArray.size; i++)
	{
		if(i % 4 == 0){
			cout << endl;
		}	

		cout << right;
		cout << setw(5) << theArray.array[i];
	}
	cout << endl;

	//Display stats
	cout << endl;
	cout << "Array Stats: " << endl;
	cout << endl;

	cout << right;
	//cout << setfill('.');
	cout << "Sum: " << setw(6) << theArray.sum << endl;
	cout << "Min: " << setw(6) << theArray.min << endl;
	cout << "Max: " << setw(6) << theArray.max << endl;
	cout << "Avg: " << setw(6) << theArray.avg << endl;

	cout << "Would you like to continue [y/n]: ";
	cin >> proceed;

	tolower(proceed);
		
		//Error Check
		while( proceed != 'y' && proceed != 'n' ){

			cin.clear();
			cin.ignore(100,'\n');

			cout << "Would you like to continue [y/n]: ";
			cin >> proceed;
		}


	//Reset Stat Object
	theArray.sum = 0;
	theArray.min = 0;
	theArray.max = 0;
	theArray.avg = 0;
	theArray.size = 0;

	
}

static void selectionSort(Stat &theArray){

	short i, j, imin;
   for( i = 0; i < theArray.size - 1; i++ ) {

      imin = i;   //get index of minimum data
      for( j = i+1; j < theArray.size; j++ ){

         if(theArray.array[j] < theArray.array[imin]){
            imin = j;
         }
         //placing in correct position
         swapping(theArray.array[i], theArray.array[imin]);
       }
   }

}

static void swapping(short &a, short &b){         //swap the content of a and b
   short temp;
   temp = a;
   a = b;
   b = temp;
}



/*
SAMPLE OUTPUT

/////////////////Welcome/////////////////

Options: 
1) Raise to power
2) Square Root
3) Read File
4) Random Array
5) Quit

Enter: 1
Enter base and power: 2 5
Answer = 32
Would you like to continue [y/n]: y

Options: 
1) Raise to power
2) Square Root
3) Read File
4) Random Array
5) Quit

Enter: 2
Enter number [0 < n < 1000]: 3
Answer = 1.73205
Would you like to continue [y/n]: y

Options: 
1) Raise to power
2) Square Root
3) Read File
4) Random Array
5) Quit

Enter: 3
Type 'BankData.txt' 
Enter the input file: BankData.txt

File Contents: 

     FIRST      LAST   ACCOUNT       PIN   BALANCE
    Lawton     Buzza   2100655      8973    111.78
      Joni    Dansey   8376524      7353     148.9
  Bellanca   Willers   4367987      1138    273.31
     KandyThursfield   4713988      9084      0.97
   Latrina   Sherman   6507309      6666     16.03
    Florie      Abad   9216510      1544    263.22
Hildegarde Sargerson   5647664      6116     49.04
     Hiram    Larose   3590713      5396     10.47
    Ferdie Narramore   7758159      7007    177.04
      Rock  Hurworth   3083698      8107    161.37
     Nicko   Pittson   4682967      3166    117.35
   Auguste     Wedon   8202281      8067    175.08
      Gina   Hardway   2646506      7150     235.5
     Mirna       Oke   2526115      2441    252.41
    Porter    Moffet   9422926      7864    152.67


Options: 
1) Raise to power
2) Square Root
3) Read File
4) Random Array
5) Quit

Enter: 4
Enter the size of array[less than 300]: 34

Array Contents: 

    8   17   33   40
   37   47   64   74
   75   78   80   85
   97  104  116  137
  137  153    3  209
  194  211  170  215
  221  228  232  232
  232  237  248  248
   60  250

Array Stats: 

Sum:   4572
Min:      0
Max:    250
Avg:    134
Would you like to continue [y/n]: n
Goodbye.

*/
