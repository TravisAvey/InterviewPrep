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

        /// <summary>
        /// Removes the item from the top of the stack
        /// </summary>
        /// <returns>Top item from stack</returns>
        /// <exception cref="ArgumentOutOfRangeException">Throws exception if empty</exception>
        public T Pop()
        {
            // if top is less than 0, then is empty
            if (mTop < 0)
                throw new ArgumentOutOfRangeException($"Stack is empty");
            else
            {
                // return top item and decrement the top position
                return mStack[mTop--];
            }
        }

        /// <summary>
        /// Peeks at the top item in the stack
        /// </summary>
        /// <returns>Top item in the stack</returns>
        /// <exception cref="ArgumentOutOfRangeException">Throws exception if stack is empty</exception>
        public T Peek()
        {
            // if top is less than 0, stack is empty
            if (mTop < 0)
                throw new ArgumentOutOfRangeException($"Stack is empty");
            else
            {
                // return the top item from stack
                return mStack[mTop];
            }
        }


        /// <summary>
        /// Checks if the stack is empty
        /// </summary>
        /// <returns>true if stack is empty</returns>
        public bool IsEmpty() => mTop == -1;


        /// <summary>
        /// Helper method to resize the stack array
        /// </summary>
        private void Resize()
        {
            // double size of stack
            mSize *= 2;
            // create temp stack, clone of stack
            T[] temp = (T[]) mStack.Clone();
            // re-init the stack to a new array
            mStack = new T[mSize];
            // using System, copy temp back into stack
            System.Array.Copy(mStack, temp, (mSize/2));
        }
        
    }
}