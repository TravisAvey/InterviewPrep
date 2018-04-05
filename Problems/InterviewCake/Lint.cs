using System;
using System.Collections.Generic;

namespace Solution
{
    class Solution
    {

        /// <summary>
        /// Checks string to see if the code is valid
        /// with matching {}, (), [].. could add more checks
        ///
        /// Runtime: O(n), has to iterate through each char in string
        /// Space:   O(n), if all characters are {, (, or [ plus any others..
        /// </summary>
        /// <returns>true if code is valid</returns>
        public static bool Lint(string code)
        {
            // use a stack to keep track of what
            // is at the top ( {, [, ( )
            // when a closing bracket is found
            Stack<char> stack = new Stack<char>();
            
            // loop over all the characters in the code string
            foreach (char c in code)
            {
                // check if one of the brackets, add to
                // the stack
                // (here if we needed to extend this the
                // interview cake solution has using a
                // dictionary to check if char is in it)
                if (c == '{' || c == '(' || c == '[')
                    stack.Push(c);
                else
                {
                    // else, check if char is one of the
                    // closing brackets/braces
                    // if we pop the top off stack and
                    // doesn't mactch the closing tag
                    // return false because code fails!
                    switch(c)
                    {
                        case '}':
                            if (stack.Pop() != '{')
                                return false;
                                break;
                        case ')':
                            if (stack.Pop() != '(')
                                return false;
                                break;
                        case ']':
                            if (stack.Pop() != '[')
                                return false;
                                break;
                        default:
                            continue;
                    }
                }
            }
            
            // we get to this point, then the code is
            // good and we can return true
            return true;
        }

        public static void Main(string[] args)
        {
            // testing
            string code = "public static void Main(string[] args){}";
            if (Lint(code))
                Console.WriteLine("Code passes");
            else
                Console.WriteLine("Code fails");
        }
    }
}
