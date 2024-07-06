using LinearAlgebra
function matrix_properties(A)
        println("Matrix")
        println(A)
        println("")
        println("Determinant:",det(A))
        println("Inverse:")
        if isposdef(A)||isposdef(Hermitian(A))
                println(inv(A))
        else
                println("Matrix is not invertible.")
        end
        println("")
        println("Rank.",rank(A))
        println("Upper triangular matrix.")
        println(upper_triangular(A))
        println("")
        println("LOwer traingular matrix")
        println(lower_triangular(A))
        println("")
        println("Diagonal Elements:",diag(A))
        println("Euclidean norm:",norm(A))
        println("Square root of matrix.")
        println(sqrt(A))
end
function upper_triangular(A)
        n=size(A,1)
        U=zeros(n,n)
        for i in 1:n,j in i:n
                U[i,j]=A[i,j]
        end
        return U
end
function lower_triangular(A)
        n=size(A,1)
        L=zeros(n,n)
        for i in 1:n,j in 1:i
                L[i,j]=A[i,j]
        end
        return L
end
A=[1 2 3;4 5 6;7 8 10]
matrix_properties(A)
