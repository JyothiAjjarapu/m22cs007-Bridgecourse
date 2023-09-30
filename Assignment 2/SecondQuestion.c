//Converting Max heap to min heap is nothing but min heapifying an input array.
#include<stdio.h>
#include<stdlib.h>

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int i){
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
        swap(&arr[smallest],&arr[i]);
        heapify(arr,size,smallest);
    }
}

void convertMaxToMinHeap(int arr[], int size){
    
    int lastParent = (size-2)/2;

    for(int i=lastParent; i>=0; i--){
        heapify(arr,size,i);
    }

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
    int arr[1000] = {10,5,6,2,4,3,1};
    int size = 7;

    convertMaxToMinHeap(arr,size);

    printHeap(arr,size);
    
}