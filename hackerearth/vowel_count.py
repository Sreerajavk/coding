
# Program to count no of substring containing vowels of a string.
for _ in range(int(input())):
    s = input()
    n = len(s)
    vowel = ['a' , 'e' , 'i' , 'o' , 'u' , 'A' , 'E' , 'I' , 'O' , 'U']
    count = 0
    indices  = []

    for i in range(len(s)):
        if s[i] in vowel:
            indices.append(i)
    # print(indices)
    for i in indices:
        count += ((n -i) * (i+1))
    print(count)