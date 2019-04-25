//
//  main.c
//  简单遍历二叉树（数组）
//
//  Created by AomineDaiki on 2019/4/23.
//  Copyright © 2019 Mac. All rights reserved.
//

#include <stdio.h>
typedef char ElemType;
typedef struct node
{
    int lchild;
    int rchild;
    ElemType data;
}bt;

void preOrder(bt p,bt root[]);
void inOrder(bt p,bt root[]);
void postOrder(bt p,bt root[]);

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    int a;
    scanf("%d",&a);
    bt tree[a+1];
    int b,c;
    char ch;
    for(int i = 1;i <= a;i++)
    {
        scanf("\n%c %d %d",&ch,&b,&c);
            tree[i].lchild = b;
            tree[i].rchild = c;
            tree[i].data = ch;
    }
    preOrder(tree[1],tree);
    printf("\n");
    inOrder(tree[1],tree);
    printf("\n");
    postOrder(tree[1],tree);
    printf("\n");
    return 0;
}
void preOrder(bt p,bt root[])
{
    if(p.data == root[0].data)
        return;
    printf("%c",p.data);
    preOrder(root[p.lchild], root);
    preOrder(root[p.rchild], root);
    
}
void inOrder(bt p,bt root[])
{
    if(p.data == root[0].data)
        return;
    inOrder(root[p.lchild], root);
    printf("%c",p.data);
    inOrder(root[p.rchild], root);
}
void postOrder(bt p,bt root[])
{
    if(p.data == root[0].data)
        return;
    postOrder(root[p.lchild], root);
    postOrder(root[p.rchild], root);
    printf("%c",p.data);
}
