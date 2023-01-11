#include <stdio.h>
#include <gmp.h>
// Function to return the count of
// primitive roots modulo p
int get_gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int countPrimitiveRoots(int p)
{
    int result = 1;
    for (int i = 2; i < p; i++)
        if (get_gcd(i, p) == 1)
        {
            result++;
        }

    return result;
}

// Driver code
int main()
{
    int p = 113;
    int ans= countPrimitiveRoots(p - 1);
    return 0;
}
