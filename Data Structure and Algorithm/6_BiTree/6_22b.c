int Find_2 ( MFSst  *SS,  DataType  x)
/* ȷ��x���ڲ��鼯SS���ĸ��Ӽ��ϣ�ͬʱ�����Ӽ�����������߶ȡ����x������SS����һ�Ӽ����򷵻�-1�����������ҵ�x�����Ӽ����ĸ�root��Ȼ��x��x���������ȣ�����root������Ϊroot���ӽ�㣬��󷵻�root�� */
{
    pos=Locate (SS, x);        /* ȷ��x��SS->tree[ ]�е��±� */
    if ( pos<0 )  return -1;      /* ���x������SS����һ�Ӽ����򷵻�-1 */
    i=pos;                   /* ��pos��ʼ������˫��ָ����Ҹ���� */
    while ( SS->tree[i].parent > 0 )  
       i= SS->tree[i].parent ;
    root=i;         /*  ��¼x�����Ӽ����ĸ�����±�  */
    i=pos;         /* ��pos��ʼ����x��x���������ȣ�����root������Ϊroot���ӽ�� */
    while ( i !=root )
   {
      temp= SS->tree[i].parent ;
      SS->tree[i].parent = root;
      i= temp ;
   }
    return  root;              /* ����x�����Ӽ����ĸ�����±� */
}
