using System;

namespace DataStructures.Classes
{
    /// <summary>
    /// This class is the LinkedList class
    /// Where each node is a link in the list
    /// Each node has the data and a pointer
    /// to the next node in the list
    /// TODO: implment a iterator interface
    /// </summary>
    /// <typeparam name="T">Generic Type</typeparam>
    public class LinkedList<T>
    {
        private int _size;        // number of items in list
        private Node<T> _head;    // head pointer

        /// <summary>
        /// Default constructor
        /// </summary>
        public LinkedList()
        {
            _size = 0;
            _head = null;
        }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="data">The value to init the list with</param>
        public LinkedList(T data)
        {
            // set the size
            _size = 1;
            // set the head to this new node
            _head = new Node<T>(data, null);
        }

        /// <summary>
        /// Gets the number of items in the linked list
        /// </summary>
        /// <returns>Size of linked list</returns>
        public int Size()
        {
            return _size;
        }

        /// <summary>
        /// Checks if the linked list is empty
        /// </summary>
        /// <returns>true if empty</returns>
        public bool IsEmpty()
        {
            return _size == 0;
        }

        /// <summary>
        /// Gets the value from the front of the linked list
        /// </summary>
        /// <returns>Value from the front of the linked list</returns>
        public T Front()
        {
            return _head.GetData();
        }

        /// <summary>
        /// Pushes a new node to the front of the linked list
        /// </summary>
        /// <param name="data">The value to add to the linked list</param>
        public void PushFront(T data)
        {
            // increment the size
            _size++;
            
            // create a new node to push to the front
            var current = new Node<T>(data, null);
            // set the current to head
            current.SetNext(_head);
            // set the head to current
            _head = current;
        }


        /// <summary>
        /// Gets the value from the back of the list
        /// </summary>
        /// <returns>Value from the back of the linked list</returns>
        /// <exception cref="ArgumentOutOfRangeException">Throws exception if list is empty</exception>
        public T Back()
        {
            // if head is null, list is empty
            if (_head == null)
                throw new ArgumentOutOfRangeException($"Linked List is empty!");
            // init a pointer to head
            var current = _head;

            // loop while next node isn't null
            while (current.GetNext() != null)
            {
                // traverse to next node
                current = current.GetNext();
            }

            // return the value from the end of the list
            return current.GetData();
        }

        /// <summary>
        /// Gets the value from the front of list and removes from list
        /// </summary>
        /// <returns>Value from the front of the Linked list</returns>
        /// <exception cref="ArgumentOutOfRangeException">Throws exception if linked list is empty</exception>
        public T PopFront()
        {
            // if head is null, empty list
            if (_head == null)
                throw new ArgumentOutOfRangeException($"Linked List is empty!");

            // store the data from the head
            var data = _head.GetData();
            // point the head to the next node
            _head = _head.GetNext();
            // decrement the size
            _size--;
            // return the data
            return data;
        }

        /// <summary>
        /// Gets the value from the end of list and returns it
        /// </summary>
        /// <returns>Value from end of linked list</returns>
        /// <exception cref="ArgumentOutOfRangeException">Throws exception if list is empty</exception>
        public T PopBack()
        {
            // if the head is null, throw exception
            if (_head == null)
                throw new ArgumentOutOfRangeException($"Linked List is empty!");

            // init a node to hold previous node
            var prev = new Node<T>();
            
            // cache head
            var current = _head;

            // while next node isn't null
            while (current.GetNext() != null)
            {
                // store prev
                prev = current;
                // move current to next
                current = current.GetNext();
            }

            // get the data from the current
            var data = current.GetData();
            // set the prev's next node to null
            prev.SetNext(null);
            // set current to null
            current = null;
            // decrement the size of list
            _size--;
            // return the data
            return data;
        }

        /// <summary>
        /// Gets the value from the node of the index passed
        /// </summary>
        /// <param name="index">Location of node</param>
        /// <returns>Value at the index supplied</returns>
        /// <exception cref="ArgumentOutOfRangeException">Throws exception if linked list is empty</exception>
        public T ValueAt(int index)
        {
            // if head is null, empty list
            if (_head == null)
                throw new ArgumentOutOfRangeException($"Linked List is empty!");

            // boolean if found in list
            var found = false;

            // store head for traversal
            var current = _head;
            // loop over linked list
            for (int i = 0; current.GetNext() != null; i++)
            {
                // if i is index, break out we found
                if (i == index)
                {
                    found = true;
                    break;
                }

                // move current to next
                current = current.GetNext();
            }
            // if the index wasn't in list
            if (!found)
                throw new ArgumentOutOfRangeException($"Index is out of range of the linked list");
            // return the data at current
            return current.GetData();
        }

        /// <summary>
        /// Removes the node with value passed
        /// 
        /// TODO: implement this method
        /// </summary>
        /// <param name="data">The value of the node to remove</param>
        /// <exception cref="NotImplementedException">Throws exception if not implemented</exception>
        public void Remove(T data)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Reverses the Linked List
        /// 
        /// TODO: implement this methovalued
        /// </summary>
        /// <exception cref="NotImplementedException">Throw exception until implemented</exception>
        public void Reverse()
        {
            throw new NotImplementedException();
        }
        
        /// <summary>
        /// The To String
        /// </summary>
        /// <returns>The string of the list</returns>
        public override string ToString()
        {
            // init a string
            var output = "";
            // init a pointer to the head
            var current = _head;
            // loop while next isn't null
            while (current.GetNext() != null)
            {
                // append the data and an arrow denoting pointing to next node
                output += current.GetData() + "->";
                // move to next
                current = current.GetNext();
            }

            // append last data to string
            output += current.GetData();
            // return the string
            return output;
        }

        #region Node

        /// <summary>
        /// This is the node class that represents
        /// each node of the linked list
        /// </summary>
        /// <typeparam name="S">Generic Type</typeparam>
        private class Node<S>
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