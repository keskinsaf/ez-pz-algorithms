#ifndef TWOTHREETREE
#define TWOTHREETREE

class TwoThreeTree{
  private:
    int value;
    TwoThreeTree* parent_;
    TwoThreeTree* left_;
    TwoThreeTree* mid_;
    TwoThreeTree* right_;
    TwoThreeTree* extra_;
  public:
    TwoThreeTree(){parent_ = left_ = nullptr; };
    TwoThreeTree( int left, int right );
    TwoThreeTree( int left, int mid, int right );
    ~TwoThreeTree();
    bool isEmpty( TwoThreeTree* );
    static TwoThreeTree* search( TwoThreeTree* tree, int key );
    TwoThreeTree* insert( TwoThreeTree* node, int& key );
    TwoThreeTree* insertTwo( TwoThreeTree* tree, int, int = -99999 );

    static void split( TwoThreeTree* );
    static void printInorder( TwoThreeTree* );
    static TwoThreeTree* printSearchedElement( TwoThreeTree* );
};



#endif
