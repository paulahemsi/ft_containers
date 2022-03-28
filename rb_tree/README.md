# trees
:deciduous_tree:

## study resources

 ### :page_facing_up: Texts
* [RedBlack tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)
* [Tree Traversals (Inorder, Preorder and Postorder)](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/)

 ### :wrench: tools
* [RedBlack tree visualization](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html)

 ### :tv: videos
* [Depth First & Breadth First Graph Search - DFS & BFS Graph Searching Algorithms](https://www.youtube.com/watch?v=TIbUeeksXcI)
* [Binary Tree Level Order Traversal - Drawing The Parallel Between Trees & Graphs](https://www.youtube.com/watch?v=gcR28Hc2TNQ)
* [Red Black Tree Insertion](https://www.youtube.com/watch?v=qA02XWRTBdw)
* [Red Black Tree deletion | Data structure](https://www.youtube.com/watch?v=w5cvkTXY0vQ)


## Tree Rotations

From [Balanced binary search tree rotations](https://www.youtube.com/watch?v=q4fnJZr8ztY)

The secret ingredient to most BBST algorithms is the clever usage of a **tree invariant** and **tree rotations**.

A tree invariant is a property/rule you impose on you tree that it must meet after every operation. To ensure that the invariant is always satisfied a series of tree rotations are normally applied.


![image](https://user-images.githubusercontent.com/63563271/158483683-7005f993-4900-432c-be2a-263e41c1c032.png)

## Red-Black Rules

* Root = Black
* no two adjacent red nodes
* count number of blacknode in each path

## Red-Black Insert algorithm

1- If tree is empty, create newnode as root node with color black

2- If tree is not empty, create newnode as leef node with color Red

3- If parentof newnode is black, then exit

4- If parent of new node is Red, then check the color of parent's sibling of newnode:

	a- if color is black or null then do switable rotation and recolor

	b- if color is red then recolor and also check if parent's parent of newnode is not root node then recolor it and recheck
	
## Red-Black Delete algorithm

1: Perform BST deletion

	1- If node to be deleted is red, just delete it
	2- If node to be deleted is black, it becames DB
	
	2- If root is DB, just remove DB

	3- If DB's sibling is black, and both its children are black:

		a- remove DB
		b- Add black to its Parent 
			1- If Parent is red it becames black
			2- If Parent is black it becames double black
		c- Make sibling red
		d- If still DB exists, apply other cases

	4- If DB's sibling is red
		a- Swap colors of parent and it's sibling
		b- rotate parent in DB directions
		c- apply cases

	5- DB's sibling is black, sibling's child who is far from DB is black, but near child to DB is red
		a- Swap color of DB's sibling and sibling's child who is near to DB
		b- rotate sibling in opposite direction to DB
		c- apply case 6

	6- DB's sibling is black, far child is red (FC)
		b- swap color of parent and sibling
		a- change far child(FC) from sibling to black
		d- remove DB
		c- rotate parent in DB's direction

