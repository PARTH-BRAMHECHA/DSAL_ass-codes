//preprocessing statements
#include<iostream>
using namespace std;
struct treenode
{
  int data;
  treenode *left, *right;
};
class MyBST
{
private:
  treenode * root;
public:
  MyBST ()
  {
    root = new treenode ();
    root = NULL;
  }
  treenode *reroot ()
  {
    return root;
  }
  treenode *makenode (int value)
  {
    treenode *temp = new treenode ();
    temp->data = value;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
  }
  void insert (int);
  void Inorder (treenode *);
  void Preorder (treenode *);
  void Postorder (treenode *);
  treenode *search (treenode *, int);
  int height (treenode *);
  void displayleafnode (treenode *);
  void mirror (treenode *);
  treenode *copy (treenode*);
  treenode *Delete (treenode *, int);
  treenode *FindMin (treenode *);
};

treenode* MyBST::copy(treenode* T){
  if (T == NULL)
        return NULL;

  treenode* temp = makenode(T->data);
  temp->left = copy(T->left);
  temp->right = copy(T->right);
  return temp;
}


void MyBST::mirror (treenode * T)
{
  if (T == NULL)
    return;
  else
    {
      treenode *temp = new treenode ();
      //swap the left and right child notes
      temp = T->left;
      T->left = T->right;
      T->right = temp;
      //Recursively mirror the left and right subtrees
      mirror (T->left);
      mirror (T->right);
    }
}

void MyBST::displayleafnode (treenode * T)
{  if (T->left == NULL && T->right == NULL){
    cout << T->data << " ";	//leafnode  
    return;
  }
    if(T->left)
        displayleafnode (T->left);
    if(T->right)
        displayleafnode (T->right);
}

int MyBST::height (treenode * T){
  if (T == NULL)
    return 0;
  else
    {
      int leftheight = height (T->left);
      int rightheight = height (T->right);
      return max (leftheight, rightheight) + 1;
    }
}

void MyBST::insert (int value)
{
  if (root == NULL)
    {
      root = makenode (value);
      return;
    }
  treenode *P, *Q;
  P = root;
  Q = root;
  while (Q != NULL && value != P->data)
    {
      P = Q;
      if (value < P->data)
	Q = P->left;
      else if (value > P->data)
	Q = P->right;
    }
  if (value == P->data)
    {
      cout << "Duplication not allowed\n";
      return;
    }
  if (value < P->data)
    P->left = makenode (value);
  else
    P->right = makenode (value);
}

void MyBST::Inorder (treenode * temp)
{
  if (temp != NULL)
    {
      Inorder (temp->left);
      cout << temp->data << " ";
      Inorder (temp->right);
    }
}

void MyBST::Preorder (treenode * temp)
{
  if (temp != NULL)
    {
      cout << temp->data << " ";
      Preorder (temp->left);
      Preorder (temp->right);
    }
}

void MyBST::Postorder (treenode * temp)
{
  if (temp != NULL)
    {
      Postorder (temp->left);
      Postorder (temp->right);
      cout << temp->data << " ";
    }
}

treenode* MyBST::search(treenode* T, int Key)
{
    if (T == NULL){
        cout << "Data not found";
        return NULL;
    }
    if (T->data == Key){
        cout << "Data found";
        return T;
    }
    else{
        if (T->data > Key)
            return search(T->left, Key);  // Fix: Return the result of the recursive call
        else
            return search(T->right, Key); // Fix: Return the result of the recursive call
    }
}


treenode * MyBST::Delete (treenode * T, int value)
{
  if (T == NULL)
    return T;
  else if (value < T->data)
    T->left = Delete (T->left, value);
  else if (value > T->data)
    T->right = Delete (T->right, value);
  else
    {
      // Case 1: No child
      if (T->left == NULL && T->right == NULL)
	{
	  delete T;
	  T = NULL;
	}
      // Case 2: One child
      else if (T->left == NULL)
	{
	  treenode *temp = T;
	  T = T->right;
	  delete temp;
	}
      else if (T->right == NULL)
	{
	  treenode *temp = T;
	  T = T->left;
	  delete temp;
	}
      // Case 3: Two children
      else
	{
	  treenode *temp = FindMin (T->right);
	  T->data = temp->data;
	  T->right = Delete (T->right, temp->data);
	}
    }
  return T;
}

treenode * MyBST::FindMin (treenode * T)
{
  while (T->left != NULL)
    T = T->left;
  return T;
}

int main ()
{
  MyBST obj;
  while(true){
    cout<<"Enter:\n1 for insertion\n2 for traversals\n3 for height\n4 for dispalying leaf nodes \n5 for copy\n6 for Deleting\n7 for searching"<<endl;
    int ch;
    cin>>ch;
    switch (ch){
      case 1:
        cout<<endl<<"Enter the data to be insered"<<endl;
        int data;
        cin>>data;
        obj.insert(data);
        break;
      case 2:
        cout<<"The traversals are"<<endl;
        cout << "Inorder: ";
        obj.Inorder (obj.reroot ());
        cout << endl;
        cout << "Preorder: ";
        obj.Preorder (obj.reroot ());
        cout << endl;
        cout << "Postorder: ";
        obj.Postorder (obj.reroot ());
        cout << endl;
        break;
      case 3:  
        cout << "Height: ";
        cout << obj.height (obj.reroot ());
        cout << endl;
        break;
      case 4:
        cout << "Display Leaf Node: ";
        obj.displayleafnode (obj.reroot ());
        cout << endl;
        break;
      case 5:
        cout<<"Copy of the bst created";
        obj.copy(obj.reroot());
        cout<<endl;
        break;
      case 6:
        cout<<"Enter the data to be deleted"<<endl;
        int dele;
        cin>>dele;
        obj.Delete (obj.reroot (), dele);
        cout <<"Data deleted"<< endl;
        break;
      case 7:{
        cout << "Search: "<<endl;
        cout<<"Enter the data to be searched"<<endl;
        int sch;
        cin>>sch;
        treenode *data_search = obj.search (obj.reroot (), sch);
        if (!data_search)
          cout << "Not found";
        cout << endl;
        break;
        } 
      default:
        cout<<"Enter correct option"<<endl;  
        break;      
      }

    cout<<"To Exit enter N\n continue enter Y:"<<endl;
    char temp;
    cin>>temp;
    if(temp=='N')
      break;
  }
return	0;
}