function evaluate_expression(expression::String)
        try
                result=eval(Meta.parse(expression))
                println("Result: ",result)
        catch e
                println("Error: ",e)
        end
end
expressions=[
             "2+3",
             "2.5*4.7",
             "sin(pi/2)",
             "sqrt(2)+exp(1)*log(10)",
             "sqrt(2)"
             ]
for exp in expressions
        println("Expression: ",exp)
        evaluate_expression(exp)
        println()
end

