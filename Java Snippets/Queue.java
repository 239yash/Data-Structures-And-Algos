public class Queue {
    public static class QueueNode {
        Integer value;
        QueueNode next;

        public QueueNode(Integer value) {
            this.value = value;
            this.next = null;
        }
    }

    QueueNode first;
    QueueNode last;

    public void push(Integer value) {
        QueueNode queueNode = new QueueNode(value);
        if (last != null) {
            last.next = queueNode;
        }
        last = queueNode;
        if (first == null) {
            first = last;
        }
    }

    public Integer pop() throws Exception {
        if (first == null) {
            throw new Exception("Already empty!");
        }

        Integer value = first.value;
        first = first.next;
        if (first == null) last = null;
        return value;
    }

    public Integer peek() throws Exception {
        if (first == null) throw new Exception("Empty queue!");
        return first.value;
    }

    public Boolean isEmpty() {
        return first == null;
    }

    public static void main(String[] args) throws Exception {
        Queue queue = new Queue();
        queue.push(5);
        queue.push(10);
        queue.push(15);
        queue.push(20);

        System.out.println("PEEK - " + queue.peek());
        System.out.println("POP - " + queue.pop());
        System.out.println("PEEK - " + queue.peek());
        System.out.println("IS EMPTY - " + queue.isEmpty());
    }
}
