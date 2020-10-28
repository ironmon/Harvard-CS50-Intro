from cs50 import get_string

#def main():
#    print(index())
    
def index():
    bookname = get_string("Text: ")
    letter_num = 0
    word_num = 1
    sentence_num = 0
    for i in range(len(bookname)):
        if 'a' <= bookname[i] <= 'z' or 'A' <= bookname[i] <= 'Z':
            letter_num += 1
        elif bookname[i] == ' ':
            word_num += 1
        elif bookname[i] in ['.', '?', '!']:
            sentence_num += 1
    
    L = letter_num / word_num * 100
    S = sentence_num / word_num * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    #round index 
    grade = round(index)
    if (1 <= grade < 16):
        print(f"Grade {grade}")
    elif (grade < 1):
        print("Before Grade 1")
    else:
        print("Grade 16+")
index()           