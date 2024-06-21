Maxcand=10
using Printf
function getnames(inn,cand)
        n=0
        while(name=readline(inn))!=""
                if n<Maxcand
                        n+=1
                        cand[n]=name
                else
                        println("\nToo many candidates")
                        println("Working with first $n")
                end
        end
        return n
end
function printres(out,max,name,vote,valid,spoilt)
        println(out,"\nNumber of voters:$(valid+spoilt)")
        println(out,"Number of valid votes:$valid")
        println(out,"Number of spoilt votes:$spoilt")
        println(out,"\nCandidate score:\n")
        for c=1:max
                @printf(out,"%-15s %3d\n",name[c],vote[c])
        end
        println(out,"\nThe winner(s)")
        winvote=maximum(vote)
        for c=1:max
                if(vote[c]==winvote)
                        println(out,"$(name[c])")
                end
        end
end
function proVotes(inn,out,numcand,vote)
        validvotes=spoiltvotes=0
        while(line=readline(inn))!=""
                num=[parse(Int,x) for x in split(line)]
                for v in num
                        if v<1||v>numcand
                                println(out,"Invalid vote:$v")
                                spoiltvotes+=1
                        else
                                vote[v]+=1
                                validvotes+=1
                        end
                end
        validvotes,spoiltvotes
end
function main()
        inn=open("votes.txt","r")
        out=open("result.txt","w")
        candi=fill("",Maxcand)
        numcand=getnames(inn,candi)
        vote=fill(0,numcand)
        valid,spoilt=proVotes(inn,out,numcand,vote)
        printres(out,numcand,candi,vote,valid,spoilt)
        close(inn)
        close(out)
end
main()
                       
