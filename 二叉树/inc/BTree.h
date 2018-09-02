/*
 * BTree.h
 *
 *  Created on: Aug 31, 2018
 *      Author: lrh
 */

#ifndef BTREE_H_
#define BTREE_H_

typedef char Type;
typedef enum {Link,Thread} PointerTag;
typedef enum{false,true} bool;

typedef struct tree
{
	Type data;
	struct tree *lchild,*rchild;
}BTree;

typedef struct BiThrNode{
	Type data;
	struct BiThrNode *lchild,*rchild;
	PointerTag Ltag,RTag;
}BiThrNode,*BiThrTree;

typedef void VIST(Type data);

BTree *createBinTree(BTree *);
void Preorder(BTree *,VIST);
void Inorder(BTree *,VIST);
void Postorder(BTree *,VIST);
void display(Type);

#endif /* BTREE_H_ */
