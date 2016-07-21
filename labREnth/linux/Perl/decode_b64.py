import base64

fo = open("./eval.txt", "r")
data = fo.read()
print base64.b64decode(data)
