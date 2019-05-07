//
//  main.c
//  AVL Tree
//
//  Created by AomineDaiki on 2019/5/2.
//  Copyright © 2019 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct node{
    int average;
    struct node *left;
    struct node *right;
    ElementType data;
}node,*AVLTree;
AVLTree creatAVLTree(AVLTree root,ElementType data);
int maxHeight(int a,int b);
int treeHeight(AVLTree T);
AVLTree leftSingleRotation(AVLTree T);
AVLTree rightSingleRotation(AVLTree T);
AVLTree left_rightDoubleRotation(AVLTree T);
AVLTree right_leftDoubleRotation(AVLTree T);
void inOrderTraversal(AVLTree root);

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    int num;
    AVLTree root = NULL;
    scanf("%d",&num);
    while(num != -1){
        root = creatAVLTree(root, num);
        scanf("%d",&num);
    }
    inOrderTraversal(root);
    printf("\n");
    printf("%d\n",root->data);
    printf("%d\n",treeHeight(root));
    return 0;
}
AVLTree creatAVLTree(AVLTree root,ElementType data)
{
    if(root == NULL)
    {
        root = (AVLTree)malloc(sizeof(node));
        root->left = root->right = NULL;
        root->data = data;
        root->average = 1;
    }
    else if(root->data > data)
    {
        root->left = creatAVLTree(root->left, data);
        if(treeHeight(root->left)-treeHeight(root->right) == 2){
            if(data < root->left->data)
                root = leftSingleRotation(root);
            else
                root = left_rightDoubleRotation(root);
        }
    }
    else if(root->data < data)
    {
        root->right = creatAVLTree(root->right, data);
        if(treeHeight(root->left)-treeHeight(root->right) == -2){
            if(data > root->right->data)
                root = rightSingleRotation(root);
            else
                root= right_leftDoubleRotation(root);
        }
    }
    root->average = maxHeight(treeHeight(root->left), treeHeight(root->right))+1;
    return root;
    
}
int maxHeight(int a,int b)
{
    return a>b?a:b;
}
int treeHeight(AVLTree T)
{
    if(T == NULL)
        return 0;
    int leftHeight = treeHeight(T->left);
    int rightHeight = treeHeight(T->right);
    return (maxHeight(leftHeight, rightHeight)+1);
}
AVLTree leftSingleRotation(AVLTree T)
{
    AVLTree B = T->left;
    T->left = B->right;
    B->right = T;
    T->average = maxHeight(treeHeight(T->left), treeHeight(T->right))+1;
    B->average = maxHeight(treeHeight(T->left), T->average)+1;
    return B;
}
AVLTree rightSingleRotation(AVLTree T)
{
    AVLTree B = T->right;
    T->right = B->left;
    B->left = T;
    T->average = maxHeight(treeHeight(T->left), treeHeight(T->right))+1;
    B->average = maxHeight(treeHeight(T->left), T->average)+1;
    return B;
}
AVLTree left_rightDoubleRotation(AVLTree T)
{
    T->left = rightSingleRotation(T->left);
    return leftSingleRotation(T);
}
AVLTree right_leftDoubleRotation(AVLTree T)
{
    T->right = leftSingleRotation(T->right);
    return rightSingleRotation(T);
}
void inOrderTraversal(AVLTree root)
{
    if(root == NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);
}
