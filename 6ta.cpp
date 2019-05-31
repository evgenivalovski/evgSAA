#include <stdio.h>
#include <stdlib.h>

void recursivePrinting(int* arr, int* subseqIdx, int index){
    int nextIndex = subseqIdx[index];

    if (subseqIdx[nextIndex] == -1) {
        printf("%d ", arr[nextIndex]);
        printf("%d ", arr[index]);
        return;
    }
    recursivePrinting(arr,subseqIdx, nextIndex);
    printf("%d ", arr[index]);
}

int getMaxElement(int* arr, int size){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int getIndexOfMax(int* arr, int size){
    int max = arr[0], index = 0;
    for(int i = 1; i < size; i++){
        if (max < arr[i]) {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

void longestDecrSeq(int* arr, int* subseqIdx, int size){
    int startIndex = getIndexOfMax(subseqIdx,size);
    recursivePrinting(arr,subseqIdx, startIndex);
}

int main(){
    int arr[] = {9, 8, 40, 5, 30, 2, 1};
    int size = sizeof(arr)/sizeof(int);
    int arrCountDecrSubseq[size];
    int arrForIndexs[size];

    for(int i = 0; i < size; i++){
        arrCountDecrSubseq[i] = 1;
        arrForIndexs[i] = -1;
    }

    for (int i = 1; i < size; i++) {
        for(int j = 0; j < i; j++){
            if (arr[j] > arr[i]) {
                int currentLenght = arrCountDecrSubseq[i];
                int newLenght = arrCountDecrSubseq[j]+1;
                if (currentLenght > newLenght) {
                    arrCountDecrSubseq[i] = currentLenght;
                } else {
                    arrCountDecrSubseq[i] = newLenght;
                    arrForIndexs[i] = j;
                }
            }
        }
    }

    for(int x = size - 1, i=0; x >= 0; x--){
        if(arrCountDecrSubseq[x] != 1){
            printf("Subsequence %d length = %d \n",i++, arrCountDecrSubseq[x]);
        }
    }
    
    printf("\n The longest decreasing subsequence length is: %d\n", getMaxElement(arrCountDecrSubseq,size));
    printf("\n The longest decreasing subsequence: ");
    longestDecrSeq(arr,arrForIndexs,size);
    printf("\n");

    return 0;
}
