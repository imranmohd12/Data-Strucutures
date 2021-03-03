//Quicsort
class QuickSort
{
    int partition(int[] inp,int ub,int lb)
    {
        int start = lb;
        //System.out.println(start);
        int end = ub;
        //System.out.println(end);
        int pivot = inp[start];
        while(start < end)
        {
            while(pivot >= inp[start] && start < ub)
            {
                //System.out.println(start);
                start++;
            }
            while(pivot < inp[end])
            {
                end--;
            }
            //System.out.println("at start:"+inp[start]+" ");
            //System.out.println("at End :"+inp[end]+" ");
            if(start < end)
            {
                swap(inp,start,end);
            }
            
            display(inp);
            }
        System.out.print("swap : ");
        swap(inp,lb,end);
        display(inp);
        return end;
    }
    void swap(int[] arr,int a,int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        //System.out.println("swap completed!!");
    }
    void display(int[] arr)
    {
        for (int i = 0;i<arr.length;i++)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
    void Qsort(int[] inp,int ub,int lb)
    {
        int loc = 0;
        if(lb < ub)
        {
            //System.out.println("lb and ub "+lb+" "+ub);
            loc  = partition(inp,ub,lb);
            //System.out.println("\n"+loc);
            Qsort(inp,(loc-1),lb); 
            Qsort(inp,ub,(loc+1));
        }
    }
    public static void main(String[] args) {
        int inp[] = {9,7,4,1,3,5,2,8};
        for (int i = 0;i<inp.length;i++)
            System.out.print(inp[i]+" ");
        System.out.println();
        int ub = (inp.length)-1;
        int lb = 0;
        QuickSort qs = new QuickSort();
        qs.Qsort(inp,ub,lb);
    }
}