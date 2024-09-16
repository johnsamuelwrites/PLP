import sys

if __name__ == '__main__':
    print(sys.getsizeof(int()))
    print(sys.getsizeof(float()))
    print(sys.getsizeof(str()))
    print(sys.getsizeof(list()))
    print(sys.getsizeof(tuple()))
    print(sys.getsizeof(dict()))
