#include "TwoThreeTree.hpp"
#include <utility>
#include <cstdio>

TwoThreeTree::TwoThreeTree( int left, int mid ){
    //if left is less than mid, swap them
    if ( left > mid )
        std::swap(left, mid);
    /*
        create left and middle leaaf nodes. roots value will be the same as
        the rightest one. For now, left and mid children created with default
        constructor due to make their children empty and its depth is 1. And
        setting right child to null due this node will have only two values
        for now.
    */
    this->parent_ = this->right_ = nullptr;
    this->left_ = new TwoThreeTree(); this->mid_ = new TwoThreeTree();
    this->left_->value = left; this->value = this->mid_->value = mid;
    this->left_->parent_ = this->mid_->parent_ = this;
}

TwoThreeTree::TwoThreeTree( int left, int mid, int right ){
    //making parameters in order
    if ( left > mid )
        std::swap(left, mid);
    if ( mid > right )
        std::swap(mid, right);
    if ( left > mid )
        std::swap(left, mid);

    /*
        create all three leaf nodes. roots value will be the same as
        the rightest one. For now, left and mid children created with default
        constructor due to make their children empty and its depth is 1. And
        setting right child to null due this node will have only two values
        for now.
    */
    this->parent_ = nullptr;
    this->left_  = new TwoThreeTree(); this->mid_ = new TwoThreeTree();
    this->right_ = new TwoThreeTree();
    this->left_->value = left; this->mid_->value = mid;
    this->value = this->right_->value = right;
    this->left_->parent_ = this->right_->parent_ = this->mid_->parent_ = this;
}

TwoThreeTree::~TwoThreeTree(){
    if ( this->left_ != nullptr ) {
        delete this->left_;
    }
    if ( this->mid_ != nullptr ) {
        delete this->mid_;
    }
    if ( this->right_ != nullptr ) {
        delete this->right_;
    }
    if ( this->extra_ != nullptr ) {
        delete this->extra_;
    }
    this->parent_ = nullptr;
}

bool TwoThreeTree::isEmpty( TwoThreeTree* node ){
    if ( node->left_ == nullptr ) return true; else return false;
}

TwoThreeTree* TwoThreeTree::search( TwoThreeTree* tree, int key ){
    if ( tree == nullptr ) return nullptr;
    if ( tree->left_ == nullptr ){
        if ( tree->value == key ){
            return tree;
        }else return nullptr;
    }
    if ( key <= tree->left_->value )
        return search(tree->left_, key);
    if ( key <= tree->mid_->value )
        return search(tree->mid_, key);
    return search(tree->right_, key);
}

//secKey has a default value that is a very small number, so it will be left child.
TwoThreeTree* TwoThreeTree::insertTwo( TwoThreeTree* tree, int key, int secKey ){
    if( tree->left_ == nullptr ){
        std::swap(key, secKey);
        tree = new TwoThreeTree();
        tree->left_ = new TwoThreeTree();   tree->left_->value = key;
        tree->mid_ = new TwoThreeTree();  tree->value = tree->mid_->value = secKey;
        tree->right_ = nullptr;
    }
    return tree;
}

TwoThreeTree* TwoThreeTree::insert( TwoThreeTree* node, int& key ){
    if ( node->left_ == nullptr )
        return insertTwo(node, key);

    //if we reached the node just up of the leaves
    if( node->left_->left_ == nullptr ){
        //if the value is more than node's value, then it should be rightest one.
        if ( key > node->value ) {
            //if node has 2 elements
            if ( node->right_ == nullptr ) {
                node->right_ = new TwoThreeTree();
                node->right_->parent_ = node;
                node->value = node->right_->value = key;
                return node;
            }
            //if it has 3, then split
            else{
                node->extra_ = new TwoThreeTree();
                node->extra_->parent_ = node;
                node->extra_->value   = key;
                split(node);
                return node;
            }
        }//if it has 3 elements and key is less than node's value but bigger than
            //mid
        else if ( key > node->mid_->value ) {
            node->extra_ = new TwoThreeTree();
            node->extra_->parent_ = node;
            node->extra_->value   =node->right_->value;
            node->right_->value   = key;
            split(node);
            return node;
        }//if the key is bigger than smallest between the children
        else if ( key > node->left_->value ) {
            //if node has only 2 children
            if ( node->right_ == nullptr ) {
                node->right_ = new TwoThreeTree();
                node->right_->parent_ = node;
                node->right_->value   = node->mid_->value;
                node->mid_->value     = key;
                return node;
            }//if node has 3 children
            else{
                node->extra_          = new TwoThreeTree();
                node->extra_->parent_ = node;
                node->extra_->value   = node->right_->value;
                node->right_->value   = node->mid_->value;
                node->mid_->value     = key;
                split(node);
                return node;
            }
        }//if the value will be the smallest one
        else{//if the node has only 2 children
            if ( node->right_ == nullptr ) {
                node->right_ = new TwoThreeTree();
                node->right_->parent_ = node;
                node->right_->value   = node->mid_->value;
                node->mid_->value     = node->left_->value;
                node->left_->value    = key;
                return node;
            }//if the node has already 3 children
            else{
                node->extra_          = new TwoThreeTree();
                node->extra_->parent_ = node;
                node->extra_->value   = node->right_->value;
                node->right_->value   = node->mid_->value;
                node->mid_->value     = node->left_->value;
                node->left_->value    = key;
                split(node);
                return node;
            }
        }
    }
    if ( key <= node->left_->value ) {
      return insert( node->left_, key );
    }
    if ( key <= node->mid_->value ) {
      return insert( node->mid_, key );
    }
    else{
        if ( node->right_ != nullptr ) {
            return insert( node->right_, key );
        }
        else{
            return insert( node->mid_, key);
        }
    }

    return nullptr;
}
//lost much time, will not be completed now.
TwoThreeTree* TwoThreeTree::split( TwoThreeTree* node ){
    TwoThreeTree* parent;
    if ( node->parent_->right_ == nullptr ) {
        node->parent_->right_ = new TwoThreeTree(node->right_->value, node->extra_->value);
        parent = node->parent_;
        parent->right_->parent_ = parent;
        while ( parent != nullptr ) {
            parent->value = node->extra_->value;
            parent = parent->parent_;
        }
        node->value = node->mid_->value;
        delete node->right_;
        delete node->extra_;
    }
    return nullptr;
}

void TwoThreeTree::printInorder( TwoThreeTree* node ){
    if ( node->left_ == nullptr ) {
      return;
    }
    if ( node->left_->left_ == nullptr ) {
      printf("The value of the left child for node '%d' is: %d\n",
              node->value, node->left_->value);
      printf("The value of the middle child for node '%d' is: %d\n",
              node->value, node->mid_->value);
      if ( node->right_ != nullptr ) {
      printf("The value of the right child for node '%d' is: %d\n",
              node->value, node->right_->value);
      }
      return;
    }
    printInorder( node->left_ );
    printInorder( node->mid_ );
    if ( node->right_->left_ != nullptr ) {
      printInorder( node->right_ );
    }

}

TwoThreeTree* TwoThreeTree::printSearchedElement( TwoThreeTree *node ){
    if ( node == nullptr )
        printf("Could not be found!\n");
    else
        printf("Node '%d' is found!\n", node->value);
    return node;
}
