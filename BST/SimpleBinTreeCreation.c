/*
 @Author: Dr.Mydhili K Nair, Professor, ISE Dept, RIT, Bangalore
 Purpose: This program does the following:
 a) Creates Binary Tree through 'Double Recursion' call to 'createTree' function
 b) Checks if the created Binary Tree is a Strictly Binary Tree or not
 c) Displays the tree through 'Double Recursion' call to 'displayTree' function
 
 Test Cases: This program checks the following unit test cases:
 NOTE: First three test cases are ONLY limited to root node
 1) Display error message of the root node is NULL
 2) Determine if Tree is Right SKEWED
 3) Determine if Tree is Left SKEWED
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct myBintree
{
    int marks;
    struct myBintree *left;
    struct myBintree *right;
    
}myBintree;


myBintree *root = NULL;

myBintree * createBinTree()
{
    int m; myBintree *ptr;
    
    printf("\n Press -1 if you dont want to enter marks ");
    scanf("%d", &m); //Remove '&' To DEMO Segmentation Fault
    
    if(m == -1) return NULL;
    else
    {
        ptr = (myBintree *)malloc(sizeof(myBintree));
        ptr->marks = m; ptr->left = NULL; ptr->right =NULL;
        printf("\n Enter Marks for LEFT node of %d ", ptr->marks);
        
        ptr->left = createBinTree();
        
        printf("\n Enter Marks for RIGHT node of %d ", ptr->marks);
        
        ptr->right = createBinTree();
    
        return ptr;
    }
    
}
void displayBinTree(myBintree * root,int i)
{
    int j;
    
    
    if(root !=NULL)
    {
        displayBinTree(root->left,i+1);
        for(j=1;j<=i;j++) printf("\t"); //DEMO : Only prints tab
        //Donot enclose the two printf in brackets as the actual print happens
        //outside the for loop when loop condition fails
        //Remove the comment in below print to see the values of i,j from stack
        //printf("%d(%d:%d)\n",root->marks,i,j);
        
        printf("%d \n",root->marks);
        displayBinTree(root->right,i+1);
    }
    
}//end display

int main()
{
    root = createBinTree();
    
    printf("\n Displaying....\n");
    if(root == NULL)
        printf("\n Test Case #1: Root does not exist - Tree not created\n");
    else if ((root->left == NULL && root->right != NULL))
        printf("\n Test Case #2: Tree is Right SKEWED\n");
    else if((root->right == NULL && root->left != NULL))
        printf("\n Test Case #3: Tree is Left SKEWED\n");
    
    displayBinTree(root, 1);
    
}




