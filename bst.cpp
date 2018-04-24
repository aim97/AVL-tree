// constructor
template <class T1, class T2>
bst<T1, T2>::bst(T1 k, T2 v):key(k), value(v){
	lvl = 1;
}

// member funtions
template <class T1, class T2>
void bst<T1, T2>::display(){
	/**
	 * this method is used to recursively display the tree contents
	 * parameters : none
	 * returns    : none
	 * excepions  : none
	 * */
	cout << "[ ";
	if(left) {left->display();cout << " , ";}         // display left
	cout <<  key << " : " << "\""<<value << "\"";     // display current
	if(right) {cout << " , ";right->display();}       // display right
	cout << " ] ";
}

template <class T1, class T2>
bool bst<T1, T2>::containsKey(T1 k){
	/**
	 * this method is used to check if the given key exists in the sub tree or not
	 * parameters : k:<T1> "key to check"
	 * returns    : bool   "true if the key exists / false if not"
	 * exceptions : none
	 * */
	if (key == k)return true;                         // if this is the key we are looking for; return true
	else if(k < key){ 
		if(left) left->containsKey(k);                // if the key we are looking for is less than current; search in left sub tree
		else return false;
	}else{
		if(right) right->containsKey(k);              // if the key we are looking for is larger than current; search in right sub tree
		else return false;
	}
}

template <class T1, class T2>
T2 bst<T1, T2>::lookUp(T1 k){
	/**
	 * this method is used to get the value associated with the given key
	 * parameters : k:<T1> "key to check"
	 * returns    : T2  "value associated with given key"
	 * exceptions : "key not found"
	 * */
	if (key == k)return value;                // get the value of that key
	else if(k < key){
		if(left) left->containsKey(k);        // check the left subtree
		else throw "key not found";
	}else{
		if(right) right->containsKey(k);      // check the right subtree
		else throw "key not found";
	}
}

template <class T1, class T2>
void bst<T1, T2>::modify(T1 k , T2 v){
	/**
	 * this method is used to get the value associated with the given key
	 * parameters : k:<T1> "key to check" , v:<T2> "new value"
	 * returns    : void
	 * exceptions : "key not found"
	 * */
	if(key == k) value = v;
	else if(k < key){
		if(left) left->modify(k, v);
		else throw "key not found";
	}else{
		if(right) right->modify(k, v);
		else throw "key not found";
	}
}


// static member functions
template <class T1, class T2>
int bst<T1, T2>::lvls(bst<T1, T2>* node){
	/**
	 * returns the height of the subtree given to it
	 * parameters  : node:<bst<T1, T2>* > "the subtree to get the height of"
	 * return type : int
	 * exceptions  : none
	 * */
	if(node) return node->lvl;    // if node is not null : return the height of it
	else return 0;                // node is not created yet so height of 0
}


template <class T1, class T2>
bst<T1, T2>* bst<T1, T2>::rotateRight(bst<T1, T2>* node){
	/**
	 * this method is used to rotate the subtree to the right to re-balance
	 * parameters : node:< bst<T1, T2>* > "subtree to rotate"
	 * returns    : bst<T1, T2>*  "root of new balanced subtree"
	 * exceptions : none
	 * */
	bst<T1, T2> *x  = node->left;                // assign the new root of the subtree to x
    bst<T1, T2> *tmp = x->right;                 // hold the right of x in tmp 
    x->right = node;                             // make the old root to be the right of the new one
    node->left = tmp;                            // get the tmp to be the left of the old root
    // recalculate the lvl of both
    node->lvl = max( lvls(node->left), lvls(node->right))+1;
    x->lvl = max( lvls(x->left), lvls(x->right))+1;
	return x; // return the new root to be assigned to the value hold be the actual old root
}

template <class T1, class T2>
bst<T1, T2>* bst<T1, T2>::rotateLeft (bst<T1, T2>* node){
	/**
	 * this method is used to rotate the subtree to the left to re-balance
	 * parameters : node:< bst<T1, T2>* > "subtree to rotate"
	 * returns    : bst<T1, T2>*  "root of new balanced subtree"
	 * exceptions : none
	 * */
	bst<T1, T2> *x  = node->right;                // assign the new root of the subtree to x
    bst<T1, T2> *tmp = x->left;                   // hold the left of x in tmp 
    x->left = node;                               // make the old root to be the left of the new one
    node->right = tmp;                            // get the tmp to be the right of the old root
    // recalculate the lvl of both
    node->lvl = max( lvls(node->left), lvls(node->right)) + 1;
    x->lvl = max( lvls(x->left), lvls(x->right)) + 1; 
    return x; // return the new root to be assigned to the value hold be the actual old root
}


template <class T1, class T2>
bst<T1, T2>* bst<T1, T2>::insert(bst<T1, T2>* node, T1 k, T2 v){
	/**
	 * this function takes a key-value pair and inserts it into the given subtree
	 * if the insertion missed up the tree balance then make appropriate rotation and reassign the root of the tree to the new value
	 * parameters : node:< bst<T1, T2> > "the root of the subtree to insert in"
	 *              k:<T1>  "the key to insert" , v:<T2> "the value associated with that key"
	 * returns    : bst<T1, T2> "the new value of the root of the tree after the rebalance"
	 * exceptions : "key already exists"
	 * */
	if(node == NULL) return new bst(k, v);
	
	if(node->key == k)throw "key already exists";
	else if(k < node->key){
		node->left = bst::insert(node->left, k, v);
	}else{
		node->right = bst::insert(node->right, k, v);
	}
	
	int l_lvl = lvls(node->left);
	int r_lvl = lvls(node->right);
	node->lvl = max(l_lvl, r_lvl) + 1;
	
	int balance = l_lvl - r_lvl;
    if(balance > 1 && k < node->left->key)
        return rotateRight(node);
 
    if(balance < -1 && k > node->right->key)
        return rotateLeft(node);
 
    if(balance > 1 && k > node->left->key){
        node->left =  rotateLeft(node->left);
        return rotateRight(node);
    }
    if(balance < -1 && k < node->right->key){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

template <class T1, class T2>
bst<T1, T2>* bst<T1, T2>::set(bst<T1, T2>* node, T1 k, T2 v){
	/**
	 * this function takes a key-value pair and inserts it into the given subtree
	 * if the insertion missed up the tree balance then make appropriate rotation and reassign the root of the tree to the new value
	 * parameters : node:< bst<T1, T2> > "the root of the subtree to insert in"
	 *              k:<T1>  "the key to insert" , v:<T2> "the value associated with that key"
	 * returns    : bst<T1, T2> "the new value of the root of the tree after the rebalance"
	 * exceptions : "key already exists"
	 * */
	if(node == NULL) return new bst(k, v);
	
	if(node->key == k) node->value = v;
	else if(k < node->key){
		node->left = bst::set(node->left, k, v);
	}else{
		node->right = bst::set(node->right, k, v);
	}
	
	int l_lvl = lvls(node->left);
	int r_lvl = lvls(node->right);
	node->lvl = max(l_lvl, r_lvl) + 1;
	
	int balance = l_lvl - r_lvl;
    if(balance > 1 && k < node->left->key)
        return rotateRight(node);
 
    if(balance < -1 && k > node->right->key)
        return rotateLeft(node);
 
    if(balance > 1 && k > node->left->key){
        node->left =  rotateLeft(node->left);
        return rotateRight(node);
    }
    if(balance < -1 && k < node->right->key){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}
