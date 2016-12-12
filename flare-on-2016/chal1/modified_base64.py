import string
import base64

"""
  -Hardcoded string: x2dtJEOmyjacxDemx2eczT5cVS9fVUGvWTuZWjuexjRqy24rV29q, len=52
    -Maybe password, too long to be alphabet
  -ZYXABCDEFGHIJKLMNOPQRSTUVWzyxabcdefghijklmnopqrstuvw012345679?/
"""

modified_alpha = "ZYXABCDEFGHIJKLMNOPQRSTUVWzyxabcdefghijklmnopqrstuvw012345679?/"
Base64_alpha   = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz012345679?/" 
s = ""

cipher_text =  "x2dtJEOmyjacxDemx2eczT5cVS9fVUGvWTuZWjuexjRqy24rV29q"

#Substitute alphabets
for ch in cipher_text:
    if (ch in Base64_alpha):
        s = s + Base64_alpha[string.find(modified_alpha, str(ch))]
    elif (ch == "="):
        s += "="

#Decode base64
print (base64.decodestring(s))
