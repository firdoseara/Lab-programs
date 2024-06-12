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
function firstLastWord()
        inn=open("input.txt","r")
        first="~"
        last=""
        word=getNextWord(inn)
        while word!=nothing
                println(word)
                if(word<first)
                        first=word
                end
                if(word>last)
                        last=word
                end
                word=getNextWord(inn)
        end
        close(inn)
        println("\nFirst word is $first")
        println("Last word is $last")
end
firstLastWord()
