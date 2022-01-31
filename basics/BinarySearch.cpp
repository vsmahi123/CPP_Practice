#include<iostream>

using namespace std;
#define ARR_SIZE 10
#define DEBUG 0
#define USELOGIC 2
#if USELOGIC == 1  
bool BinarySearch(int array[ARR_SIZE],int Element)
{
	int Start = 0;
	int End= ARR_SIZE -1;
	int Mid = (Start+End)/2;
	bool RetVal=0;
	#if DEBUG == 1
	cout<<"Start="<<Start<<" mid:"<<Mid<<" end:"<<End<<endl;
	cout<<array[Start]<<" "<<array[Mid]<<" "<<array[End]<<endl;
	#endif
	while(Start<End)
	{
		if(array[End] == Element)
		{
			RetVal=1;
			Start=End+1;
			cout<<"found at end"<<endl;
		}
		else if(array[Mid] == Element)
		{
			RetVal=1;
			Start=End+1;
		}
		else if(((Start==Mid)&&(Start == (End-1))&&(array[Mid]!=Element)))
		{
			cout<<"start == mid"<<Start<<""<<Mid<<endl;
			RetVal = 0;
			Start=End+1;
		}
		else if(array[Mid]>Element)
		{
			End= Mid;
		}
		else if(array[Mid]<Element)
		{
			Start = Mid;
		}
		
		else{}

		Mid = (Start+End)/2;
	#if DEBUG == 1
		cout<<"iteration start"<<endl;
		cout<<"Start="<<Start<<" mid:"<<Mid<<" end:"<<End<<endl;
		cout<<array[Start]<<" "<<array[Mid]<<" "<<array[End]<<endl;
		cout<<"iteration end"<<endl;
	#endif
	}

	return RetVal;
}
#elif USELOGIC == 2
bool BinarySearch(int array[ARR_SIZE],int Element)
{
	bool RetVal=0;
	int start = 0;
	int mid=0;
	int end = ARR_SIZE - 1;

	while(RetVal !=1 && start!= (end+1))
	{
		mid = (start+end)/2;

	#if DEBUG == 1
		cout<<"Start="<<start<<" mid:"<<mid<<" end:"<<end<<endl;
		cout<<array[start]<<" "<<array[mid]<<" "<<array[end]<<endl;
	#endif

		if(array[mid] == Element)
		{
			RetVal = 1;
		}
		else if(array[mid]<Element )
		{
			start = mid+1;
		}
		else if(array[mid]>Element)
		{
			end = mid -1;
		}
	}
	#if DEBUG == 1
		cout<<"ending NOTE :Start="<<start<<" mid:"<<mid<<" end:"<<end<<endl;
	#endif
	return RetVal;
}
#endif
int main()
{
	int arr[ARR_SIZE] = {1,2,3,4,5,25,28,35,46,100};
	int val=0;
	bool ans=0;
	cout<<"enter value to search:";
	cin>>val;
	ans= BinarySearch(arr,val);
	cout<<"searchRes: "<<ans<<endl;
	return 0;
}

