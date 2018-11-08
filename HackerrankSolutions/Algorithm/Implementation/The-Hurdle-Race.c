#include <stdio.h>
#include <stdlib.h>

int hurdleRace(int k, int height_size, int* height) {
    int i, max = 0;
    for( i = 0; i < height_size; i++ )
    {
        if( height[i] > max )
            max = height[i];
    }
    if ( k > max )
        return 0;
    else
        return max - k;
}

int main() {
    int n; 
    int k; 
    scanf("%i %i", &n, &k);
    int *height = malloc(sizeof(int) * n);
    for (int height_i = 0; height_i < n; height_i++) {
       scanf("%i",&height[height_i]);
    }
    int result = hurdleRace(k, n, height);
    printf("%d\n", result);
    return 0;
}
