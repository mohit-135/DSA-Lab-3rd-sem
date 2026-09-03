#include <stdio.h>

void merge(int low,int mid,int high,int arr[]){
    int n1=mid-low+1;
    int n2=high-mid;
    
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=arr[mid+1+i];
    }
    
    //merging into the origingal 
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    
    while(i<n1){
        arr[k]=left[i];
        i++,k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++,k++;
    }
    
    
}

void divide(int low,int high,int arr[]){
    int mid=(low+high)/2;
    if(low<high){
        divide(low,mid,arr);
        divide(mid+1,high,arr);
        merge(low,mid,high,arr);
    }
}


int main(){
    int arr[4]={20,40,10,5};
    int size=4;
    divide(0,size-1,arr);
    
    printf("Array after sorting is:");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
    
}