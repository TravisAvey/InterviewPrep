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

     /**
     * This method converts the int 'x' to a string
     *
     * Time Complexity O(n)
     *      where n is the number of digits of x
     *
     * @param x int
     * @return string
     */
    public static String intToString(int x) {
        // set a flag of is negative to false
        boolean isNeg = false;

        // if x is less than zero, is negative
        if (x < 0)
            isNeg = true;

        // init a new string builder
        StringBuilder sb = new StringBuilder();

        // continue doing while x isn't zero
        do {
            // take the last digit convert to char
            sb.append((char)('0' + Math.abs(x % 10)));
            // remove that last digit
            x /= 10;
        } while (x != 0);

        // if negative, append the negative sign
        if (isNeg) {
            sb.append('-');
        }

        // reverse the string
        // because appending last digit in do..while loop
        // is putting the digits in reverse order, so must
        // reverse back to normal
        sb.reverse();

        // return the string
        return sb.toString();
    }
}