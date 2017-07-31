#include "Ttree.h"  
#define _countof(array) (sizeof(array)/sizeof(*array))  
  
static int a[] = { 30, 28, 45, 15, 16, 17, 19, 90, 25, 36, 31, 32, 20, 95, 23, 91, 21, 11, 12, 13, 10, 8, 9, 7};   
   
int main( void )     
{     
    CTtree tree;       
    int nSize = _countof(a);      
    for(int i = 0; i < nSize; i++ )   
    {     
        ElementType key = a[i];  
        ElementData data = i;  
        tree.Insert(key, data);  
    }  
    tree.TraverseTree(LevelOrder);  
    ElementType datakey = 90;     
    int nDepth = tree.Depth();  
    ElementData dataindex = tree.Find(datakey);  
    const TTREENODE *pNode = tree.GetMinNode();  
    datakey = 7;  
    tree.Delete(datakey);  
    return 0;     
}    
