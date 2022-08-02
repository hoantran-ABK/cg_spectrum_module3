#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

void QuickSort(int arr[], int low, int high);
int Partition(int arr[], int low, int high);

void FillArray(int arr[], int size);
void PrintArray(int arr[], int size);

int main() 
{
	const int SIZE_SMALL = 10;
	const int SIZE_MED   = 100;
	const int SIZE_LARGE = 500;

	int arr1[SIZE_SMALL] = { 0 };
	int arr2[SIZE_MED]   = { 0 };
	int arr3[SIZE_LARGE] = { 0 };

	srand(time(nullptr));
	FillArray(arr1, SIZE_SMALL);
	
	/*cout << "Unsorted (10) : \n";
	PrintArray(arr1, SIZE_SMALL);
	cout << endl;*/

	chrono::time_point<chrono::system_clock> StartTime, EndTime;
	StartTime = chrono::system_clock::now();
	QuickSort(arr1, 0, SIZE_SMALL-1);
	EndTime = chrono::system_clock::now();

	chrono::nanoseconds elapsed_nano = EndTime - StartTime;
	cout << "Quick Sort Time (10)  : " << elapsed_nano.count() << " ns \n";

	/*cout << "Sorted (10) : \n";
	PrintArray(arr1, SIZE_SMALL);
	cout << endl;*/

	//------------------------------------------------------------------

	FillArray(arr2, SIZE_MED);
	
	/*cout << "Unsorted (100) : \n";
	PrintArray(arr2, SIZE_MED);
	cout << endl;*/

	//chrono::time_point<chrono::system_clock> StartTime, EndTime;
	StartTime = chrono::system_clock::now();
	QuickSort(arr2, 0, SIZE_MED - 1);
	EndTime = chrono::system_clock::now();

	elapsed_nano = EndTime - StartTime;
	cout << "Quick Sort Time (100) : " << elapsed_nano.count() << " ns \n";

	/*cout << "Sorted (100) : \n";
	PrintArray(arr2, SIZE_MED);
	cout << endl;*/

	//------------------------------------------------------------------

	FillArray(arr3, SIZE_LARGE);
	/*cout << "Unsorted (500) : \n";
	PrintArray(arr3, SIZE_LARGE);
	cout << endl;*/

	//chrono::time_point<chrono::system_clock> StartTime, EndTime;
	StartTime = chrono::system_clock::now();
	QuickSort(arr3, 0, SIZE_LARGE - 1);
	EndTime = chrono::system_clock::now();

	elapsed_nano = EndTime - StartTime;
	cout << "Quick Sort Time (500) : " << elapsed_nano.count() << " ns \n";

	/*cout << "Sorted (500) : \n";
	PrintArray(arr3, SIZE_LARGE);
	cout << endl;*/

	//chrono::milliseconds elapsed_milli =  chrono::duration_cast<chrono::milliseconds>(EndTime - StartTime);
	//cout << "Quick Sort Time : " << elapsed_milli.count() << " ms \n";
	

}


void QuickSort(int arr[], int low, int high)
{
	if (low >= 0 && high >= 0 && low < high)
	{
		int pivot = Partition(arr, low, high);
		QuickSort(arr, low, pivot);
		QuickSort(arr, pivot + 1, high);
	}
}

int Partition(int arr[], int low, int high)
{
	int pivot = arr[ (int) floor((high + low) / 2) ];

	int left = low - 1;
	int right = high + 1;
	
	while (true)
	{
		do
		{
			left = left + 1;
		} while (arr[left] < pivot);

		do
		{
			right = right - 1;
		} while (arr[right] > pivot);

		if (left >= right)
		{
			return right;
		}

		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}

	//return -1;
}

void FillArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % size+1;
	}
}

void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ",";
	}
}
