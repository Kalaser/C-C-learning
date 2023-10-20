#include<iostream>
#include<map>
#include<string.h>
#include<unordered_map>
#include<vector>
using namespace std;
std::unordered_map<int,string> mymap;
struct Entry
{
    public:
        int key;
        string val;
        Entry(int key,string val)
        {
            this->key=key;
            this->val=val;
        }
};
//基于数组实现的哈希表
class ArrayHashMap
{
private:
    vector<Entry*> buckets;/* data */
public:
    ArrayHashMap(/* args */)
    {
        buckets=vector<Entry*>(100);
    };//初始化数组
    int hashFunc(int key)
    {
        int index=key%100;
        return index;
    }//哈希函数
    string get(int key)
    {
        int index=hashFunc(key);
        Entry*pair=buckets[index];
        if(pair==nullptr)
           return nullptr;
        return pair->val;

    }//查询操作
    void put(int key,string val)
    {
        Entry*pair=new Entry(key,val);
        int index=hashFunc(key);
        buckets[index]=pair;
    }//添加操作

    void remove(int key)
    {
        int index=hashFunc(key);
        buckets[index]=nullptr;

    }
    vector<Entry*>entrySet(){
         vector<Entry*>entrySet;
         for(Entry*pair:buckets)
         {
            if(pair!=nullptr)
            {
                entrySet.push_back(pair);
            }
         }
         return entrySet;
    }
    void print() {
for (Entry* kv: entrySet()) 
{
cout << kv->key << " -> " << kv->val << endl;
}
}


    ~ArrayHashMap();
};


int main()
{
mymap[12836]="小哈";
mymap[15937]="小啰";
mymap[16750]="小算";
mymap[13276]="小法";
mymap[10583]="小鸭";

string name=mymap[15937];

mymap.erase(10583);//删除操作，在哈希表中删除键值对(key,value)

for(auto kv:mymap)
{
    cout<<kv.first<<"->"<<kv.second<<endl;

}
cout<<"\n";
for(auto key:mymap)
{
    cout<<key.first<<endl;
}
cout<<"\n";
for(auto val:mymap)
{
    cout<<val.second<<endl;
}
return 0;
}