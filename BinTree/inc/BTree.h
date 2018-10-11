/*
 * BTree.h
 *
 *  Created on: Aug 31, 2018
 *      Author: lrh
 */

#ifndef BTREE_H_
#define BTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef int Type;
typedef enum {Link,Thread} PointerTag;
typedef bool VIST(Type data);

//二叉树节点
typedef struct BTreeNode
{
	Type data;
	BTreeNode *lchild,*rchild;

	BTreeNode(Type data){
		this->data = data;
		lchild = rchild = NULL;
	}
}BTreeNode;
//线索树节点
typedef struct BiThrNode
{
	Type data;
	BiThrNode *lchild,*rchild;
	PointerTag LTag,RTag;
}BiThrNode;
//AVL树节点
typedef struct AVLNode
{
	Type data;
	int hight;
	AVLNode *lchild,*rchild;

	AVLNode(Type data){
		this->data = data;
		hight = 0;
		lchild = rchild = NULL;
	}
}AVLNode;
//二叉树
class BTree
{
public:
	BTreeNode *root;
public:
	BTree();
	~BTree();
	void CreateBinTree(BTreeNode **);
	void DestroyBinTree(BTreeNode *);
	void Preorder(BTreeNode *,VIST);
	void Inorder(BTreeNode *,VIST);
	void Postorder(BTreeNode *,VIST);
	BTreeNode *getLchild(BTreeNode *, Type);
	BTreeNode *getRchild(BTreeNode *, Type);
};
//线索树
class BiThrTree
{
public:
	BiThrNode *root;
	BiThrNode *head;
	BiThrNode *pre;
public:
	BiThrTree();
	~BiThrTree();
	void createBinTree(BiThrNode **);
	void DestroyBinTree(BiThrNode *,BiThrNode *);
	void Preorder(BiThrNode *,VIST);
	void Inorder(BiThrNode *,VIST);
	void Postorder(BiThrNode *,VIST);
	bool display(Type);
	BiThrNode *getLchild(BiThrNode *, Type);
	BiThrNode *getRchild(BiThrNode *, Type);
	bool InOrderTraverse_Thr(BiThrNode *,VIST);
	bool InorderThreading(BiThrNode **,BiThrNode *);
	void InThreading(BiThrNode *);
};
//搜索树/查找树
class SearchTree
{
public:
	BTreeNode *root;
private:
	BTreeNode * InsertBST(BTreeNode*,Type);
	BTreeNode * SearchBST(BTreeNode *,Type);
public:
	SearchTree();
	~SearchTree();
	BTreeNode * SearchBST(Type);
//	bool InsertBST(Type);
	bool Insert(Type);
	bool DeleteBST(BTreeNode **,Type);
	void DestroyBinTree(BTreeNode *);
	void InorderReverse(BTreeNode *T,VIST vist);
};
//AVL平衡树
class AVLTree
{
private:
	AVLNode *root;
	int GetHeight(AVLNode *);
	AVLNode *InsertAVL(AVLNode *,Type);
	AVLNode *NodeDeleteAVL(AVLNode *,Type,bool &);
	AVLNode *SearchNode(AVLNode *,Type);
	AVLNode *L_Rotate(AVLNode *);
	AVLNode *R_Rotate(AVLNode *);
	AVLNode *LR_Rotate(AVLNode *);
	AVLNode *RL_Rotate(AVLNode *);
	void InorderReverse(AVLNode *T,VIST vist);
	AVLNode * SearchAVL(AVLNode*,Type);
public:
	AVLTree(AVLNode *T=NULL);
	~AVLTree();
	void Insert(Type);
//	void InsertAVL(Type);
	bool NodeDeleteAVL(Type);
	AVLNode *SearchNode(Type);
	void InorderReverse(VIST vist);
	AVLNode * SearchAVL(Type);
};

bool display(Type);
bool display1(Type);

#endif /* BTREE_H_ */
