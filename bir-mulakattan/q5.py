# program that finds largest sized set that contains consecutive numbers
# in random order and print same list

n = list(map(int, input().split()))

# print(n)

res = 0
res_list = []

ctr_b_index = b_index = 0
ctr_e_index = e_index = len(n) - 1

while ctr_b_index < e_index:
    ctr_e_index = e_index
    while ctr_e_index > ctr_b_index:
        disting = True
        new_list    = n[ctr_b_index:ctr_e_index]
        for i in new_list: # distinct elements check
            if new_list.count(i) > 2:
                disting = False
                break
        if (not disting):
            ctr_e_index -= 1
        else:
            consecutive = True
            sorted_list = sorted(new_list)
            for index in range(len(sorted_list) - 1):
                if sorted_list[index + 1] - sorted_list[index] != 1:
                    consecutive = False
                    break
                index += 1
            if consecutive:
                if len(res_list) < len(new_list):
                    res_list = new_list
                    res = len(new_list)
            ctr_e_index -= 1
            #print(res_list)
    ctr_b_index += 1

for i in res_list:
    print( i, end=' ' )
