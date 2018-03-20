using System;
using System.Collections.Generic;

namespace DataStructures.Classes
{
    public class Trie
    {
        private readonly Node root;

        public Trie()
        {
            root = new Node();
        }

        public void Insert(string word)
        {
            if (string.IsNullOrEmpty(word))
                throw new ArgumentNullException($"Word cannot be empty or null");

            Node current = root;

            for (int i = 0; i < word.Length; i++)
            {
                char ch = word[i];
                Node node;
                if (current.Children.ContainsKey(ch))
                    node = current.Children[ch];
                else
                {
                    node = new Node();
                    current.Children.Add(ch, node);
                }

                current = node;
            }

            current.IsWord = true;

        }

        public bool Search(string word)
        {
            if (string.IsNullOrEmpty(word))
                throw new ArgumentNullException($"Word cannot be empty or null");

            Node current = root;

            for (int i = 0; i < word.Length; i++)
            {
                char ch = word[i];
                Node node;
                if (current.Children.ContainsKey(ch))
                {
                    node = current.Children[ch];
                }
                else return false;

                current = node;
            }

            return current.IsWord;
        }
        
        
    }

    class Node
    {
        public Node()
        {
            Children = new Dictionary<char, Node>();
            IsWord = false;
        }

        public Dictionary<char, Node> Children { get; set; }

        public bool IsWord { get; set; }
    }
}