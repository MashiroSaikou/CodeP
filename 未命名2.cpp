#include <iostream>  
using namespace std;  
int main()  
{  
    int a[10];  
    for(int i=0;i<10;i++)  
        cin>>a[i];  
    for(int i=1;i<10;i++)  
    {  
        if(a[i]>0)  
        {  
            cout<<i;  
            a[i]--;  
            for(int j=0;j<10;j++)  
            {  
                for(int k=0;k<a[j];k++)  
                    cout<<j;  
            }  
            cout<<endl;  
            break;  
        }  
    }  
    return 0;  
}  
