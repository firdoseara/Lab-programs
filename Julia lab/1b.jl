struct ComplexNumber
real::Float64
imag::Float64
end
function add_complex(a::ComplexNumber,b::ComplexNumber)
        return ComplexNumber(a.real+b.real,a.imag+b.imag)
end
function subtract_complex(a::ComplexNumber,b::ComplexNumber)
        return ComplexNumber(a.real-b.real,a.imag-b.imag)
end
function multiply_complex(a::ComplexNumber,b::ComplexNumber)
        real_part=a.real*b.real-a.imag*b.imag
        imag_part=a.real*b.imag+a.imag*b.real
        return ComplexNumber(real_part,imag_part)
end
function division_complex(a::ComplexNumber,b::ComplexNumber)
        denominator=b.real^2+b.imag^2
        if denominator!=0
                real_part=(a.real*b.real+a.imag*b.imag)/denominator
                imag_part=(a.imag*b.real-a.real*b.imag)/denominator
                return ComplexNumber(real_part,imag_part)
        else
                println("Error:Division by zero!")
                return ComplexNumber(NaN,NaN)
        end
end
function main()
        println("Enter the real and imaginary parts of the first complex number.")
        real1=parse(Float64,readline())
        imag1=parse(Float64,readline())
        println("Enter the real and imaginary parts of the second complex number.")
        real2=parse(Float64,readline())
        imag2=parse(Float64,readline())
        complex1=ComplexNumber(real1,imag1)
        complex2=ComplexNumber(real2,imag2)
        println("Addition:",add_complex(complex1,complex2))
        println("Subtraction:",subtract_complex(complex1,complex2))
        println("Multiplication:",multiply_complex(complex1,complex2))
        println("Division:",division_complex(complex1,complex2))
end
main()
