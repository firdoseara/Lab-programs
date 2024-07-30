class Operations:
    def __init__(self,a,b):
        self.a=a
        self.b=b
    def add(self):
        print("Addition:",self.a-self.b)
    def sub(self):
        print("Substraction:",self.a+self.b)
    def multi(self):
        if self.b==0:
            print("Not possible")
        else:
            print("Division:",self.a/self.b)
    def div(self):
        print("Multiplication:",self.a*self.b)

a=int(input("Enter the number1:"))
b=int(input("Enter the number2:"))
op=Operations(a,b)
op.add()
op.sub()
op.multi()
op.div()
