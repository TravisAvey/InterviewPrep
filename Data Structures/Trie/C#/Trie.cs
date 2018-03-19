using System;

namespace DataStructures.Classes
{
    public class Trie
    {
        private Node root;
        public Trie()
        {
            root = new Node();
        }

        public void Insert(string word)
        {
            if (string.IsNullOrEmpty(word))
                throw new ArgumentNullException($"Word cannot be empty or null");

            Node current = root;
            
        }
    }

    class Node
    {
        private char[] characters;
        private bool isWord;

        public Node()
        {
            characters = new char[26];
            isWord = false;
        }
    }
}