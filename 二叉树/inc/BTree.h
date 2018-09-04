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
	void InorderReverse(BTreeNode *T,VIST vist);
};

bool display(Type);


#endif /* BTREE_H_ */
