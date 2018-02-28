import java.util.HashMap;
import java.util.Map;

/**
 * This Trie class
 * Holds the root that points to its children
 * Each TrieNode a char that's of a word and
 * a TrieNode pointing to it's children
 */
public class Trie {
    // root of the Trie
    private final TrieNode root;

    /**
     * Constructor
     * Set the TrieNode
     */
    public Trie() {
        root = new TrieNode();
    }


    /**
     * This method inserts a word into the trie
     * @param word to add
     */
    public void insert(String word) {
        // throw exception if null
        if (word == null)
            throw new IllegalArgumentException("The word cannot be null");
        
        // create a current to point at root
        TrieNode current = root;

        // loop over the word
        for (int i=0; i<word.length(); i++) {
            // get current char
            char ch = word.charAt(i);
            // get the node at the current char
            TrieNode node = current.children.get(ch);
            // if this node is null
            if (node == null) {
                // set to a new node
                node = new TrieNode();
                // input the child char
                current.children.put(ch, node);
            }
            // move current to the node
            current = node;
        }
        // after done, set this word (at current node) to true
        current.isWord = true;
    }

    /**
     * Searches the trie for the word
     * @param word to search
     * @return true if found
     */
    public boolean search(String word) {
        // if word null, throw exception
        if (word == null)
            throw new IllegalArgumentException("Word cannot be null");
        // Init a node pointing to root
        TrieNode current = root;
        
        // loop over the word
        for (int i=0; i<word.length(); i++) {
            // get current char
            char ch = word.charAt(i);
            // get node at this char
            TrieNode node = current.children.get(ch);
            
            // if this node is null, not a word, return false
            if (node == null) return false;
            // set current to this node
            current = node;
        }
        
        // after fall of loop, return whether
        // this current node is a word
        return current.isWord;
    }

    /**
     * This class is the data structure to
     * hold each node.
     * A character, with it's children, and
     * a boolean value if this node is a word
     */
    private class TrieNode {
        
        // A map of current char and trie node
        Map<Character, TrieNode> children;
        // boolean if is word or not
        private boolean isWord;

        /**
         * Constructor
         * Init map & set boolean to false
         */
        public TrieNode() {
            children = new HashMap<>();
            isWord = false;
        }
    }
}
