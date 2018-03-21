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
        
        public void Delete(string word)
        {
            if (String.IsNullOrEmpty(word))
                throw new ArgumentNullException($"Word cannot be empty or null.");

            if (!Search(word))
            {
                Console.WriteLine("Word is not in Trie");
                return;
            }

            Node current = root;

            foreach (char ch in word)
            {


                if (current.Children.ContainsKey(ch))
                {
                    current.Children.Remove(ch);
                }
                else
                    return;

                current.IsWord = false;
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