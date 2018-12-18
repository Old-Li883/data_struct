/*****************************************************
FILENAME:ensure_tree.cpp
DESCRIPTION:This file contains functions which solve
            can create tree by giving Preorder_traversal
AUTHOR:Chenhao Li
REVISION HISTORY:
    Initial version - 2018/12/17
*****************************************************/

#include "tree.h"

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef SUCCESS
#define SUCCESS (-1)
#endif

tAddr createRightTree(char *fir, char *middle, int f_index, int start, int end);

tAddr createLeftTree(char *fir, char *middle, int f_index, int start, int end) // start与end均是在中序数组中的值
{
    char ele = fir[f_index];
    tAddr p = createTreeNode(ele);
    if (start == end)
    {
        f_index += 1;
        return p;
    }
    int index;
    for (index = start; index <= end; index++)
    {
        if (ele == middle[index]) // 此处应该有找不到的判断
        {
            break;
        }
    }
    tAddr lt = NULL, rt = NULL;
    if (!(index == start))
    {
        // (*f_index) += 1;
        lt = createLeftTree(fir, middle, f_index, start, index - 1); // 建立左子树
    }
    // if (!(index == end))
    // {
    //     (*f_index) += 1;
    //     rt = createLeftTree(fir, middle, f_index + 1, index + 1, end); // 建立右子树
    // }
    p->left = lt;
    p->right = rt;
    return p;
}

int main(int argc, char const *argv[])
{
    tAddr t;
    int *f_index;
    int j = 0;
    f_index = &j;
    char first_array[7] = {'1', '2', '4', '5', '6', '3', '7'};
    char mid_array[7] = {'4', '2', '6', '5', '1', '3', '7'};
    t = createLeftTree(first_array, mid_array, 0, 0, 6);
    first(t);
    printf("\n");
    // mid(t);
    printf("\n");
    // last(t);
    printf("\n");
    // layer(t);
    return 0;
}