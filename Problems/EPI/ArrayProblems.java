import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public final class ArrayProblems {

    /**
     * This method takes a list of integers
     * such as [1,2,9] and adds one to the list
     * and returns [1,3,0] treating the list as an int
     *
     * Time Complexity: O(n)
     *
     * @param A List of integers
     * @return Added 1 to A list
     */
    public static List<Integer> plusOne(List<Integer> A) {
        // store the size
        int n = A.size() - 1;
        // set last as last+1
        A.set(n, A.get(n) + 1);

        // loop over list finding where ith pos is 10
        for (int i=n; i > 0 && A.get(i) == 10; i--) {
            // set ith to 0
            A.set(i, 0);
            // add one to prev
            A.set(i-1, A.get(i-1) + 1);
        }

        // if 0 is 10, then we have carry out
        if (A.get(0) == 10) {
            // we set one to the first
            A.set(0, 1);
            // then add a 0 to end
            A.add(0);

            // if we had [9,9] as list.. add one we will get
            // 10, 0.. so we set first to 1, then append 0 to end
            // resulting in [1,0,0]
        }
        // return list
        return A;
    }

    /**
     * Multiplies 2 lists together and product as list
     * i.e., [1,2] X [3,4] = [4,0,8]
     *
     * Time Complexity: O(n*m)
     *  n = length of N
     *  m = length of M
     *
     * @param N first list
     * @param M second list
     * @return product of N * M
     */
    public static List<Integer> multiply(List<Integer> N, List<Integer> M) {
        // store the sign of the numbers
        final int sign = N.get(0) < 0 ^ M.get(0) < 0 ? -1 : 1;
        // initially set the first digit to a positive number regardless
        N.set(0, Math.abs(N.get(0)));
        M.set(0, Math.abs(M.get(0)));
        // create a list for the result to be stored in
        List<Integer> result = new ArrayList<>(Collections.nCopies(N.size() + M.size(), 0));

        // loop through the lists
        for (int i=N.size()-1; i>=0; i--) {
            for (int j=M.size()-1; j>=0; j--) {
                // this basically is doing the basic grade school multiplication
                result.set(i + j + 1, result.get(i+j+1) + N.get(i) * M.get(j));
                result.set(i+j, result.get(i+j) + result.get(i+j+1) / 10);
                result.set(i+j+1, result.get(i+j+1) % 10);
            }
        }

        // this is finding the position of the first non zero as there
        // may be padding zeros at beginning of list due to multiplication
        int nonZero = 0;
        while (nonZero < result.size() && result.get(nonZero) == 0) {
            ++nonZero;
        }

        // set the list as a sublist of first non-zero to end
        result = result.subList(nonZero, result.size());

        // if empty, return 0
        if (result.isEmpty())
            return java.util.Arrays.asList(0);

        // now we return the result re-applying the sign
        result.set(0, result.get(0) * sign);
        return result;
    }

    /**
     * Given a list of allowable steps to take in one turn..
     * i.e., [3,3,1,0,2,0,1]
     * this method will determine if the player can make it
     * to the end of the list (board game)
     *
     * So we start at first A[0] -> 3, so we get to move 3 steps,
     * now we are at A[4] -> 2, so we get to move 2 steps and now at end!
     *
     * As opposed to [3,2,0,0,2,0,1] is not winnable
     *
     * Time Complexity O(n)
     *
     * @param steps list of steps for player
     * @return true if player can reach end
     */
    public static boolean canReachEnd(List<Integer> steps) {
        // initialize farthest: position player can go in turn
        // and last index of list
        int farthest = 0, lastIndex = steps.size()-1;

        // loop through list as long as farthest is less than last index
        for (int i=0; i<= farthest && farthest < lastIndex; i++) {
            // determine which steps to take.. farthest or the next
            farthest = Math.max(farthest, i + steps.get(i));
        }

        // return boolean based on if player won or not
        return farthest >= lastIndex;
    }

    /**
     * Given a list, will remove all the duplicates and will
     * return the number of valid entries of the list
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param A list of integers
     * @return Number of valid entries in list
     */
    public static int removeDuplicates(List<Integer> A) {
        // if list is empty, return 0
        if (A.isEmpty())
            return 0;

        // set the index to 1
        int index = 1;
        // loop over list
        for (int i=1; i<A.size(); i++) {
            // if previous item isnt the same as current
            if (!A.get(index -1).equals(A.get(i))) {
                // set the index to current item and then increment index
                A.set(index++, A.get(i));
            }
        }
        // return the number valid entries in list
        return index;
    }

    /**
     * Variant of removeDuplicates.  This method removes
     * the supplied key from the list.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param A list
     * @param key item to remove from list
     * @return number of valid entries in list
     */
    public static int removeKey(List<Integer> A, int key) {
        // if list is empty, return 0
        if (A.isEmpty())
            return 0;
        // init an index
        int index = 0;
        // loop through index
        for (int i=0; i<A.size(); i++) {
            // if the current isnt the key to remove
            if (!A.get(i).equals(key))
                // set the current index to current item
                A.set(index++, A.get(i));
        }
        // return index
        return index;
    }

    /**
     * This method will calculate the max profit one could
     * make from buying and selling shares in the same day.
     * The profit can only be made by buying and then selling.
     * So the order of the list is the 'time' of the stock prices.
     *
     * This is a greedy algorithm
     *
     * Time Complexity O(n)
     * Space Complexity O(1)
     *
     * @param prices list of stock prices
     * @return max profit to be made from these stocks
     */
    public static double maxProfit(List<Double> prices) {
        // init values
        double profit = 0.0, min = Double.MAX_VALUE;

        // loop over stock prices
        for (double price : prices) {

            // calculate the max profit each loop
            // if min is greater that price, (price - min)
            // will be negative and current profit will
            // be the max (if stocks go down, will always be 0)
            profit = Math.max(profit, price - min);

            // determine which is lower, price or min
            min = Math.min(price, min);
        }

        // when loop falls off, profit will be max
        // profit from buying and selling stocks
        return profit;
    }

    /**
     * Variant of stock prices problem
     *
     * This method returns the length of the longest
     * sub array of equal numbers.
     * Example: the array of {1,1,2,2,2,2,3,3}
     * would yield the result of 4, bc there are
     * 4 of the number 2 that would make a sub array
     *
     * Time Complexity O(n)
     * Space Complexity O(1)
     *
     * @param numbers list of numbers
     * @return length of the sub array of equal numbers
     */
    public static int longestSubArray(List<Integer> numbers) {
        // init values (len as 1, because the first number in a
        // series needs to be counted.  started w/ 0, but was one off)
        int len = 1, max = 0;

        // loop over the numbers
        for (int i=0; i<numbers.size()-1; i++) {
            // check current and next num
            if (numbers.get(i).equals(numbers.get(i+1)))
                // increment len if same
                len++;
            else
                // reset len if different
                len = 1;

            // store the max each iteration
            max = Math.max(len, max);
        }

        // return the max count sub array
        return max;
    }


    /**
     * This method rearranges the list as:
     * A[0] <= A[1] >= A[2] <= A[3] ...
     *
     * Time Complexity: O(n)
     *
     * @param A List to rearrange
     */
    public static void rearrange(List<Integer> A) {
        // loop from 2nd item to last
        for (int i=1; i<A.size(); i++){
            // when even swap if prior is less than current
            // when odd swap if prior is greater than current
            if (((i % 2) == 0 && A.get(i-1) < A.get(i))
                    || ((i % 2) != 0 && A.get(i-1) > A.get(i)))
                // swap.
                Collections.swap(A, i-1, i);
        }
    }
}
