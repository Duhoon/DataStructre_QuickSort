//
//  main.c
//  QuickSort
//
//  Created by duh8n on 2021/07/23.
//

#include <stdio.h>

void swap(int arr[], int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right){
    int high = right;
    int low = left + 1 ;
    int pivot = left;
    
    while(high >= low){ // low 가 high를 지나치게 하거나 high가 low를 지나쳐야 한다.
        //high가 pivot을 가리켜야 할 순간이 생기기 때문이다.
        if(arr[low] > arr[pivot] && arr[high] < arr[pivot]){
            swap(arr, low, high);
            low++; high--;
        }
        
        // 열혈 자료구조와는 다르게 배열에 수가 같은 것이 있을 떄를 대비한 조건문
        if(arr[low] <= arr[pivot]) low++;
        if(arr[high] >= arr[pivot]) high--;
    }
    
    return high;
}

// 재귀적 함수 사용
void QuickSort(int arr[], int left, int right){
    int pivot;
    
    if(left<right){
        pivot = Partition(arr, left, right);
        swap(arr, left, pivot);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}


int main(int argc, const char * argv[]) {
    int arr[9] = {3, 3, 3, 2, 5, 5, 9, 6, 3};
    
    QuickSort(arr, 0, 8);
    
    for(int i = 0 ; i < sizeof(arr)/sizeof(int) ; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}
