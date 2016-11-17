#include <iostream>
using namespace std;

void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void showArray(int number, int position);
int binarySearch(int array[], int size, int value);
void getArray(int &number);
void searchMethod(int &method);

int main()
{
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = 10;
	int position;
	int number;
	int method;
	getArray(number);
	searchMethod(method);
	if (method == 1)
		bubbleSort(array, size);
	else
		selectionSort(array, size);
	position = binarySearch(array, size, number);
	showArray(number, position);
	system("pause");
}

void bubbleSort(int array[], int size)
{
	int temp;
	bool swap;
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
			//showArray(array, size);
		}
	} while (swap);
}
void selectionSort(int array[], int size)
{
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
		//showArray(array, size);
	}
}
int binarySearch(int array[], int size, int value)
{
	int first = 0, last = size - 1, middle, position = -1;
	bool found = false;
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}
void showArray(int number, int position)
{
	if (position != -1)
		cout << "The Number " << number << " is in position " << position << endl;
	else
		cout << "The Number " << number << " was not found in the array " << endl;
	/*for (int count = 0; count < size; count++)
		cout << array[count] << " ";
	cout << endl;*/
}

void getArray(int &number)
{
	cout << "Enter a number to search the array: ";
	cin >> number;
	cout << endl;
}
void searchMethod(int &method)
{
	cout << "Enter 1 to search using the bubble sort or 2 to search using the selection sort method: ";
	cin >> method;
	cout << endl;
}