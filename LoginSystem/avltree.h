#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <iomanip>
#include <vector>
#include "string"
#include "student.h"
#include <fstream>
using namespace std;

template <typename T>
class avlnode{
    public:
    T data;
    int height;
    avlnode<T>* left;
    avlnode<T>* right;
    avlnode():height(0),left(0),right(0){}
    avlnode(T item):height(0),data(item),left(0),right(0){}
};
template <typename T>
class avltree{
    private:
    ofstream outer;
    avlnode<T>* root;
    vector<T> allitem;
    int getheight(avlnode<T>* target);              //获取节点的高度信息
    vector<T>& inorder2(avlnode<T>* target);        //把所有的节点存储到一个向量中并返回向量的引用
    void insert(avlnode<T>* &target,T item);        //插入数据
    bool search(avlnode<T>* root,T item);           //查找数据
    void leftrotate(avlnode<T>* &target);           //左旋
    void rightrotate(avlnode<T>* &target);          //右旋
    void lrrotate(avlnode<T>* &target);             //左右旋
    void rlrotate(avlnode<T>* &target);             //右左旋
    void deletenode(avlnode<T>* &target,T item);    //删除节点
    void inorder(avlnode<T>* target);               //中序遍历
    void seebalence(avlnode<T>* target);            //查看平衡度
    void showtree(avlnode<T>* target,int depth);    //显示树
    void showheight(avlnode<T>* target,int depth);  //显示高度
    void showinout(avlnode<T>* target,int depth);   //把树显示到外部文件
    public:
    avltree():root(NULL){}                          //构造函数
    void insert(T item);                            //插入节点的接口
    void showinout();                               //显示到外部文件
    vector<T>& inorder2();                          //把节点的数据放到向量并返回的接口
    bool search(T item);                            //查找数据的接口
    void deletenode(T item);                        //删除数据的接口
    void showheight();                              //显示高度的接口
    void inorder();                                 //中序遍历的接口
    void seebalence();                              //查看平衡度的接口
    void showtree();                                //显示树到外部文件的接口
    int max(int a,int b);                           //max函数
};
template <typename T>
int avltree<T>::getheight(avlnode<T>* target){		//得到node的height值
    if(target == 0) return -1;
    else return target->height;
}
template <typename T>
void avltree<T>::leftrotate(avlnode<T>* &target){
    avlnode<T>* temp = target;                      //新建一个节点指针把target保存
    target = target->right;                         //target指针指向target的右孩子
    avlnode<T>* temp2 = target->left;               //新建一个指针保存当前的target的做孩子
    target->left = temp;                            //当前target的左孩子置为原来的target
    temp->right = temp2;                            //原来target的右孩子置为temp2
    target->height = max(getheight(target->left),getheight(target->right)) + 1;		//可以发现，只有两个点的高度发生变化了
    temp->height = max(getheight(temp->left),getheight(temp->right))+1;
}
template <typename T>
void avltree<T>::rightrotate(avlnode<T>* &target){			//同左旋
    avlnode<T>* temp = target;
    target = target->left;
    avlnode<T>* temp2 = target->right;
    target->right = temp;
    temp->left = temp2;
    target->height = max(getheight(target->left),getheight(target->right)) + 1;
    temp->height = max(getheight(temp->left),getheight(temp->right))+1;
}
template <typename T>
void avltree<T>::lrrotate(avlnode<T>* &target){		//左右旋其实是先进行一次左旋在进行一次右旋，只是旋转的点不一样。
    leftrotate(target->left);
    rightrotate(target);
}
template <typename T>
void avltree<T>::rlrotate(avlnode<T>* &target){			//同左右旋
    rightrotate(target->right);
    leftrotate(target);
}
template <typename T>
void avltree<T>::insert(T item){        //插入节点
    insert(root,item);
}
template <typename T>
void avltree<T>::insert(avlnode<T>* &target,T item){
    if(target == 0){							//空的话建立新节点并插入
        target = new avlnode<T>(item);
        return ;
    }
    else if(target->data > item	){              //如果目标的数据小于当前节点的值，插入数据到它的左子树，插入完后回溯回来调整平衡
        bool dorotate = false;
        insert(target->left,item);
        //cout<<target->height<<"     ";
        target->height = max(getheight(target->left),getheight(target->right)) + 1;
        //cout<<target->height<<endl;
        if(getheight(target->left) - getheight(target->right) >= 2){
            if(target->left->data > item){
                avlnode<T>* temp;
                if(target->data	 == root->data){                //如果当前节点就是root，那么就需要把root变为它的左孩子
                    temp = target->left;
                    dorotate = true;
                }
                rightrotate(target);
                if(dorotate == true) root = temp;

            }
            else{
                avlnode<T>* temp;
                if(target == root){                 //同上，判断当前节点为root的情况
                    temp = target->left->right;
                    dorotate = true;
                }
                lrrotate(target);
                if(dorotate == true) root = temp;
            }
        }
    }
    else if(target->data < item	){              //同插入到左子树
        insert(target->right,item);
        //cout<<target->height<<"     ";
        target->height = max(getheight(target->left),getheight(target->right)) + 1;
        //cout<<target->height<<endl;
        bool dorotate = false;
        if(getheight(target->left) - getheight(target->right) <= -2){
            if(target->right->data < item){
                avlnode<T>* temp;
                if(target->data	 == root->data){
                    temp = target->right;
                    dorotate = true;
                }
                leftrotate(target);
                if(dorotate == true) root = temp;
            }
            else{
                avlnode<T>* temp;
                if(target == root){
                    temp = target->right->left;
                    dorotate = true;
                }
                rlrotate(target);
                if(dorotate == true) root = temp;
            }
        }

    }
    target->height = max(getheight(target->left),getheight(target->right)) + 1;			//important，调增插入之后的那段树的高度
}
template <typename T>
bool avltree<T>::search(T item){            //查找数据的接口
    return search(root,item);
}
template <typename T>
bool avltree<T>::search(avlnode<T>* target,T item){                 //查找数据
    avlnode<T>* pos = target;
    while(pos != 0){
        if(pos->data == item){
            return true;
        }
        if(pos->data > item){
            pos = pos->left;
        }
        else{
            pos = pos->right;
        }
    }
    return false;
}
template <typename T>
void avltree<T>::deletenode(T item){            //删除元素
    if(!search(item)){
        cout<<"没有这个元素\n";
        return ;
    }
    deletenode(root,item);
}
template <typename T>
void avltree<T>::deletenode(avlnode<T>* &target,T item){        //删除节点
    if(target->data > item){
        deletenode(target->left,item);
    }
    else if(target->data < item){
        deletenode(target->right,item);
    }
    else{
        if(target->left!=NULL && target->right != NULL){        //如果要删除的节点的左右孩子都不为空，那么找到刚好比左孩子大一点的节点，替换当期节点值为那个节点，然后再删除那个节点。
            avlnode<T>* temp = target->left;
             while(temp->right != 0){
                temp = temp->right;
            }
            target->data = temp->data;
            deletenode(target->left,target->data);
        }
        else{                               //否则只有一条子链，直接连上即可
            avlnode<T>* temp = target;
            if(target->left == NULL) target = target->right;
            else if(target->right == NULL) target = target->left;
            delete temp;
        }
    }
    if(target == NULL) return ;
    bool dorotate = false;
    target->height = max(getheight(target->left),getheight(target->right)) + 1;
    if(getheight(target->left) - getheight(target->right) >= 2){                //调整平衡，判断现在的不平衡度是有哪边产生的，然后相应作出调整。
        if(getheight(target->left->left) >= getheight(target->left->right)){
            avlnode<T>* temp;
            if(target->data	 == root->data){
                temp = target->left;
                dorotate = true;
            }
            rightrotate(target);
            if(dorotate == true) root = temp;
        }
        else{
            avlnode<T>* temp;
            if(target->data	 == root->data){
                temp = target->left->right;
                dorotate = true;
            }
            lrrotate(target);
            if(dorotate == true) root = temp;
        }
    }
    else if(getheight(target->right) - getheight(target->left) >= 2){
        avlnode<T>* temp;
        if(getheight(target->right->right) >= getheight(target->right->left	)){
            if(target->data	 == root->data){
                temp = target->right;
                dorotate = true;
            }
            leftrotate(target);
            if(dorotate == true) root = temp;
        }
        else{
            if(target->data	 == root->data){
                temp = target->right->left;
                dorotate = true;
            }
            rlrotate(target);
            if(dorotate == true) root = temp;
        }
    }
}
template <typename T>
void avltree<T>::inorder(){         //中序遍历接口
    inorder(root);
    cout<<endl;
}
template <typename T>
void avltree<T>::inorder(avlnode<T>* target){       //中序遍历
    if(target == 0) return ;
    inorder(target->left);
    cout<<" "<<target->data;
    inorder(target->right);
}
template <typename T>
void avltree<T>::seebalence(){          //查看平衡度
    seebalence(root);
    cout<<endl;
}
template <typename T>
void avltree<T>::seebalence(avlnode<T>* target){
    if(target == 0) return ;
    seebalence(target->left);
    if(target->left != 0 && target->right != 0){
        cout<<getheight(target->left)-getheight(target->right)<<" ";
    }
    seebalence(target->right);
}
template <typename T>
void avltree<T>::showtree(){            //显示树
    showtree(root,0);
    cout<<endl;
}
template <typename T>
void avltree<T>::showtree(avlnode<T>* nodenow,int depth){
    if(nodenow != NULL){
        showtree(nodenow->right,depth+8);
        cout<<setw(depth)<<" "<<nodenow->data<<endl;
        showtree(nodenow->left,depth+8);
    }
}
template <typename T>
void avltree<T>::showinout(){               //显示树到外部文件
    outer.open("showit.txt",ios::out);      //打开文件
    showinout(root,0);                      //调用驱动的函数
    outer<<"\n";
    outer.close();                          //关闭文件
}

template <typename T>
void avltree<T>::showinout(avlnode<T>* nodenow,int depth){
    if(nodenow != NULL){
        showinout(nodenow->right,depth+8);
        outer<<string(depth,' ')<<nodenow->data<<"\n";
        showinout(nodenow->left,depth+8);
    }
}

template <typename T>
void avltree<T>::showheight(){          //显示高度
    showheight(root,0);
    cout<<endl;
}
template <typename T>
void avltree<T>::showheight(avlnode<T>* nodenow,int depth){
    if(nodenow != NULL){
        showheight(nodenow->right,depth+8);
        cout<<setw(depth)<<" "<<getheight(nodenow)<<endl;
        showheight(nodenow->left,depth+8);
    }
}

template <typename T>
vector<T>& avltree<T>::inorder2()
{
    allitem.clear();
    inorder2(root);
    return allitem;
}

template <typename T>
vector<T>& avltree<T>::inorder2(avlnode<T> *target)
{
    if(target != 0)
    {
        inorder2(target->left);
        allitem.push_back(target->data);
        inorder2(target->right);
    }
}

template <typename T>
int avltree<T>::max(int a,int b){
    if(a>b) return a;
    return b;
}



#endif // AVLTREE_H
