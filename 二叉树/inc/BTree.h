/*
 * BTree.h
 *
 *  Created on: Aug 31, 2018
 *      Author: lrh
 */

#ifndef BTREE_H_
#define BTREE_H_

typedef struct tree
{
	char data;
	struct tree *lchild,*rchild;
}BTree;

typedef void VIST(BTree *node);

BTree *createBinTree(BTree *);
void Preorder(BTree *,VIST);
void display(BTree *);

#endif /* BTREE_H_ */
