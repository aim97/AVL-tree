#ifndef BST_H
#define BST_H

#include <bits/stdc++.h>
using namespace std;

template <class T1, class T2>
class bst{
	private:
		T1 key;
		T2 value;
		bst* left = NULL;
		bst* right = NULL;
		
		int lvl = 0;
		
		// helper funcions
		static bst<T1, T2>* rotateRight(bst<T1, T2>*);
		static bst<T1, T2>* rotateLeft (bst<T1, T2>*); 
		static int lvls(bst<T1, T2>*);
	public:
		bst(T1, T2);
		bool containsKey(T1);
		T2 lookUp(T1);
		static bst<T1, T2>* insert(bst<T1, T2>*, T1, T2);
		void modify (T1, T2);
		static bst<T1, T2>* set(bst<T1, T2>*, T1, T2);
		void display();
		
	
};


#include "bst.cpp"
#endif

/**
 * BST class
 * ----------
 * bst()  constructor : this cnstructor creates a new bst with the given key-value pairs
 * 		                parameters  : k:<T1> , v:<T1>
 * 1 - fields
 * ==================
 * key   : this is like the index used to order the tree
 * value : this is the value associated to the given key
 * left  : this is a pointer pointing to the left child element (sub tree)
 * right : this is a pointer pointing to the right child element (sub tree)
 * lvl   : the maximum number of levels currently under this node
 * 
 * 2 - methods
 * ==================
 * 1 - containsKey(T1): this method takes value of type T1 and returns if that value occurs in the tree as a key or not
 * 		parameters  : k:<T1>
 * 		return type : bool
 * 		excpetions  : none
 * 
 * 2 - lookup(T1)     : this method takes a key and returns the value associated with it, raising an exception if key not found
 * 		parameters  : k:<T1>
 * 		return type : v:<T2>
 *              excpetions  : "key not found"
 * 
 * 3 - modify(T1, T2) : changes that value associated with the given key of type T1 (1st argument) to the given value of type T2 (2nd argument)
 * 		parameters  : k:<T1> , v:<T2>
 * 	        return type : void 
 *              exceptions  : "key not found"
 * 
 * 4 - display()      : this one displays the tree in preorder left-root-right as [[left], rootkey : "rootValue" , [right]]
 * 		parameters  : none
 * 		return type : void
 *              exceptions  : none
 * 
 * static methods
 * =================
 * 1 - insert() : 
 * 	inserts a new key value pair of the given two values such that 1st parameter is key and 2nd one is value
 * 		parameters  : node:<bst<T1, T2>* > , k:<T1> , v:<T2>
 * 		return type : bst<T1, T2>*
 * 	        exceptions  : "key already exists"
 * 
 * 2 - set()      : 
 *      changes that value associated with the given key of type T1 (1st argument) to the given value of type T2 (2nd argument) 
 *      if key not found make it
 * 		parameters  : node <bst<T1, T2>* >, k:<T1> , v:<T2>
 * 		return type : bst<T1, T2>*
 *      	excpetions  : none
 * 
 * 
 * 3 - rotateLeft()   : 
 * 	does the left rotation operation on the given subtree
 * 		parameters  : node:<bst<T1, T2> >
 *              return type : bst<T1, T2>*
 * 		excpetions  : none
 * 
 * 4 - rotateRight()  : 
 *	does the right rotation operation on the given subtree
 * 		parameters  : node:<bst<T1, T2> >
 *              return type : bst<T1, T2>*
 * 		excpetions  : none
 * 
 * 5 - lvl()          : 
 *	returns the height of the subtree given to it
 *              parameters  : node:<bst<T1, T2>* >
 *              retunn type : int 
 *              exceptions  : none
 * possible updates
 * =================
 * 1 - erase(T1)      : erases the node with given key
 * 		parameters  : k:<T1>
 * 		return type : void
 *              exceptions  : "key not found"
 * */
