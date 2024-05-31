function fibonnacci(n::Int)
        if n==1
                return[0]
        elseif n==2
                return[0,1]
        else
                prev_series=fibonnacci(n-1)
                push!(prev_series,prev_series[end-1]+prev_series[end])
                return prev_series
        end
end
println("Enter the number of terms in fibonnacci series:")
num_terms=parse(Int,readline())
if num_terms<0
        println("Number of terms should be at least 1.")
else
        fib_series=fibonnacci(num_terms)
        println("Fibonnacci series of $num_terms terms:")
        println(fib_series)
end
