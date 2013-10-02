


#include <iostream>
#include <string>
#include "TheStack.h";
using namespace std;

TheStack* stack = new TheStack();
bool repeat = true;

void menu();
void stackPush();
void stackPop();
void stackTop();
void isStackEmpty();
void isStackFull();
/****************************************************
 * Method     : Main
 *
 * Purpose    : Starts the program and maintains the flow.
 *
 * Parameters : none
 *
 * Returns    : Integer
 *
 ****************************************************/
int main( )
{
	string myName="Kenyon Brown";
	string myCourse="CS 2420-001";
	string myProject="SimpleFunctions";

	cout << "\nName: " << myName;
	cout << "\ncourse: " << myCourse;
	cout << "\nproject: " << myProject;
	cout << endl;

	cout<< "Welcome to the Stack test program." <<endl << "Please make a selection. 1-6"<<endl<<endl;
	
	do
	{

	menu();

	}while(repeat);

	system("PAUSE");

}

void menu()
{
	bool isSelected = false;
	int selection = 0;
	do
	{
		try
		{
			cout<< "1. Add integer to the stack. (stackPush)"<<endl;
			cout<< "2. Take most recent integer out of stack. (stackPop)" <<endl;
			cout<< "3. Peek at the most recent integer.(Peek) " << endl;
			cout<< "4. Check if stack is empty (isStackEmpty)" << endl;
			cout<< "5. Check if stack is full (isStackFull)" <<endl;
			cout<< "6. Display entire stack. (Show)" <<endl;
			cout<< "7. quit."<<endl;
			
			cin>>selection;

			if(selection>0 &&selection<8)
			{
				isSelected=false;
			}
			else
			{
				throw exception(); 
			}
		}

		catch(exception) 
		{
			cout<< "Please make a proper selection."<<endl;
			selection = 0;
		}

	}while(isSelected);

	cout<<"success"<<endl;
	
	switch(selection)
	{
	case 1:
		stackPush();
		break;
	case 2:
		stackPop();
		break;
	case 3:
		stackTop();
		break;
	case 4:
		isStackEmpty();
		break;
	case 5:
		isStackFull();
		break;
	case 6:
		stack->show();
		break;
	case 7:
		repeat = false;
		break;
	}
	
}
/****************************************************
 * Method     : stackPush() 
 *
 * Purpose    : Parses the user for an interger to 
				add to the stack.
 *
 * Parameters : none
 *
 * Returns    : This method does not return a value.
 *
 ****************************************************/
void stackPush()
{
	if(!stack->isFull())
	{
		int number;
		int result;

		cout<<"Please choose a number to place.";
		try
		{
			cin>>number;
			stack->push(number);
		}
		catch(exception)
		{
			cout<<" Please input a valid number.";
		}
	}
	else
	{
		cout<<"List is full.";
	}
}
/****************************************************
 * Method     : stackPop
 *
 * Purpose    : Takes the stack's last added integer off 
				the list and displays it, by using TheStack's 
				stackPop method.
 *
 * Parameters : none
 *
 * Returns    : This method does not return a value.
 *
 ****************************************************/
void stackPop()
{
	cout<<"stackPop: " <<stack->pop()<<endl;

}
/****************************************************
 * Method     : stackTop
 *
 * Purpose    : Returns the stack's last added integer, 
				by using TheStack's stackPop method.
 *
 * Parameters : 
 *
 * Returns    : This method does not return a value.
 *
 ****************************************************/
void stackTop()
{
	cout<<"stackTop: " <<stack->top()<<endl;

}
/****************************************************
 * Method     : isStackEmpty
 *
 * Purpose    : Checks TheStack to see if if the Stack
				is empty by using the Stack's isEmpty method.
 *
 * Parameters : 
 *
 * Returns    : This method does not return a value.
 *
 ****************************************************/
void isStackEmpty()
{
	if(stack->isEmpty())
	{
		cout<< "The Stack is empty!"<<endl;
	}
	else
		cout<<"The list is not empty."<<endl;
}
/****************************************************
 * Method     : isStackFull
 *
 * Purpose    : Checks TheStack to see if if the Stack
				is empty by using the Stack's isFull method.
 *
 * Parameters : 
 *
 * Returns    : This method does not return a value.
 *
 ****************************************************/
void isStackFull()
{
	if(stack->isFull())
	{
		cout<< "The list is Full!"<<endl;
	}
	else
	{
		cout<<"The list is not full."<<endl;
	}
}