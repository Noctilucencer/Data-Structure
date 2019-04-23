//
//  main.c
//  BinarySearchTree
//
//  Created by AomineDaiki on 2019/4/23.
//  Copyright © 2019 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//Create a binary tree Node
typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node* lchild;
    struct node* rchild;
}bt;
//create a binary search tree
bt* CreateBinarySearchTree(bt*root,ElemType data);
void preOrderTravseral(bt*root);//先序遍历

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    int a;
    bt* root = NULL;
    while(~scanf("%d",&a))
    {
        root = CreateBinarySearchTree(root, a);
    }
    preOrderTravseral(root);
    printf("\n");
    return 0;
}
//create a binary search tree
bt* CreateBinarySearchTree(bt*root,ElemType data)
{
    if(root == NULL)
    {
        root = (bt*)malloc(sizeof(bt));
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        return root;
    }
    if(root->data > data)
       root->lchild = CreateBinarySearchTree(root->lchild, data);
    else if(root->data == data)
        return root;
    else
        root->rchild=CreateBinarySearchTree(root->rchild, data);
    return root;
}
void preOrderTravseral(bt*root)//先序遍历
{
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preOrderTravseral(root->lchild);
    preOrderTravseral(root->rchild);
    
}
