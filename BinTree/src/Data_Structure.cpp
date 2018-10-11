/*
 * Data_Structure.c
 *
 *  Created on: Aug 31, 2018
 *      Author: lrh
 */
#include "BTree.h"
#include "data.h"

int main()
{
	Type data = '/';
#if 0

  	BTree btree;
  	BTreeNode *node;
	cout << "先序遍历顺序为：\n\t";
	btree.Preorder(btree.root,display);//先序遍历
	cout << endl;
	cout << "中序遍历顺序为：\n\t";
	btree.Inorder(btree.root,display);//中序遍历
	cout << endl;
	cout << "后序遍历顺序为：\n\t";
	btree.Postorder(btree.root,display);//后序遍历
	cout << endl ;

	node = btree.getLchild(btree.root,data);//找左孩子
	if(node)
		cout << "节点 " << data << " 左孩子为 " <<  node->data << endl;
	node = btree.getRchild(btree.root,data);//找右孩子
	if(node)
		cout << "节点 " << data << " 右孩子为 " <<  node->data << endl;
#endif

#if 0
	BiThrTree bithrtree;
	BiThrNode *node1;
	cout << "先序遍历顺序为：\n\t";
	bithrtree.Preorder(bithrtree.root,display);//先序遍历
	cout << endl;
	cout << "中序遍历顺序为：\n\t";
	bithrtree.Inorder(bithrtree.root,display);//中序遍历
	cout << endl;
	cout << "后序遍历顺序为：\n\t";
	bithrtree.Postorder(bithrtree.root,display);//后序遍历
	cout << endl ;

	node1 = bithrtree.getLchild(bithrtree.root,data);//找左孩子
	if(node1)
		cout << "节点 " << data << " 左孩子为 " <<  node1->data << endl;
	node1 = bithrtree.getRchild(bithrtree.root,data);//找右孩子
	if(node1)
		cout << "节点 " << data << " 右孩子为 " <<  node1->data << endl;

	cout << "线索化" << endl;
	bithrtree.InorderThreading(&bithrtree.head,bithrtree.root);

	cout << "线索化中序遍历顺序" <<endl;
	bithrtree.InOrderTraverse_Thr(bithrtree.head,display);

#endif

#if 0
	int value;
	SearchTree searchtree;
	data_create("data",50000);
	data_read("data",searchtree);
	searchtree.InorderReverse(searchtree.root,display1);
	cout<<"查找数据："<<endl;
	cin>>value;
	searchtree.SearchBST(value);
	return 0;
#endif

#if 1
	int value;
	AVLTree avltree;
	AVLNode* avlnode;
	data_create("data",50000);
	data_read("data",avltree);
	avltree.InorderReverse(display1);
	cout<<"查找数据："<<endl;
	cin>>value;
	avlnode = avltree.SearchAVL(value);
	if(NULL != avlnode)
		cout<<"value = "<<value<<endl;
#endif
}



