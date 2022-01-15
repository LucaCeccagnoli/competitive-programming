Given a weighted binary tree T, find the maximum possible sum on a path from one leaf to another.

# Solution
Run a [[📌Trees#Postorder|postorder]] visit.
The maximum path between two leaves wil belong to a subtree.
Calulate the maximum path sum recursively for each subtree, keeping track of the subtree with the max value between the others.

1) When visiting a node **u** with left subtree **u.L** and right subtree **u.R**, the maximum path sum for its subtree is:
	w(u.L) + w(u.R) + w(u)

2) When visiting a higher node **v** such that **u** belongs to the maximum path sum for **v**'s subtree, **u**' s contribution is given by:

	max { w(u.L), w(u.R) } + w(u)

	because the path to a leaf only goes through one child.

So during the recursive visit, every node propagates 2) to its parent,  but the total weight for the best subtree is given by 1)

## completity
O(n) time: only requires a postorder visit
O(n) space: tree size.