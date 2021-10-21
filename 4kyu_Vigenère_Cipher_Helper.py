class VigenereCipher(object):
    def __init__(self, key, alphabet):
        self.key = key
        self.alphabet = alphabet
        self.isKata = False
        self.kata = "アイウエオァィゥェォカキクケコサシスセソタチツッテトナニヌネノハヒフヘホマミムメモヤャユュヨョラリルレロワヲンー"
        self.kataDic = {}
        self.kataRevDic = {}
        for i in range(0, len(self.kata)):
            self.kataDic[i] = self.kata[i]
            self.kataRevDic[self.kata[i]] = i
            #o = ord(self.kata[i])
            #self.kataDic[o] = self.kata[i]

    def encode(self, text):
        if ord(text[0])>256:
            self.isKata = True
        ret = ""
        lenPass = len(self.key)
        first = 0
        size = 0
        if self.isKata:
            size = len(self.kata)
        else:
            first = ord('a')
            size = 26

        for i in range(0,len(text)):
            if self.alphabet.find(text[i]) == -1:
                ret+= text[i]
            else:
                if self.isKata:
                    o = self.kataRevDic[text[i]]
                    p = self.kataRevDic[self.key[i % lenPass]]
                    r = (p + o) % size
                    c = self.kataDic[r]
                else:
                    o = ord(text[i]) - first
                    p = ord(self.key[i % lenPass]) - first
                    r = (p + o) % size + first
                    c = chr(r)
                ret += c
        return ret
    
    def decode(self, text):
        if ord(text[0])>256:
            self.isKata = True
        ret = ""
        lenPass = len(self.key)
        first = 0
        size = 0
        if self.isKata:
            size = len(self.kata)
        else:
            first = ord('a')
            size = 26

        for i in range(0,len(text)):
            if self.alphabet.find(text[i]) == -1:
                ret+= text[i]
            else:
                if self.isKata:
                    o = self.kataRevDic[text[i]]
                    p = self.kataRevDic[self.key[i % lenPass]]
                    r = o - p
                    if r< 0:
                        r += size
                    c = self.kataDic[r]
                else:
                    o = ord(text[i]) - first
                    p = ord(self.key[i % lenPass])- first
                    r = o - p
                    if r< 0:
                        r += size
                    r = r + first
                    c = chr(r)
                ret += c
        return ret
