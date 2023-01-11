import string
import sys



k_trad = "hupendrabcfgijklmoqstvwxyz"
chars = list(map(str,list(range(10)))) + [" "] + [chr for chr in string.ascii_lowercase]

def get_index_of_char(char):
    if '0' <= char <= '9':
        return int(char)
    elif char == " ":
        return 10
    else:
        return ord(char) - 86

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



def generate_hill_key(k_trad):
    key_mat = [[0 for i in range(5)] for j in range(5)]
    for i in range(25):
        key_mat[i //5 ][i % 5] = get_index_of_char(k_trad[i])
    return key_mat
def matrix_mul_mod(A,B,m):
    # retrieving the sizes/dimensions of the matrices
    for i in A:
        print(i)
    for i in B:
        print(i)
    p = len(A)
    q = len(A[0])

    t = len(B)
    r = len(B[0])

    # creating the product matrix of dimensions p×r
    # and filling the matrix with 0 entries
    C = []
    for row in range(p):
        curr_row = []
        for col in range(r):
            curr_row.append(0)
        C.append(curr_row)

    # performing the matrix multiplication
    for i in range(p):
        for j in range(r):
            curr_val = 0
            for k in range(q):
                curr_val += ((A[i][k] * B[k][j]))
            print(curr_val)
            C[i][j] = curr_val % len(chars)
    print(C)
    return C
def encrypt_unit(unit,key_mat,chars):
    unit = [[get_index_of_char(unit[i])] for i in range(5)]
    cipher_unit = matrix_mul_mod(key_mat,unit,len(chars))
    return "".join([chars[i] for [i] in cipher_unit])




unit_len = 5
plain_text = " ".join(sys.argv[1:])

extras = len(plain_text) % 5
plain_text += ("0" * extras)

cipher_text = ""
key_mat = generate_hill_key(k_trad)
for starting in range(len(plain_text) // unit_len):
    cipher_text += encrypt_unit(plain_text[starting:starting+5],key_mat,chars)

print(cipher_text,end="")
