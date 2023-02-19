

#include <stdio.h>
#include <math.h>
int count=-1;

void printPowerSet(int *set, int set_size,int *sqp)
{
    
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
    int sum=0;
 
    for(counter = 0; counter < pow_set_size; counter++)
    {
        sum=0;
        count++;
      for(j = 0; j < set_size; j++)
       {
       
          if(counter & (1<<j)){
            printf("-->%d", set[j]);
            sum=sum+set[j];}
       }
       sqp[count]=sum;
       printf("\n%d\n",sum);
       
    }
}
void printSpecPowerSet(int *set, int set_size,int index,int index2)
{
        count=0;

    unsigned int pow_set_size = pow(2, set_size);
    int counter,j;
    
    for(counter = 0; counter < pow_set_size; counter++)
    {
        count++;
      for(j = 0; j < set_size; j++)
       {
        
            if(count==index || count==index2){

       
          if(counter & (1<<j)){
            printf("-->%d", set[j]);
            }
            }
       }
       printf("\n");
       
    }
}
 
 
int main()
{
    int set[] = {1,2,3,4};
    int n=4;
    int comb=pow(2,n);
    int sqp[comb];
    printPowerSet(set, n,&sqp);
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+set[i];
        
    }
   
    int flag=0;
    
    printf("sum /2 : %d\n",sum);
    int indx[2];
    for(int i=0;i<pow(2,n);i++){
        if(flag==2){
            printf("partitions found\n");
            break;
            
        }
        else if(sqp[i]==sum/2){
            indx[flag]=i;
            flag++;
            printf("\ndiv exists\n");
        }
    }
    printf("index : %d index 2 : %d",indx[0],indx[1]);
    printSpecPowerSet(set, n,indx[0]+1,indx[1]+1);
    
    return 0;
}