#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
int partition(vector<T>& nums,int left,int right);
template <typename T>                                    //template function of quickSearch declaration
T quickSearch(vector<T>& nums,int low,int high, int k);
int main()
{
    int k;
    cout<<"Enter in the kth element to find: ";
    cin>>k;

    vector<int> nums;
    for(int i=1;i<11;i++)
    {
        nums.push_back(i);
    }

    int answer=quickSearch(nums,0,nums.size()-1,k);
    cout<<"The "<<k<<"th element is: "<<answer<<endl;

    cin.ignore();//clear the buffer
    
    vector<string> books;
    for(int i=0;i<5;i++)
    {
        cout<<"Enter in the "<<i<<"-th book: ";
        string title;
        getline(cin,title);                            //have the user insert 5 books
        books.push_back(title);
    }
    cout<<"Enter in the k-th element to find in book vector: ";     //ask for the k-th elemnt of book we want to find
    cin>>k;
    string answer2=quickSearch(books,0,books.size()-1,k);
    cout<<"The "<<k<<"-th element in the book is: "<<answer2<<endl;
    return 0;
}

template <typename T>
int partition(vector<T>& nums,int left,int right)
{
    T pivot=nums[right];              //declare pivot
    int i=left;
    for(int j=left;j<right;j++)
    {
        if(nums[j]<=pivot)              //shift values to left or right of pivot
        {
            swap(nums[i],nums[j]);
            i+=1;
        }
    }
    swap(nums[i],nums[right]);          //place pivot in middle of our array
    return i;
}

template <typename T>                                //template function implementation of quickSearch to find k-th element
T quickSearch(vector<T>& nums,int low,int high, int k)
{
        if(k<0 || k>nums.size())
        {
            return T();
        }
        while(low<=high)                    //iterative approach to quick searching, Average Complexity: O(N);
        {
            int pivot=partition(nums,low,high);
            if(k-1==pivot)
            {
                return nums[k-1];
            }
            
            if(pivot>k-1)               //if pivot is too high, set our upper bound to pivot-1
            {
                high=pivot-1;
            }
            else{                       //if pivot is too low, set our lower bound to be pivot+1
                low=pivot+1;
            }
        }
        return T();
}


