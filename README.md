# AVL-tree
it's a self balancing Binary Search Tree that rebalances itself after each update in the in it, to keep logarithmic 
1 - fields
============
root : bst tree root

2 - methods
============
1 - containsKey(T1): this method takes value of type T1 and returns if that value occurs in the tree as a key or not
 	parameters  : k:<T1>
  	return type : bool
  	excpetions  : none 
2 - lookup(T1)     : this method takes a key and returns the value associated with it, raising an exception if key not found
 	parameters  : k:<T1>
 	return type : v:<T2>
        excpetions  : "key not found"
            
3 - insert(T1, T2) : inserts a new key value pair of the given two values such that 1st parameter is key and 2nd one is value
        parameters  : k:<T1> , v:<T2>
        return type : void
        exceptions  : "key already exists"

4 - modify(T1, T2) : changes that value associated with the given key of type T1 (1st argument) to the given value of type T2 
		     (2nd argument)
 	parameters  : k:<T1> , v:<T2>
        return type : void 
        exceptions  : "key not found"

5 - set(T1, T2)    : changes that value associated with the given key of type T1 (1st argument) to the given value of type T2 
		     (2nd argument), if key not found make it
        parameters  : k:<T1> , v:<T2>
  	return type : void
        excpetions  : none
  
6 - display()      : this one displays the tree in preorder left-root-right as [[left], rootkey : "rootValue" , [right]]     
	parameters  : none
	return type : void
        exceptions  : none

future updates
1 - erase(T1)      : erases the node with given key
        parameters  : k:<T1>
 	return type : void
        exceptions  : "key not found"
