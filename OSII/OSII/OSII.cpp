//
//
//OSII PROJECT
//
//
//

//Project idea is "Memory Allocation Simulator"
//Done By Youssef sameer and Mohamed Yasser

//******
//STEP 1:FIRST WE ASK ABOUT NUMBER OF MEMORY BLOCK
//STEP2: THEN ENTER THE SIZE OF EACH MEMORY BLOCK
//STEP3: WE ASK ABOUT THE PROCESSES SIZE
//STEP4: ENTER THE SIZE OF EACH PROCESSES
//STEP4:CHOOSE WHICH ALGO YOU NEED (FIRSTFIT,BESTFIT,WORSTFIT)
//******
#include<iostream>;
using namespace std;
int main() {
	//first
	//varibales
	int choice, key, number, l, Bloksise[10], p[10], po[20], flag, temp0, temp02;
	//four varible for for!
	int  FirstV, SecondV, val, xval;
	//FIRST WE ASK ABOUT NUMBER OF MEMORY BLOCK
	//enter number of memory block
	cout << "enter memory block number : ";
	cin >> number;
	//enter number of block size
	//THEN ENTER THE SIZE OF EACH MEMORY BLOCK
	cout << "\nenter memory size for\n";
	for (FirstV = 1; FirstV <= number; FirstV++)
	{
		cout << "\nBLOCK " << FirstV << " :\t";
		cin >> Bloksise[FirstV];
		po[FirstV] = FirstV;
	}
	//enter number of process 
	cout << "\nenter process:\t";
	cin >> SecondV;
	//enter number of process size
	cout << "\nenter memory size for\n";
	for (FirstV = 1; FirstV <= SecondV; FirstV++)
	{
		cout << "\nprocess " << FirstV << " :\t";
		cin >> p[FirstV];
	}
	// STEP4:CHOOSE WHICH ALGO YOU NEED(FIRSTFIT, BESTFIT, WORSTFIT)
	//first fit
	//bestfit
	//worstfit
	cout << "\n** WELCOME TO THE ALGO PROGRAN *\n1.First Fit\n2.Best Fit\n3.Worst Fit\nEnter Your Choice of which algo you want:\t";
	cin >> choice;
	//here the user will pick from 1 or 2 or 3 to choose what algo he wants
	//switch case for every case of first best or worst fit
	switch (choice)
	{
		//first case is for the first fit
		//first fit algo proceses takes the 1stt enough block
		//first fit is the fastest of all thre
	case 1:
		for (FirstV = 1; FirstV <= SecondV; FirstV++)
		{
			flag = 1;
			for (key = 1; key <= number; key++)
			{
				if (p[FirstV] <= Bloksise[key])
				{
					cout << "\nprocess " << FirstV << "  memory size : " << p[FirstV] << " allocated at memory block:\t" << po[key];
					Bloksise[key] = Bloksise[key] - p[FirstV];
					break;
				}
				else
				{
					flag++;
				}
			}
			//if there is no empty block 
			//value cannot be allocated
			if (flag > number)
			{
				cout << "\nprocess " << FirstV << "  memory size :" << p[FirstV] << " can't be allocated";
			}
		}
		//break cse so it wint go through all of the cases
		break;
		//second case for bestfit
		//best firt algo is the fit that takes the first and nearest fit possible
		//that makes it take more time than first fit as it goes through all blocks first to see which one is the nest
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case 2:
		for (xval = 1; xval <= number; xval++)
		{
			for (val = xval; val <= number; val++)
			{
				if (Bloksise[xval] > Bloksise[val])
				{
					temp0 = Bloksise[xval];
					Bloksise[xval] = Bloksise[val];
					Bloksise[val] = temp0;
					temp02 = po[xval];
					po[xval] = po[val];
					po[val] = temp02;
				}
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//nested for loop for best fit!
		for (FirstV = 1; FirstV <= SecondV; FirstV++)
		{
			flag = 1;
			for (key = 1; key <= number; key++)
			{
				if (p[FirstV] <= Bloksise[key])
				{
					cout << "\nprocess " << FirstV << "  memory size :" << p[FirstV] << "allocated at meBloksiseory block:\t" << po[key];
					Bloksise[key] = Bloksise[key] - p[FirstV];
					break;
				}
				else
				{
					flag++;
				}
			}
			// if there is no empty block and no fit one
			if (flag > number)
			{
				cout << "\nprocess " << FirstV << " memory size: " << p[FirstV] << " can not be allocated";
			}
		}
		//break cse so it wint go through all of the cases
		break;
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//third case for thr worst fit
			//wrst firt algo is the fit that takes the first but wrst fit possible
		//that makes it take more time than first fit as it goes through all blocks first to see which one is the wrst for it


	case 3:
		//nested for loop for worst fit!
		for (xval = 1; xval <= number; xval++)
		{
			for (val = xval; val <= number; val++)
			{
				if (Bloksise[xval] < Bloksise[val])
				{
					temp0 = Bloksise[xval];
					Bloksise[xval] = Bloksise[val];
					Bloksise[val] = temp0;
					temp02 = po[xval];
					po[xval] = po[val];
					po[val] = temp02;
				}
			}
			///////////////////////////////////////////////////////////////////////////////////////////
			for (FirstV = 1; FirstV <= SecondV; FirstV++)
			{
				flag = 1;
				for (key = 1; key <= number; key++)
				{
					if (p[FirstV] <= Bloksise[key])
					{
						cout << "\nprocess " << FirstV << "  memory size : " << p[FirstV] << " allocated at memory block:\t" << po[key];
						Bloksise[key] = Bloksise[key] - p[FirstV];
						break;
					}
					else
					{
						flag++;
					}
				}
				// if there is no empty block and no fit one
				if (flag > number)
				{
					cout << "\nprocess " << FirstV << "  memory size: " << p[FirstV] << " can nott be allocated";
				}
			}
			//break cse so it wint go through all of the cases
			break;
		}
		return 0;
	}
	//end of the code of algo program
	/*
	The End
	*/
}