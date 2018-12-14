#include "sequance.h"

sequance::sequance()
{
    //ctor
}
//////////////////////////////////////////////////////////////////////////
sequance::sequance(sequance& rhs) // copy constructor
{
    seq = rhs.seq;
}
//////////////////////////////////////////////////////////////////////////
string sequance::Align( sequance * s2)
{
    string s;
    int m = seq.length();
    int n = s2->seq.length();
    int L[m+1][n+1];
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (seq[i-1] == s2->seq[j-1])
                {
                    L[i][j] = L [i-1] [j-1] + 1;
                }
            else
                L[i][j] = max( L[i-1][j], L[i][j-1] );
        }
    }

    int lcs = L[m][n];    // getting the number of chars

    while( m != 0 && n != 0)    // getting the chars
    {
        if (seq[m-1] == s2->seq[n-1])
        {
            s+= seq[m-1];
            lcs-=1;
            m-=1;
            n-=1;
        }
        else if (L[m - 1][n] > L[m][n - 1]) {
			m--;
		}
		else {
			n--;
		}
    }
    return s;
}
//////////////////////////////////////////////////////////////////////////
sequance::~sequance()
{
    //dtor
}
