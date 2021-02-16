from random import randint

LEN = 500
TAB = "          "

f = open("in.txt", "w")
# Clear the file
f.truncate(0)

word_bank = ["yyet", "yeet", "yeett", "yet", "yeeeet", "yeeeeeeet", "yeeetteet"]

for i in range(LEN):
	char = word_bank[randint(0, 6)]
	if(i != LEN-1):
		f.write(char + " ")
	else:
		f.write(char)


f.close()

g = open("in.txt", "r")

split_text = g.read()
split_text = split_text.split(" ")
#print(split_text)

g.close()

h = open("out1.txt", "w")

h.write("Word number" + TAB + TAB + "Word")

for i in range(LEN):
	h.write("\n" + str(i) + TAB + split_text[i] )


h.close()


