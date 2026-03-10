#include <stdio.h>

int n;
long long m;
long long array[1000000]; 

int main() {
    scanf("%d %lld", &n, &m);
    long long max_h = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &array[i]);
        if (array[i] > max_h) {
            max_h = array[i];
        }
    }

    long long start = 0;
    long long end = max_h;
    long long result = 0;

    while (start <= end) {
        long long total = 0;
        long long mid = (start + end) / 2;

        for (int i = 0; i < n; i++) {
            if (array[i] > mid) {
                total += (array[i] - mid);
            }
        }
        if (total < m) {
            end = mid - 1;
        }
        else {
            result = mid; 
            start = mid + 1;
        }
    }

    printf("%lld\n", result);

    return 0;
}