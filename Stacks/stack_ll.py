class StackNode: 
	def __init__(self, data):
		self.data = data
		self.next = None

class Stack:
	def __init__(self):
		self.root = None

	def isEmpty(self):
		return True if self.root is None else False

	def push(self, data):
		newNode = StackNode(data)
		newNode.next = self.root
		self.root = newNode
		print( str(data) + " pushed into the stack")

	def pop(self):
		if self.isEmpty():
			print("Stack is Empty")
			return
		temp = self.root
		self.root = self.root.next
		print(str(temp.data) + " popped from the stack")

			
stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)

stack.pop()
stack.pop()
stack.pop()
stack.pop()