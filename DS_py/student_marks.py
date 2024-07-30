class Student:
    students = {}
    
    def __init__(self, name, reg, m1, m2, m3):
        self.name = name
        self.reg = reg
        self.m1 = m1
        self.m2 = m2
        self.m3 = m3
        self.total = self.m1 + self.m2 + self.m3
        self.avg = self.total / 3
        Student.students[reg] = self


    def input_student_data():
        name = input("Enter the name of the student: ")
        reg = int(input("Enter the register number: "))
        m1, m2, m3 = map(int, input("Enter the marks of three subjects (separated by space): ").split())
        return Student(name, reg, m1, m2, m3)

    
    def rank_all():
        sorted_students = sorted(Student.students.values(), key=lambda x: x.avg, reverse=True)
        for rank, student in enumerate(sorted_students, 1):
            print(f"Rank {rank}: {student.name} - Average Marks: {student.avg:.2f}")

    
    def get_rank(reg):
        sorted_students = sorted(Student.students.values(), key=lambda x: x.avg, reverse=True)
        for rank, student in enumerate(sorted_students, 1):
            if student.reg == reg:
                print(f"Rank of {student.name} is: {rank}")
                return
        print("Student not found")


    def compare_students(reg1, reg2):
        student1 = Student.students.get(reg1)
        student2 = Student.students.get(reg2)
        if not student1 or not student2:
            print("One or both students not found")
            return
        if student1.avg > student2.avg:
            print(f"{student1.name} has higher marks than {student2.name}")
        else:
            print(f"{student2.name} has higher marks than {student1.name}")

def main():
    n = int(input("Enter the number of students: "))
    for _ in range(n):
        Student.input_student_data()
    Student.rank_all()
    
    while True:
        print("1. Rank of a student\n2. Compare two students\n3. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            reg = int(input("Enter the register number of the student: "))
            Student.get_rank(reg)
        elif choice == 2:
            reg1 = int(input("Enter the register number of student 1: "))
            reg2 = int(input("Enter the register number of student 2: "))
            Student.compare_students(reg1, reg2)
        elif choice == 3:
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
