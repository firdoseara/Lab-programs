using Printf
function jobCharge()
        print("Hours worked?")
        hours=parse(Float64,readline())
        print("Cost of parts?")
        parts=parse(Float64,readline())
        jobCharge=hours*100+parts
        if jobCharge<150
                jobCharge=150
        end
        @printf("\nTotal charges: \$%0.2f\n",jobCharge)
end
jobCharge()
