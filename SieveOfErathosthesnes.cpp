
// note N can be at most 10^7
// TC =O(NloglogN)
const int N = 10000000;
vector<bool> prime(N + 1, true);
void SieveOfErathosthesnes()
{
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (prime[i] && (long long)i * i <= N)
        {
            for (int j = i * i; j < N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

void solve(int tc = 0)
{
    SieveOfErathosthesnes();
}
