import java.util.ArrayList;
import java.util.List;

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
    private final int SIZE = 4;

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
            while (temp.next != null) {
                // go to next
                temp = temp.next;
            }
            // set the temp's next to the entry
            // Issue was here *********
            // Needed to set the next to the entry
            // also, while loop needed to check next
            // wasn't null !!! ***!!!
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
            while (temp != null) {
                if (temp.key.equals(key))
                    return (V) temp.value;
                // move to next in list
                temp = temp.next;
            }

        }
        // if we got here, not in table
        // return null
        return null;
    }

    /**
     * This method returns the set of keys
     * for each value in the hash table
     * @return
     */
    public List<K> keySet() {
        // init a new list
        List<K> list = new ArrayList<>();
        // loop through the entries
        for (Entry entry : entries) {
            // if the current entry isn't null
            if (entry == null) continue;

            // store current entry
            Entry temp = entry;
            // while temp isn't null
            while (temp != null) {
                // add the key to the list
                list.add((K) temp.key);
                // move to next entry
                temp = temp.next;
            }

        }
        // return the list
        return list;
    }

    /**
     * This method determines if the key is
     * present in the hash table
     * @param key to find
     * @return true if contains, false otherwise
     */
    public boolean containsKey(Object key) {
        // for each entry
        for (Entry entry : entries) {
            // if current is null, continue
            if (entry == null) continue;
            // store current entry
            Entry temp = entry;
            // while current isn't null
            while (temp != null) {
                // if the current key is what
                // we are looking for, return true
                if (temp.key.equals(key))
                    return true;
                // move to next
                temp = temp.next;
            }
        }
        // got here? not in table, return false
        return false;
    }

    /**
     * This method searches the hash table for
     * the value
     * @param value to search
     * @return true contains, false otherwise
     */
    public boolean contains(V value) {
        // loop over all entries
        for (Entry entry : entries) {
            // if the entry is null, go to next
            if (entry == null) continue;
            // save entry
            Entry temp = entry;
            // while temp isn't null
            while (temp != null) {
                // check if the value is what looking for
                // return true if it is
                if (temp.value.equals(value)) return true;
                // move to next entry
                temp = temp.next;
            }
        }
        // if we got here, not in hash table, return false
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
        return java.util.Objects.hash(key) % SIZE;
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

