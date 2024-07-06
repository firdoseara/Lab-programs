function matrix_addition(A::Matrix,B::Matrix)::Matrix
        if size(A)!=size(B)
                error("Matrices must have the same dimensions for addition")
        end
        return A+B
end
function matrix_subtraction(A::Matrix,B::Matrix)::Matrix
        if size(A)!=size(B)
                error("Matrices must have the same dimensions for subtraction")
        end
        return A-B
end
A=[1 2 3;4 5 6;7 8 9]
B=[9 8 7;6 5 4;3 2 1]
result_addition=matrix_addition(A,B)
println("Element wise addition.")
println(result_addition)
result_subtraction=matrix_subtraction(A,B)
println("Element wise subtracion.")
println(result_subtraction)

