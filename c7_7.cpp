#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
template<class T>
void display(string name,T& container){
    cout<<name;
    typename T::iterator it;
    for(it=container.begin();it!=container.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

bool twice(int elem1,int elem2){
    return elem1*2 == elem2;
}

int main(){
    int a[]={2,4,2,3,4,6,2,3};
    deque<int> v1(a,a+8);
    vector<int> v2(a+6,a+8);
    list<int> v3(a+4,a+6);
    display("v1:",v1);
    display("v2:",v3);
    display("v3:",v3);
    deque<int>::iterator result,result1;
    result=search(v1.begin(),v1.end(),v2.begin(),v2.end());
    result1=find_first_of(v1.begin(),v1.end(),v2.begin(),v2.end());
    cout<<"search:"<<result-v1.begin()<<endl;
    cout<<"find_first_of:"<<result1-v1.begin()<<endl;
    return 0;
}  