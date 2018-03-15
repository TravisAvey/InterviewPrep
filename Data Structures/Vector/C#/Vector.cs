using System;

namespace DataStructures.Classes
{
    /// <summary>
    /// This is the Vector class
    /// Uses the array underneath to hold
    /// the data.  Another way is to use
    /// a linked list.
    /// </summary>
    /// <typeparam name="T">Generic Type</typeparam>
    public class Vector<T>
    {
        private const int SIZE = 16;    // Default Vector Size

        private int mSize;              // size of vector
        private T[] vector;             // vector array
        private int mLength;            // number of items in vector

        /// <summary>
        /// Default constructor
        /// </summary>
        public Vector()
        {
            init(SIZE);   
        }

        /// <summary>
        /// Constructor for initial size for vector
        /// </summary>
        /// <param name="size">Size of vector</param>
        public Vector(int size)
        {
            // if array size is less than 0
            // use default size
            init(size <= 0 ? SIZE : size);
        }

        /// <summary>
        /// Constructor to create a vector with an array
        /// </summary>
        /// <param name="array">Array to construct vector from</param>
        public Vector(T[] array)
        {
            // if array size is greater than default, use array size to init
            init(array.Length > SIZE ? array.Length : SIZE);

            // copy over array to vector
            Array.Copy(vector, array, mSize);
        }

        /// <summary>
        /// Pushes new data to the back of the
        /// vector
        /// </summary>
        /// <param name="data">Data to append to end of vector</param>
        /// <exception cref="NotImplementedException"></exception>
        public void PushBack(T data)
        {
            // TODO: Implement resize method
            if (mLength >= mSize -1)
                throw new NotImplementedException($"Need to implement a method to double array size");

            // put new item in vector array
            vector[++mLength] = data;
        }

        /// <summary>
        /// Removes the last item from the vector
        /// </summary>
        /// <returns>Last item in vector</returns>
        /// <exception cref="ArgumentOutOfRangeException">Throws if vector is empty</exception>
        public T PopBack()
        {
            // if we are at -1 or less, empty vector throw exception
            if (mLength < 0)
                throw new ArgumentOutOfRangeException($"Vector is empty");
            
            // returns last item from vector, and decrements no. items
            return vector[mLength--];
        }

        /// <summary>
        /// Gets the first item from the vector
        /// </summary>
        /// <returns>First item in vector</returns>
        /// <exception cref="ArgumentOutOfRangeException">Throws if vector is empty</exception>
        public T Front()
        {
            // if length is -1 or less, throw error
            if (mLength < 0)
                throw new ArgumentOutOfRangeException($"Veoctor is empty");
            // return the first item in vector
            return vector[0];
        }

        /// <summary>
        /// Gets the last item in the vector
        /// </summary>
        /// <returns>Last item in vector</returns>
        public T Back()
        {
            return vector[mLength];
        }

        
        /// <summary>
        /// Gets the item at specified index
        /// </summary>
        /// <param name="index">location in vector</param>
        /// <returns>Item at index location</returns>
        /// <exception cref="IndexOutOfRangeException">Throws if out of range of vector</exception>
        public T At(int index)
        {
            // if index is greater than len, out of range
            if (index > mLength)
                throw new IndexOutOfRangeException($"Index out of range of vector");

            // return the item at the index
            return vector[index];
        }

        /// <summary>
        /// Inserts data at index supplied
        /// </summary>
        /// <param name="data">value to add to vector</param>
        /// <param name="index">index which to insert into vector</param>
        /// <exception cref="ArgumentOutOfRangeException">Throws if out of range of vector</exception>
        public void Insert(T data, int index)
        {
            // if index is greater than len, out of range
            if (index > mLength) 
                throw new ArgumentOutOfRangeException($"Index out of range of vector");
            
            //TODO: this doesn't check if moving everything over will overwrite end value....

            // loop through vector and move everything
            // from end to the index
            for (int i = mLength - 1; i >= index; i--)
                vector[i + 1] = vector[i];
            // after for loop, put new data into vector at index
            vector[index] = data;
        }

        /// <summary>
        /// Clears the vector
        /// </summary>
        public void Clear()
        {
            // clears the length by resetting
            // the length to -1
            mLength = -1;
            
        }

        /// <summary>
        /// Checks if the vector is empty
        /// </summary>
        /// <returns>True if empty</returns>
        public bool IsEmpty() => mLength == -1;
        
        /// <summary>
        /// Helper method to initialize the vector class
        /// </summary>
        /// <param name="size">size to create array with</param>
        private void init(int size)
        {
            mSize = size;
            vector = new T[mSize];
            mLength = -1;
        }
    }
}