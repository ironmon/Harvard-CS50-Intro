from cs50 import get_float

def main():
    cents = get_change()
    print(coins(cents))

    
def get_change():
    while True:
        n = get_float("Changed owed: ")
        if n > 0:
            break
    return round(n * 100)

def coins(cents):
    a = cents // 25
    cents -= a * 25
    b = cents // 10
    cents -= b * 10
    c = cents // 5
    cents -= c * 5
    d = cents 
    return a + b + c + d
    
main()