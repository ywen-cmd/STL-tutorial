#include<valarray>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<numeric>
using namespace std;

template<class T>
void print(string name,T& c){
    cout<<name<<":";
    for(int i=0;i<c.size();i++)
        cout<<c[i]<<" ";
    cout<<endl;
}

int main(){
    vector<int> v(8);
    iota(v.begin(),v.end(),1);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    valarray<int> val1(v.data(),8);
    print("val1",val1);
    valarray<int> val2 = val1[slice()];
    print("val2",val2);
    return 0;
}