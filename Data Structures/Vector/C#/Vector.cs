using System;

namespace DataStructures.Classes
{
    public class Vector<T>
    {
        private const int SIZE = 16;

        private int mSize;
        private T[] vector;
        private int mLength;

        public Vector()
        {
            init(SIZE);   
        }

        public Vector(int size)
        {
            init(size);
        }

        public Vector(T[] array)
        {
            init(array.Length);
            
            Array.Copy(vector, array, (int)mSize);
        }

        public void PushBack(T data)
        {
            if (mLength >= mSize -1)
                throw new NotImplementedException($"Need to implement a method to double array size");

            vector[++mLength] = data;
        }

        public T PopBack()
        {
            if (mLength < 0)
                throw new NotImplementedException($"Implement a way to handle this");
            
            return vector[mLength--];
        }

        public T Front()
        {
            if (mLength < 0)
                throw new NotImplementedException($"Implement handle for this");
            return vector[0];
        }

        public T Back()
        {
            return vector[mLength];
        }

        public T At(int index)
        {
            if (index > mLength)
                throw new IndexOutOfRangeException();

            return vector[index];
        }

        public bool IsEmpty() => mLength == -1;
        private void init(int size)
        {
            mSize = size;
            vector = new T[mSize];
            mLength = -1;
        }
    }
}