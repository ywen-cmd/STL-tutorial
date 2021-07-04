#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include<algorithm>
#include<iterator>
#include<functional>
#include<time.h>
using namespace std;
// int Fibonacci(){
//     static int f1 = 0,f2=1,sum;
//     sum = f1 + f2;
//     f1 = f2;
//     f2 = sum;
//     return f1;
// }

template<class T>
void print(const char* name,T const& container){
    cout<<name<<": ";
    typedef typename T::value_type valtype;
    copy(container.begin(),container.end(),ostream_iterator<valtype>(cout," "));
    cout<<endl;
}

template<class T>
bool pred(const T& elem){
    return elem<0;
}

void print(const char* name,int* arr,int size){
    cout<<name<<": ";
    copy(arr,arr+size,ostream_iterator<int>(cout," "));
    cout<<endl;
}

int myRand(int n){
    int result = rand()%n;
    cout<<"n:"<<n<<" result:"<<result<<endl;
    return result;
}

int main(){
    // vector<int> v1{-10,-20,-30,-40,-50};
    // int a[5]={1,0,2,0,-3};
    // auto it_end = remove(a,a+5,0);
    // print("a[]",a,5);
    // cout<<it_end-a<<endl;
    // print("v1",v1);
    // auto it_end1 = remove_copy_if(a,a+5,v1.begin(),pred<int>);
    // print("v1",v1);
    // cout<<it_end1-v1.begin()<<endl;
    vector<int> v1{8,7,9,7,5,6};
    auto iter_end = unique(v1.begin(),v1.end(),greater_equal<int>());
    print("v1",v1);
    v1.erase(iter_end,v1.end());
    print("v1",v1);
    //random_shuffle
    //refer to introduction to algorithm
    vector<int> v2;
    for(int i=0;i<6;i++){
        v2.push_back(i);
    }
    print("before shuffle:",v2);
    random_shuffle(v2.begin(),v2.end(),myRand);
    print("after shuffle:",v2);
    return 0;
}