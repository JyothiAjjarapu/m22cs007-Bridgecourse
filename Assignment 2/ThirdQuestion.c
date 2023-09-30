//Converting Max heap to min heap is nothing but min heapifying an input array.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool CheckParentLessThanChild(int arr[], int size, int i){
    int smallest = i;
    int leftChild = i*2+1;
    int rightChild = i*2+2;

    if(leftChild < size && arr[leftChild]< arr[smallest]){
        smallest = leftChild;
    }

    if(rightChild < size && arr[rightChild] < arr[smallest]){
        smallest = rightChild;
    }

    if(smallest!=i){
        return false;
    }

    return true;

}

bool isMinHeap(int arr[], int size){
    
    int lastParent = (size-2)/2;

    for(int i=lastParent; i>=0; i--){
        if(!CheckParentLessThanChild(arr,size,i)){
            return false;
        }
    }

    return true;

}

void printHeap(int arr[], int size){
    int i;
    printf("HeapElements:\n");
    for(int i =0; i <size; i++){
        printf("%d ",arr[i]);
    }

    printf("\n");
}
int main(){
    int arr[1000] = {1,2,3,5,4,10,6};
    int size = 7;

    bool IsMin = isMinHeap(arr,7);

    if(IsMin)
    {
        printf("Heap is MinHeap");
    }
    else{
        printf("Heap is Not MinHeap");
    }

    
    
}