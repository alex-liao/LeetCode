import sys

class Solution(object):

    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        longest_length = 0
        i = 0
        last_index = len(s) - 1

        while(i <= last_index):
            substring = ""
            j = i
            while(j <= last_index):
                if s[j] not in substring:
                    substring += s[j]
                    j += 1
                    continue
                else:
                    break

            if len(substring) > longest_length:
                longest_length = len(substring)

            i += 1

        return longest_length

if __name__ == "__main__":

    if len(sys.argv) < 2:
        print "usage: python <script_name> <random_string>"
    else:
        soln = Solution()
        print soln.lengthOfLongestSubstring(sys.argv[1])