// Write a program to sort set of integers using bubble sort. Analyze its time
// efficiency. Obtain the experimental result of order of growth. Plot the result for
// the best and worst case.

int sort(int* arr,int n){
    int temp;
    int flag=0;
    int op=0;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            op++;
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag++;
            }

        }
        if(!flag){
            return op;
        }
    }
    return op;
}
void print(int arr[],int n){
    printf("print array :\n");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
}
int main()
{
    int n=10;
    int arr[]={11,234,56,23,7,234,6,4,2,3};
    print(arr,n);
    int op=sort(&arr,n);
    print(arr,n);

    printf("\nn : %d\nop count = %d",n,op);
    return 0;
}
