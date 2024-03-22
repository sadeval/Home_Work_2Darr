#include <iostream>
using namespace std;
using uintc = const unsigned int;
using uint = unsigned int;

void AllocateMemory2DArr(int*** ar, uintc width, uintc height);
void RandomFill2DArr(int** ar, uintc width, uintc height, int min, int max);
void Print2DArr(int** ar, uintc width, uintc height);
void FreeMemory2DArr(int** ar, uintc height);
void AddLineToEnd(int*** ar, uintc width, uint& height);
void DelLineFromEnd(int*** ar, uintc width, uint& height);
void AddColToEnd(int*** ar, uint& width, uintc height);
void DelColFromEnd(int*** ar, uint& width, uintc height);


int Random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int main() {

	uint width;
	uint height;
	cout << "Enter width: ";
	cin >> width;
	cout << "Enter height: ";
	cin >> height; 

	int** ar = nullptr;

	AllocateMemory2DArr(&ar, width, height);
	RandomFill2DArr(ar, width, height, 10, 99);
	AddLineToEnd(&ar, width, height);
	DelLineFromEnd(&ar, width, height);
	AddColToEnd(&ar, width, height);
	DelColFromEnd(&ar, width, height);
	Print2DArr(ar, width, height);
	FreeMemory2DArr(ar, height);
	
	return 0;
}

void AllocateMemory2DArr(int*** ar, uintc width, uintc height)
{
	(*ar) = new int* [height];
	for (int y = 0; y < height; y++) 
		(*ar)[y] = new int[width];
}

void RandomFill2DArr(int** ar, uintc width, uintc height, int min, int max)
{
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			ar[y][x] = Random(min, max);
		
}
void AddLineToEnd(int*** ar, uintc width, uint& height) {
	
	int** temp = *ar;
	int** newArr = new int* [height + 1];
	
	for (uint y = 0; y < height; y++) {
		newArr[y] = new int[width];
		for (uint x = 0; x < width; x++) {
			newArr[y][x] = temp[y][x];
			cout << newArr[y][x] << "\t";
		}
		cout << "\n\n";
	}
	newArr[height] = new int[width]();
	delete[] temp;
	*ar = newArr;
	height++; 
}

void DelLineFromEnd(int*** ar, uintc width, uint& height)
{
	if (height == 0) return;

	int** temp = *ar;
	int** newArr = new int* [height];

	for (uint y = 0; y < height; y++) {
		newArr[y] = new int[width];
		for (uint x = 0; x < width; x++) {
			newArr[y][x] = temp[y][x];
			cout << newArr[y][x] << "\t";
		}
		cout << "\n\n";
		delete[] temp[y];
	}
	delete[] temp;
	*ar = newArr;
	height--;
}

void AddColToEnd(int*** ar, uint& width, uintc height)
{
	int** temp = *ar;
	int** newArr = new int* [height];

	for (uint y = 0; y < height; y++) {
		newArr[y] = new int[width + 1];
		for (uint x = 0; x < width; x++) {
			newArr[y][x] = temp[y][x];
			cout << newArr[y][x] << "\t";
		}
		newArr[y][width] = 0;
		cout << "0\n\n";
		delete[] temp[y]; 
	}
	delete[] temp; 
	*ar = newArr; 
	width++; 
}

void DelColFromEnd(int*** ar, uint& width, uintc height)
{
	int** temp = *ar;
	int** newArr = new int* [height];

	for (uint y = 0; y < height; y++) {
		newArr[y] = new int[width - 1];
		for (uint x = 0; x < width - 1; x++) {
			newArr[y][x] = temp[y][x];
			cout << newArr[y][x] << "\t";
		}
		cout << "\n\n";
		delete[] temp[y]; 
	}
	delete[] temp;
	*ar = newArr;
	width--; 
}


void Print2DArr(int** ar, uintc width, uintc height)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++)
		   cout << ar[y][x] << "\t";
		cout << "\n\n";
	}

}

void FreeMemory2DArr(int** ar, uintc height)
{
	for (int y = 0; y < height; y++)
		delete[] ar[y];
	delete[] ar;
}


