using System;

namespace DataStructures.Classes
{
    /// <summary>
    /// This class is the LinkedList class
    /// Where each node is a link in the list
    /// Each node has the data and a pointer
    /// to the next node in the list
    /// </summary>
    /// <typeparam name="T">Generic Type</typeparam>
    public class LinkedList<T>
    {
        private int _size;
        private Node<T> _head;

        public LinkedList()
        {
            _size = 0;
            _head = null;
        }

        public LinkedList(T data)
        {
            _size = 1;
            _head = new Node<T>(data, null);
        }

        public int Size()
        {
            return _size;
        }

        public bool IsEmpty()
        {
            return _size == 0;
        }

        public T Front()
        {
            return _head.GetData();
        }

        public void PushFront(T data)
        {
            _size++;
            
            var current = new Node<T>(data, null);
            
            current.SetNext(_head);
            _head = current;
        }


        public override string ToString()
        {
            var output = "";

            var current = _head;

            while (current.GetNext() != null)
            {
                output += current.GetData() + "->";
                current = current.GetNext();
            }

            output += current.GetData();
            return output;
        }

        public T Back()
        {
            if (_head == null)
                throw new ArgumentOutOfRangeException($"Linked List is empty!");
            Node<T> current = _head;

            while (current.GetNext() != null)
            {
                current = current.GetNext();
            }

            return current.GetData();
        }

        #region Node

        /// <summary>
        /// This is the node class that represents
        /// each node of the linked list
        /// </summary>
        /// <typeparam name="S">Generic Type</typeparam>
        class Node<S>
        {
            private S _data;
            private Node<S> _next;
        
            public Node()
            {
                _next = null;
            }

            public Node(S data, Node<S> node)
            {
                _data = data;
                _next = node;
            }

            public void SetNext(Node<S> node)
            {
                _next = node;
            }

            public void SetData(S data)
            {
                _data = data;
            }

            public Node<S> GetNext()
            {
                return _next;
            }

            public S GetData()
            {
                return _data;
            }

        }

        #endregion

    }

    
}  