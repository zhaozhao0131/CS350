#include<iostream>
#include<cstdlib>

using namespace std;

int swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int BubbleSort(int array[], int size)
{
   int i,j;
   for(i=size; i>1; i--)
   {
       for(j=0;j<i-1;j++)
       {
	   if(array[j] > array[j+1])
	       swap(&array[j],&array[j+1]);
       }
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

    cout<<"<Bubble Sorting>"<<endl;
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

    cout<<"Bubble Sorting.."<<endl;
    BubbleSort(array, size);
    display(array,size);
}


