void Initialization ( MFSst  *SS,  SeqList  *S)
/* ��S�е�n��Ԫ�ع���n��������������n����Ԫ�ؼ���S0��S1������Sn-1����n������������һ��ɭ�֣������鼯SS  */
{ 
    int i;
    SS->nodenum=S->last+1;
    for(i=0;  i<SS->nodenum;  i++)
    { 
       SS->tree[i].data= S->elem[i];
       SS->tree[i].parent= -1;
    }
}
