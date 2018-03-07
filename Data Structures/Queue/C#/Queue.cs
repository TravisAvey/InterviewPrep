namespace DataStructures.Classes
{
    public class Queue<T>
    {
        private const int SIZE = 16;

        private int front;
        private int back;
        private int _size;
        private int N;
        private T[] queue;
        
        public Queue()
        {
            _size = SIZE;
            queue = new T[_size];
            front = back = -1;
            N = 0;
        }

        public Queue(int size)
        {
            _size = size;
            queue = new T[_size];
            front = back = -1;
            N = 0;
        }

        public int Length() => N;

        public int Size => _size;

        public bool IsEmpty => front == back;

        public void EnQueue(T data)
        {
            if (IsEmpty) front = back = 0;
            else
            {
                back = (back + 1) % _size;
            }

            queue[back] = data;
            N++;
        }
    }
}