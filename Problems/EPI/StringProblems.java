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

        /**
     * This method converts a string to an integer
     * 
     * Time Complexity O(n)
     *      where n is the length of the string
     *      
     * @param s string to convert
     * @return converted integer of s
     */
    public static int stringToInt(String s) {
        // init result
        int result = 0;

        // loop over string, starting at 0 if pos, or 1 if neg
        for (int i = s.charAt(0) == '-' ? 1 : 0; i < s.length(); i++) {
            // convert current char to int
            final int digit = s.charAt(i) - '0';
            // append digit to end of result
            result = result * 10 + digit;
        }

        // return the appropriate value (neg/pos)
        return s.charAt(0) == '-' ? -result : result;
    }

    /**
     * This method converts a numbers base to another base
     * 
     * Time Complexity: O(n(1 + log b2 (b1))  --log base b2 (b1)
     *          where n is length of the number
     *          
     * @param num string value of number
     * @param b1 base of number
     * @param b2 base to convert to
     * @return converted string to new base
     */
    public static String convertBase(String num, int b1, int b2) {
        // check if number is negative
        boolean isNegative = num.startsWith("-");
        // init number
        int N = 0;
        // loop over string, starting at 0/1 if negative or not
        for (int i= (isNegative ? 1 : 0); i < num.length(); i++) {
            // multiply N by b1
            N *= b1;
            // add to N the next digit
            N += Character.isDigit(num.charAt(i))
                    ? num.charAt(i) - '0'
                    : num.charAt(i) - 'A' + 10;
        }

        // return the number with a negative sign or not
        return (isNegative ? "-" : "")
                + (N == 0 ? "0" : constructFromBase(N, b2));

    }

    /**
     * Helper method for converting the base of a number
     * 
     * @param N number to convert
     * @param base base to convert to
     * @return string representation of converted number
     */
    private static String constructFromBase(int N, int base) {
        // if N is 0 return blank string
        return N == 0 ? ""
                // else recurse on number dividing by the base
                // adding the appropriate character
                : constructFromBase(N/base, base)
                + (char)(N % base >= 10 ? 'A' + N % base - 10
                                        : '0' + N % base);
    }

    /**
     * This method reverses a char array of words:
     * ram is costly : yltsoc si mar
     * 
     * Time Complexity O(n)
     * Additional space O(1)
     * 
     * @param input char array to reverse
     */
    public static void reverseWords(char[] input) {
        // cache length of input
        int n = input.length;
        // init start and end to 0
        int start = 0, end = 0;
        
        
        // while start is less than n
        while (start < n) {
            // while start less than end or if current char is a space
            while (start < end || start < n && input[start] == ' ') {
                // increment start
                ++start;
            }
            // while end is less than start, or if current char isn't a space
            while (end < start || end < n && input[end] != ' ') {
                // increment end
                ++end;
            }
            // we now have a word from start to end-1
            // call helper method to reverse the word
            reverse(input, start, end-1);
        }
    }

    /**
     * This is a helper method that reverses a word 
     * 
     * Time Complexity O(n)
     * 
     * @param array char array containing word to reverse
     * @param start start index of word
     * @param end end index of word
     */
    private static void reverse(char[] array, int start, int end) {
        // while start index is less than end index
        while (start < end) {
            // exchange start and end chars
            char temp = array[start];
            array[start++] = array[end];
            array[end--] = temp;
        }
    }

    /**
     * This method converts a roman numeral to an integer
     * 
     * Main algorithm:
     * as looping down from 2nd to last, we are checking
     * the next if value is greater, as in IX or IV
     * Firt iteration we have stored X or V, next
     * time through loop, I is less so we subtract that
     * value ending with correct value of either 9 or 4
     * in this case
     * 
     * Time Complexity O(n)
     * 
     * @param roman string : roman numeral
     * @return converted roman numeral
     */
    public static int romanToInteger(String roman) {
        
        // create a Hash Map of values for each roman numeral integer
        Map<Character, Integer> map = new HashMap<Character, Integer>() {
            {
                put('I', 1);
                put('V', 5);
                put('X', 10);
                put('C', 50);
                put('M', 100);
                put('D', 500);
                put('L', 1000);
            }
        };

        // get the last letter value
        int sum = map.get(roman.charAt(roman.length()-1));

        // loop over from 2nd to last to beginning
        for (int i=roman.length()-2; i>=0; i--) {
            // if current value is less than next
            if (roman.charAt(i) < roman.charAt(i+1))
                // subtract value from sum
                sum -= map.get(roman.charAt(i));
            else
                // otherwise, add the current value
                sum += map.get(roman.charAt(i));
        }
        // finally value of the roman numeral
        return sum;
    }
}