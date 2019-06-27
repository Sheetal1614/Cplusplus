/*
Given an array A, of N elements. Sort the array using quicksort algorithm.(Note : Use randomized quicksort, otherwise worst case will not pass).

Input Format:
A single integer, N, denoting the number of elements in array. Next line contains N integers, denoting the elements of array.

Constraints:
1<=N<=2*10^5 |Ai|<=10^9

Output Format
Print in a single line, N spaced integers, denoting the elements of array A in sorted order.

Sample Input
5
3 6 4 1 2
Sample Output
1 2 3 4 6 
*/
#include<iostream>
using namespace std;
void quickSort(long int array[], int start, int end){
	if(start >= end){
		return;
	}
	int i = start - 1;
	int pivot = array[end];
	for(int j = start; j < end; j++){
		if(array[j] <= pivot){
			i++;
			//swap a[i] and a[j]
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	//swap a[e] and a[i+1]
	int temp = array[end];
	array[end] = array[i+1];
	array[i+1] = temp;
	int p = i + 1;
	quickSort(array, start, p - 1);
	quickSort(array, p + 1, end);
}
int main(){
	int numOfElements;
	cin >> numOfElements;
	long int array[200000];
	for(int i = 0; i < numOfElements; i++){
		cin >> array[i];
	}
	quickSort(array, 0, numOfElements - 1);
	for(int i = 0; i < numOfElements; i++){
		cout << array[i] << " ";
	}
	return 0;
}