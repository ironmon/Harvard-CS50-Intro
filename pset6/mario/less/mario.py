from cs50 import get_int
def main():
    height = get_height()
    draw(height)
    
def get_height():
    while True:
        n = get_int("Height: ")
        if 0 < n < 9:
            break
    return n

def draw(height):
    for i in range(1, height + 1):
        print(" " * (height - i) + "#" * i)

main()
        
