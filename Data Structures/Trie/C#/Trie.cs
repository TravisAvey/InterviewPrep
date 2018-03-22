using System;
using System.Collections.Generic;

namespace DataStructures.Classes
{
    /// <summary>
    /// This class is the Trie class
    /// It is a tree where each node contains
    /// a character and a pointer to the next node
    /// that will make up a word. At the end of each
    /// word, a boolean value will determine if it is a
    /// word or not.
    /// </summary>
    public class Trie
    {
        // the root
        private readonly Node root;
        
        /// <summary>
        /// Constructor
        /// </summary>
        public Trie()
        {
            // init the root
            root = new Node();
        }

        /// <summary>
        /// Inserts a word into the Trie
        /// </summary>
        /// <param name="word">String to insert</param>
        /// <exception cref="ArgumentNullException">Throws if word is empty or null</exception>
        public void Insert(string word)
        {
            // if word is empty or null, throw exception
            if (string.IsNullOrEmpty(word))
                throw new ArgumentNullException($"Word cannot be empty or null");

            // init a travesal node pointing at the root
            Node current = root;

            // loop over length of the word
            for (int i = 0; i < word.Length; i++)
            {
                // get the current char of the word
                char ch = word[i];
                
                // declare a node
                Node node;
                // if the current node is the current char
                if (current.Children.ContainsKey(ch))
                    // set the node
                    node = current.Children[ch];
                // else, the node isn't the char.. 
                // need to create a new node for this
                // char and append to the trie
                else
                {
                    // init new node
                    node = new Node();
                    // add this node to the current
                    current.Children.Add(ch, node);
                }
                // set current to 'next'
                current = node;
            }

            // finally set the current to be a word
            // when the loop falls off, we are at the
            // last character of the word.
            current.IsWord = true;

        }

        /// <summary>
        /// Searches for the word in the trie
        /// </summary>
        /// <param name="word">String to search for</param>
        /// <returns>True if word is in trie, false otherwise</returns>
        /// <exception cref="ArgumentNullException">Throws exception if string is empty or null</exception>
        public bool Search(string word)
        {
            // throw exception if empty/null
            if (string.IsNullOrEmpty(word))
                throw new ArgumentNullException($"Word cannot be empty or null");

            // init a traversal node pointing at the root
            Node current = root;

            // loop over each char in the string
            foreach(char ch in word)
            {
                // declare a node
                Node node;
                // if the current is the char
                if (current.Children.ContainsKey(ch))
                {
                    // set node to this current node
                    node = current.Children[ch];
                }
                else
                    // otherwise if the char isn't a node
                    // then we can return false, because
                    // it's not a word in the trie
                    return false;
                
                // move current to this node
                current = node;
            }
            
            // finally return if the current is a word or not
            return current.IsWord;
        }
        
        /// <summary>
        /// Removes a word from the Trie
        /// 
        /// Uses a stack to put on each node of the word
        /// then checks each node to see if it is a word
        /// if not, then we can safely remove the node
        /// this keeps all other words in trie
        /// </summary>
        /// <param name="word">String to remove</param>
        /// <exception cref="ArgumentNullException">Throws exception if word is empty</exception>
        public void Delete(string word)
        {
            // Throw exception if string is empty/null
            if (String.IsNullOrEmpty(word))
                throw new ArgumentNullException($"Word cannot be empty or null.");

            // check to see if word is in Trie
            if (!Search(word))
            {
                // ouptut error
                Console.WriteLine("Word is not in Trie");
                // return
                return;
            }

            // create a pointer for traversal
            Node current = root;
            // create a stack to put each node in
            // for when we actually remove the nodes
            Stack<Node> stack = new Stack<Node>();
            
            foreach (char ch in word)
            {

                if (current.Children.ContainsKey(ch))
                {
                    stack.Push(current.Children[ch]);
                }
                else
                    return;
                
            }

            // remove last first first b/c checking
            // in while loop for words
            stack.Pop();
            // get the length of the word
            // minus 2 (b/c we removed the last node already)
            int len = word.Length - 2;
            // loop over stack and word len
            while (!stack.IsEmpty() && len >= 0)
            {
                // get the current char
                char ch = word[len];
                // get the current node
                Node node = stack.Pop();
                // if this node is a word
                // then we break out of loop
                // .. can't remove this node
                if (node.IsWord)
                    break;
                // remove this node
                node.Children.Remove(ch);
                // decrement word len
                len--;
            }
        }
    }
    
    /// <summary>
    /// This class is used for each node of the
    /// trie.  Each of these nodes has a dictionary
    /// for a character and a pointer to the next node
    /// Each node specifies a character that will make up
    /// a word.  At the end of the word, a bool will be true
    /// </summary>
    class Node
    {
        /// <summary>
        /// Construtor
        /// </summary>
        public Node()
        {
            // init dictionary
            Children = new Dictionary<char, Node>();
            // init bool to false, not a word yet
            IsWord = false;
        }

        /// <summary>
        /// The Dictionary that holds what char and pointer
        /// to the next node in the trie
        /// </summary>
        public Dictionary<char, Node> Children { get; set; }

        /// <summary>
        /// Boolean value if this node is the end of a
        /// word
        /// </summary>
        public bool IsWord { get; set; }
    }
}