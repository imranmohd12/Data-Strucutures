import java.util.*;
import java.lang.*;
class readVar
{
    int id=0,age=0,inp=0,opInt=0;
    String name="",op="",vowels = "";
    Scanner sc = new Scanner(System.in);
    void reads()
    {
        
        try {
            name = sc.nextLine();
            id = sc.nextInt();
            
            age = sc.nextInt();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    void displayReverse()
    {
        inp = sc.nextInt();
        op = Integer.toString(inp);
        StringBuilder sb = new StringBuilder(op);
        opInt = Integer.parseInt((sb.reverse()).toString());
        System.out.println(opInt);
    }
    void vowelsAndConsonants()
    {
        vowels = sc.nextLine();
        int v=0,c=0;
        for(int i=0;i<vowels.length();i++)
        {
            if(vowels.charAt(i) == 'a' || vowels.charAt(i) == 'e' || vowels.charAt(i) == 'i' || vowels.charAt(i) == 'o' || vowels.charAt(i) == 'u')
                v++;
            else if(vowels.charAt(i) > 47 && vowels.charAt(i) < 58)
                break;
            else
                c++;
        }
        System.out.println("vowels : "+v);
        System.out.println("consonants : "+c);
    }
    void minVowel()
    {
        String inpStr = sc.nextLine();
        char min = 'u';
        for(int i = 0;i < inpStr.length();i++)
        {
            if(vowels.charAt(i) == 'a' || vowels.charAt(i) == 'e' || vowels.charAt(i) == 'i' || vowels.charAt(i) == 'o' || vowels.charAt(i) == 'u')
            {
                if(inpStr.charAt(i)<min)
                    min = inpStr.charAt(i);
            }
        }
        System.out.println(min);
    } 
    
}
class sampleObj
{
    public static void main(String[] args) {
        readVar readobj = new readVar();
        //readobj.reads();
        System.out.println("ID : "+readobj.id);
        System.out.println("NAME : "+readobj.name.trim());
        System.out.println("AGE : "+readobj.age);
        //readobj.displayReverse();
        readobj.vowelsAndConsonants();
        readobj.minVowel();
    }
}