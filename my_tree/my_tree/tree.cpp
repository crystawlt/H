//#include <iostream>
//# include <vector>
//# include <queue>
//# include <iomanip>
//# include <stack>
//using namespace std;
//class node
//{
//public:
//	node(char b):a(b),left(NULL),right(NULL){}
//	~node(){}
//
//public:
//	char a;
//	node*left;
//	node*right;
//};
//int max(int a, int b)
//{
//	return a > b ? a : b;
//}
//class tree
//{
//public:
//	tree():head(NULL){}
//	node*tree_create(char *arr, int len)
//	{
//		node *pts = NULL;
//		static int i = -1;
//		if (i >= len)
//		{
//			return NULL;
//		}
//		++i;
//		
//		if (arr[i] != '#')
//		{
//			pts = new node(arr[i]);
//			if (head == NULL)
//			{
//				head = pts;
//			}
//			pts->left = tree_create(arr, len);
//			pts->right = tree_create(arr, len);
//		}
//		return pts;
//	}
//	~tree()
//	{
//		//后序遍历销毁树
//	}
//	void Preorder_traversal()//先序递归
//	{
//		xian(head);
//	}
//	void Intermediate_traversal()//中序遍历
//	{
//		zhong(head);
//	}
//	void Postorder_traversal()//后序遍历
//	{
//		hou(head);
//	}
//	void Preorder_traversal_non_recursive()//先序非递归
//	{
//		xian_non_recursive(head);
//	}
//	void Intermediate_traversal_non_recursive()//中序非递归
//	{
//		zhong_non_recursive(head);
//	}
//	void  Postorder_traversal_non_recursive()//后序非递归
//	{
//		hou_non_recursive(head);
//	}
//	void print_k(int k)//打印第k层
//	{
//		K_layer(head, k);
//	}
//	int tree_hig()//树的高度递归
//	{
//		return is_tree_hig(head);
//	}
//	int tree_hig_non_recursive()//树高度非递归，队列
//	{
//		return is_tree_hig_non_recursive(head);
//	}
//	void tree_Mid_post(char *arr, char *brr,int len)//根据中序和后序构造二叉树
//	{
//		head = tree_hou_zhong(arr, brr, len);
//	}
//	void tree_Mid_Pri(char *arr, char *brr,int len)//根据中序和先序构造二叉树
//	{
//		head = tree_zhong_xian(arr, brr, len);
//	}
//	void tree_image()//二叉树镜像
//	{
//		is_tree_image(head);
//	}
//	node* child_parent(char a)//找ps的父亲节点
//	{
//		return is_child_parent(head, a);
//	}
//	bool tree_Substructure(tree&pts)//判断一颗树是不是另一颗树的子结构
//	{
//		return is_tree_Substructure(this->head, pts.get_tree_root());
//	}
//	node * get_tree_root()
//	{
//		return this->head;
//	}
//private:
//	node*head;
//	void xian(node*pts)
//	{
//		if (pts != NULL)
//		{
//			cout << setw(3) << pts->a;
//			xian(pts->left);
//			xian(pts->right);
//		}
//	}
//	void xian_non_recursive(node*pts)//先序非递归
//	{
//		stack<node*> s1;
//		while (s1.size()>0||pts!=NULL)
//		{
//			while (pts!=NULL)
//			{
//				cout << setw(3)<<pts->a;
//				s1.push(pts);
//				pts = pts->left;
//			}
//			pts = s1.top();
//			s1.pop();
//			pts = pts->right;
//		}
//	}
//	void zhong(node*pts)
//	{
//		if (pts != NULL)
//		{
//			zhong(pts->left);
//			cout << setw(3) << pts->a;
//			zhong(pts->right);
//		}
//	}
//	void zhong_non_recursive(node *pts)
//	{
//		stack<node*>s1;
//		while (s1.size()>0||pts!=NULL)
//		{
//			while (pts!=NULL)
//			{
//				s1.push(pts);
//				pts = pts->left;
//			}
//			pts = s1.top();
//			s1.pop();
//			cout << setw(3)<<pts->a;
//			pts = pts->right;
//		}
//	}
//	void hou(node*pts)
//	{
//		if (pts != NULL)
//		{
//			hou(pts->left);
//			hou(pts->right);
//			cout << setw(3) << pts->a;
//		}
//	}
//	void hou_non_recursive(node *pts)
//	{
//		stack<node*> s1;
//		node * ts=NULL;
//		while (pts!=NULL||s1.size()>0)
//		{
//			while (pts!=NULL)
//			{
//				s1.push(pts);
//				pts = pts->left;
//			}
//			pts = s1.top();
//			if (ts == pts->right || pts->right == NULL)
//			{
//				s1.pop();
//				cout << setw(3) << pts->a;
//				ts = pts;
//				pts = NULL;
//			}
//			else
//				pts = pts->right;
//		}
//	}
//	void K_layer(node*pts, int k)//打印第K层
//	{
//		if (k==1&&pts!=NULL)
//		{
//			cout << setw(3) << pts->a;
//		}
//		else if (pts!=NULL)
//		{
//			K_layer(pts->left, k-1);
//			K_layer(pts->right, k-1);
//		}
//	}
//	int is_tree_hig(node *pts)
//	{
//		if (pts == NULL)
//			return 0;
//		return max(is_tree_hig(pts->left), is_tree_hig(pts->right)) + 1;
//	}
//	int is_tree_hig_non_recursive(node *head)
//	{
//		int tmp = 0;
//		queue<node*>s1;
//		s1.push(head);
//		while (s1.size()>0)
//		{
//			int i = s1.size();
//			while (i>0)
//			{
//				node *pts = s1.front();
//				s1.pop();
//				cout << setw(3)<<pts->a;
//				if (pts->left!=NULL)
//				s1.push(pts->left);
//				if (pts->right!=NULL)
//				s1.push(pts->right);
//				--i;
//			}
//			tmp++;
//			cout << endl;
//		}
//		return tmp;
//	}
//	node*tree_zhong_xian(char *arr, char *brr, int len)
//	{
//		node * pts = NULL;
//		if (len > 0)
//		{
//			char a = arr[0];
//			pts = new node(a);
//			int i = 0;
//			while (brr[i] != a)
//			{
//				++i;
//			}
//			pts->left = tree_zhong_xian(arr + 1, brr, i);
//			pts->right = tree_zhong_xian(arr + i + 1, brr + i + 1, len - i - 1);
//		}
//		return pts;
//	}
//	node*tree_hou_zhong(char *arr, char *brr, int len)
//	{
//		node * pts = NULL;
//		if (len > 0)
//		{
//			char a = arr[len - 1];
//			 pts = new node(a);
//			int i = 0;
//			while (brr[i] != a)
//			{
//				++i;
//			}
//			pts->left = tree_hou_zhong(arr, brr, i);
//			pts->right = tree_hou_zhong(arr + i, brr + i + 1, len - i - 1);
//		}
//		return pts;
//	}
//	void is_tree_image(node * pts)
//	{
//		if (pts == NULL)
//			return;
//		if (pts->left != NULL || pts->right != NULL)
//		{
//			node * pds = pts->left;
//			pts->left = pts->right;
//			pts->right = pds;
//			is_tree_image(pts->left);
//			is_tree_image(pts->right);
//		}
//	}
//	node*is_child_parent(node*pts, char c)
//	{
//		if (pts == NULL)
//			return NULL;
//		if (pts->left->a == c&&pts->left!=NULL || pts->right!=NULL&&pts->right->a == c)
//		{
//			return pts;
//		}
//		else
//		{
//			node *pds = is_child_parent(pts->left, c);
//			if (pds == NULL)
//			{
//				pds = is_child_parent(pts->right, c);
//			}
//			return pds;
//		}
//	}
//	bool judge_tree(node *pts, node*pds)
//	{
//		if (pds == NULL)
//			return true;
//		if (pts == NULL)
//		{
//			return false;
//		}
//		if (pts!=NULL&&pds!=NULL)
//		{
//			if (pds->a == pts->a)
//			{
//				if (judge_tree(pts->left, pds->left) == true && judge_tree(pts->right, pds->right) == true)
//				{
//					return true;
//				}
//				else
//					return false;
//			}
//			else
//				return false;
//		}
//	}
//	bool is_tree_Substructure(node *pts, node*pds)
//	{
//		 bool tmp = false;
//		if (pts!=NULL&&pds!=NULL)
//		{
//			if (pts->a == pds->a)
//			{
//				tmp = judge_tree(pts, pds);
//			}
//			if (tmp==false)
//			tmp=is_tree_Substructure(pts->left, pds);
//			if (tmp ==false)
//			{
//				tmp = is_tree_Substructure(pts->right, pds);
//			}
//			return tmp;
//		}
//	}
//};
//bool tree_fun(node *pts, char *arr, int len)//判断一个序列是否为二叉搜索树的后序遍历
//{
//	if (pts == NULL || len <= 0)
//	{
//		return false;
//	}
//	else
//	{
//		if (pts->a == arr[len - 1])
//		{
//			int i, j;
//			for ( i= 0; i < len; i++)
//			{
//				if (arr[i]>arr[len - 1])
//					break;
//			}
//			for ( j = i; j < len; j++)
//			{
//				if (arr[j] < arr[len - 1])
//					return false;
//			}
//
//		}
//		else
//		{
//			return false;
//		}
//	}
//}



//int main()
//{
//	char arr[] = { "ABC##DE##F##G#H" };
//	tree is_tree;
//	is_tree.tree_create(arr, strlen(arr));
//	is_tree.Preorder_traversal();
//	cout << endl;
//	is_tree.Preorder_traversal_non_recursive();
//	cout << endl;
//	is_tree.Intermediate_traversal();
//	cout << endl;
//	is_tree.Intermediate_traversal_non_recursive();
//	cout << endl;
//	is_tree.Postorder_traversal();
//	cout << endl;
//	is_tree.Postorder_traversal_non_recursive();
//	cout << endl;
//	int a= is_tree.tree_hig();
//	cout << endl;
//	for ( int i = 1; i <= a; i++)
//	{
//		is_tree.print_k(i);
//        cout << endl;
//	}
//	cout << endl;
//	cout<<is_tree.tree_hig_non_recursive();
//	cout << endl;
//	is_tree.tree_image();
//	is_tree.tree_hig_non_recursive();
//}




#include<iostream>
# include <vector>
# include <queue>
# include <stack>
# include <iomanip>
using namespace std;
template <typename T>
class node
{
public:
	node(T b) :a(b), left(NULL), right(NULL){}
	~node(){}

public:
	T a;
	node<T>*left;
	node<T>*right;
};
int max(int a, int b)
{
	return a > b ? a : b;
}
template <typename T>
class tree
{
public:
	tree() :head(NULL){}
	node<T>*tree_create(T *arr, int len)
	{
		node<T> *pts = NULL;
		static int i = -1;
		if (i >= len)
		{
			return NULL;
		}
		++i;

		if (arr[i] != -1)
		{
			pts = new node<T>(arr[i]);
			if (head == NULL)
			{
				head = pts;
			}
			pts->left = tree_create(arr, len);
			pts->right = tree_create(arr, len);
		}
		return pts;
	}
	~tree()
	{
		//后序遍历销毁树
	}
	void Preorder_traversal()//先序递归
	{
		xian(head);
	}
	void Intermediate_traversal()//中序遍历
	{
		zhong(head);
	}
	void Postorder_traversal()//后序遍历
	{
		hou(head);
	}
	void Preorder_traversal_non_recursive()//先序非递归
	{
		xian_non_recursive(head);
	}
	void Intermediate_traversal_non_recursive()//中序非递归
	{
		zhong_non_recursive(head);
	}
	void  Postorder_traversal_non_recursive()//后序非递归
	{
		hou_non_recursive(head);
	}
	void print_k(int k)//打印第k层
	{
		K_layer(head, k);
	}
	int tree_hig()//树的高度递归
	{
		return is_tree_hig(head);
	}
	int tree_hig_non_recursive()//树高度非递归，队列
	{
		return is_tree_hig_non_recursive(head);
	}
	void tree_Mid_post(T *arr, T *brr, int len)//根据中序和后序构造二叉树
	{
		head = tree_hou_zhong(arr, brr, len);
	}
	void tree_Mid_Pri(T *arr, T *brr, int len)//根据中序和先序构造二叉树
	{
		head = tree_zhong_xian(arr, brr, len);
	}
	void tree_image()//二叉树镜像
	{
		is_tree_image(head);
	}
	node<T>* child_parent(T a)//找ps的父亲节点
	{
		return is_child_parent(head, a);
	}
	bool tree_Substructure(tree&pts)//判断一颗树是不是另一颗树的子结构
	{
		return is_tree_Substructure(this->head, pts.get_tree_root());
	}
	node <T>* get_tree_root()
	{
		return this->head;
	}
private:
	node<T>*head;
	void xian(node<T>*pts)
	{
		if (pts != NULL)
		{
			cout << setw(3) << pts->a;
			xian(pts->left);
			xian(pts->right);
		}
	}
	void xian_non_recursive(node<T>*pts)//先序非递归
	{
		stack<node*> s1;
		while (s1.size()>0 || pts != NULL)
		{
			while (pts != NULL)
			{
				cout << setw(3) << pts->a;
				s1.push(pts);
				pts = pts->left;
			}
			pts = s1.top();
			s1.pop();
			pts = pts->right;
		}
	}
	void zhong(node<T>*pts)
	{
		if (pts != NULL)
		{
			zhong(pts->left);
			cout << setw(3) << pts->a;
			zhong(pts->right);
		}
	}
	void zhong_non_recursive(node<T>*pts)
	{
		stack<node*>s1;
		while (s1.size()>0 || pts != NULL)
		{
			while (pts != NULL)
			{
				s1.push(pts);
				pts = pts->left;
			}
			pts = s1.top();
			s1.pop();
			cout << setw(3) << pts->a;
			pts = pts->right;
		}
	}
	void hou(node<T>*pts)
	{
		if (pts != NULL)
		{
			hou(pts->left);
			hou(pts->right);
			cout << setw(3) << pts->a;
		}
	}
	void hou_non_recursive(node<T>*pts)
	{
		stack<node<T>*> s1;
		node<T> * ts = NULL;
		while (pts != NULL || s1.size()>0)
		{
			while (pts != NULL)
			{
				s1.push(pts);
				pts = pts->left;
			}
			pts = s1.top();
			if (ts == pts->right || pts->right == NULL)
			{
				s1.pop();
				cout << setw(3) << pts->a;
				ts = pts;
				pts = NULL;
			}
			else
				pts = pts->right;
		}
	}
	void K_layer(node<T>*pts, int k)//打印第K层
	{
		if (k == 1 && pts != NULL)
		{
			cout << setw(3) << pts->a;
		}
		else if (pts != NULL)
		{
			K_layer(pts->left, k - 1);
			K_layer(pts->right, k - 1);
		}
	}
	int is_tree_hig(node<T>*pts)
	{
		if (pts == NULL)
			return 0;
		return max(is_tree_hig(pts->left), is_tree_hig(pts->right)) + 1;
	}
	int is_tree_hig_non_recursive(node<T>*pts)
	{
		int tmp = 0;
		queue<node*>s1;
		s1.push(head);
		while (s1.size()>0)
		{
			int i = s1.size();
			while (i>0)
			{
				node *pts = s1.front();
				s1.pop();
				cout << setw(3) << pts->a;
				if (pts->left != NULL)
					s1.push(pts->left);
				if (pts->right != NULL)
					s1.push(pts->right);
				--i;
			}
			tmp++;
			cout << endl;
		}
		return tmp;
	}
	node<T>*tree_zhong_xian(T *arr, T *brr, int len)
	{
		node * pts = NULL;
		if (len > 0)
		{
			char a = arr[0];
			pts = new node(a);
			int i = 0;
			while (brr[i] != a)
			{
				++i;
			}
			pts->left = tree_zhong_xian(arr + 1, brr, i);
			pts->right = tree_zhong_xian(arr + i + 1, brr + i + 1, len - i - 1);
		}
		return pts;
	}
	node<T>*tree_hou_zhong(T *arr, T *brr, int len)
	{
		node * pts = NULL;
		if (len > 0)
		{
			char a = arr[len - 1];
			pts = new node(a);
			int i = 0;
			while (brr[i] != a)
			{
				++i;
			}
			pts->left = tree_hou_zhong(arr, brr, i);
			pts->right = tree_hou_zhong(arr + i, brr + i + 1, len - i - 1);
		}
		return pts;
	}
	void is_tree_image(node<T>*pts)
	{
		if (pts == NULL)
			return;
		if (pts->left != NULL || pts->right != NULL)
		{
			node * pds = pts->left;
			pts->left = pts->right;
			pts->right = pds;
			is_tree_image(pts->left);
			is_tree_image(pts->right);
		}
	}
	node<T>*is_child_parent(node<T>*pts, T c)
	{
		if (pts == NULL)
			return NULL;
		if (pts->left->a == c&&pts->left != NULL || pts->right != NULL&&pts->right->a == c)
		{
			return pts;
		}
		else
		{
			node *pds = is_child_parent(pts->left, c);
			if (pds == NULL)
			{
				pds = is_child_parent(pts->right, c);
			}
			return pds;
		}
	}
	bool judge_tree(node<T>*pts, node<T>*pds)
	{
		if (pds == NULL)
			return true;
		if (pts == NULL)
		{
			return false;
		}
		if (pts != NULL&&pds != NULL)
		{
			if (pds->a == pts->a)
			{
				if (judge_tree(pts->left, pds->left) == true && judge_tree(pts->right, pds->right) == true)
				{
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
	}
	bool is_tree_Substructure(node<T>*pts, node<T>*pds)
	{
		bool tmp = false;
		if (pts != NULL&&pds != NULL)
		{
			if (pts->a == pds->a)
			{
				tmp = judge_tree(pts, pds);
			}
			if (tmp == false)
				tmp = is_tree_Substructure(pts->left, pds);
			if (tmp == false)
			{
				tmp = is_tree_Substructure(pts->right, pds);
			}
			return tmp;
		}
	}
};
int main()
{
	int arr[] = { 10,5,4,-1,-1,7,-1,-1,12,-1,-1 };
	tree<int> is_tree;
	is_tree.tree_create(arr,11);
	is_tree.print_k(3);

}
