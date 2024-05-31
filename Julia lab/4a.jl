function gcd(a::Int,b::Int)
        while b!=0
                a,b=b,a%b
        end
        return abs(a)
end
function lcm(a::Int,b::Int)
        return abs(a*b)/gcd(a,b)
end
println("Enter two integers: ")
a=parse(Int,readline())
b=parse(Int,readline())
gcd_result=gcd(a,b)
lcm_result=lcm(a,b)
println("GCD of $a and $b is $gcd_result")
println("LCM of $a and $b is $lcm_result")
