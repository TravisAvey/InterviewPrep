import java.util.ArrayList;
import java.util.List;

public class Heap<T extends Comparable<T>> {


    public enum Type { MAX, MIN };

    private final int SIZE = 1024;

    private List<T> data;
    private int count;
    private Type type;

    @SuppressWarnings("unchecked")
    public Heap() {
        data = new ArrayList<>(SIZE);
        count = 0;
        type = Type.MAX;
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

    public boolean isFull() { return count == data.size(); }

    private int parent(int index) {
        return (index-1) / 2;
    }

    private int leftChild(int index) {
        int left = 2 * index + 1;
        if (left >= count)
            return -1;
        return left;
    }

    private int rightChild(int index) {
        int right = 2 * index + 2;
        if (right >= count)
            return -1;
        return right;
    }

    public T getMax() {
        if (count == 0) return null;
        if (type == Type.MAX)
            return data.get(0);
        else {
            T val = data.get(0);
            for (int i=1; i<data.size(); i++)
                if (val.compareTo(data.get(i)) < 0)
                    val = data.get(i);
            return val;
        }
    }

    public T getMin() {
        if (count == 0) return null;

        if (type == Type.MIN)
            return data.get(0);
        else {
            T val = data.get(0);
            for (int i=1; i<data.size(); i++)
                if (val.compareTo(data.get(i)) > 0)
                    val = data.get(i);
            return val;
        }
    }

    public void insert(T val) {
        data.add(val);
        heapify();
        count++;
    }

    private void heapify() {
        int index = count;
        if (type == Type.MIN) {
            while(data.get(parent(index)).compareTo(data.get(index)) > 0) {
                swap(index, parent(index));
                index = parent(index);
            }
        } else {
            while (data.get(parent(index)).compareTo(data.get(index)) < 0) {
                swap(index, parent(index));
                index = parent(index);
            }
        }
    }


    private void swap(int aPos, int bPos) {
        T temp = data.get(aPos);
        data.set(aPos, data.get(bPos));
        data.set(bPos, temp);
    }

}