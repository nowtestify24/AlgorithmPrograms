#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>&myNums,int left,int right);
void quickSort(vector<int>&myNums,int low,int high);
int main()
{
    vector<int> numbers;
    for(int i=10;i>=0;i--)
    {
            numbers.push_back(i);
    }
   quickSort(numbers,0,numbers.size()-1);
    for(auto itr : numbers)
    {
        cout<<itr<<" ";
    }
    return 0;
}


int partition(vector<int>& myNums,int left,int right)
{
    int pivot=myNums[right];
    int i=left;
    for(int j=left;j<right;j++)         //partition function to make sure small values are at front of vector
    {                                   //and larger values at the back
            if(myNums[j]<=pivot)
            {
                swap(myNums[i],myNums[j]);    //if we find an entry that's lower than our middle, move it to the left of our pivot
                i+=1;
            }
    }
    swap(myNums[i],myNums[right]);      //place pivot in middle of the array
    return i;
}

void quickSort(vector<int>& myNums,int low,int high)
{
  if(low>=high)
  {
    return;
  }
  int pivot=partition(myNums,low,high);               
  quickSort(myNums,low,pivot-1);            //recursively call our function
  quickSort(myNums,pivot+1,high);
}

