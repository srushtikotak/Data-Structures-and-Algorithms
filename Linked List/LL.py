class Node:
	def __init__(self,data):
		self.data=data
		self.next=None

class LinkedList:
	def __init__(self):
		self.head=None

	def push(self, new_data):
		new_node = Node(new_data)
		new_node.next = self.head
		self.head = new_node

	def insertAfter(self, prev , new_data):
		if prev is None:
			print('The given previous node does not exists')
			return
		new_node = Node(new_data)

		new_node.next = prev.next
		prev.next = new_node

	def append(self, new_data):
		new_node = Node(new_data)
		if self.head is None:
			self.head = new_node
			return
		last = self.head
		while(last.next):
			last = last.next

		last.next = new_node

	def printlist(self):
		temp = self.head
		while (temp):
			print(temp.data)
			temp=temp.next

if __name__ == '__main__':
	llist = LinkedList()

	llist.head = Node(1)
	second = Node(2)
	third = Node(3)
	fourth = Node(4)

	llist.head.next = second
	second.next = third

	llist.push(0)
	llist.insertAfter(second.next , 8)
	llist.append(5)

	llist.printlist()