/**
 * This is the hash table implementation
 * using an array for the entries. Where
 * each entry is a linked list
 *
 * @param <K> generic key type
 * @param <V> generic value type
 */
public class HashTable<K, V> {
    // the size of the entries
    private final int SIZE = 32;

    // the entries array
    private Entry[] entries = new Entry[SIZE];

    /**
     * This method puts the value into
     * the hash table
     *
     * @param key the key to retrieve later
     * @param value the value to add
     */
    public void put(K key, V value) {
        // generate the hash value (where this will go in table)
        int hash = getHash(key);
        // init a new entry with the key and value
        final Entry<K, V> entry = new Entry<>(key, value);
        // if this hash location is null
        if (entries[hash] == null)
            // store entry in hash location
            entries[hash] = entry;
        // otherwise the loc isn't null
        else {
            // store the entry in temp variable
            Entry temp = entries[hash];
            // while temp isn't null
            while (temp != null) {
                // go to next
                temp = temp.next;
            }
            // set the temp's next to the entry
            temp.next = entry;
        }
    }

    /**
     * This method retrieves a value from the hash table
     * 
     * @param key to retrieve the value
     * @return the value retrieved from hash table
     */
    public V get(K key) {
        // get the hash of key
        int hash = getHash(key);
        // if the loc isn't null
        if (entries[hash] != null) {
            // get the linked list of hash
            Entry temp = entries[hash];
            
            // as long as keys dont match and next isn't null
            while (!temp.key.equals(key) && temp.next != null) {
                // move to next in list
                temp = temp.next;
            }
            // return the value
            return (V) temp.value;
        }
        // if we got here, not in table
        // return null
        return null;
    }
    
    public boolean find(V value) {
        for (Entry entry : entries) {
          if (entry == null) continue;
          Entry temp = entry.next;
          while (temp != null) {
            if (temp.equals(value)) return true;
            temp = temp.next;
          } 
        }
        return false;
    }

    /**
     * This helper method gets the hash
     * of the key
     * 
     * @param key to hash
     * @return hash value of key
     */
    private int getHash(K key) {
        // return hash value
        return key.hashCode() % SIZE;
    }

    /**
     * Private helper class to store the entries
     * @param <K> generic key type
     * @param <V> generic value type
     */
    private class Entry<K, V> {
        // the key and value
        K key;
        V value;
        
        // pointer to next
        Entry<K, V> next;

        /**
         * Constructor
         * 
         * @param key the key to retrieve
         * @param value the value to store
         */
        private Entry(K key, V value) {
            // set variables
            this.key = key;
            this.value = value;
            this.next = null;
        }

        @Override
        public String toString() {
            return "[" + key + ", " + value + "]";
        }
    }
}
