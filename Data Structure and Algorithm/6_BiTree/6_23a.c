int Merge_1 ( MFSst  *SS,  int  root1,  int  root2 )
/* root1��root2�ǲ��鼯SS�����������ཻ�ķǿ��Ӽ����ĸ������Ӽ���root2�����Ӽ���root1��*/
{
   if ( root1<0 || root1> SS->nodenum-1 ) 
        return  ERROR;
   if ( root2<0 || root2> SS->nodenum-1 )  
        return  ERROR;
   SS->tree[root2].parent=root1;
   return OK;
}
