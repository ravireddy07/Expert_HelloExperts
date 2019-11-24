import java.util.Random;
import java.util.*;
import java.util.Arrays;


class Stack {
	static int MAX = 100;
	int top;
	int a[] = new int[MAX];

	boolean isEmpty() {
		return (top < 0);
	}

	Stack() {
		top = -1;
	}

	boolean push(int x) {
		if (top >= (MAX - 1)) {
			System.out.println("Stack Overflow");
			return false;
		} else {
			a[++top] = x;
			System.out.println(x + " pushed into stack");
			return true;
		}
	}

	void SortDisplay() {
		for (int i = 0; i < 100; i++) {
			System.out.println("Element at " + (i + 1) + " before sorting is: " + a[i]);
		}
		Arrays.sort(a);
		for (int i = 0; i < 100; i++) {
			System.out.println("Element at " + (i + 1) + " after sorting is: " + a[i]);
		}
	}

	int pop() {
		if (top < 0) {
			System.out.println("Stack Underflow");
			return 0;
		} else {
			int x = a[top--];
			return x;
		}
	}

	int peek() {
		if (top < 0) {
			System.out.println("Stack Underflow");
			return 0;
		} else {
			int x = a[top];
			return x;
		}
	}
}



class Node {
	protected int data;
	protected Node link;

	public Node() {
		link = null;
		data = 0;
	}

	public Node(int d, Node n) {
		data = d;
		link = n;
	}

	public void setLink(Node n) {
		link = n;
	}

	public void setData(int d) {
		data = d;
	}

	public Node getLink() {
		return link;
	}

	public int getData() {
		return data;
	}
}


class linkedQueue {
	public static int queueCount = 0;
	protected Node front, rear;
	public int size;

	public linkedQueue() {
		front = null;
		rear = null;
		size = 0;
	}

	public boolean isEmpty() {
		return front == null;
	}

	public int getSize() {
		return size;
	}

	public void insert(int data) {
		Node nptr = new Node(data, null);
		if (rear == null) {
			front = nptr;
			rear = nptr;
		} else {
			rear.setLink(nptr);
			rear = rear.getLink();
		}
        System.out.println(data + " enqueued into Queue");
		size++;
	}

	public int remove() {
		if (isEmpty())
			throw new NoSuchElementException("Underflow Exception");
		Node ptr = front;
		front = ptr.getLink();
		if (front == null)
			rear = null;
		size--;
		queueCount++;
		return ptr.getData();
	}

	public int peek() {
		if (isEmpty())
			throw new NoSuchElementException("Underflow Exception");
		return front.getData();
	}

	public void display() {
        int cc=1;
		System.out.print("\nQueue = ");
		if (size == 0) {
			System.out.print("Empty\n");
			return;
		}
		Node ptr = front;
		while (ptr != rear.getLink()) {
            System.out.println("Element at " + (cc) + " before sorting is: " + ptr.getData());
            cc++;
			ptr = ptr.getLink();
		}
		System.out.println();
	}

	int count() {
		return queueCount;
	}
}


public class LinkedQueueImplement {
	public static void main(String[] args) {
		Random rand = new Random();
		int rand_int, stackCount = 0;
		Stack s = new Stack();
		linkedQueue lq = new linkedQueue();

		for (int i = 0; i < 100; i++) {
			rand_int = rand.nextInt(100);
			lq.insert(rand_int);
			s.push(rand_int);
		}

        lq.display();
		s.SortDisplay();

		for (int i = 0; i < 100; i++) {
			try {
				lq.remove();
				stackCount++;
				s.pop();
			} 
			catch (Exception e) {
				System.out.println("Error : " + e.getMessage());
			}
		}

		System.out.println("Empty status = " + lq.isEmpty());
        System.out.println("Stack is Empty.!!");
        System.out.println("Queue is Empty.!!");

		System.out.println("Stack has taken " + stackCount + " times to get emptyed.");
		System.out.println("Queue has taken " + lq.count() + " times to get emptyed.");
		//System.out.println("It takes same number of size of the queue to drop the elements.Same for stack as well.");
	}
}