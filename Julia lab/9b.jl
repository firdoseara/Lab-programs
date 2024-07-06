using LinearAlgebra
function scalar_multiplication(A::Matrix,scalar::Real)::Matrix
        return A*scalar
end
function elementwise_multiplication(A::Matrix,B::Matrix)::Matrix
        if size(A)!=size(B)
                error("Matrices must have same dimensions for element-wise multiplication")
        end
        return A.*B
end
function dot_product(A::Matrix,B::Matrix)::Real
        if size(A)!=size(B)
                error("Matrices must have same dimensions for dot product")
        end
        return dot(A,B)
end

function cross_product(A::Matrix,B::Matrix)
        if size(A)!=(3,3)||size(B)!=(3,3)
                error("Matrices must be 3x3 for cross product")
        end
        col1_A,col2_A,col3_A=eachcol(A)
        col1_B,col2_B,col3_B=eachcol(B)
        result_col1=cross(col1_A,col1_B)
        result_col2=cross(col2_A,col2_B)
        result_col3=cross(col3_A,col3_B)
        return hcat(result_col1,result_col2,result_col3)
end
A=[1 2 3;4 5 6;7 8 9]
B=[9 8 7;6 5 4;3 2 1]
scalar=2
result_scalar_multiplication=scalar_multiplication(A,scalar)
println("Scalar multiplication(A*Scalar)")
println(result_scalar_multiplication)
result_elementwise_multiplication=elementwise_multiplication(A,B)
println("Element-wise Multiplication")
println(result_elementwise_multiplication)
result_dot_product=dot_product(A,B)
println("Dot product")
println(result_dot_product)
result_cross_product=cross_product(A,B)
println("Cross product")
println(result_cross_product)
