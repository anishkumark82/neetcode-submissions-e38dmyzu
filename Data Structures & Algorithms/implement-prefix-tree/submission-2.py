class TrieNode:
    def __init__(self):
        self.chMap = {}
        self.word = False

class PrefixTree:

    def __init__(self):
        self.head = TrieNode()        

    def insert(self, word: str) -> None:
        itr = self.head
        for w in word:
            if w not in itr.chMap:
                itr.chMap[w] = TrieNode()
            itr = itr.chMap[w]
        itr.word = True

    def search(self, word: str) -> bool:
        itr = self.head
        for w in word:
            if w not in itr.chMap:
                return False
            itr = itr.chMap[w]
        return itr.word

    def startsWith(self, prefix: str) -> bool:
        itr = self.head
        for w in prefix:
            if w not in itr.chMap:
                return False
            itr = itr.chMap[w]
        return True
        