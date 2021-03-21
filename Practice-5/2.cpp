#include <bits/stdc++.h> 
using namespace std; 
using namespace std::chrono;

#define ll long long


class Parent{
public:
	void bubbleSort(int *v,int s,int e);
	void selectionSort(int *v,int s,int e);
	void insertionSort(int *v,int s,int e);
	void print(int v[],int n);
	vector<int> randomVector(ll n,ll lower,ll upper);


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

};

vector<int> Parent::randomVector(ll n,ll lower,ll upper)
{
       vector<int>v;
       for(ll i=0;i<=n;i++){
       ll num = (rand() % (upper - lower + 1)) + lower;
        v.push_back(num);
        }
        return v;
}

void Parent::print(int v[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

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
	int n,m1,m2,m3;
	cout<<"Enter the no.of elements"<<endl;
	cin>>n;

	Child ob;

	vector<int>v=ob.randomVector(1000,0,500);

	int a[n];
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		a[i]=v[i];
	}

	//ob.mergeSort3WayRec_bubble(a,0,n); 

	cout<<"----------------merge+bubble----------------"<<endl;
	auto start = high_resolution_clock::now(); 
	ob.mergeSort3WayRec_bubble(a,0,n); 
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start); 
	m1=duration.count();

	ob.print(a,n);
	cout<<"Time Duration-> "<<m1<<endl;
	cout<<endl;
	



	cout<<"----------------merge+selection----------------"<<endl;
	start = high_resolution_clock::now(); 
	ob.mergeSort3WayRec_selection(a,0,n);
	stop = high_resolution_clock::now(); 
	duration = duration_cast<microseconds>(stop - start); 
	m2=duration.count();

	ob.print(a,n);
	cout<<"Time Duration-> "<<m2<<endl;
	cout<<endl;

	cout<<"----------------merge+insertion----------------"<<endl;
	start = high_resolution_clock::now();
	ob.mergeSort3WayRec_insertion(a,0,n);
	stop = high_resolution_clock::now(); 
	duration = duration_cast<microseconds>(stop - start); 
	m3=duration.count();

	ob.print(a,n);
	cout<<"Time Duration-> "<<m3<<endl;
	cout<<endl;
	
} 
