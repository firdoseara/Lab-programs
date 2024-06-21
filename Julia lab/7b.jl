function getNextWord(inn::IOStream)
        ch=' '
        while !eof(inn)&&!isletter(ch)
                ch=read(inn,Char)
        end
        if eof(inn)
                return nothing
        end
        wrd=string(ch)
        ch=read(inn,Char)
        while isletter(ch)
                wrd*=ch
                ch=read(inn,Char)
        end
        return wrd
end
function main()
        inn=open("input7b.txt","r")
        WordList=Set{String}()
        while(word=getNextWord(inn))!=nothing
                union!(WordList,[lowercase(word)])
        end
        close(inn)
        print("Number of unique words:$(length(WordList))\n\n")
        print("Words in set\n$WordList\n")
        print("\nWords in order\n")
        for w in sort(collect(WordList))
                print("$w ")
        end
        println()
end
main()
