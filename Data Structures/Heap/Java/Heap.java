import java.util.Arrays;

public class Heap<T extends Comparable<T>> {


    public enum Type {MIN, MAX};

    private final int SIZE = 16;

    private T data[];
    private int count;
    private int capacity;
    private Type type;

    @SuppressWarnings("unchecked")
    public Heap() {
        data = (T[]) new Comparable[SIZE];
        Arrays.fill(data, -1);
        count = 0;
        type = Type.MIN;
        capacity = SIZE;
    }

    public Heap(int size) {
        this();
        capacity = size;
    }
    public Heap(int size, Type type) {
        this(size);
        this.type = type;
    }


    public boolean isEmpty() { return count == 0; }

    public boolean isFull() { return count == data.length; }

    public int parent(int index) {
        return (index - 1) / 2;
    }

    public int leftChild(int index) {
        int left = 2 * index + 1;
        if (left >= count)
            return -1;
        return left;
    }

    public int rightChild(int index) {
        int right = 2 * index + 2;
        if (right >= count)
            return -1;
        return right;
    }

    public T getMax() {
        if (count == 0) return null;
        if (type == Type.MAX)
            return data[0];
        return data[count-1];
    }

    public T getMin() {
        if (count == 0) return null;
        if (type == Type.MIN)
            return data[0];
        return data[count-1];
    }

    public void insert(T val) {
        if (count >= capacity-1)
            resize();
        this.data[++count] = val;
        heapUp();
    }

    private void heapUp() {
        int index = count;
        if (type == Type.MIN) {
            while(data[parent(index)].compareTo(data[index]) > 0) {
                swap(index, parent(index));
                index = parent(index);
            }
        } else {
            while (data[parent(index)].compareTo(data[index]) < 0) {
                swap(index, parent(index));
                index = parent(index);
            }
        }
    }

    private void swap(int aPos, int bPos) {
        T temp = data[aPos];
        data[aPos] = data[bPos];
        data[bPos] = temp;
    }

    private void resize() {
        data = Arrays.copyOf(data, capacity*2);
        capacity *= 2;
    }
}