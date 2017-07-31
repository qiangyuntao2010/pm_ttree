//  
// Ttree.h: header file  
//  
// Copyright (C) liuxuezong.  All rights reserved  
//  
// This source is free to use as you like.  If you make  
// any changes please keep me in the loop.  Email them to  
// liuxuezong@126.com.  
//  
// PURPOSE:  
//  
//  To implement thread as a C++ object  
//  
// REVISIONS  
// =======================================================  
// Date: 2010.12.03   
// Name: liuxuezong  
// Description: File creation  
//  
// Date:  
// Name:  
// Description:  
//  
//  
//////////////////////////////////////////////////////////////////////  
#ifndef _TTREE_H_  
#define _TTREE_H_  
  
enum   
{   
   pageSize = 125,  
   minItems = pageSize - 2 // minimal number of items in internal node  
};  

/*typedef struct key_t 
{
	char k[16];
	key_t(const char *str="")
	{
		bzero(k,sizeof(k));
		strcpy(k,str);
	}
}t_key;*/

typedef struct key_value_pair
{
	char key[16];
	char value[16];
	key_value_pair(const char *str = " ")
	{
		bzero(value,sizeof(value));
		strcpy(value,str);
	}
}kv_t;

enum TraverseOrder  
{  
    PreOrder,  
    InOrder,  
    PostOrder,  
    LevelOrder  
};  
  
//typedef int ElementData;  
//typedef int ElementType;   
  
typedef struct tagTTREENODE  
{     
    tagTTREENODE *parent;
	tagTTREENODE *left;         // Left child pointer.  
    tagTTREENODE *right;        // Right child pointer.  
    unsigned short int nItems;  // Internal node items.  
   // t_key key[pageSize]; // Item key array.  
   // ElementData item[pageSize]; // Item data array. 
    kv_t item[pageSize];
    char bf;                    // Balabce factor(bf = right subtree height - left subtree height)     
} TTREENODE;// *LPTTREENODE, *PTTREENODE;  
  
class CTtree   
{  
public:  
  
    // Constructor.   
    CTtree();  
  
    // Destructor.  
    virtual ~CTtree();  
  
public:  
  
    // Insert key with data into T-Tree.  
    void Insert(ElementType key, ElementData data);  
  
    // Delete node with key from T-Tree.  
    void Delete(ElementType key);  
  
    // Find a node with key, retutrn value = -1 no found, >=0 found.  
    ElementData Find(ElementType key);   
      
    // Traversing T-tree.  
    void TraverseTree(TraverseOrder order);  
      
    // return the current size of the t-tree's node.  
    int GetNodeSize();  
  
    // Get t-tree's depth.  
    int Depth();  
  
    // Get the minimum node.  
    const TTREENODE *GetMinNode();  
  
    // Get the maximum node.  
    const TTREENODE *GetMaxNode();  
  
    // Depending on the application, you can inherit your comparison function.  
    virtual int keycompare(ElementType key1, ElementType key2);  
  
    // Clean the whole T-Tree's nodes.  
    void Clear();  
  
    // Test if the tree is logically empty.Return true if empty, false otherwise.  
    bool IsEmpty( ) const;  
  
// Traverse nodes  
private:  
  
    // Pre-order traverse.  
    void PreOrderTraverse(TTREENODE *pNode) const;  
  
    // In-order traverse.  
    void InOrderTraverse(TTREENODE *pNode) const;  
  
    // Post-order traverse.  
    void PostOrderTraverse(TTREENODE *pNode) const;  
  
    // Level-order traverse.  
    void LevelOrderTraverse(TTREENODE *pNode) const;  
  
private:  
      
    // Malloc node space from memory buffer.  
    TTREENODE *MallocNode();  
  
    // Free node from memory buffer.  
    void FreeNode(TTREENODE *pNode);  
  
    // To obtain the maximum value of a, b.  
    int Max(int a, int b) const;  
  
    bool _insert(TTREENODE *&pNode, ElementType key, ElementData data);  
  
    int remove(TTREENODE *&pNode, ElementType key);  
  
    void _earse(TTREENODE *pNode);  
  
// Rotate operate  
private:  
  
    // Get balabce factor of node.  
    int BalanceFactor(TTREENODE *pNode) const;   
  
    // LL (clock wise) type adjustment.  
    TTREENODE *SingleRotateLeft(TTREENODE *pNode);  
  
    // RR (counter clock wise) type adjustment.  
    TTREENODE *SingleRotateRight(TTREENODE *pNode);  
  
    // LR (after the first reverse cis) type adjustment.  
    TTREENODE *DoubleRotateLeft(TTREENODE *pNode);  
  
    // RL (Soon after the first reverse) type adjustment.  
    TTREENODE *DoubleRotateRight(TTREENODE *pNode);  
  
    // Balance T-tree's right branch.  
    int BalanceRightBranch(TTREENODE *&pNode);  
  
    // Balance T-tree's left branch.  
    int BalanceLeftBranch(TTREENODE *&pNode);  
  
// Attributes  
protected:  
  
    // T-tree's root.  
    TTREENODE   *root;        
  
    // T-tree's current already alloc node size.  
    int         m_nSize;  
};  
  
#endif // _TTEE_H_  
