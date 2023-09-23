#include <stdio.h>
#include<bits/stdc++.h>
#include <stdlib.h>
#include <omp.h>
using namespace std;
#define MAX_SIZE 1000000

int arr[MAX_SIZE];

int find_min(int start, int end) {
    if (start == end) {
        return arr[start];
    }
    int mid = start + (end - start) / 2;
    int left_min, right_min;
#pragma omp sections
    {
#pragma omp section
        {
            left_min = find_min(start, mid);
        }
#pragma omp section
        {
            right_min = find_min(mid + 1, end);
        }
    }
    return left_min < right_min ? left_min : right_min;
}

int find_max(int start, int end) {
    if (start == end) {
        return arr[start];
    }
    int mid = start + (end - start) / 2;
    int left_max, right_max;
#pragma omp parallel sections
    {
#pragma omp section
        {
            left_max = find_max(start, mid);
        }
#pragma omp section
        {
            right_max = find_max(mid + 1, end);
        }
    }
    return left_max > right_max ? left_max : right_max;
}

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int min_val1=INT_MAX,max_val1=INT_MIN;
    double serial_start=omp_get_wtime();
    for(int i=0;i<n;i++) {
        min_val1=min(min_val1,arr[i]);
        max_val1=max(max_val1,arr[i]);
    }
    double serial_end_time=omp_get_wtime();
    printf("serial time : %f",serial_end_time-serial_start);
    // cout<<"serial_time = "<<<<endl;
    double start_time = omp_get_wtime();
    int min_val = find_min(0, n - 1);
    double end_time = omp_get_wtime();
    printf("Minimum value: %d\n", min_val);
    printf("Time taken: %f seconds\n", end_time - start_time);
    start_time = omp_get_wtime();
    int max_val = find_max(0, n - 1);
    end_time = omp_get_wtime();
    printf("Maximum value: %d\n", max_val);
    printf("Time taken: %f seconds\n", end_time - start_time);
    return 0;
}