class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class Queue:
	def __init__(self):
		self.front = self.rear = None

	def Enqueue(self, item):
		newNode = Node(item)

		print(str(item) + ' added to queue')
		
		if self.rear == None:
			self.front = self.rear = newNode
			return 

		self.rear.next = newNode
		self.rear = newNode

	def Dequeue(self):
		if self.front == None:
			print("Queue is empty")
			return

		temp = self.front
		self.front = self.front.next
		print(str(temp.data) + ' removed from queue')

		if self.front == None:
			self.rear = None

if __name__ == '__main__':
	q = Queue()
	q.Enqueue(1)	
	q.Enqueue(2)
	q.Enqueue(3)

	q.Dequeue()
	q.Dequeue()
	q.Dequeue()
	q.Dequeue()