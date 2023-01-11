import string
import sys
def cipher_text(plain_text,chars,key1,key2):
    cipher_text = ""
    len_chars = len(chars)
    for char in plain_text:
        #if char is between 0 and 9 its index will be same as it's integer value
        if '0' <= char <= '9':
            cipher_index = (int(char)* key1 + key2) % len_chars
        #space is at index 10 so return 10
        elif char == " ":
            cipher_index = (10 * key1 + key2) % len_chars
        else:
            cipher_index = ((ord(char) - 86) * key1 + key2) % len_chars
        cipher_text += chars[cipher_index]
    return cipher_text
chars = list(map(str,list(range(10)))) + [" "] + [chr for chr in string.ascii_lowercase]
k_roll1 = 7  ## last digit of roll no BT19CSE037
k_roll2 = 3  ## last second digit of roll no BT19CSE037
plain_text = " ".join(sys.argv[1:])
print(cipher_text(plain_text,chars,k_roll1,k_roll2).upper(),end="")