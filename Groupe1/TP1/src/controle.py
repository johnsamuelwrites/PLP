# Author: Rémi Jara
# Date: 16/09/2024

if __name__ == '__main__':
    for i in range(1,1001):
        if (i % 4 == 0 and i % 6 != 0):
            print(i)

        if (i % 2 == 0 and i % 8 == 0):
            print(i)

        if ((i % 5 == 0 or i % 7 == 0) and i % 10 != 0):
            print(i)
        