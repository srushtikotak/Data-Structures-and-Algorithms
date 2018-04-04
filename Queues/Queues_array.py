class Queue:

	def __init__(self, capacity):
		self.front = self.size = 0
		self.rear = capacity-1
		self.capacity = capacity
		self.Q = [None]*capacity
		
	def isFull(self):
		return self.rear == self.capacity

	def isEmpty(self):
		return self.size == 0

	def Enqueue(self, data):
		if self.isFull():
			print('Full')
			return
		self.rear = (self.rear + 1) % (self.capacity)
		self.Q[self.rear] = data
		self.size = self.size + 1 
		print(str(data) + ' added to queue')

	def Dequeue(self):
		if self.isEmpty():
			print('Queue Empty')
			return
		item = self.Q[self.front]
		print(str(item) + ' removed from queue')
		self.front = (self.front + 1) % (self.capacity)
		self.size = self.size - 1

if __name__ == '__main__':
	queue = Queue(10)

	queue.Enqueue(1) 
	queue.Enqueue(2)
	queue.Enqueue(3)

	queue.Dequeue()
	queue.Dequeue()
	queue.Dequeue()
	queue.Dequeue()