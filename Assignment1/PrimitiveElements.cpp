#include<bits/stdc++.h> 
using namespace std;  
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
vector<int> findz(int n){
    vector<int> zn;
    for(int i=1;i<=n-1;i++){
        if(gcd(n,i)==1)zn.push_back(i);
    }
    return zn;
}
bool isPrime(int n) 
{ 
    
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
            return false; 
  
    return true; 
} 

int power(int x, unsigned int y, int p) 
{ 
    int res = 1;    
    x = x % p; 
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        
        y = y >> 1; 
        x = (x*x) % p; 
    } 
    return res; 
} 

void findPrimefactors(unordered_set<int> &s, int n) 
{ 
    
    while (n%2 == 0) 
    { 
        s.insert(2); 
        n = n/2; 
    } 
  
    
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        
        while (n%i == 0) 
        { 
            s.insert(i); 
            n = n/i; 
        } 
    } 
  
   
    if (n > 2) 
        s.insert(n); 
} 
  

int findPrimitive(int n) 
{ 
    unordered_set<int> s; 
  
     
    if (isPrime(n)==false) 
        return -1; 
  
    int phi = n-1; 
  
   
    findPrimefactors(s, phi); 
  
   
    for (int r=2; r<=phi; r++) 
    { 
       
        bool flag = false; 
        for (auto it = s.begin(); it != s.end(); it++) 
        { 
  
           
            if (power(r, phi/(*it), n) == 1) 
            { 
                flag = true; 
                break; 
            } 
         } 
  
         
         if (flag == false) 
           return r; 
    } 

    return -1; 
} 
  

int main() 
{ 
    int n=39877;
    cout<<"Primitive Elemnts of "<<n<<endl;
    int k=findPrimitive(n);
    vector<int> v=findz(n-1);
    for(int i=0;i<v.size();i++){
        cout<<power(k,v[i],n)<<endl;
    }
    n=31319;
    cout<<"Primitive Elemnts of "<<n<<endl;
    k=findPrimitive(n);
    v=findz(n-1);
    for(int i=0;i<v.size();i++){
        cout<<power(k,v[i],n)<<endl;
    }
    n=39869;
    cout<<"Primitive Elemnts of "<<n<<endl;
    k=findPrimitive(n);
    v=findz(n-1);
    for(int i=0;i<v.size();i++){
        cout<<power(k,v[i],n)<<endl;
    }
    return 0; 
} 