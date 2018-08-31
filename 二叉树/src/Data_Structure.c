/*
 * Data_Structure.c
 *
 *  Created on: Aug 31, 2018
 *      Author: lrh
 */
#include <stdio.h>
#include <BTree.h>

int main()
{
	BTree *root = NULL,*node = NULL;
	char data = '/';
	printf("input BTree data char\n");

	root = createBinTree(root);//创建二叉树

	printf("先序遍历顺序为：\n\t");
	Preorder(root,display);//先序遍历
	printf("\n");
	printf("中序遍历顺序为：\n\t");
	Inorder(root,display);//中序遍历
	printf("\n");
	printf("后序遍历顺序为：\n\t");
	Postorder(root,display);//后序遍历
	printf("\n");

	node = getLchild(root,data);//找左孩子
	if(node)
		printf("节点 ‘%c’ 左孩子为 ‘%c’ \n",data,node->data);
	node = getRchild(root,data);//找右孩子
	if(node)
		printf("节点 ‘%c’ 右孩子为 ‘%c’ \n",data,node->data);
	return 0;
}



