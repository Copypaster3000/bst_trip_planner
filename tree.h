//tree.h
//Header file for the tree class that declares the functions that edit the BST. The node used
//in the BST is also declared here.

#include "trip_entry.h"

struct node
{
	trip_entry entry;
	
	node* left {nullptr};
	node* right {nullptr};
};


class tree
{
	public:
		tree(void);
		~tree(void);
		int insert(front_trip& trip_info); //Wrapper, pass in struct w/ trip info to add it to bst, returns 1 for success
		int abc_display(void); //Wrapper, displays bst in order, returns 0 if nothing to display
		int remove(char check[]); //Wrapper, pass in name of location to be removed, returns 0 if no match
		int retrieve(char check[], front_trip& trip_info); //Wrapper, pass in name of trip to be retrieved, and struct to fill w/ trip info, returns 0 if no match
		int display_by_when(char check[]); //Wrapper, Pass in best travel time to display returns 0 is no matches
		int display_bst_data(void); //Displays height and num of items in bst
		int load_file(char file[]); //Pass in file name to add contents to bst

	private:
		node* root;
		int num_nodes {0}; //Counts num of items in bst
		void remove_all(node*& root); //Deallocates all node from bst
		int insert(front_trip& trip_info, node*& root); //Recursive, pass in bst root for 2nd arg
		int abc_display(node* root); //Recursive, pass in root
		int remove(char check[], node*& root); //Recursive, 
		int retrieve(char check[], front_trip& trip_info, node* root); //Recursive, 
		int display_by_when(char check[], node* root, int match); //Recursive, pas in root bst and match indicator variable
		int height(node* root); //Displays height of bst
};
