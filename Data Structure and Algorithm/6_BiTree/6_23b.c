int Merge_2 ( MFSst  *SS,  int  root1,  int  root2 )
/* root1��root2�ǲ��鼯SS�����������ཻ�ķǿ��Ӽ����ĸ���������parent�������н����Ŀ�ĸ�ֵ�����㷨�������Ŀ���ٵ��Ӽ�����������Ŀ�϶���Ӽ�����*/
{
    if ( root1<0 || root1> SS->nodenum-1 )  return  ERROR;
    if ( root2<0 || root2> SS->nodenum-1 )  return  ERROR;
    if ( SS->tree[root1].parent < SS->tree[root2].parent )  /* ��һ���Ӽ����н����Ŀ�϶� */
    {  
        SS->tree[root2].parent=root1;
        SS->tree[root1].parent+= SS->tree[root2].parent ;
     }
    else  /* �ڶ����Ӽ����н����Ŀ�϶� */
    {  
        SS->tree[root1].parent=root2;
        SS->tree[root2].parent+= SS->tree[root1].parent ;
     }
    return OK;
}
