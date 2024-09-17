# Author:    Rémi Jara
# Created:   17/09/2024

class Student:
    def __init__(self):
        self.firstName = ""
        self.lastName = ""
        self.address = ""
        self.grades = [0.0] * 5

students = []

for i in range(5):
    student = Student()

    student.firstName = input(f"Enter the first name of student {i + 1}: ")
    student.lastName = input(f"Enter the last name of student {i + 1}: ")
    student.address = input(f"Enter the address of student {i + 1}: ")

    for j in range(5):
        student.grades[j] = float(input(f"Enter the grade {j + 1} of student {i + 1}: "))

    students.append(student)

for i, student in enumerate(students):
    print(f"Student {i + 1}")
    print(f"First name: {student.firstName}")
    print(f"Last name: {student.lastName}")
    print(f"Address: {student.address}")
    print(f"Grades: {' '.join(str(grade) for grade in student.grades)}")