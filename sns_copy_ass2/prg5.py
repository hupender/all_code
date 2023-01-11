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
    if '0' <= char <= '9':
        return int(char)
    elif char == " ":
        return 10
    else:
        return ord(char) - 86

def encrypt(plain_text,chars,k_trad):
    cipher_text = ""
    len_chars = len(chars)
    cur_ind = 0
    for char in plain_text:
        cipher_index = (get_index_of_char(char) + get_index_of_char(k_trad[cur_ind])) % len_chars
        cipher_text += chars[cipher_index]
        cur_ind += 1
    return cipher_text




chars = list(map(str,list(range(10)))) + [" "] + [chr for chr in string.ascii_lowercase]

k_trad = "hupendrabcfgijklmoqstvwxyz"

one_unit = k_trad

plain_text = " ".join(sys.argv[1:])

while len(plain_text) > len(k_trad):
    k_trad += one_unit
k_trad = k_trad[:len(plain_text)]
print(encrypt(plain_text,chars,k_trad).upper(),end="")

