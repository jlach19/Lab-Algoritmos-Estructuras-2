#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n, ans;
    vector<int> a(100010);
    vector<int> b(100010);

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

    ans = -1;

    for ( int i = 0; i < count; i++)
    {
        int temp = min(b[i] - b[i - 1], b[i + 1] - b[i]);
        ans = max(ans, temp);
    }

    cout << ans * 2 << endl;

    return 0;
}