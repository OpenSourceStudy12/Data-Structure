#include <BTree.h>
#include <stdio.h>
#include <stdlib.h>

//创建二叉树(先序遍历)
BTree *createBinTree(BTree *root)
{
	char ch;
	if((ch=getchar())==' ')
		root=NULL;
	else
	{
		root=(BTree *)malloc(sizeof(BTree));
		root->data = ch;
		root->lchild=createBinTree(root->lchild);
		root->rchild=createBinTree(root->rchild);
	}
	return root;
}

/*
*函数名：getLchild
*功能：获得一个节点的左孩子
*入参：T:要找树的根节点指针，data:要查找的关键字
*返回值：找到返回左孩子的地址，未找到返回NULL;
*其他说明：无
*/
BTree *getLchild(BTree *root, Type data) //获得一个节点的左孩子
{
	BTree *p_lchild = NULL, *p_rchild = NULL;
	if (!root)
		return NULL;

	if (root->data == data) //找到待查找节点，返回其左孩子
		return root->lchild;
	else //找到待查找节点，继续在左子树，右子树中找
	{
		p_lchild = getLchild(root->lchild, data);
		if (p_lchild != NULL) //左子树种找到则返回
			return p_lchild;
		else //左子树没有找到找右子树
		{
			p_rchild = getLchild(root->rchild, data);
			if (p_rchild != NULL) //右子树找到
				return p_rchild;
			else
				//右子树未找到
				return NULL;
		}
	}
}

BTree *getRchild(BTree *root, Type data)
{
	BTree *p_lchild = NULL, *p_rchild = NULL;
	if (!root)
		return NULL;

	if (root->data == data)
		return root->rchild;
	else {
		p_lchild = getRchild(root->lchild, data);
		if (p_lchild != NULL)
			return p_lchild;
		else {
			p_rchild = getRchild(root->rchild, data);
			if (p_rchild != NULL)
				return p_rchild;
			else
				return NULL;
		}
	}
}

bool display(Type data)
{
	printf("%c",data);
	return true;
}

//先序遍历
void Preorder(BTree *root,VIST vist)
{
	if(!root)
		return;
	vist(root->data);
	Preorder(root->lchild,vist);
	Preorder(root->rchild,vist);
}

//中序遍历
void Inorder(BTree *root,VIST vist)
{
	if(!root)
		return;
	Inorder(root->lchild,vist);
	vist(root->data);
	Inorder(root->rchild,vist);
}

//后序遍历
void Postorder(BTree *root,VIST vist)
{
	if(!root)
		return;
	Postorder(root->lchild,vist);
	Postorder(root->rchild,vist);
	vist(root->data);
}

//以线索链表为存储结构对二叉树遍历(中序)
bool InOrderTraverse_Thr(BiThrTree T,VIST vist)
{
	BiThrTree p = T->lchild;//二叉树根节点
	while(p != T)
	{
		while(p->LTag == Link)//中序遍历访问的第一个节点
			p= p->lchild;
		if(!vist(p->data))
			return false;
		while(p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			vist(p->data);
		}
		p = p->rchild;
	}
	return true;
}

BiThrTree pre= NULL;
//二叉树的线索化
bool InorderThreading(BiThrTree *Thrt,BiThrTree T)
{
	if((*Thrt = (BiThrTree)malloc(sizeof(BiThrNode))) == NULL)//头结点
		return false;

	(*Thrt)->LTag = Link;
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = *Thrt;
	if(!T)
		(*Thrt)->lchild = (*Thrt);
	else
	{
		(*Thrt)->lchild = T;
		pre = (*Thrt);
		InThreading(T);
		pre->rchild = (*Thrt);
		pre->RTag = Thread;
		(*Thrt)->rchild = pre;
	}
	return true;
}

void InThreading(BiThrTree T)
{
	if(T)
	{
		InThreading(T->lchild);
		if(!T->lchild)
		{
			T->LTag = Thread;
			T->lchild = pre;
		}
		if(!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = T;
			pre = T;
		}
		InThreading(T->rchild);
	}
}




