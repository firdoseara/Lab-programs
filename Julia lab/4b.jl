function factorial(n::Int)
        if n==0||n==1
                return 1
        else
                return n*factorial(n-1)
        end
end
println("Enter a number to calculate its factorial:")
num=parse(Int,readline())
if num<0
        println("Factorial is not defined for negative numbers.")
else
        result=factorial(num)
        println("Factorial of $num is $result")
end
