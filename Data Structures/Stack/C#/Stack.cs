using System;

namespace DataStructures.Classes
{
    /// <summary>
    /// Stack class.  LIFO
    /// 
    /// </summary>
    /// <typeparam name="T">Generic Data Type</typeparam>
    public class Stack<T>
    {
        // Default stack size
        private const int SIZE = 16;

        private int mSize;    // Size of the stack
        private int mTop;     // Location of the top of the stack
        private T[] mStack;   // The underlying stack data structure

        /// <summary>
        /// Default constructor
        /// </summary>
        public Stack()
        {
            // init stack with default size
            init(SIZE);
        }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="size">Size of stack to init</param>
        public Stack(int size)
        {
            // if 0 or less throw error
            if (size <= 0)
                throw new ArgumentException($"Size cannot be 0 or less");
            // init stack with size param
            init(size);
        }

        /// <summary>
        /// Private helper method to initialize
        /// the class
        /// </summary>
        /// <param name="size">Size of stack array</param>
        private void init(int size)
        {
            // set size
            mSize = size;
            // init top to -1
            mTop = -1;
            // init the array with size
            mStack = new T[mSize];
        }

        /// <summary>
        /// Push a new item onto the stack
        /// </summary>
        /// <param name="data">Item to push</param>
        public void Push(T data)
        {
            // if mTop is now at size
            if (mTop >= mSize-1)
                // call helper method to resize array
                Resize();
            else
            {
                // put on stack
                // ++mTop because we init top to -1
                // therefore, first time will be at 0
                // and so on.. 
                mStack[++mTop] = data;
            }
        }

        public T Pop()
        {
            if (mTop < 0)
                throw new ArgumentOutOfRangeException($"Stack is empty");
            else
            {
                return mStack[mTop--];
            }
        }

        public T Peek()
        {
            if (mTop < 0)
                throw new ArgumentOutOfRangeException($"Stack is empty");
            else
            {
                return mStack[mTop];
            }
        }


        public bool IsEmpty() => mTop == -1;


        private void Resize()
        {
            mSize *= 2;
            T[] temp = (T[]) mStack.Clone();
            mStack = new T[mSize];
            System.Array.Copy(mStack, temp, (mSize/2));
        }
        
    }
}