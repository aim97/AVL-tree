template <class T1, class T2>
inline void avl<T1, T2>::display(){
	/**
	 * this function displayes the contect of the tree in preoreder
	 * parameters : none
	 * returns    : none
	 * excpetions : none
	 * */
	if(root) root->display(); // if there is a root display it
	else cout << "[]";        // if not display "[]"
	cout << endl;             // print a new line any way
}
template <class T1, class T2>
inline T2 avl<T1, T2>::lookUp(T1 k){
	/**
	 * this function is used to get the value associated with the given key
	 * parameters : k:<T1> "the key to look up"
	 * returns    : T2 "the value associated with the given key"
	 * exceptions : "key not found"
	 * */
	if(root) return root->lookUp(k);  // if the root exists search in it
	else throw "key not found";       // if not then there can't be such a key
}
template <class T1, class T2>
inline bool avl<T1, T2>::containsKey(T1 k){
	/**
	 * this function checks if some key exists in the tree or not
	 * parameters : k<T1> "the key to search for"
	 * returns    : bool "true if found / false if not found"
	 * exceptions : none
	 * */
	if(root) return root->containsKey(k);  // if there is a root, search there, and return the result
	else return false;                     // if not then there can't be such a key
}

template <class T1, class T2>
inline void avl<T1, T2>::modify(T1 k, T2 v){
	/**
	 * this function modifies the value associated with the given key to the given value
	 * parameters : k<T1> "key to update" v<T2> "new value"
	 * returns    : none
	 * exceptions : "key not found"
	 * */
	if(root) root->modify(k, v);   // if there is a root modify there
	else throw "key not found";    // if not then there can't be such a key
}

template <class T1, class T2>
inline void avl<T1, T2>::insert(T1 k, T2 v){
	/**
	 * this function adds the given key-value pair to the tree
	 * parameters : k<T1> "key to insert" v<T2> "value to associate with it"
	 * returns    : none
	 * exceptions : "key already exists"
	 * */
	root = bst<T1, T2>::insert(root, k, v);  // insert a new node, then reset the root in case of re-balance
}

template <class T1, class T2>
inline void avl<T1, T2>::set(T1 k, T2 v){
	/**
	 * this function mdofies the value associated with given key to the given value if key is found and if not found add the key value pair to the tree
	 * parameters : k<T1> "key to insert" v<T2> "value to associate with it"
	 * returns    : none
	 * exceptions : none
	 * */
	root = bst<T1, T2>::set(root, k, v);     // set the given node, then reset the root in case of re-balance
}
