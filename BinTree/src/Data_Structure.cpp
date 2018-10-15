/*
 * Data_Structure.c
 *
 *  Created on: Aug 31, 2018
 *      Author: lrh
 */
#include "BTree.h"
#include "data.h"
#include <sys/time.h>

int main()
{
	//Type data = '/';
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

#if 1
	int value;
	struct timeval timeval1,timeval2;
	SearchTree searchtree;
	BTreeNode *btreenode;
	data_create("data",100000);
	gettimeofday(&timeval1,NULL);
	data_read("data",searchtree);
	gettimeofday(&timeval2,NULL);
	printf("insert time cast %f \n",(timeval2.tv_sec-timeval1.tv_sec)\
			+(timeval2.tv_usec-timeval1.tv_usec)/1000.0/1000.0);
	cout<<"查找数据："<<endl;
	cin>>value;
	gettimeofday(&timeval1,NULL);
	searchtree.SearchBST(searchtree.root,value,NULL,&btreenode);
	if(NULL != btreenode)
		cout<<"value = "<<btreenode->data<<endl;
	else
		cout<<"no found!"<<endl;
	gettimeofday(&timeval2,NULL);
	printf("search time cast %f \n",(timeval2.tv_sec-timeval1.tv_sec)\
			+(timeval2.tv_usec-timeval1.tv_usec)/1000.0/1000.0);
	return 0;
#endif

#if 0
	int value;
	struct timeval timeval1,timeval2;
	AVLTree avltree;
	AVLNode* avlnode;
	data_create("data",400000);
	gettimeofday(&timeval1,NULL);
	data_read("data",avltree);
	gettimeofday(&timeval2,NULL);
	printf("search time cast %f \n",(timeval2.tv_sec-timeval1.tv_sec)\
			+(timeval2.tv_usec-timeval1.tv_usec)/1000.0/1000.0);
	//avltree.InorderReverse(display1);
	cout<<"查找数据："<<endl;
	cin>>value;
	gettimeofday(&timeval1,NULL);
	avlnode = avltree.SearchAVL(value);
	gettimeofday(&timeval2,NULL);
	if(NULL != avlnode)
		cout<<"value = "<<avlnode->data<<endl;
	else
		cout<<"no found!"<<endl;
	printf("search time cast %f \n",(timeval2.tv_sec-timeval1.tv_sec)\
			+(timeval2.tv_usec-timeval1.tv_usec)/1000.0/1000.0);
	printf("num = %d\n",avltree.num);
	return 0;
#endif
}



