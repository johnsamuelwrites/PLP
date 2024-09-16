if __name__ == "__main__":
    my_int = 0

    if my_int == 0:
        my_bin = "0"
    else:
        my_bin = ""
        while my_int > 0:
            my_bin += str(my_int % 2)
            my_int = my_int // 2

    print(my_bin[::-1])
    


