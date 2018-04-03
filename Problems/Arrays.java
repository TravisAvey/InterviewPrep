import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public final class Arrays {

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
        
        final int sign = N.get(0) < 0 ^ M.get(0) < 0 ? -1 : 1;
        
        List<Integer> result = new ArrayList<>(Collections.nCopies(N.size() + M.size(), 0));

        for (int i=N.size()-1; i>=0; i--) {
            for (int j=M.size()-1; j>=0; j--) {
                result.set(i + j + 1, result.get(i+j+1) + N.get(i) * M.get(j));
                result.set(i+j, result.get(i+j) + result.get(i+j+1) / 10);
                result.set(i+j+1, result.get(i+j+1) % 10);
            }
        }

        int nonZero = 0;
        while (nonZero < result.size() && result.get(nonZero) == 0) {
            ++nonZero;
        }
        
        result = result.subList(nonZero, result.size());
        
        if (result.isEmpty())
            return java.util.Arrays.asList(0);
        
        result.set(0, result.get(0) * sign);
        return result;
    }

}
