#include<stdio.h>
int binarySearch(int a[] , int n , int key){
    int l = 0;
    int r = n-1;
    while(l<r){
        int mid = (l+r)/2;
        if(key==a[mid]){
            return mid+1;
        }
        else if(key>a[mid]){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1;
}
int main(){
    int array[] = {10,20,30,40,50,60,70,80}; 
    int result = binarySearch(array,8,60);
    if(result == -1){
        printf("Not in the array");
    }
    else{
        printf("The result found in %d",result);
    }
    return 0;
}