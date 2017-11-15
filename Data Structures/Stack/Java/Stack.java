public class Stack<T>
{

    private int size;
    private int top;
    private T stack[];

    public Stack ()
    {
        size = 16;
        top = -1;
        stack = (T[]) new Object[size];
    }

    public void push(T data)
    {
        if (top > size)
        {
            resize(2);
            stack[++top] = data;
        }
        else
        {
            stack[++top] = data;
        }
    }

    public T pop()
    {
        if (top < 0)
            throw new ArrayIndexOutOfBoundsException();
        else
        {
            return stack[top--];
        }
    }

    public T peek()
    {
        return stack[top];
    }

    public boolean isEmpty()
    {
        return top < 0;
    }

    private void resize(int factor)
    {
        size *= factor;
        T[] temp = this.stack.clone();
        this.stack = (T[]) new Object[size];
        System.arraycopy(temp, 0, this.stack, 0, temp.length);
    }

}
