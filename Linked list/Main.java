public class Main {
    public static class LinkedList {
        private Node head;
        private int size;

        public LinkedList() {
            head = null;
            size = 0;
        }

        public void add(Integer data) {
            Node newNode = new Node(data);
            if (head == null) {
                head = newNode;
                size++;
                return;
            }

            Node current = head;
            while(current.next != null) {
                current = current.next;
            }
            current.next = newNode;
            size++;
        }

        public void reverseLinkedList() {
            if (head == null) return;

            Node prev = null;
            Node current = head;
            Node next = null;

            while(current != null) {
                next = current.next;
                current.next = prev;
                prev = current;
                current = next;
            }

            head = prev;
        }

        public void printList() {
            if (head == null) return;
            Node current = head;
            while(current != null) {
                System.out.print(current.data);
                current = current.next;
            }
            return;
        }
    }
    
    public static class Node {
        private Integer data;
        private Node next;

        public Node(Integer data) {
            this.data = data;
            this.next = null;
        }
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.add(1);
        list.add(2);
        list.add(3);

        list.printList();
        list.reverseLinkedList();
        System.out.print("\n");
        list.printList();
    }
}
