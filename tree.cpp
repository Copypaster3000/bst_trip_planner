//tree.cpp
//This file holds the tree class definitions

#include <cstring>
#include <iostream>
#include <fstream>
#include <cctype>
#include "tree.h"
using namespace std;

//Constructor
tree::tree(void)
{
	root = nullptr;
}



//Destructor
tree::~tree(void)
{
	remove_all(root);
}



//Removes all nodes from bst
void tree::remove_all(node*& root)
{
if (!root) return;

	remove_all(root->left);
	remove_all(root->right); //Calls it self to the left and right

	delete root; //Deletes node
	--num_nodes;
	root = nullptr; //Sets pointer to null
}



//Wrapper function, pass in struct w/ trip info to add it to bst
int tree::insert(front_trip& trip_info)
{ 
	return insert(trip_info, root);
}



//Pass in struct w/ trip info and root of bst
int tree::insert(front_trip& trip_info, node*& root)
{
	if (!root) //Adds new node once it has traversed to correct spot 
	{
		root = new node; //Sets pointer to new node
		root->entry.set(trip_info); //Sets new node w/ trip info
		++num_nodes;
		return 1;
	}
	if (root->entry.name_match(trip_info.name)) return 0; //Trip already in bst
														  
	if (!root->entry.compare(trip_info.name)) //If trip being added is smaller than current trip
		return insert(trip_info, root->left); //Call itself passing in node to the left
	else
		return insert(trip_info, root->right); 
	
}



//Wrapper, Displays all trips in order
int tree::abc_display(void)
{
	if (!root) return 0; //Nothing to display

	return abc_display(root);
}



//Recursive, pass in root
int tree::abc_display(node* root)
{
	if (!root) return 1; //Returns 1 for success

	abc_display(root->left); //Calls itself to the left

	root->entry.display(); //Displays node's trip info

	abc_display(root->right);
}

	

//Wrapper, pass in name of locaiton to be removed
int tree::remove(char check[])
{
	if (!root) return 0; //No trips to remove

	return remove(check, root);	
}



//Recursive, pass in root of bst
int tree::remove(char check[], node*& root)
{
	if (!root) return 0; //Made it to an end w/ no matches

	if (root->entry.name_match(check)) //If match found
	{
		if (!root->left && !root->right) //If leaf (no children)
		{
			delete root;
			root = nullptr;
		}
		else if (root->left && !root->right) //If only left child
		{
			node* hold = root->left; //Hold onto node that will be replacing the removed
			delete root; //Delete the removed
			root = hold; //Set pointer to removed to replacement
		}
		else if (!root->left && root->right) //If only right child
		{
			node* hold = root->right;
			delete root;
			root = hold;
		}
		else //Node being removed has two children (IOS is the smallest node in right sub tree)
		{
			node* current = root->right; //Make current pointer 
			
			if (!current->left) //If right child of node being removed has no left childe then "current" is IOS
			{//Because IOS then has only one or no children removal is as below
				delete root; //Delete node being removed
				root = current; //Set root pointer to IOS
			}
			else
			{
				node* prev = nullptr; //Previous pointer

				while (!current->left) //Traverse until find smallest item in right sub tree
				{
					prev = current;
					current = current->left;
				} //Current is now IOS

				front_trip trip_info; //Used to copy data from one node to another
				current->entry.copy_to(trip_info); //Copies current's trip info to struct
				root->entry.set(trip_info); //Sets root's trip info w/ that struct

				node* hold = current->right; //Hold pointer to set it to child of IOS after IOS has been removed to replace root
				delete current;
				prev->left = hold;
			}
		}
		--num_nodes; //Subtracts one to update data items in bst

		return 1; //For successful removal
	}

	if (root->entry.compare(check)) //Calls it self to the left or right subtree based on where the match would have to be alphabetically
		return remove(check, root->right);
	else
		return remove(check, root->left);
}


	
//Wrapper, Pass in name of trip to retrieve and struct to get trip info w/
int tree::retrieve(char check[], front_trip& trip_info)
{
	if (!root) return 0; //No trips

	return retrieve(check, trip_info, root);
}



//Recursive, pass in bst root
int tree::retrieve(char check[], front_trip& trip_info, node* root)
{
	if (!root) return 0;

	if (root->entry.name_match(check))//If current node matches trip being searched for
	{
		root->entry.copy_to(trip_info); //Copy trip info to struct
		return 1;
	}

	return retrieve(check, trip_info, root->left) + retrieve(check, trip_info, root->right); //Calls itself to left and right sub tree
}



//Wrapper, pass in the best time to travel of the trips to be displayed
int tree::display_by_when(char check[])
{
	int match {0};

	cout << endl;

	if (!root) return match; //No trips to display

	match = display_by_when(check, root, match);

	return match;
}


//Recursive, pass in bst root and match indicator variable
int tree::display_by_when(char check[], node* root, int match)
{
	if (!root) return match; //Stops traversing once at nullptr

	if (root->entry.when_match(check)) //If current node has a match display it
	{
		root->entry.display();
		match = 1;
	}
	//Goes through left and right sub-trees
	return display_by_when(check, root->left, match) + display_by_when(check, root->right, match);
}



//Displays height and num of node in bst to user
int tree::display_bst_data(void)
{
	cout << "\nThe binary search tree has " << num_nodes << " data items in it." << endl;
	cout << "The tree is " << height(root) << " levels tall." << endl;

	return 1;
}
	


//Displays the height of the BST
int tree::height(node* root)
{
	if (!root) return 0;

	return 1 + max(height(root->left), height(root->right)); 
}



//Puts entire contents of external file into bst, pass in name of file
int tree::load_file(char file[])
{
	ifstream fin; //Creates file input variable
	front_trip temp_trip; //Struct to hold trip info in to then insert

	fin.open(file); //Opens file passed in

	if (!fin) return 0; //If unable to access file

	fin.get(temp_trip.name, MAX, '|'); //Tests that it's able to read in from the file, store first trip detail in struct member
	fin.ignore(100,'|'); //Clears input stream and ingnores delimeter

	while (!fin.eof()) //While it's not the end of the file keeps looping
	{
		fin.get(temp_trip.location, MAX, '|');
		fin.ignore(100, '|');

		fin.get(temp_trip.attraction, MAX, '|');
		fin.ignore(100, '|');

		fin.get(temp_trip.when, MAX, '|');
		fin.ignore(100, '|');

		fin.get(temp_trip.travel, MAX, '|');
		fin.ignore(100, '|');

		fin.get(temp_trip.climate, MAX, '\n');
		fin.ignore(100, '\n');

		insert(temp_trip); //Adds trip to hash table

		fin.get(temp_trip.name, MAX, '|');
		fin.ignore(100, '|');
	}

 	fin.close(); //Done with file, closes it
    fin.clear(); //Clears file input variable, allows for re-use

    return 1;
}




