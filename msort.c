#include <stdio.h>



void join(int *arr, int *final, int start, int mid, int end) {
    int k = start, i=start, j=mid;
    while (k <= end) {
        if (arr[i] < arr[j]) {
            final[k] = arr[i];
            k++;
            i++;
        }
        else {
            final[k] = arr[j];
            k++;
            j++;
        }
        if (i == mid) {
            while (j <= end){
                final[k] = arr[j];
                j++;
                k++;
            }
        }
        if (j == end+1) {
            while (i < mid) {
                final[k] = arr[i];
                i++;
                k++;
            }
        }
    }
    for (i=start; i<=end; i++)
        arr[i] = final[i];
    /*for (i=0; i<9; i++)*/
        /*printf("%d ", final[i]);*/
    /*printf("\n join end on %d %d %d\n", start, mid, end);*/
}

void merge (int *arr, int *final, int start, int end) {
    printf("merge in %d %d\n", start, end);
    if (start == end)
        return; 
    int mid = (start + end)/2;
    merge(arr, final, start, mid);
    merge(arr, final, mid+1, end);
    join(arr, final, start, mid+1, end);
}

int main(){
    int arr[9] = {17, 3, 5, 15, 10, 12, 8, 6, 1};
    int fin[9] = {0}, i;
    merge(arr, fin, 0, 8);
    for (i=0; i<9; i++)
        printf("%d ", fin[i]);
    printf("\n");
    return 0;
}
