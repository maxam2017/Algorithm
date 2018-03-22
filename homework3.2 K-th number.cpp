#include <iostream>
using namespace std;

long long int a, b, c;

int main()
{
    long long int num;
    cin >> num;
    for(long long int i = 0; i < num; i++)
    {
        long long int total, nth;
        long long int *f;
        f = new long long int[1000000]();

        cin >> total >> nth >> a >> b >> c;
        for(int j = 1; j <= total; j++)
        {
            f[(a*j*j + b*j + c) % 1000000]++;
        }
        long long int accumulation = 0;
        for(int j = 0; j < 1000000; j++)
        {
            accumulation += f[j];
            //cout << accumulation << endl;
            if(accumulation >= nth)
            {
                cout << j << endl;
                break;
            }
        }
        delete [] f;
    }

    return 0;
}