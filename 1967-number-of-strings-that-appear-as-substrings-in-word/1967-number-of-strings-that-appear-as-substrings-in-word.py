class Solution(object):
    def numOfStrings(self, patterns, word):
        """
        :type patterns: List[str]
        :type word: str
        :rtype: int
        """
        res = 0;
        for i in range (0, len(patterns)):
            if patterns[i] in word:
                res=res+1;
        return res
        