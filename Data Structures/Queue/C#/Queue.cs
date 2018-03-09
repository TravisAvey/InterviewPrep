using System;

namespace DataStructures.Classes
{
    /// <summary>
    /// This class is the Queue ADT
    /// </summary>
    /// <typeparam name="T">Generic Type</typeparam>
    public class Queue<T>
    {
        // the default capcity of the queue
        private const int SIZE = 16;

        
        private int front;    // location of the front of the queue
        private int back;     // location of the back of the queue
        private int size;     // the capacity of the queue
        private int N;        // the number of items in the queue
        private T[] queue;    // the queue itself, an array
        
        /// <summary>
        /// Default constructor
        /// </summary>
        public Queue()
        {
            Init(SIZE);
        }

        /// <summary>
        /// Constructor with optional capacity parameter
        /// </summary>
        /// <param name="size">the capacity of the queue</param>
        public Queue(int size)
        {
            Init(size);
        }

        /// <summary>
        /// Private helper method to init the object
        /// upon constructor being called
        /// </summary>
        /// <param name="size">size of the queue</param>
        private void Init(int size)
        {
            // set the size
            this.size = size;
            // init the queue array with size
            queue = new T[this.size];
            // set front and back to -1
            front = back = -1;
            // start the number of items at 0
            N = 0;
        }

        /// <summary>
        /// Gets the number of items currently in the queue
        /// </summary>
        /// <returns>The number of items in queue</returns>
        public int Length() => N;

        /// <summary>
        /// Gets the capcacity of the queue
        /// </summary>
        public int Capacity => size;

        /// <summary>
        /// Returns true if queue is empty
        /// </summary>
        public bool IsEmpty => N == 0;
        
        /// <summary>
        /// Puts in the back of the queue the item
        /// </summary>
        /// <param name="data">The item to enqueue</param>
        public void EnQueue(T data)
        {
            // if empty, set the front and back to 0
            if (IsEmpty) front = back = 0;
            else
            {
                // set back to the next in queue
                // note that this will wrap around the array
                // if user goes over the capacity, then will write over
                // TODO: either throw exception or resize array
                back = (back + 1) % size;
            }
            // set the data in the back of the queue
            queue[back] = data;
            // increment the number of items in the queue
            N++;
        }

        /// <summary>
        /// Removes the front item from the queue
        /// </summary>
        /// <returns>The front item</returns>
        /// <exception cref="ArgumentOutOfRangeException">Throws exception if queue is empty</exception>
        public T DeQueue()
        {
            // if empty, throw exception
            if (IsEmpty)
                throw new ArgumentOutOfRangeException($"Queue is empty");

            // cache the item from the front of the queue
            T item = queue[front];

            // since we are using the ability to wrap around the queue
            // then once front and back are the same, then queue is
            // now empty, so reset back to -1
            if (front == back)
                front = back = -1;
            else
                // set front to the next
                front = (front + 1) % size;
            // decrement to number of items in the queue
            N--;
            // return the item
            return item;
        }
    }
}