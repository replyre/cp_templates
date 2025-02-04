#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)

// freopen('input.txt', 'r', stdin);
// freopen('output.txt', 'w', stdout);

// recursion is function calling itself
// works like stack;
// basic example print no 1 to 10

void print1ton(int n)
{
    if (n == 0)
        return;
    // put the value in rec memory stack
    print1ton(n - 1);
    // remove the value from the stack;
    cout << n << " ";
}

void printnto1(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printnto1(n - 1);
}
int cnt = 0;

int fib(int n)
{
    if (n == 0)
    {

        return 0;
    }
    if (n == 1)
    {

        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>>_t; while(_t--)
    // print1ton(10);
    // cout << endl;
    // printnto1(10);
    cout << fib(6);
    return 0;
}