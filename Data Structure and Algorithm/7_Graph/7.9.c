int pre[];
void one_path(Graph *G, int u, int v)
/*����ͨͼG����һ���ӵ�u�����㵽v������ļ�·��*/
{
	int i;
    	pre=(int *)malloc(G->vexnum*sizeof(int));
    	for(i=0;i<G->vexnum;i++) 
    		pre[i]=-1;
    	pre[u]=u;               /*��pre[u]��Ϊ��-1����ʾ��u�������ѱ�����*/
    	DFS_path(G, u, v);       /*���������������һ����u��v�ļ�·����*/
    	free(pre);
}

int DFS_path(Graph *G, int u, int v)
  /*����ͨͼG���������������������һ����u��v�ļ�·����*/
{
	int j;
        	for(j=firstadj(G,u);j>=0;j=nextadj(G,u,j))
             		if(pre[j]==-1)
		          {
                  		pre[j]=u;
                  		if(j==v) 
                  		      {print_path(pre ,v); return 1;}/*���·��*/
                  		else 
                  		      if(DFS_path(G,j,v))  return 1; 
              	          }
               return 0;
}
