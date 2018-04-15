#include<stdio.h>
#include<limits.h>

int heap[10000];
int heapsize;

void Init(){
	heapsize = 0;
	heap[0] = -INT_MAX;
}

void Insert(int data){
	heapsize++;
	heap[heapsize] = data;

	int now = heapsize;
	while(heap[now/2] > data){
		heap[now] = heap[now/2];
		now = now/2;
	}
	heap[now] = data;
}

int DeleteMin(){
	int min = heap[1];
	int last = heap[heapsize--];
	int now,child;
	for (now = 1; now * 2  <= heapsize; now = child)
	{
		child = now*2;
		if(child != heapsize && heap[child+1] < heap[child])
			child++;
		if(last > heap[child])
			heap[now] = heap[child];
		else
			break;
	}
	heap[now] = last;
	return min;
}

int main()
{
	int n;
	printf("Enter number of elements: \n");
	scanf("%d",&n);
	Init();
	int i, data;
	printf("Enter %d elements\n",n );
	for(i=0; i<n; i++){
		scanf("%d", &data);
		Insert(data);
	}
	printf("Elements in the heap are :\n");
	for(int j=1; j<=n; j++){
		printf("%d\n", heap[j]);
	}
	printf("Elements deleted in sequence : \n");
	for(int j=1; j<=n; j++){
		printf("%d\n", DeleteMin());
	}
	return 0;
}