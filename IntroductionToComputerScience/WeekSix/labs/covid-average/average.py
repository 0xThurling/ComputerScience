import csv

state_dict = {}

user = input("State: ")

with open("./us-states.csv", newline='') as states:
    reader = csv.DictReader(states)
    for row in reader:
        if row['state'] not in state_dict.keys():
            state_dict[row['state']] = [row['cases']]
        else:
            state_dict[row['state']] = state_dict[row['state']] + [row['cases']]

def main():
    total = 0
    for case in state_dict[user][-14:]:
        total = total + int(case)
    
    print(total/14)


main()