// Write a program to implement brute-force string matching. Analyze its time
// efficiency.
int matcher(char *str,int sz_st,char* substr,int sz_sub){
    int check=0;
    int op=0;
    for(int i=0;i<sz_st;i++){
        op++;
        
        if(str[i]==substr[check]){
            check++;
        }
        else{
            check=0;
        }
        if(check==sz_sub){
            printf("substring present ---> \n");
            return op;
        }
    }
    printf("substring not present \n");
    return op;
}

int main()
{
    char str[]="rudra";
    int sz_st=5;
    int sz_sub=3;
    char sub[]="rue";
    int op=matcher(str,sz_st,sub,sz_sub);
    printf("sz+sub : %d\n",sz_st+sz_sub);
    printf("op : %d",op);
    return 0;
}
