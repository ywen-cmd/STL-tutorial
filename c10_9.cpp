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

// template<class T>
unsigned long myFill(unsigned long a,unsigned long& b){ b+=1; return 0;}
unsigned long myfiller(unsigned long& c){ c+=1;}


int main(){
    //==============test mask_array====================== 
    valarray<double> va(9);
    for(int i=0;i<9;i++)
        va[i] = i;
    print("va[]",va);
    bool B[7]={1,1,1,1,1};
    valarray<bool> mk(B,7);
    valarray<double> val1 = va[mk];
    print("val1[]",val1);
    // no iterator for valarray
    // fill(mk.begin(),mk.begin()+2,0);
    mk[0]=0;
    mk[1]=0;
    print("mk[]",mk);
    valarray<double> val2 = va[mk];
    print("val2[]",val2);
    val2[0]=100;
    print("va[]",va);
    cout<<"do not change\n";
    va[mk] = 100;
    print("va[]",va);
    cout<<"it work\n";
    
    //==============test indirect_array==================
    for(int i=0;i<va.size();i++)
        va[i] = i+1;
    print("new va[]",va);
    unsigned long index[20]={1,1,3,2};
    // there 3 methods to set array
    // fill(index+4,index+20,1); ==> error{no iterator}
    // template myFill<unsigned long>;
    // accumulate(index+4,index+20,0,myFill);
    for_each(index+4,index+20,myfiller);
    //
    copy(index+4,index+20,ostream_iterator<double>(cout," "));
    cout<<endl;

    valarray<size_t> vi(index,20);
    valarray<double> val3 = va[vi];
    print("val3[]",val3);
    return 0;
}