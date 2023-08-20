import java.util.HashMap;
import java.util.Map;

public class LruCache {
    private Map<String, Node> arr;
    private Node start;
    private Node end;
    private int capacity;

    private class Node {
        int key;
        int value;
        Node prev;
        Node next;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    public void LruCache() {
        this.capacity = 10;
        this.start = new Node(0, 0);
        this.end = new Node(0, 0);
        this.arr = new HashMap<>();
        this.start.next = end;
        this.end.prev = start;
    }

    public int getKey(int k) {
        if (arr.containsKey(k)) {
            Node data = arr.get(k);
            remove(data);
            addToStart(data);
            return data.value;
        }
        return -1;
    }

    public void put(int k, int v) {
        if (arr.containsKey(k)) {
            Node data = arr.get(k);
            data.value = v;
            remove(data);
            addToStart(data);
        } else {
        }
    }

    private void remove(Node node) {

    }

    private void addToStart(Node node) {

    }
}
