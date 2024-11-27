#include<stdio.h>
void linearSearch(int a[], int n , int key){
    int found = 0;
    for (int i = 0; i < n ; i++){
        if(key==a[i]){
            printf("Found at %d",i+1);
            found++;
            break;
        }
    }
    if(found==0){
        printf("Not Found");
    }
}
int main(){
    int array[] = {1,30,5,59,35,76,7,5,4};
    linearSearch(array,9,35);
    return 0;
}