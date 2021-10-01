import csv
import sys


def main():

    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py FILENAME FILENAME")

    individuals = []
    with open(sys.argv[1], "r") as file_1:
        reader = csv.DictReader(file_1)
        for i in reader:
            for key in i.keys():
                if key != "name":
                    i[key] = int(i[key])
            individuals.append(i)

    with open(sys.argv[2], "r") as file_2:
        sequence = file_2.read()

    repeats = []
    i = 0
    for key in individuals[i].keys():
        if key != "name":
            repeats.append(get_repeats(sequence, key))

    repeats_1 = []
    if match(repeats, repeats_1, individuals) is None:
        print("No match")
    else:
        i = match(repeats, repeats_1, individuals)
        print(individuals[i]["name"])
    
def match(r, r_1, ind):

    for i in range(0, len(ind)):
        r_1.clear()
        for key in ind[i].keys():
            if key != "name":
                r_1.append(ind[i][key])
        if r == r_1:
            return i
    return None


def get_repeats(DNA, STR):

    x = 1
    max_x = 0
    for i in range(0, len(DNA)):
        if DNA[i:i + len(STR)] == STR:
            for m in range(i, len(DNA), len(STR)):
                if DNA[m:m + len(STR)] == STR and DNA[m + len(STR):m + len(STR) + len(STR)] == STR:
                    x += 1
                    if max_x < x:
                        max_x = x
                else:
                    x = 1
            if max_x == 0 and STR in DNA:
                max_x = 1
    return max_x

if __name__ == "__main__":
    main()

