function lettersOnlyLower(phrase)
        word=""
        for ch in phrase
                if isletter(ch)
                        word*=lowercase(ch)
                end
        end
        return word
end
function isPalindrome(phrase)
        word=lettersOnlyLower(phrase)
        lo=1
        hi=length(word)
        while lo<hi
                if word[lo]!=word[hi]
                        return false
                end
                lo+=1;hi-=1
        end
        return true
end
function main()
        print("\nWord or Phrase?(To stop, press Enter):")
        phrs=readline()
        while phrs!=""
                if isPalindrome(phrs)
                        println("is a palindrome")
                else
                        println("is not palindrome")
                end
                print("\nWord or Phrase?(To stop,press Enter):")
                phrs=readline()
        end
end
main()
~       
