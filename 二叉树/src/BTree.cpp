#include <BTree.h>

bool display(Type data) {
	cout << data << ' ';
	return true;
}

BTree::BTree() {
	cout << "input BTree data char\n";
	CreateBinTree(&root);
}
BTree::~BTree() {
	DestroyBinTree(root);
	root = NULL;
}

//创建二叉树(先序遍历)
void BTree::CreateBinTree(BTreeNode **T) {
	char ch;
	cin.get(ch);
	if (ch == ' ')
		*T = NULL;
	else {
		*T = new BTreeNode;
		(*T)->data = ch;
		CreateBinTree(&(*T)->lchild);
		CreateBinTree(&(*T)->rchild);
	}
}

//销毁二叉树(后序遍历)
void BTree::DestroyBinTree(BTreeNode *T) {
	if (T) {
		DestroyBinTree(T->lchild);
		if (T->lchild == NULL)
			delete T->lchild;
		T->lchild = NULL;
		DestroyBinTree(T->rchild);
		if (T->rchild == NULL)
			delete T->rchild;
		T->rchild = NULL;
	}
}

/*
 *函数名：getLchild
 *功能：获得一个节点的左孩子
 *入参：T:要找树的根节点指针，data:要查找的关键字
 *返回值：找到返回左孩子的地址，未找到返回NULL;
 *其他说明：无
 */
BTreeNode * BTree::getLchild(BTreeNode *T, Type data) //获得一个节点的左孩子
		{
	BTreeNode *p_lchild = NULL, *p_rchild = NULL;
	if (!T)
		return NULL;

	if (T->data == data) //找到待查找节点，返回其左孩子
		return T->lchild;
	else //找到待查找节点，继续在左子树，右子树中找
	{
		p_lchild = getLchild(T->lchild, data);
		if (p_lchild != NULL) //左子树种找到则返回
			return p_lchild;
		else //左子树没有找到找右子树
		{
			p_rchild = getLchild(T->rchild, data);
			if (p_rchild != NULL) //右子树找到
				return p_rchild;
			else
				//右子树未找到
				return NULL;
		}
	}
}

BTreeNode *BTree::getRchild(BTreeNode *T, Type data) {
	BTreeNode *p_lchild = NULL, *p_rchild = NULL;
	if (!T)
		return NULL;

	if (T->data == data)
		return T->rchild;
	else {
		p_lchild = getRchild(T->lchild, data);
		if (p_lchild != NULL)
			return p_lchild;
		else {
			p_rchild = getRchild(T->rchild, data);
			if (p_rchild != NULL)
				return p_rchild;
			else
				return NULL;
		}
	}
}

//先序遍历
void BTree::Preorder(BTreeNode *T, VIST vist) {
	if (!T)
		return;
	vist(T->data);
	Preorder(T->lchild, vist);
	Preorder(T->rchild, vist);
}

//中序遍历
void BTree::Inorder(BTreeNode *T, VIST vist) {
	if (!T)
		return;
	Inorder(T->lchild, vist);
	vist(T->data);
	Inorder(T->rchild, vist);
}

//后序遍历
void BTree::Postorder(BTreeNode *T, VIST vist) {
	if (!T)
		return;
	Postorder(T->lchild, vist);
	Postorder(T->rchild, vist);
	vist(T->data);
}

BiThrTree::BiThrTree() {
	cout << "input BTree data char\n";
	createBinTree(&root);
}
BiThrTree::~BiThrTree() {
}

BiThrNode * BiThrTree::pre = NULL;
//创建二叉树(先序遍历)
void BiThrTree::createBinTree(BiThrNode **T) {
	char ch;
	cin.get(ch);
	if (ch == ' ')
		*T = NULL;
	else {
		*T = new BiThrNode;
		(*T)->data = ch;
		createBinTree(&(*T)->lchild);
		createBinTree(&(*T)->rchild);
	}
}

/*
 *函数名：getLchild
 *功能：获得一个节点的左孩子
 *入参：T:要找树的根节点指针，data:要查找的关键字
 *返回值：找到返回左孩子的地址，未找到返回NULL;
 *其他说明：无
 */
BiThrNode * BiThrTree::getLchild(BiThrNode *T, Type data) //获得一个节点的左孩子
		{
	BiThrNode *p_lchild = NULL, *p_rchild = NULL;
	if (!T)
		return NULL;

	if (T->data == data) //找到待查找节点，返回其左孩子
		return T->lchild;
	else //找到待查找节点，继续在左子树，右子树中找
	{
		p_lchild = getLchild(T->lchild, data);
		if (p_lchild != NULL) //左子树种找到则返回
			return p_lchild;
		else //左子树没有找到找右子树
		{
			p_rchild = getLchild(T->rchild, data);
			if (p_rchild != NULL) //右子树找到
				return p_rchild;
			else
				//右子树未找到
				return NULL;
		}
	}
}

BiThrNode *BiThrTree::getRchild(BiThrNode *T, Type data) {
	BiThrNode *p_lchild = NULL, *p_rchild = NULL;
	if (!T)
		return NULL;

	if (T->data == data)
		return T->rchild;
	else {
		p_lchild = getRchild(T->lchild, data);
		if (p_lchild != NULL)
			return p_lchild;
		else {
			p_rchild = getRchild(T->rchild, data);
			if (p_rchild != NULL)
				return p_rchild;
			else
				return NULL;
		}
	}
}

//先序遍历
void BiThrTree::Preorder(BiThrNode *T, VIST vist) {
	if (!T)
		return;
	vist(T->data);
	Preorder(T->lchild, vist);
	Preorder(T->rchild, vist);
}

//中序遍历
void BiThrTree::Inorder(BiThrNode *T, VIST vist) {
	if (!T)
		return;
	Inorder(T->lchild, vist);
	vist(T->data);
	Inorder(T->rchild, vist);
}

//后序遍历
void BiThrTree::Postorder(BiThrNode *T, VIST vist) {
	if (!T)
		return;
	Postorder(T->lchild, vist);
	Postorder(T->rchild, vist);
	vist(T->data);
}

//以线索链表为存储结构对二叉树遍历(中序)
bool BiThrTree::InOrderTraverse_Thr(BiThrNode *T, VIST vist) {
	BiThrNode *p = T->lchild; //二叉树根节点
	while (p != T) {
		while (p->LTag == Link) //中序遍历访问的第一个节点
			p = p->lchild;
		if (!vist(p->data))
			return false;
		while (p->RTag == Thread && p->rchild != T) {
			p = p->rchild;
			vist(p->data);
		}
		p = p->rchild;
	}
	return true;
}

//二叉树的线索化
bool BiThrTree::InorderThreading(BiThrNode **Thrt, BiThrNode *T) {
	if ((*Thrt = new BiThrNode) == NULL) //头结点
		return false;

	(*Thrt)->LTag = Link;
	(*Thrt)->RTag = Thread;
	if (!T) {
		(*Thrt)->lchild = (*Thrt);
		(*Thrt)->rchild = *Thrt;
	} else {
		(*Thrt)->lchild = T;
		pre = (*Thrt);
		InThreading(T);
		pre->rchild = (*Thrt);
		pre->RTag = Thread;
		(*Thrt)->rchild = pre;
	}
	return true;
}

void BiThrTree::InThreading(BiThrNode *T) {
	if (T) {
		InThreading(T->lchild);
		if (!T->lchild) {
			T->LTag = Thread;
			T->lchild = pre;
		}
		if (!pre->rchild) {
			pre->RTag = Thread;
			pre->rchild = T;
		}
		pre = T;
		InThreading(T->rchild);
	}
}

SearchTree::SearchTree() {
	root = NULL;
}
SearchTree::~SearchTree() {
}

bool SearchTree::SearchBST(BTreeNode *T, Type key, BTreeNode *pre,
		BTreeNode **n) {
	if (!T) {
		*n = pre;
		return false;
	}
	if (T->data == key) {
		*n = T;
		return true;
	} else if (T->data > key)
		SearchBST(T->lchild, key, T, n);
	else
		SearchBST(T->rchild, key, T, n);
	return false;
}

bool SearchTree::InsertBST(Type key) {
	BTreeNode *p;
	if (!SearchBST(root, key, NULL, &p)) {
		BTreeNode *temp = new BTreeNode;
		temp->data = key;
		temp->lchild = temp->rchild = NULL;
		if (!p)
			root = temp;
		else {
			if (p->data > key)
				p->lchild = temp;
			else
				p->rchild = temp;
		}
		return true;
	} else
		return false;
}

/*
 * 删除的节点可分为三种情况
 * 1.只有左子树
 * 2.只有右子树
 * 3.左右子树都有
 */
bool SearchTree::DeleteBST(BTreeNode **T, Type key) {
	if(!*T)
		return false;
	if((*T)->data == key){
		BTreeNode *s,*p;
		if((*T)->lchild == NULL){ //只有右子树
			s = (*T);
			(*T) = (*T)->rchild;
		}
		else if((*T)->rchild == NULL){ //只有左子树
			s = (*T);
			(*T) = (*T)->lchild;
		}
		else{	//左右子树都有,
			p = (*T);
			s = (*T)->rchild;	//查找后继节点
			while(s->lchild){
				p = s;
				s = s->lchild;
			}
			(*T)->data = s->data;
			p->lchild = s->rchild;
		}
		delete s;
		return true;
	}
	else if((*T)->data > key)
		DeleteBST(&(*T)->lchild,key);//与左子树比较
	else
		DeleteBST(&(*T)->rchild,key);//与右子树比较
	return false;
}

void SearchTree::InorderReverse(BTreeNode *T,VIST vist){
	if(T){
		InorderReverse(T->lchild,vist);
		vist(T->data);
		InorderReverse(T->rchild,vist);
	}
}
