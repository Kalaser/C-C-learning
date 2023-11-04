#include<iostream>
#include<vector>

using namespace std;

void printvec(const vector<int>& vec, const string& strbegin = "", const string& strend = "") {
    cout << strbegin << endl;
    for (auto val : vec) {
        cout << val << "\t";
    }

    cout << endl;
    cout << strend << endl;
}


void selectsort(vector<int>&mer)
{
    for(int i =0;i<mer.size()-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<mer.size();j++)
        {
            if(mer[min_index]>mer[j])
            {
                min_index =j;
            }
        }
        swap(mer[i],mer[min_index]);
    }
}

int main()
{
    vector<int>mer={9,8,7,6,5,4,3,2,1,0};
    printvec(mer);
    selectsort(mer);
    printvec(mer,"选择排序后的结果");
    return 0;
}