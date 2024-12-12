#include <iostream>
#include <chrono>
#include <cstdio>
using namespace std;

#define LL long long

const int MAXN = 1e5 + 5;
int N, K, a[MAXN], b[MAXN];
bool isOK = true;
int solutionCount = 0; 

void initialize()
{
    for (int i = 1; i <= N; i++)
        a[i] = 1;
}

bool checkSubsetWithSumK()
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
        sum += a[i] * b[i];
    
    if (sum == K) {
        solutionCount++;  
        return true;
    }
    return false;
}

void printCurrentSubset()
{
    for (int i = 1; i <= N; i++)
        if (a[i])
            cout << b[i] << " ";
    cout << endl;
}

void nextSubset()
{
    int i = N;
    while (i > 0 && a[i] == 0)
    {
        a[i] = 1;
        i--;
    }
    if (i > 0)
        a[i] = 0;
    else
        isOK = false;
}

int main()
{
    
            cin >> N;
            for (int j = 1; j <= N; j++) {
                cin >> b[j];
            }
            cin >> K;

            if (N <= 0 || K <= 0) {
                cout << "The input error! Re-enter N>=0, K>=0" << endl;
                
                return 0;
            }

            initialize();

            auto start = chrono::high_resolution_clock::now();
            
            while (isOK)
            {
                if (checkSubsetWithSumK())  
                    printCurrentSubset();   
                nextSubset();
            }

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;

            cout << "The total number of solutions is " << solutionCount << endl;
            cout << "Time to find the solution is: " << duration.count() << " seconds" << endl;

            
        
    

    return 0;
}