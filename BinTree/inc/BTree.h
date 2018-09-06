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

typedef struct BTreeNode
{
	Type data;
	BTreeNode *lchild,*rchild;
}BTreeNode;

typedef struct BiThrNode
{
	Type data;
	BiThrNode *lchild,*rchild;
	PointerTag LTag,RTag;
}BiThrNode;

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

class BiThrTree
{
public:
	BiThrNode *root;
	BiThrNode *head;
	static BiThrNode *pre;
public:
	BiThrTree();
	~BiThrTree();
	void createBinTree(BiThrNode **);
	void DestroyBinTree(BiThrNode *);
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

class SearchTree
{
public:
	BTreeNode *root;
public:
	SearchTree();
	~SearchTree();
	bool SearchBST(BTreeNode *,Type key,BTreeNode *,BTreeNode **);
	bool InsertBST(Type);
	bool DeleteBST(BTreeNode **,Type);
	void DestroyBinTree(BTreeNode *);
	void InorderReverse(BTreeNode *T,VIST vist);
};

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
public:
	AVLTree();
	~AVLTree();
	void InsertAVL(Type);
	bool NodeDeleteAVL(Type);
	AVLNode *SearchNode(Type);
};

bool display(Type);


#endif /* BTREE_H_ */
