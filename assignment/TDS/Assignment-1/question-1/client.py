import xmlrpc.client

# creating the proxy for the RPC server
proxy = xmlrpc.client.ServerProxy("http://localhost:8000/")

# callin the methods remotely 

result_add = proxy.add(2,3)

result_subt = proxy.subtract(3,2)

result_mult = proxy.multiply(3,3)

result_div = proxy.divide(8,3)

result_exp = proxy.exponent(2,3)

result_log = proxy.logarithm(8,2)

print("Addition result: ", result_add)
print("Subtraction result: ", result_subt)
print("Multiplication result: ", result_mult)
print("Division result: ", result_div)
print("Exponentiation result: ", result_exp)
print("Logarithm result: ", result_log)
