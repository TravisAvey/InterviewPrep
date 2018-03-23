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

    public static long multiply(long x, long y) {
        long sum = 0;

        while (x != 0) {
            if ((x & 1) != 0) {
                sum = add(sum, y);
            }

            x >>= 1;
            y <<= 1;
        }

        return sum;
    }

    public static long add(long x, long y) {
        long sum = 0;
        long carry = 0;
        long k = 1;
        long tempX = x, tempY = y;

        while (tempX != 0 || tempY != 0) {
            long xK = x & k;
            long yK = y & k;
            long carryOut = (xK & yK) | (xK & carry) | (yK & carry);

            sum |= (xK ^ yK ^ carry);
            carry = carryOut << 1;
            k <<= 1;
            tempX >>= 1;
            tempY >>= 1;
        }


        return sum | carry;
    }
}
