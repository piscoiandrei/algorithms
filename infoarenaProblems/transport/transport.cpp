// https://infoarena.ro/problema/transport
#include <fstream>
std :: ifstream in("transport.in");
std :: ofstream out("transport.out");

#define N 16000

unsigned v[N+1], n, k, s, mx;

void read()
{
    in >> n >> k;
    for(unsigned i = 0; i < n; i++)
    {
        in >> v[i];
        if (v[i] > mx)
            mx = v[i];
        s += v[i];
    }
}

void solve()
{
    unsigned l = mx, r = s, min_cap = s+1, cap;
    while(l <= r)
    {
        cap = (l+r)/2;
        unsigned i = 0, j = 0;
        bool complete = false;
        for(; i < k && !complete; i++)
        {
            unsigned load = 0;
            for(; j < n; j++)
                if(load+v[j] <= cap)
                    load+=v[j];
                else
                    break;
            if(j == n)
                complete = true;
        }

        if(!complete)
            l = cap+1;
        else{
            if(min_cap > cap)
                min_cap = cap;
            r = cap-1;
        }
    }
    out<<min_cap;
}

int main()
{
    read();
    solve();
}
