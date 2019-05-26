import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;



class glass
{

	public static void main(String args[])
	{
	
		while(true)
		{
			System.out.println("\nEnter DD/MM/YYYY and I will tell the day of the week on that day!!\n\n");
		
			Scanner sc = new Scanner(System.in);
			int d,m,y;
			d = sc.nextInt();
			m = sc.nextInt();
			y = sc.nextInt();
	
			if(d<0||d>31||m<0||m>12)
			{
				System.out.println("^^^^^^^ Get off Idiot\n");
				continue;
			}
			if(m==2 && d>29)
			{
				System.out.println("!!! Your are real Soyabean. Bread-Jam-Bondaaaaaaaaa\n");
				continue;
			}
			else
			{
				Calendar cal = GregorianCalendar.getInstance();
				cal.set(y,m-1,d);
		
				SimpleDateFormat dayCaster = new SimpleDateFormat("EEEE");
		
				System.out.println(dayCaster.format(cal.getTime()));
			}
		}
	}

}
