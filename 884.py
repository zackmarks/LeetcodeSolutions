"""
884. Uncommon Words from Two Sentences
https://leetcode.com/problems/uncommon-words-from-two-sentences/description/
Skills: Hashmaps, Strings, Algorithms
"""


class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        words1 = s1.split()
        words2 = s2.split()

        wordDict = {}
        for word in words1:
            wordDict[word] = wordDict.get(word, 0) + 1
        for word in words2:
            wordDict[word] = wordDict.get(word, 0) + 1

        uncommonWords = []

        for key, val in wordDict.items():
            if val == 1:
                uncommonWords.append(key)

        return uncommonWords

