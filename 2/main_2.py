class Submarine:
    def __init__(self, x=0, y=0, aim=0):
        self.x = x
        self.y = y
        self.aim = aim

    def forward(self, dist):
        self.x += int(dist)
        self.y += self.aim*int(dist)

    def up(self, dist):
        self.aim -= int(dist)

    def down(self, dist):
        self.aim += int(dist)

sub = Submarine()

with open("input.txt") as f:
    for line in f:
        lin_lst = list(line)
        if lin_lst[-1] == "\n":
            lin_lst = lin_lst[:-1]
        if lin_lst[0] == "f":
            sub.forward(lin_lst[-1])
        if lin_lst[0] == "d":
            sub.down(lin_lst[-1])
        if lin_lst[0] == "u":
            sub.up(lin_lst[-1])
        print(sub.x, sub.y)
    print(sub.x * sub.y)



