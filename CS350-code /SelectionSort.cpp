#include<iostream>
#include<cstdlib>

using namespace std;

int swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int SelectionSort(int array[], int size)
{
    int min = 0;
    for(int i = 0; i <size-1 ; i++)
    {
	min = i;
	for(int j = i+1; j<size ; j++)
	{
	    if(array[j] < array[min])
	    {
		min = j;
	    }
	}
	swap(&array[min],&array[i]);
    }
}

void display(int array[],int size)
{
    cout<<"THE ARRAY: "<<endl;
    for(int m=0;m < size;m++)
    {
	cout<<array[m]<<' ';
    }
    cout<<endl;
}


int main(){

    cout<<"<SelectingSort>"<<endl;
    cout<<"Please enter SIZE of array: ";
    int size =0;
    cin>>size;
    cout<<"size: "<<size<<endl;
    int array[size];
    for(int i=0;i < size;i++)
    {
	array[i] = rand()%100;
    }
    display(array,size);
    cout<<"Select Sorting.."<<endl;
    SelectionSort(array, size);
    display(array,size);
}


