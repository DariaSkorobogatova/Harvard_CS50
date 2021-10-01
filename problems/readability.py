import cs50

text = cs50.get_string("Text: ")

letters = sentences = words = 0
for char in text:
    if char.isalpha():
        letters += 1
    if char.isspace():
        words += 1
    if char in ['!', '.', '?']:
        sentences += 1

words += 1

L = 100.0 * letters / words
S = 100.0 * sentences / words
G = int(round(0.0588 * L - 0.296 * S - 15.8))
if G < 1:
    print("Before Grade 1")
elif G >= 16:
    print("Grade 16+")
else:
    print(f"Grade {G}")