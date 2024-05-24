using Printf
function calculatePay()
        print("Hours worked?")
        hours=parse(Float64,readline())
        print("Rate of pay?")
        rate=parse(Float64,readline())
        if hours<=40
                regPay=hours*rate
                ovtPay=0
        else
                regPay=40*rate
                ovtPay=(hours-40)*rate*1.5
        end
        grossPay=regPay+ovtPay
        @printf("\nRegular pay:\$%0.2f\n",regPay)
        @printf("Overtime Pay:\$%0.2f\n",ovtPay)
        @printf("Gross Pay:\$%0.2f\n",grossPay)
end
calculatePay()
