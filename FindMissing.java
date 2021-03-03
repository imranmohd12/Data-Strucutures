import java.util.Scanner;
class FindMissing{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String inp = sc.nextLine();
        int n = inp.length()+1;
        System.out.println(n);
        String[] inpArr = inp.split("");
        int temp = 0;
        int total = 0;
        for(String a:inpArr){
            temp = Integer.parseInt(a);
            total += temp;
        }
        int result =  ((n-1)*(n)/2)-total;
        System.out.println("For loop : "+total);
        System.out.println("Formula loop : "+result);
    }
}