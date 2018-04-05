public class ReverseWords {

    private ReverseWords() {}

    /**
     * This method reverses the words in a char array
     * where each word is separated by a space in the char array
     * 
     * example: ['t', 'h', 'e', ' ', 'f', 'u', 'n', ' ', 'b', 'e', 'g', 'i', 'n', 's']
     * returns: begins fun the
     * 
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     * 
     * This is solved by trying to solve a simpler version of the problem.
     * We reverse the characters, which puts the words in order but the
     * characters are backwards for each word.  So, the only thing left 
     * to do is reverse the chars of each word.
     *
     * @param message char array to reverse
     */
    public static void reverseWords(char[] message) {
        // start by reversing all the characters in the array
        reverseCharacters(message, 0, message.length-1);

        // keep track of current word index
        int currentWord = 0;

        // loop through array, note <= len
        for (int i=0; i<= message.length; i++) {
            // if we are at message len or current char is a space
            if (i == message.length || message[i] == ' ') {
                // reverse the characters from the word index to last index (i-1)
                // where i-1 is the last letter of the word, and i is a space...
                reverseCharacters(message, currentWord, i-1);
                // move current word index to next character
                currentWord = i+1;
            }
        }
    }

    /**
     * Private helper method to reverse the characters in the array
     * ex: ['a', 'b', 'c'] becomes ['c', 'b', 'a']
     * 
     * @param message char array to reverse
     * @param left index of first char
     * @param right index of last char
     */
    private static void reverseCharacters(char[] message, int left, int right) {
        // loop while left is less than right
        // this way we don't cross and re-swap chars
        while (left < right) {
            // store temp
            char temp = message[left];
            // store right's into left's
            message[left] = message[right];
            // store temp into right
            message[right] = temp;
            // increment/decrement left/right
            left++;
            right--;
        }
    }
}
