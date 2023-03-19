public class CircularList<E> {
    private class Node {
        private E value;
        private Node next;
        
        public Node(E value) {
            this.value = value;
            this.next = null;
        }
    }
    
    private Node current;
    private int size;
    
    public CircularList() {
        current = null;
        size = 0;
    }
    
    public boolean isEmpty() {
        return size == 0;
    }
    
    public int size() {
        return size;
    }
    
    public void insert(E value) {
        Node newNode = new Node(value);
        if (isEmpty()) {
            newNode.next = newNode;
            current = newNode;
        } else {
            newNode.next = current.next;
            current.next = newNode;
        }
        size++;
    }
    
    public void delete() {
        if (!isEmpty()) {
            Node nextNode = current.next;
            if (nextNode == current) {
                current = null;
            } else {
                current.next = nextNode.next;
                nextNode = null;
            }
            size--;
        }
    }
    
    public boolean search(E value) {
        if (!isEmpty()) {
            Node currentNode = current;
            do {
                currentNode = currentNode.next;
                if (currentNode.value.equals(value)) {
                    return true;
                }
            } while (currentNode != current);
        }
        return false;
    }
    
    public void step() {
        if (!isEmpty()) {
            current = current.next;
        }
    }
    
    public void display() {
        if (!isEmpty()) {
            Node currentNode = current;
            do {
                System.out.print(currentNode.value + " ");
                currentNode = currentNode.next;
            } while (currentNode != current);
            System.out.println();
        }
    }
}
