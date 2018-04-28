public class StringProblems {

    // Use static methods, don't allow
    // instantiation.
    private StringProblems() {}

    /**
     * This method checks the string s if it
     * is a palindrome
     * 
     * Time Complexity: O(n)
     * 
     * @param s string
     * @return true if palindrome
     */
    public static boolean isPalindrome(String s) {
        
        // loop from beginning and end
        for (int i=0, j=s.length()-1; i<j; i++, j--) {
            // if at anytime ith and jth are different
            // this is not a palindrome, return false
            if (s.charAt(i) != s.charAt(j))
                return false;
        }
        // fall off loop, it is a palindrome
        return true;
    }
}