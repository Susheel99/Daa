#include <bits/stdc++.h> 
using namespace std; 


class Parent{
public:
	void bubbleSort(int *v,int s,int e);
	void selectionSort(int *v,int s,int e);
	void insertionSort(int *v,int s,int e);
	void print(int v[],int n);
	//vector<int> randomVector(ll n,ll lower,ll upper);


};

class Child:public Parent{
public:
	void merge(int gArray[], int low, int mid1, 
		int mid2, int high);
	void mergeSort3WayRec_bubble(int gArray[], int low, 
					int high);
	void mergeSort3WayRec_selection(int gArray[], int low, 
					int high);
	void mergeSort3WayRec_insertion(int gArray[], int low, 
					int high);
	//void mergeSort3Way(int gArray[], int n);

};




void Parent::bubbleSort(int *v,int s,int e)
{
	int temp;
	for(int i=s;i<=e;i++)
	{
		for(int j=s;j<=e;j++)
		{
			if(v[j]>v[j+1])
			{
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;			
			}
		}
	}
}

void Parent::insertionSort(int *v,int s,int e)
{
	int j=0,temp;
	for(int i=s+1;i<=e;i++)
	{
		j=i;
		while(j!=s && v[j]<v[j-1])
		{
			temp=v[j];
			v[j]=v[j-1];
			v[j-1]=temp;
			j--;
		}
	}
}

void Parent::selectionSort(int *v,int s,int e)
{
	int p,i,j,min1,ind;
	for( i=s;i<=e;i++)
	{
		min1=v[i];p=0;
		for( j=i+1;j<=e;j++)
		{
			if(min1>v[j])
			{
				p++;
				ind=j;
				min1=v[j];
			}
		}
		if(p!=0){
		v[ind]=v[i];
		v[i]=min1;
	}
	}

}

void Child::merge(int gArray[], int low, int mid1, 
		int mid2, int high) 
{ 
	int destArray[high+1];
	int i = low, j = mid1, k = mid2, l = low; 

	while ((i < mid1) && (j < mid2) && (k < high)) 
	{ 
		if(gArray[i] < gArray[j]) 
		{ 
			if(gArray[i] < gArray[k]) 
			{ 
				destArray[l++] = gArray[i++]; 
			} 
			else
			{ 
				destArray[l++] = gArray[k++]; 
			} 
		} 
		else
		{ 
			if(gArray[j] < gArray[k]) 
			{ 
				destArray[l++] = gArray[j++]; 
			} 
			else
			{ 
				destArray[l++] = gArray[k++]; 
			} 
		} 
	} 

	while ((i < mid1) && (j < mid2)) 
	{ 
		if(gArray[i] < gArray[j]) 
		{ 
			destArray[l++] = gArray[i++]; 
		} 
		else
		{ 
			destArray[l++] = gArray[j++]; 
		} 
	} 


	while ((j < mid2) && (k < high)) 
	{ 
		if(gArray[j] < gArray[k]) 
		{ 
			destArray[l++] = gArray[j++]; 
		} 
		else
		{ 
			destArray[l++] = gArray[k++]; 
		} 
	} 

	while ((i < mid1) && (k < high)) 
	{ 
		if(gArray[i] < gArray[k]) 
		{ 
			destArray[l++] = gArray[i++]; 
		} 
		else
		{ 
			destArray[l++] = gArray[k++]; 
		} 
	} 

	while (i < mid1) 
		destArray[l++] = gArray[i++]; 

	while (j < mid2) 
		destArray[l++] = gArray[j++]; 

	while (k < high) 
		destArray[l++] = gArray[k++]; 

	for(int i=low;i<=high;i++)
	{
		gArray[i]=destArray[i];
	}

} 



void Child::mergeSort3WayRec_bubble(int gArray[], int low, 
					int high) 
{ 
	if(high-low<4 and high - low < 2)
	{
		bubbleSort(gArray,low,high);
		return ;
	}
	else if (high - low < 2) 
		return; 

	else{
	int mid1 = low + ((high - low) / 3); 
	int mid2 = low + 2 * ((high - low) / 3) + 1; 


	mergeSort3WayRec_bubble(gArray, low, mid1); 
	mergeSort3WayRec_bubble(gArray, mid1, mid2); 
	mergeSort3WayRec_bubble(gArray, mid2, high); 

	merge(gArray, low, mid1, mid2, high); 
    }
} 

void Child::mergeSort3WayRec_selection(int gArray[], int low, 
					int high) 
{ 
	if(high-low<4 and high - low < 2)
	{
		selectionSort(gArray,low,high);
		return ;
	}
	else if (high - low < 2) 
		return; 

	else{
	int mid1 = low + ((high - low) / 3); 
	int mid2 = low + 2 * ((high - low) / 3) + 1; 


	mergeSort3WayRec_selection(gArray, mid2, high); 
	mergeSort3WayRec_selection(gArray, mid2, high); 
	mergeSort3WayRec_selection(gArray, mid2, high); 

	merge(gArray, low, mid1, mid2, high); 
    }
} 

void Child::mergeSort3WayRec_insertion(int gArray[], int low, 
					int high) 
{ 
	if(high-low<4 and high - low < 2)
	{
		insertionSort(gArray,low,high);
		return ;
	}
	else if (high - low < 2) 
		return; 

	else{
	int mid1 = low + ((high - low) / 3); 
	int mid2 = low + 2 * ((high - low) / 3) + 1; 


	mergeSort3WayRec_insertion(gArray, mid2, high); 
	mergeSort3WayRec_insertion(gArray, mid2, high); 
	mergeSort3WayRec_insertion(gArray, mid2, high); 

	merge(gArray, low, mid1, mid2, high); 
    }
} 

int main() 
{ 
	int data[] = {45, -2, -45, 78, 30, 
				-42, 10, 19, 73, 93,87,95,62,47,45,79,25,36,64,15}; 
	Child ob;
	ob.mergeSort3WayRec_bubble(data,0,20); 
	cout << "After 3 way merge sort: "; 
	for (int i = 0; i < 20; i++) 
	{ 
		cout << data[i] << " "; 
	} 
	return 0; 
} 
