from sys import maxsize

def createstack():
	stack = []
	return stack

def isEmpty(stack):
	return len(stack) == 0

def push(stack , value):
	stack.append(value)
	print(str(value) + " pushed into stack")

def pop(stack):
	if isEmpty(stack):
		return 	str(-maxsize-1)

	return str(stack.pop())

stack = createstack()

push(stack, 1)
push(stack, 2)
push(stack, 3)

print( pop(stack) + " popped from stack")
print( pop(stack) + " popped from stack")
print( pop(stack) + " popped from stack")