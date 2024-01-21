import java.util.EmptyStackException;

public class Stack {
    public static class Node {
        Integer value;
        Node next;

        public Node(Integer value) {
            this.value = value;
            this.next = null;
        }
    }

    Node top;
    public void push(Integer value) {
        Node newNode = new Node(value);
        newNode.next = top;
        top = newNode;
    }

    public Integer pop() throws Exception {
        if (top == null) {
            throw new Exception("Stack is already empty");
        }
        Integer topValue = top.value;
        top = top.next;
        return topValue;
    }

    public Integer peek() {
        if (top == null) throw new EmptyStackException();
        return top.value;
    }

    public boolean isEmpty() {
        return top == null;
    }

    public static void main(String[] args) throws Exception {
        Stack stack = new Stack();
        stack.push(5);
        stack.push(10);
        stack.push(15);
        System.out.println("PEEK - " + stack.peek());
        System.out.println("POP - " + stack.pop());
        System.out.println("PEEK - " + stack.peek());
    }
}