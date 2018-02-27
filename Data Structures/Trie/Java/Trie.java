import java.util.HashMap;
import java.util.Map;

public class Trie {

    private final TrieNode root;

    public Trie() {
        root = new TrieNode();
    }


    public void insert(String word) {

        TrieNode current = root;

        for (int i=0; i<word.length(); i++) {

            char ch = word.charAt(i);
            TrieNode node = current.children.get(ch);

            if (node == null) {
                node = new TrieNode();
                current.children.put(ch, node);
            }

            current = node;
        }

        current.isWord = true;
    }

    public boolean search(String word) {

        TrieNode current = root;

        for (int i=0; i<word.length(); i++) {

            char ch = word.charAt(i);
            TrieNode node = current.children.get(ch);

            if (node == null) return false;

            current = node;
        }

        return current.isWord;
    }


    private class TrieNode {

        Map<Character, TrieNode> children;
        private boolean isWord;

        public TrieNode() {
            children = new HashMap<>();
            isWord = false;
        }
    }
}
