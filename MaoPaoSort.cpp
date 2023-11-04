#include<vector>
#include<iostream>

using namespace std;
void maopaoSort(vector<int> &arr)
{
    int n=arr.size();
    for(int i=0;i<n-1;++i)
    {
        bool change =false;
        for(int j=0;j<n-i-1;++j)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                change=true;
            }
        }
        if(!change)break;
    }

}
int main()
{
    vector<int>arr={9,8,7,6,5,4,3,2,1,0};
    maopaoSort(arr);
    for(int s:arr)
    {
        cout<<s<<"\n";
    }
    cout<<endl;

}