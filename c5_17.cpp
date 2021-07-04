#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
typedef unordered_multimap<int,string> hash_Map;
typedef hash_Map::value_type v_t;

template<class T>
void display(char const* name,T& m){
    cout<<name;
    typename T::iterator it = m.begin();
    while(it != m.end()){
        cout<<"("<<it->first<<","<<it->second<<") ";
        it++;
    }
    cout<<endl;
}

int main(){
    int a[] = {80,60,70};
    string s[]={"z","q","s","l","z","s"};
    hash_Map unMap;
    unMap.emplace(a[0],s[0]);
    unMap.emplace(a[1],s[1]);
    unMap.emplace(a[2],s[2]);
    unMap.emplace(a[1],s[3]);
    unMap.emplace(a[2],s[4]);
    unMap.emplace(a[1],s[5]);
    display("container：",unMap);
    hash_Map::iterator it = unMap.find(60);
    cout<<"60 elem:"<<it->first<<","<<it->second<<endl;
    cout<<"++ 60 elem:"<<(++it)->first<<","<<(++it)->second<<endl;
    return 0;
}