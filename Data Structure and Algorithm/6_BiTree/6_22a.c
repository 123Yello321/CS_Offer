int Find_1 ( MFSst  *SS,  DataType  x)
/* ȷ��x���ڲ��鼯SS���ĸ��Ӽ��ϡ����������SS����һ�Ӽ����򷵻�-1�����򷵻������Ӽ����ĸ�����±ꡣ*/
{
    pos=Locate (SS, x);        /* ȷ��x��SS->tree[ ]�е��±� */
    if ( pos<0 )  return -1;      /* ���x������SS����һ�Ӽ����򷵻�-1 */
    i=pos;                   /* ��pos��ʼ������˫��ָ����Ҹ���� */
    while(SS->tree[i].parent > 0 )  
        i= SS->tree[i].parent ;
    return  i;                /* ����x�����Ӽ����ĸ�����±� */
}
