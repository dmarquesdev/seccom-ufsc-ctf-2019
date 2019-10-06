flag = "WHY_S0_S3R14L_H4HA_L33T_THE_FUN_B3GIN"
serial = "F4A23-B05C6-CC94A-B2458"

i = 0
result = ""
for c in flag:
    result = result + ('\\x%0.2x' % (ord(c) ^ ord(serial[i % len(serial)])))
    i = i + 1

print(result)