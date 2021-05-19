/*
 * @Description: 
 * @Author: Cai Minya
 * @Date: 2021-04-07 15:14:22
 * @LastEditTime: 2021-05-19 16:42:34
 * @LastEditors: Cai Minya
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef struct BiTNode {
    int data;                   //数据域，此处创建char类型的数据域
    BiTNode *lchild, *rchild;    //左、右指针域
}BiTNode, *BiTree;

/**
 * @description: 先序序列创建二叉树
 * @return {BiTree} 创建好的二叉树
 */
BiTree CreateBiTree()
{	
    BiTree T;
	int item;
	cin >> item;
    if(item == 0) {
        T = nullptr;
    } else {
        T = new BiTNode;
        T->data = item;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
    }
    return T;
}


/**
 * @description: 先序遍历二叉树
 * @return {*}
 */
bool PreOrderTraverse(BiTree& T) {
    if(T) {
        cout << T->data << " " ;    //如果树不为空，就输出值
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    else {
        
        return false;
    }

    return true;
}


/**
 * @description: 中序遍历二叉树方法一：迭代
 * @return {*}
 */
bool InOrderTraverse1(BiTree& T) {
    stack<BiTree> t;
    BiTree p = T;
    
    while(p || (!t.empty())) {
        while(p) {
            t.push(p);
            p = p->lchild;
        }
        
        p = t.top();
        p = p->rchild;
        cout << t.top()->data << " ";
        t.pop();
        
    }
    cout << endl;
    return true;
}
/**
 * @description: 中序遍历二叉树方法二：递归
 * @return {*}
 */
bool InOrderTraverse2(BiTree& T) {
    if(T) {
        InOrderTraverse2(T->lchild); 
        cout << T->data << " " ;    //如果树不为空，就输出值
        InOrderTraverse2(T->rchild);
    }
    else { 
        return false;
    }
    return true;
}
/**
 * @description: 中序遍历二叉树方法三：Morris 中序遍历
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/er-cha-shu-de-zhong-xu-bian-li-by-leetcode-solutio/
 * @return {*}
 */
bool InOrderTraverse3(BiTree& T) {

}


/**
 * @description: 后续遍历二叉树:递归
 * @return {*}
 */
bool PostOrderTraverse(BiTree& T) {
    if(T) {
        PostOrderTraverse(T->lchild); 
        PostOrderTraverse(T->rchild);
        cout << T->data << " " ;    //如果树不为空，就输出值
    }
    else { 
        return false;
    }
    return true;
}


int main() {
    BiTree T = CreateBiTree();
    cout << "preorder:" << endl;
    PreOrderTraverse(T);
    cout << endl;
    cout << "inorder1:" << endl;
    InOrderTraverse1(T);
    cout << "inorder2:" << endl;
    InOrderTraverse2(T);
    cout << endl;
    cout << "postorder:" << endl;
    PostOrderTraverse(T);
    cout << endl;
    return 0;
}