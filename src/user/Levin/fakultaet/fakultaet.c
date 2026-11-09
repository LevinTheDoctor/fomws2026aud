#include <stdio.h>
#include <time.h>

int factr(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factr(n - 1);
    }
}

int facti(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        int fact = 1;
        for (int i = 1; i <= n; i++)
        {
            fact = fact * i;
        }
        return fact;
    }
}

void benchmarkFactCaller(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    int n = 5;
    printf("Starting factorial benchmark ... \n");

    clock_t t_start, t_stop;
    double runtime;

    t_start = clock();
    printf("Recursive: %i\n", factr(n));
    t_stop = clock();
    runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
    printf("Runtime %lf for factr alg \n", runtime);

    t_start = clock();
    printf("Iterative: %i\n", facti(n));
    t_stop = clock();
    runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
    printf("Runtime %lf for facti alg \n", runtime);
}

int main(void)
{
    // Call recursive and iterative implementation
    // Add some nice output here ...
    factr(5);
    facti(5);

    // Calls benchmark
    benchmarkFactCaller();
}
