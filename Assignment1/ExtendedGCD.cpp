#include <bits/stdc++.h>
using namespace std;
void extendedGCD(int a,int b){
    int s=0,olds=1,t=1,oldt=0,r=b,oldr=a;
    while(r!=0){
        int q=floor(oldr/r);
        int p=oldr-q*r;
        oldr=r;
        r=p;
        p=olds-q*s;
        olds=s;
        s=p;
        p=oldt-q*t;
        oldt=t;
        t=p;
        
    }
    
    cout<<"Gcd is "<<oldr<<endl;
    cout<<"Multiplicative inverse of "<<b<<" mod "<<a<<" is "<<oldt<<endl;
    
    
    
}
int main() {
	extendedGCD(56211,53947);
	extendedGCD(43159,19385);
	return 0;
}
