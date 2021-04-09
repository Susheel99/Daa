#include<bits/stdc++.h>
using namespace std;



class Parent{
public:
	int arr[101];
	void swap (int *a, int *b);
	void print(int a[],int n);
	void input(int n)
	{
		cout<<"Enter the elements"<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
	}
};

class Child:public Parent{
public:
	void DualPivot (int *arr, int low, int high);
	int partition (int *arr, int low, int high, int *lp);

};

void Parent::print(int a[],int n)
{
	cout<<"Dual Pivot Quick sort"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

 
void Parent::swap (int *a, int *b) 
{ 
  int temp = *a; 
  *a = *b;  
  *b = temp;
} 
 
void Child::DualPivot (int *arr, int low, int high) 
{
  
  if (low < high)
  {				
    int lp, rp;  
    rp = partition (arr, low, high, &lp);
      
    DualPivot (arr, low, lp - 1);  
    DualPivot (arr, lp + 1, rp - 1);
    DualPivot (arr, rp + 1, high);
  }
}


int Child::partition (int *arr, int low, int high, int *lp) 
 {
  if (arr[low] > arr[high])
    swap (&arr[low], &arr[high]);


  int j = low + 1;
  int g = high -1, k = low + 1, p = arr[low], q = arr[high];
  
   while (k <= g)
    {				
      if (arr[k] < p)
	  {
	   swap (&arr[k], &arr[j]);
	   j++;
	  }			 
     else if (arr[k] >= q)
	 {
	   while (arr[g] > q && k < g)
      g--;
	     
       swap (&arr[k], &arr[g]);
	     g--;
	  
       if (arr[k] < p)
	    {
		  swap (&arr[k], &arr[j]);  
          j++;
        } 
     }
      k++;
     }
  
  j--;
  
  g++;				
  swap (&arr[low], &arr[j]);
  swap (&arr[high], &arr[g]);	
  *lp = j;			
  return g;

}				

int main () 
{
	cout<<"Enter the number of elements"<<endl;
	int n;
	cin>>n;
     
    Child ob;
    ob.input(n);
    ob.DualPivot(ob.arr, 0, n-1);
 
    ob.print(ob.arr,n);

}				


 