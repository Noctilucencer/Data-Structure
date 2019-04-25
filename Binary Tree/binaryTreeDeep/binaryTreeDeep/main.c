#include <stdio.h>

typedef struct _node
{
    int left;
    int right;
}node;

void traversal(int root);
int curHeight, maxHeight;
node myTree[11];

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &myTree[i].left, &myTree[i].right);
    }
    traversal(1);
    printf("%d\n", maxHeight);
    return 0;
}

void traversal(int root)
{
    if (root == -1)
        return;
    curHeight++;
    if (myTree[root].left == -1 && myTree[root].right == -1)
    {
        if (curHeight > maxHeight)
            maxHeight = curHeight;
    }
    traversal(myTree[root].left);
    traversal(myTree[root].right);
    curHeight--;
}
