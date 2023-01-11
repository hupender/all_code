# Python3 implementation of
# Columnar Transposition
import math


key = "hupendrabcfgijklmoqstvwxyz"

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

def encryptMessage(msg):
	cipher = ""

	# track key indices
	k_indx = 0

	msg_len = float(len(msg))
	msg_lst = list(msg)
	key_lst = sorted(list(key))

	# calculate column of the matrix
	col = len(key)
	
	# calculate maximum row of the matrix
	row = int(math.ceil(msg_len / col))

	# add the padding character '_' in empty
	# the empty cell of the matix
	fill_null = int((row * col) - msg_len)
	msg_lst.extend('_' * fill_null)

	# create Matrix and insert message and
	# padding characters row-wise
	matrix = [msg_lst[i: i + col]
			for i in range(0, len(msg_lst), col)]

	# read matrix column-wise using key
	for _ in range(col):
		curr_idx = key.index(key_lst[k_indx])
		cipher += ''.join([row[curr_idx]
						for row in matrix])
		k_indx += 1

	return cipher
# Driver Code
msg = " ".join(sys.argv[1:])

cipher = encryptMessage(msg)

print(cipher)
