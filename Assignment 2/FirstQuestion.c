#include<stdio.h>
#include<stdlib.h>
//Putting size globally for the heap.
void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

//size is nothing but the number of elements in the heap. 
void insertheapify(int arr[], int size, int i)
{
    //Given the index i where the node is inserted. Now we need to check if i's parent is greater
    //than i (Heap property-> parent greater then child.)
    int parent = (i-1)/2;

    
    if(arr[parent] > 0){
        if( arr[i] > arr[parent]){
            swap(&arr[i],&arr[parent]);
            insertheapify(arr, size, parent); 
        }
    }

}

//Taking size as pointer as we are going to change the size value.
void insert(int arr[],int* size, int num){
    
    //increase the size by 1
    *size = *size + 1;

    //place the new element at the end.
    arr[*size-1] = num;

    //heapify from the last element to root.
    insertheapify(arr,*size, *size-1);
}

void deleteheapify(int arr[], int size, int i){

    //Delete heapify starts from root.
    //Initilly 0 for root.
    int max = i;

    //Find left and right child indices
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;

    //Left child and right child values should be less than max index value.If not swap.
    if(leftChild < size && arr[leftChild]>arr[max]){
        max = leftChild; 
    }

    if(rightChild < size && arr[rightChild]> arr[max]){
        max = rightChild;
    }

    //If max index value is not the root, then the swap the root with max index value and heapify
    //recursively down the max index.
    if(max!=i){
        swap(&arr[max],&arr[i]);

        deleteheapify(arr,size, max);
    }

    

}

void delete(int arr[], int*size){

    //Find the last element

    if(*size == 0){
        printf("Heap is empty\n");
        return;
    }

    int l = arr[*size-1];

    //Replace the root with last element.
    arr[0] = l;

    *size = *size-1;

    deleteheapify(arr,*size, 0);

}

void printHeap(int arr[], int size){
    int i =0;
    printf("Heap Elements:\n");
    for(int i =0; i< size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){

    int arr[1000];
    int size = 0;

    while(1){
        int op;
        printf("Max Heap.\n 1. Insert\n 2. Delete\n 3.Print\n");
        scanf("%d",&op);

        switch(op){
            case 1: int key;
                    printf("Please enter the value to be inserted:\n");
                    scanf("%d",&key);
                    insert(arr,&size,key);
                    break;
            case 2: delete(arr,&size);
                    printf("Deleted root from Heap.");
                    break;
            case 3: printHeap(arr,size);
                    break;

            default: exit(1);
        }
    }

    return(0);
}