# Name : Nitin Kumar
# BT19CSE071

k_trad = "hupendrabcfgijklmoqstvwxyz"
k_trad_2 = "hupendrabcfgijklmoqstvwxyz0123456789"
k_roll1 = 7
k_roll2 = 3

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


# function to encrypt a message
def encryptRailFence(text, key):

	# create the matrix to cipher
	# plain text key = rows ,
	# length(text) = columns
	# filling the rail matrix
	# to distinguish filled
	# spaces from blank ones
	rail = [['\n' for i in range(len(text))]
				for j in range(key)]
	
	# to find the direction
	dir_down = False
	row, col = 0, 0
	
	for i in range(len(text)):
		
		# check the direction of flow
		# reverse the direction if we've just
		# filled the top or bottom rail
		if (row == 0) or (row == key - 1):
			dir_down = not dir_down
		
		# fill the corresponding alphabet
		rail[row][col] = text[i]
		col += 1
		
		# find the next row using
		# direction flag
		if dir_down:
			row += 1
		else:
			row -= 1
	# now we can construct the cipher
	# using the rail matrix
	result = []
	for i in range(key):
		for j in range(len(text)):
			if rail[i][j] != '\n':
				result.append(rail[i][j])
	return("" . join(result))


plain_text = " ".join(sys.argv[1:])

key = min(3, len(plain_text)-1)

print(encryptRailFence(plain_text, 3))