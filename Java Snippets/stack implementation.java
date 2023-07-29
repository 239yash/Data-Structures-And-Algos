public class Stack {
    private int maxSize;
    private int[] stackArray;
    private int top;

    // Constructor to initialize the stack with a given maximum size
    public Stack(int maxSize) {
        this.maxSize = maxSize;
        this.stackArray = new int[maxSize];
        this.top = -1; // Initialize top to -1 to indicate an empty stack
    }

    // Method to add an element to the top of the stack
    public void push(int value) {
        if (isFull()) {
            System.out.println("Stack is full. Cannot push element: " + value);
            return;
        }
        top++;
        stackArray[top] = value;
    }

    // Method to remove and return the element from the top of the stack
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty. Cannot pop element.");
            return -1; // Return a sentinel value or throw an exception to indicate an error
        }
        int poppedValue = stackArray[top];
        top--;
        return poppedValue;
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        return (top == -1);
    }

    // Method to check if the stack is full
    public boolean isFull() {
        return (top == maxSize - 1);
    }

    // Method to get the top element of the stack without removing it
    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty. Cannot peek.");
            return -1; // Return a sentinel value or throw an exception to indicate an error
        }
        return stackArray[top];
    }

    // Method to get the size of the stack
    public int size() {
        return top + 1;
    }

    // Method to display the elements of the stack
    public void display() {
        System.out.print("Stack (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            System.out.print(stackArray[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Stack stack = new Stack(5);

        stack.push(10);
        stack.push(20);
        stack.push(30);

        stack.display(); // Output: Stack (top to bottom): 30 20 10

        System.out.println("Top element: " + stack.peek()); // Output: Top element: 30

        System.out.println("Popped element: " + stack.pop()); // Output: Popped element: 30

        stack.display(); // Output: Stack (top to bottom): 20 10
    }
}
