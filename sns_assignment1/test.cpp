// CPP program to find the number of
// primitive roots modulo prime
#include <bits/stdc++.h>
using namespace std;

// Function to return the count of
// primitive roots modulo p
vector<int> v;
int countPrimitiveRoots(int p)
{
    int result = 1;
    for (int i = 2; i < p; i++)
        if (__gcd(i, p) == 1)
            v.push_back(i);w
            result++;

    return result;
}

// Driver code
int main()
{
    int p = 113;
    cout<<"no of primitive root:"<<endl;
    cout << countPrimitiveRoots(p - 1)<<endl;
    cout << "primitive roots are " << endl;
    int l = v.size();
    for (int i = 0; i < l; i++)
    {
        cout << v[i]-1 << " ";
    }

    return 0;
}