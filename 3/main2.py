def bin2dec(binstr):
    dec_val = 0
    for char_pos, char in enumerate(list(binstr)[::-1]):
        dec_val += 2 ** char_pos * int(char)
    return dec_val
        
        
def get_commons(arr):   
    gamma = ""
    epsilon = ""
    
    num_lines = len(arr)
    line_length = len(arr[0])
    
    for col in range(line_length):
        cnt_z = 0
        cnt_o = 0
        for i in range(0, num_lines):
            if arr[i][col] == "0":
                cnt_z += 1
            else:
                cnt_o += 1
        
        if cnt_z > cnt_o:
            gamma += "0"
            epsilon += "1"
        else:
            gamma += "1"
            epsilon += "0"

    return gamma, epsilon



if __name__ == "__main__": 
    char_lst = []
    with open("input.txt") as f:
        for line in f:
            char_lst.append(list(line)[:-1])

    ox_rating = char_lst[:]
    co2_rating = char_lst[:]
    del char_lst
    
    for bit in range(len(ox_rating[0])):
        lines_to_remove = []
        most_common = list(get_commons(ox_rating)[0])[bit]
        for lineid, line in enumerate(ox_rating):
            if line[bit] != most_common:
                lines_to_remove.append(lineid)
        
        new_ox_rating = []
        for lineid, line in enumerate(ox_rating):
            if lineid not in lines_to_remove:
                new_ox_rating.append(line)
                
        del ox_rating
        ox_rating = new_ox_rating[:]
        del new_ox_rating
        
    print(ox_rating)
    
    for bit in range(len(co2_rating[0])):
        if len(co2_rating) == 1: 
            continue
        lines_to_remove = []
        most_common = list(get_commons(co2_rating)[1])[bit]
        for lineid, line in enumerate(co2_rating):
            if line[bit] != most_common:
                lines_to_remove.append(lineid)
        
        new_co2_rating = []
        for lineid, line in enumerate(co2_rating):
            if lineid not in lines_to_remove:
                new_co2_rating.append(line)
         
        del co2_rating
        co2_rating = new_co2_rating[:]
        del new_co2_rating
        
    print(co2_rating)
    
    oxstr = ""
    co2str = ""
    
    for char in ox_rating[0]:
        oxstr += char
    
    for char in co2_rating[0]:
        co2str += char
        
    print(bin2dec(oxstr) * bin2dec(co2str))
                

            
    