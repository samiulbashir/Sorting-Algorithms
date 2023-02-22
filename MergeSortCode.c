#include<stdio.h>

int n; //Array size globally decleared

void Marge(int a[], int l, int mid, int r)
{
    int temp[n];
    int i = l, j = mid+1, k = l;
    while(i <= mid && j <= r){
        if(a[i] > a[j]){
            temp[k++] = a[j++];
        }
        else{
            temp[k++] = a[i++];
        }
    }
    while(i <= mid){
        temp[k++] = a[i++];
    }
    while(j <= r){
        temp[k++] = a[j++];
    }

    i = l;
    while( i <= r){
        a[i] = temp[i];
        i++;   
    }

}

void MargeSort(int a[], int l, int r)
{
    if(l < r){
        int mid = (l+r)/2;
        MargeSort(a, l, mid);
        MargeSort(a, mid+1, r);
        Marge(a, l, mid, r);
    }

}
int main()
{
    int i, a[1000];
    printf("Array size: ");
    scanf("%d", &n);
    printf("Array elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    MargeSort(a, 0, n-1);

    printf("After Sorting: ");
    for(i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    return 0;
}
