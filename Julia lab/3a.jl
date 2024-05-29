using Printf
function calcInterest()
        print("Principal?")
        p=parse(Int64,readline())
        print("Interest rate?")
        r=parse(Float64,readline())
        println("Year amount")
        amt=p
        for y=1:10
                amt+=amt*r/100
                @printf("%3d%8.2f\n",y,amt)
                if amt>2p break end
        end
end
calcInterest()
~             
