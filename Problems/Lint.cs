using System;
using System.Collections.Generic;

namespace Solution
{
    class Solution
    {

        
        public static bool Lint(string code)
        {
            Stack<char> stack = new Stack<char>();
            
            foreach (char c in code)
            {
                if (c == '{' || c == '(' || c == '[')
                    stack.Push(c);
                else
                {
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
            
            return true;
        }

        public static void Main(string[] args)
        {
            string code = "public static void Main(string[] args){}";
            if (Lint(code))
                Console.WriteLine("Code passes");
            else
                Console.WriteLine("Code fails");
        }
    }
}
