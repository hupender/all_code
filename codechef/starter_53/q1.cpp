#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int a[n],b[n];
	    long sum1=0,sum2=0;
	    for(int i=0;i<n;i++) {
	        cin>>a[i];
	        sum1+=a[i];
	    }
        cout<<"sum of array a is "<<sum1<<endl;
	    for(int i=0;i<n;i++) {
	        cin>>b[i];
	        sum2+=b[i];
	    }
        cout<<"sum of array b is "<<sum2<<endl;
	    int count=0;
	    if(sum1!=sum2) {
	        cout<<"-1"<<endl;
	    }
	    else {
	        for(int i=0;i<n-1;i++) {
	            if(a[i]<b[i]) {
	                for(int j=i+1;j<n;j++) {
	                    if(b[j]<a[j]) {
	                        b[j]++;
	                        a[i]++;
	                        count++;
	                        break;
	                    }
	                }
	            }
	            if(b[i]<a[i]) {
	                for(int j=i+1;j<n;j++) {
	                    if(a[j]<b[j]) {
	                        a[j]++;
	                        b[i]++;
	                        count++;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    cout<<count<<endl;
	    
	}
	return 0;
}
