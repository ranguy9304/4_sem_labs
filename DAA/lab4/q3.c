
#include <stdio.h>
#include <stdlib.h>
typedef struct node* node_ptr;
typedef struct node
{
    int key;
    
    node_ptr *links;
    int no_links
}node;


node_ptr init_node(int no_vert,int val){
    node_ptr node = (node_ptr)malloc(sizeof(node));
    node->key=val;
    int links;
    printf("enter the number of connections for [ %d ] : ",val);
    scanf("%d",&links);
    if(links>=no_vert){
        printf("ERR : links not possible : enter within range [ 0 - %d ]\ntry again :",no_vert-1);
        scanf("%d",&links);
    }
    node->no_links=links;
    node->links=(node_ptr*)malloc(links*sizeof(node_ptr));

    return node;

}
void connect(node_ptr node,node_ptr *lookup,int no_vert){
    int ver;
    int count=0;
    printf("\n\n#####  %d  ######\n",node->key);
    printf("Enter links in ascending order \n");
    printf("which are the linked vertices : [ no links = %d ]\n",node->no_links);
    for(int i=0;i<node->no_links;i++){
        scanf("%d",&ver);
        if(ver>=no_vert){
            printf("ERR : vertice entered incorectly enter within range [ 0 - %d ]\ntry again ",no_vert-1);
            scanf("%d",&ver);}

        node->links[count]=lookup[ver];
        count++;
    }

}
node_ptr* make_lookup(int no_vert){
    node_ptr node;
    node_ptr *lookup=(node_ptr*)malloc(no_vert*sizeof(node_ptr));


    for(int i=0;i<no_vert;i++){
        node=init_node(no_vert,i);
        lookup[i]=node;
    }
    return lookup;

}
void print_links(node_ptr n){
    printf("------ links for [ %d ] ------ \n",n->key);
    for(int i =0 ;i< n->no_links;i++){
        printf(" %d ",n->links[i]->key);
    }
    printf("\n");
}

int g[100][100];
int V;
int visited[100];
void print_matrix(node_ptr* lookup,int no_vert){
    printf("\n*****  ADA MATRIX *****\n");
    int count =0;
    for(int i=0;i<no_vert;i++){
        count=1;
        for(int j=0;j<no_vert;j++){
            if(lookup[i]->no_links==0){
                continue;
            }
            if(lookup[i]->links[count-1]->key == j){
                g[i][j]=1;
                printf(" 1 ");
                if(lookup[i]->no_links>count)
                    count++;
            }
            else{
                g[i][j]=1;

                printf(" 0 ");
            }
                        
        }
    printf("\n");
    }
    

}



int queue[100], f = 0, r = 0;

void enqueue(int v)
{
	queue[r++] = v;
}

int dequeue()
{
	if(f == r)
	{
		return -1;
	}
	
	return queue[f++];
}

void bfsv(int v)
{
	printf("Visiting %d\n", v);
	visited[v] = 1;
	
	int i;
	
	for(i = 0; i < V; ++i)
	{
		if(!visited[i] && g[v][i] && i != v)
		{
			enqueue(i);
		}
	}
}

void bfs()
{
	int i, x;
	enqueue(0);
	
	do
	{
		x = dequeue();
		
		if(x != -1 && !visited[x])
		{
			bfsv(x);
		}
	}while (x != -1);
}

void main(){
    int no_vert=4;
    V=4;
    printf(" the existing vertices are \n");
    for(int i=0;i<no_vert;i++){
        printf(" %d ",i);
    }
    printf("\n");
    node_ptr *lookup=make_lookup(no_vert);
    for(int i=0;i<no_vert;i++){
        connect(lookup[i],lookup,no_vert);
    }
    for(int i=0;i<no_vert;i++){
        print_links(lookup[i]);
    }
    print_matrix(lookup,no_vert);
    bfs();
}
