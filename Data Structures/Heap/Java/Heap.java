import java.util.Arrays;

public class Heap<T> {
    final int SIZE = 16;
    T data[];
    int count;
    int capacity;

    public Heap() {
        data = (T[]) new Object[SIZE];
        Arrays.fill(data, -1);
        count = 0;
        capacity = SIZE;
    }

    public Heap(int size) {
        this();
        capacity = size;
    }

    public boolean isEmpty() { return count == 0; }

    public boolean isFull() { return count == data.length; }

    public T parent(int index) {
        return data[(index - 1) / 2];
    }

    public T leftChild(int index) {
        int left = 2 * index + 1;
        if (left >= count)
            return null;
        return data[left];
    }

    public T rightChild(int index) {
        int right = 2 * index + 2;
        if (right >= count)
            return null;
        return data[right];
    }
    
    public T getMax() {
        if (count == 0) return null;
        return data[0];
    }
}