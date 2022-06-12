def parse_input(filename):
    with open(filename) as f:
        number_sequence = f.readlines()
        for index in range(len(number_sequence)):
            number_sequence[index] = int(number_sequence[index].replace("\n", ""))
        return number_sequence

def is_bigger(a, b):
    return 1 if b > a else 0

def add_three(nums: list):
    return sum(nums)

def Q1(nums):
    counter = 0
    for index in range(len(nums)-1):
        counter += is_bigger(nums[index], nums[index + 1])
    return counter

def Q2(nums):
    counter = 0
    for index in range(len(nums)-3):
        counter += is_bigger(add_three(nums[index:index+3]), add_three(nums[index+1:index+4]))
    return counter

if __name__ == "__main__":
    nums = parse_input("input.txt")
    print(Q1(nums))
    print(Q2(nums))

    print(add_three([1,2,3]))




