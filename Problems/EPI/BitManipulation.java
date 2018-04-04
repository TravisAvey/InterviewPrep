/**
 * Problems/Examples from Elements of Programming Interviews
 * on bit manipulation
 */
public class BitManipulation {


    // all methods static, no need for object instantiation
    private BitManipulation() {}

    /**
     * This method counts the parity of the 'word'
     * Checks the number of 1's in the word.
     *
     * Time Complexity O(n)
     * where n is the number of 1s in the word
     *
     * @param value word
     * @return 1 if number of 1's is odd, 0 if even
     */
    public static short parity(long value) {
        // init result to 0
        short result = 0;

        // while the word isn't 0
        while (value != 0) {
            // XOR result with 1
            // every other loop will be 0 or 1
            // leaving 1 for odd times, and 0 for
            // even times
            result ^= 1;
            // drops the lowest bit of the value
            value &= (value - 1);
        }

        // return the parity
        return result;
    }

    /**
     * This method takes in the value and two positions
     * to swap the bits
     *
     * Time Complexity: O(1)
     * Only needs to check ith and jth bit, then perform
     * the bit mask to swap the bits
     *
     * @param val word to swap bits
     * @param i index i
     * @param j index j
     * @return value with swapped bits
     */
    public static long swapBits(long val, int i, int j) {
        // Extract ith and jth bits and see if they differ
        if (((val >> i) & 1) != ((val >> j) & 1)) {
            // swap them by flipping their values
            // select bits with mask: x ^ 1 = 0 when x = 1
            // and x ^ 1 = 1 when x = 0, perform the flip XOR
            long bitMask = (1L << i) | (1L << j);
            val ^= bitMask;
        }
        // return word (if bits were swapped or not)
        return val;
    }

    /**
     * This method counts the number of 1's in the word
     *
     * Time Complexity: O(n)
     * need to check every bit to see if it is a 1 or 0
     *
     * @param val word to count bits
     * @return number of 1s in the word
     */
    public static short countBits(long val) {
        // init a count
        short count = 0;
        // loop while val isn't 0
        while (val != 0) {
            // append to the count :
            // val AND 0001, which will
            // add 1 IFF the last bit is a 0
            count += (val & 1);
            // shift the bits 1 to the right
            // removing last bit from word
            val >>= 1;
        }
        // return the count of bits
        return count;
    }

    /**
     * Without the use of operators, this method
     * multiplies the two values
     * 
     * Time Complexity: O(n^2)
     * Because we do n number of add method, which
     * is O(n) = n*n
     * @param x value
     * @param y value
     * @return x * y
     */
    public static long multiply(long x, long y) {
        // init a sum
        long sum = 0;
        // while x isn't 0
        while (x != 0) {
            // check the lowest bit isn't 0
            if ((x & 1) != 0) {
                // add to the sum y
                sum = add(sum, y);
            }
            // shift x one bit to the right
            x >>= 1;
            // shift y one bit to the left
            y <<= 1;
        }

        // return the sum
        return sum;
    }

    /**
     * Without the use of operators, this method
     * adds the 2 values passed
     * 
     * Time Complexity: O(n)
     * 
     * @param x value
     * @param y value
     * @return the sum of x and y
     */
    public static long add(long x, long y) {
        // init sum
        long sum = 0;
        // carry
        long carry = 0;
        // init counter to 1
        long k = 1;
        // init temps for x and y
        long tempX = x, tempY = y;

        // while the temps arent 0
        while (tempX != 0 || tempY != 0) {
            // and the values of x and k
            long xK = x & k;
            // and the values of y and x
            long yK = y & k;
            // compute the carry out
            long carryOut = (xK & yK) | (xK & carry) | (yK & carry);

            // OR the values of xK, yK and carry
            sum |= (xK ^ yK ^ carry);
            // set carry to carry out shifted 1 bit to left
            carry = carryOut << 1;
            // shift k one bit left
            k <<= 1;
            // shift temp vals to the right one
            tempX >>= 1;
            tempY >>= 1;
        }

        // return the sum OR'd with carry
        return sum | carry;
    }

    /**
     * Without the use of division/multiplication, this method
     * divides the two values. x / y
     * 
     * Time Complexity: O(n)
     * 
     * @param x numerator
     * @param y denominator
     * @return x / y
     */
    public static int divide(int x, int y) {
        // init the result
        int result = 0;
        // init the power
        int power = 32;
        // init yPoer to y shift to the left power
        long yPower = y << power;
        // while x is greater than y
        while (x >= y) {
            // while the y power is greater than x
            while (yPower > x) {
                // shift yPower 1 to right
                yPower >>= 1;
                // decrement power
                --power;
            }

            // add to result 1 shifted to the left by power
            // this in reality increments result by 1 each loop
            result += 1 << power;
            // decrement x by yPower
            x -= yPower;
        }
        // return the result of x / y
        return result;
    }

    /**
     * Without the use of Math.pow, this method calculates
     * the power of x^y
     * 
     * Time Complexity: O(n)
     * @param x base
     * @param y exponent
     * @return x ^ y
     */
    public static double power(double x, int y) {
        // init result to 1
        double result = 1.0;
        // set power to y
        long power = y;

        // if y is negative
        if (y < 0) {
            // gets pos val of power
            power = -power;
            // invert the base
            x = 1.0 / x;
        }

        // while power isn't 0
        while (power != 0) {
            // if the last bit of power isn't 0
            if ((power & 1) != 0) {
                // multiply result by x
                result *= x;
            }
            // multiply x by x
            x *= x;
            // shift power to the right by 1 bit
            power >>= 1;
        }
        // return result of x^y
        return result;
    }

    /**
     * This method takes an integer and reverses
     * 123 becomes 321
     *
     * Time Complexity: O(n)
     *
     * @param x int to reverse
     * @return reversed x
     */
    public static long reverse(int x) {
        // init result
        long result = 0;
        // get the positive value of x
        long remaining = Math.abs(x);
        // while remainingin isn't 0
        while (remaining != 0) {
            // put the result of:
            // result x 10, which adds on zero to result
            // add remaining modulus 10, which adds the last digit
            result = result * 10 + remaining % 10;
            // set remaining to next digit
            remaining /= 10;
        }

        // here we return the result, putting back
        // the negative sign if there was one
        return x < 0 ? -result : result;
    }
}
