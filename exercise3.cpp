#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, res;
int a[N], b[N];

int main()
{
    cin >> n;
    
    for ( int i = 0; i < n; i++ )
    {
        cin >> a[i];
    }

    b[0] = 0;

    int count = 1;

    for ( int i = 1; i < n; i++ )
    {
        if ( a[i - 1] != a[i] )
        {
            b[count++] = i;
        }
    }

    b[count] = n;

    res = -1;

    for ( int i = 0; i < count; i++)
    {
        int temp = min(b[i] - b[i - 1], b[i + 1] - b[i]);
        res = max(res, temp);
    }

    cout << res * 2 << endl;

    return 0;
}
