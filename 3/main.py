def bin2dec(binstr):
    dec_val = 0
    for char_pos, char in enumerate(list(binstr)[::-1]):
        dec_val += 2 ** char_pos * int(char)
    return dec_val
        
        

char_lst = []
with open("input.txt") as f:
    for line in f:
        char_lst.append(list(line)[:-1])
        
gamma = ""
epsilon = ""

num_lines = len(char_lst)
line_length = len(char_lst[0])

for col in range(line_length):
    cnt_z = 0
    cnt_o = 0
    for i in range(0, num_lines):
        if char_lst[i][col] == "0":
            cnt_z += 1
        else:
            cnt_o += 1
    
    if cnt_z >= cnt_o:
        gamma += "0"
        epsilon += "1"
    else:
        gamma += "1"
        epsilon += "0"
        

print(bin2dec(gamma) * bin2dec(epsilon))
