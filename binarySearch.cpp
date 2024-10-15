#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int>& vector,int target);
int main()
{
    vector<int> vector;
    for(int i=10;i<101;i+=10)
    {
        vector.push_back(i);
    }
    cout<<binarySearch(vector,50);            //returns the index of where 50 is located in our vector
    return 0;
}
int binarySearch(vector<int>& vector,int target)
{
    int low=0;
    int high=vector.size()-1;
    while(low<=high)
    {
        int pivot=(low +high)/2;                  
        if(vector[pivot]==target)
        {
            return pivot;           //return the index of our target
        }
        else if(vector[pivot]>target)          //if the entry at our current index/pivot is too high, set our bound to be the middle-1
        {
            high=pivot-1;
        }
        else                                    //if the netry at our current index/pivot is too low, set the bound to be middle + 1
        {
            low=pivot+1;
        }
    }
return -1;
}
