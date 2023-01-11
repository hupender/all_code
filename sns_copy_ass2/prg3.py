from pickle import TRUE
import string
import sys

def check_lower_case(char):
    if 'a'<=char<='z':
        return True
    else:
        return False

def check_upper_case(char):
    if 'A'<=char<='Z':
        return True
    else:
        return False

def check_num(char):
    if '0'<=char<='9':
        return True
    else:
        return False

def get_index_of_char(char):
    #if char is between 0 and 9 its index will be same as it's integer value
    if '0' <= char <= '9':
        return int(char)
    #space is at index 10 so return 10
    elif char == " ":
        return 10
    else:
        return ord(char) - 86

def cipher_text(plain_text,chars,initial_key):
    cipher_text = ""
    len_chars = len(chars)
    next_key = initial_key
    for char in plain_text:
        cur_key = next_key
        cipher_index = (get_index_of_char(char) + cur_key) % len_chars
        cipher_text += chars[cipher_index]
        next_key = get_index_of_char(char)
    return cipher_text

chars = list(map(str,list(range(10)))) + [" "] + [chr for chr in string.ascii_lowercase]
k_roll1 = 7  ## last digit of roll no BT19CSE037
plain_text = " ".join(sys.argv[1:])
print(cipher_text(plain_text,chars,k_roll1).upper(),end="")