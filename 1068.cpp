#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long n ;
        vector<long long> arr;
    cin>>n;
      arr.push_back(n);

    while(n!=1){
        if(n%2==0){
            n/=2;
            arr.push_back(n);
        }else{
             n=n*3+1;
            arr.push_back(n);
        }
    }
    for(auto i: arr){
        cout<<i<<" ";
    }

    return 0;
}
