#include<iostream>
#include<vector>

using namespace std;

void print(const vector<int>&mer,const string& strbegin="",const string& strend="")
{
    cout<<strbegin<<endl;

    for(auto val:mer)
    {
        cout<<val<<"\t";
    }
    cout<<endl;
    cout<<strend<<endl;
}
void insertsort(vector<int>& mer)
{
    for (int i=1;i<mer.size();i++)
    {
        int j=i-1;
        int num=mer[i];
        for(;j>=0&&mer[j]>num;j--)
        {
            mer[j+1]=mer[j];
        }
        mer[j+1]=num;
    }
    return ;
}

int main()
{
    vector<int> mer={9,8,7,6,5,4,3,2,1,0};
    print(mer);
    insertsort(mer);
    print(mer,"插入排序后");
    return 0;
}