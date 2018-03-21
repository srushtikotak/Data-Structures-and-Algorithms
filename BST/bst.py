class Node:
	def __init__(self, key):
		self.left = None
		self.right = None
		self.value = key

def insert(root,node):
	if root is None:
		root = node

	else:
		if root.value < node.value:
			if root.right is None:
				root.right = node
			else:
				insert(root.right, node)
		else:
			if root.left is None:
				root.left = node
			else:
				insert(root.left, node)

def inorder(root):
	if root:
		inorder(root.left)
		print(root.value)
		inorder(root.right)

root = Node(100)
insert(root, Node(90))
insert(root, Node(110))
insert(root, Node(80))
insert(root, Node(95))

inorder(root)