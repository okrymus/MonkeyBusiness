// The program finds the average, the least, and the greatest amount of food eaten during the week by monkeys
// Monkey Business Homework 1
// Programmer: Panupong Leenawarat
// Last modified: 1/26/2016

#include <iostream>
using namespace std;

const int NUMBER_ROWS = 3;
const int NUMBER_COLS = 5;

// Functions Pototypes
void loadData(double dataArray[][NUMBER_COLS], int NUMBER_ROWS);
double getRowSum(double dataArray[][NUMBER_COLS], int monkeyNum);
double getGreatest(double monkey1Total, double monkey2Total, double monkey3Total);
double getLowest(double monkey1Total, double monkey2Total, double monkey3Total);

int main()
{
	int monkey1 = 0,
		monkey2 = 1,
		monkey3 = 2;
	double dataArray[NUMBER_ROWS][NUMBER_COLS];
	double monkey1Total,
		monkey2Total,
		monkey3Total,
		average,
		greatest,
		lowest;

	// Introduction and create empty lines
	cout
		<< endl
		<< "\t             The program is Monkey Business" << endl
		<< "\t                      By Panupong Lee." << endl << endl;

	cout << "    Enter the number of pounds eaten by following monkeys" << endl << endl;
	
	// Get input the amount of food eaten by each monkey
	loadData(dataArray, NUMBER_ROWS);

	// Get the total amount of food eaten by each monkey
	monkey1Total = getRowSum(dataArray, monkey1);
	monkey2Total = getRowSum(dataArray, monkey2);
	monkey3Total = getRowSum(dataArray, monkey3);

	// Get the greatest amount of food eaten during the week by any monkey
	greatest = getGreatest(monkey1Total, monkey2Total, monkey3Total);

	// Get the lowest amount of food eaten during the week by any monkey
	lowest = getLowest(monkey1Total, monkey2Total, monkey3Total);

	// Cals the average of food eaten per day by the whole monkeys
	average = (monkey1Total + monkey2Total + monkey3Total) / (NUMBER_COLS * 3);

	char sign = 2;

	// Print out all information
	cout << " " << sign << " Average amount of food eated per day by the whole monkeys is " << average << endl;
	cout << " " << sign << " The least amount of food eaten during the week by any monkey is " << lowest << endl;
	cout << " " << sign << " The greatest amount of food eaten during the week by any monkey is " << greatest << endl << endl;

	system("pause");
	return 0;
}

void loadData(double dataArray[][NUMBER_COLS], int NUMBER_ROWS)
{
	for (int rows = 0; rows < NUMBER_ROWS; rows++)
	{
		cout << " Monkey #" << (rows + 1) << endl;
		for (int cols = 0; cols < NUMBER_COLS; cols++)
		{
			cout << "    Day " << (cols + 1) << ": ";
			cin >> dataArray[rows][cols];

			// while input is a negative number, process it.
			while (dataArray[rows][cols] < 0)
			{
				cout << "\t!Do not enter negative number, please try again: ";
				cin >> dataArray[rows][cols];
			}
		}
		cout << endl;
	}
}

double getRowSum(double dataArray[][NUMBER_COLS], int monkeyNum)
{
	double total = 0;

	for (int cols = 0; cols < NUMBER_COLS; cols++)
		total += dataArray[monkeyNum][cols];

	return total;
}


double getGreatest(double monkey1Total, double monkey2Total, double monkey3Total)
{
	double a[3] = { monkey1Total, monkey2Total, monkey3Total };
	double max = a[0];
	
	for (int count = 0; count < 3; count++)
	{
		if (a[count] > max){
			max = a[count];
		}
	}
	return max;
}

double getLowest(double monkey1Total, double monkey2Total, double monkey3Total)
{
	double a[3] = { monkey1Total, monkey2Total, monkey3Total };
	double min = a[0];

	for (int count = 0; count < 3; count++)
	{
		if (a[count] < min){
			min = a[count];
		}
	}
	return min;
}