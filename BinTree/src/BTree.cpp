#include <BTree.h>

bool display(Type data) {
	cout << data << ' ';
	return true;
}

bool display1(Type data) {
	cout << data << endl;
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
		*T = new BTreeNode(ch);
		CreateBinTree(&(*T)->lchild);
		CreateBinTree(&(*T)->rchild);
	}
}

//销毁二叉树(后序遍历)
void BTree::DestroyBinTree(BTreeNode *T) {
	if (T) {
		DestroyBinTree(T->lchild);
		DestroyBinTree(T->rchild);
		T->lchild = T->rchild = NULL;
		delete T;
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
	else { //找到待查找节点，继续在左子树，右子树中找
		p_lchild = getLchild(T->lchild, data);
		if (p_lchild != NULL) //左子树种找到则返回
			return p_lchild;
		else { //左子树没有找到找右子树
			p_rchild = getLchild(T->rchild, data);
			if (p_rchild != NULL) //右子树找到
				return p_rchild;
			else //右子树未找到
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
	head = pre = NULL;
}
BiThrTree::~BiThrTree() {
	DestroyBinTree(head,head->rchild);
	delete head;
	head = NULL;
	root = NULL;
	pre = NULL;
}

//BiThrNode * BiThrTree::pre = NULL;
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

void BiThrTree::DestroyBinTree(BiThrNode *H,BiThrNode *T) {
//按线索化序列反序方式删除
//	if(T != H){
//		if(T->LTag == Link){
//			BiThrNode *temp = T->lchild;
//			DestroyBinTree(H,temp);
//		}else if(T->LTag == Thread){
//			DestroyBinTree(H,T->lchild);
//			delete T;
//		}
//	}
//按二叉树后序遍历方式删除
	if (T->LTag == Link)
		DestroyBinTree(H, T->lchild);
	if (T->RTag == Link)
		DestroyBinTree(H, T->rchild);
	delete T;
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
	else { //找到待查找节点，继续在左子树，右子树中找
		p_lchild = getLchild(T->lchild, data);
		if (p_lchild != NULL) //左子树种找到则返回
			return p_lchild;
		else { //左子树没有找到找右子树
			p_rchild = getLchild(T->rchild, data);
			if (p_rchild != NULL) //右子树找到
				return p_rchild;
			else //右子树未找到
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
	cout << endl;
	return true;
}

//二叉树的线索化（中序）
bool BiThrTree::InorderThreading(BiThrNode **Thrt, BiThrNode *T) {
	if ((*Thrt = new BiThrNode) == NULL) //头结点
		return false;

	(*Thrt)->LTag = Link;
	(*Thrt)->RTag = Thread;
	if (!T) {
		(*Thrt)->lchild = *Thrt;
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
	DestroyBinTree(root);
	root = NULL;
}

BTreeNode * SearchTree::SearchBST(Type key){
	return SearchBST(root,key);
}

BTreeNode * SearchTree::SearchBST(BTreeNode *T, Type key) {
	if (!T)
		return NULL;
	if (T->data == key) {
		return T;
	} else if (T->data > key)
		return SearchBST(T->lchild, key);
	else
		return SearchBST(T->rchild, key);
}

//bool SearchTree::InsertBST(Type key) {
bool SearchTree::Insert(Type key) {
	return InsertBST(root,key) == NULL ? false:true;
}

BTreeNode * SearchTree::InsertBST(BTreeNode *T,Type key) {
	if (NULL == T)
		return T = new BTreeNode(key);
	else {
		if (key == T->data)
			return T;
		else if (key < T->data)
			T->lchild = InsertBST(T->lchild, key);
		else
			T->rchild = InsertBST(T->rchild, key);
		return T;
	}
}

/*
 * 删除的节点可分为三种情况
 * 1.只有左子树
 * 2.只有右子树
 * 3.左右子树都有
 */
bool SearchTree::DeleteBST(BTreeNode **T, Type key) {
	if (!*T)
		return false;
	if ((*T)->data == key) {
		BTreeNode *s, *p;
		if ((*T)->lchild == NULL) { //只有右子树
			s = (*T);
			(*T) = (*T)->rchild;
		} else if ((*T)->rchild == NULL) { //只有左子树
			s = (*T);
			(*T) = (*T)->lchild;
		} else {	//左右子树都有
			p = (*T);
			s = (*T)->rchild;	//查找后继节点
			while (s->lchild) {
				p = s;
				s = s->lchild;
			}
			(*T)->data = s->data;
			p->lchild = s->rchild;
		}
		delete s;
		return true;
	} else if ((*T)->data > key)
		DeleteBST(&(*T)->lchild, key);	//与左子树比较
	else
		DeleteBST(&(*T)->rchild, key);	//与右子树比较
	return false;
}

//中序遍历二叉搜索树
void SearchTree::InorderReverse(BTreeNode *T, VIST vist) {
	if (T) {
		InorderReverse(T->lchild, vist);
		vist(T->data);
		InorderReverse(T->rchild, vist);
	}
}

void SearchTree::DestroyBinTree(BTreeNode *T) {
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
AVLTree::AVLTree(AVLNode* T) {
	root = T;
}
AVLTree::~AVLTree() {
}

inline int AVLTree::GetHeight(AVLNode *T) {
	return NULL == T ? -1 : T->hight;
}
/*********************************************
 *参数：待插入元素,当前节点
 *返回值：当前子树根节点
 *功能：插入元素到当前节点的子树
 **********************************************/
AVLNode *AVLTree::InsertAVL(AVLNode *T, Type key) {
	if (NULL == T)
		return T = new AVLNode(key);
	else {
		if (key == T->data)
			return T;
		else if (key < T->data)
			T->lchild = InsertAVL(T->lchild, key);
		else
			T->rchild = InsertAVL(T->rchild, key);
	}
	if (2 == GetHeight(T->lchild) - GetHeight(T->rchild)) {
		if (key < T->lchild->data)
			T = L_Rotate(T);
		else
			T = LR_Rotate(T);
	} else if (-2 == GetHeight(T->lchild) - GetHeight(T->rchild)) {
		if (key > T->rchild->data)
			T = R_Rotate(T);
		else
			T = RL_Rotate(T);
	}
	T->hight = max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;
	return T;
}

//void AVLTree::InsertAVL(Type key) {
void AVLTree::Insert(Type key) {
	root = InsertAVL(root, key);
}

AVLNode* AVLTree::SearchAVL(Type key){
	 return SearchAVL(root,key);
}

AVLNode* AVLTree::SearchAVL(AVLNode *T,Type key){
	if (!T)
		return NULL;

	if (T->data == key) {
		return T;
	} else if (T->data > key)
		return SearchAVL(T->lchild, key);
	else
		return SearchAVL(T->rchild, key);
}
/*********************************************
 *参数：待删除元素,当前节点
 *返回值：当前子树根节点
 *功能：删除元素
 **********************************************/
AVLNode *AVLTree::NodeDeleteAVL(AVLNode *T, Type key, bool &isDelSucceed) {
	if (NULL == T)
		return NULL;
	else {
		if (key == T->data) {
			AVLNode *cur;
			if (NULL == T->rchild) {
				cur = T;
				T = T->lchild;
				delete cur;
				isDelSucceed = true;
				return T;
			} else	{ //找到右子树最小的元素代替，然后删除
				cur = T->rchild;
				while (cur->lchild != NULL)
					cur = cur->lchild;
				T->data = cur->data;
				T->rchild = NodeDeleteAVL(T->rchild, cur->data, isDelSucceed);
			}
		} else if (key < T->data)
			T->lchild = NodeDeleteAVL(T->lchild, key, isDelSucceed);
		else
			T->rchild = NodeDeleteAVL(T->rchild, key, isDelSucceed);

		if (-2 == GetHeight(T->lchild) - GetHeight(T->rchild)) {	//删除的是左子树上的
			if (GetHeight(T->rchild->rchild) >= GetHeight(T->rchild->lchild))
				T = R_Rotate(T);
			else
				T = RL_Rotate(T);
		} else if (2 == GetHeight(T->lchild) - GetHeight(T->rchild)) {
			if (GetHeight(T->lchild->lchild) >= GetHeight(T->lchild->rchild))
				T = L_Rotate(T);
			else
				T = LR_Rotate(T);
		}
		T->hight = max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;
	}
	return T;
}
bool AVLTree::NodeDeleteAVL(Type key) {
	bool isDelSucceed = false;
	root = NodeDeleteAVL(root, key, isDelSucceed);
	return isDelSucceed;
}

/*********************************************
 *参数：待查找元素，当前节点
 *返回值：元素所在节点
 *功能：返回元素所在节点
 **********************************************/
AVLNode *AVLTree::SearchNode(AVLNode *T, Type key) {
	if (NULL == T)
		return NULL;
	else if (key == T->data)
		return T;
	else if (key < T->data)
		return SearchNode(T->lchild, key);
	return SearchNode(T->rchild, key);
}

/***********************************************
 * 参数：节点，访问方法
 * 返回值：void
 * 功能：中序遍历AVL平衡树
 */
void AVLTree::InorderReverse(VIST vist){
	InorderReverse(root,vist);
	cout << endl;
}

void AVLTree::InorderReverse(AVLNode *T,VIST vist){
	if(T){
		InorderReverse(T->lchild,vist);
		vist(T->data);
		InorderReverse(T->rchild,vist);
	}
}
/*********************************************
 *参数：当前节点
 *返回值：当前子树根节点
 *功能：左旋调平衡
 **********************************************/
AVLNode *AVLTree::R_Rotate(AVLNode *T) {
	AVLNode *lChildNode = T->rchild->lchild, *newRoot = T->rchild;
	T->rchild->lchild = T;
	T->rchild = lChildNode;
	T->hight = max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;
//	if (NULL != T->rchild)
//		T->rchild->hight = max(GetHeight(T->rchild->lchild),
//				GetHeight(T->rchild->rchild)) + 1;
//	newRoot->hight = max(GetHeight(newRoot->lchild), GetHeight(newRoot->rchild)) + 1;
	return newRoot;
}

/*********************************************
 *参数：当前节点
 *返回值：当前子树根节点
 *功能：右旋调平衡
 **********************************************/
AVLNode *AVLTree::L_Rotate(AVLNode *T) {
	AVLNode *rChildNode = T->lchild->rchild, *newRoot = T->lchild;
	T->lchild->rchild = T;
	T->lchild = rChildNode;
	T->hight = max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;
//	if (NULL != T->lchild)
//		T->lchild->hight = max(GetHeight(T->lchild->lchild),
//				GetHeight(T->lchild->rchild)) + 1;
//	newRoot->hight = max(GetHeight(newRoot->lchild), GetHeight(newRoot->rchild)) + 1;
	return newRoot;
}

/*********************************************
 *参数：当前节点
 *返回值：当前子树根节点
 *功能：先左旋后右旋调平衡
 **********************************************/
AVLNode *AVLTree::RL_Rotate(AVLNode *T) {
	T->rchild = L_Rotate(T->rchild);
	return R_Rotate(T);
}

/*********************************************
 *参数：当前节点
 *返回值：当前子树根节点
 *功能：先右旋后左旋调平衡
 **********************************************/
AVLNode *AVLTree::LR_Rotate(AVLNode *T) {
	T->lchild = R_Rotate(T->lchild);
	return L_Rotate(T);
}
