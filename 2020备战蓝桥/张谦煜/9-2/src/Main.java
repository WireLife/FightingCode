import java.util.*;

public class Main {

	public static void main(String[] args) {
		Integer bnum;
		Scanner in = new Scanner(System.in);
		bnum=Integer.parseInt(in.nextLine());
		Integer dnum=0;
		int flag=0;
		while (bnum!=0)
		{
			dnum+=(int)Math.pow(2,flag)*(bnum%10);
			flag++;
			bnum/=10;
		}
		String hnum="";
		int r=0;
		flag=0;
		String str[] = {"A","B","C","D","E","F"};
		while (dnum!=0)
		{
			r=dnum%16;
			if (r>=10)
				hnum=str[r-10]+hnum;
			else
				hnum=String.valueOf(r)+hnum;
			dnum/=16;
		}
		System.out.println(hnum);
	}

}
