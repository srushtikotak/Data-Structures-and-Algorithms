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

def MinValue(node):
	while node.left is not None:
		node = node.left
	return node

def deletenode(root,value):
	if root is None:
		return root
	if value < root.value:
		root.left = deletenode(root.left , value)
	elif value > root.value:
		root.right = deletenode(root.right , value)
	else:
		if root.left is None:
			temp =root.right
			root = None
			return temp
		elif root.right is None:
			temp = root.left
			root = None
			return temp
		temp = MinValue(root.right)
		root.value = temp.value
		root.right = deletenode(root.right, temp.value)
		print("Deleted node is", value)
	return root

root = Node(100)
insert(root, Node(90))
insert(root, Node(110))
insert(root, Node(80))
insert(root, Node(95))

inorder(root)
print("\n")

deletenode(root,100)
inorder(root)
print("\n")