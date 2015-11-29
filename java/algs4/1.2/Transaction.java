public class Transaction implements Comparable<Transaction>
{
	private String name;
	private Date date;
	private double money;
	public Transaction(String who, Date when, double amount)
	{
		name = who;
		date = when;
		money = amount;
	}
	public Transaction(String t)
	{
		String[] fields = t.split("\\s+");
		name = fields[0];
		date = new Date(fields[1]);
		money = Double.parseDouble(fields[2]);
	}
	public String who()
	{	return name;	}
	public Date when()
	{	return date;	}
	public double amount()
	{	return money;	}
	public String toString()
	{	return date + ": " + name + " transacts $" + money;	}
	public boolean equals(Object that)
	{
		if (this == that)	return true;
		if (that == null)	return false;
		if (this.getClass() != that.getClass())
			return false;
		Transaction t = (Transaction) that;
		if (name.compareTo(t.who()) != 0)
			return false;
		if (date.compareTo(t.when()) != 0)
			return false;
		if (money != t.amount())
			return false;
		return true;
	}
	public int compareTo(Transaction that)
	{
		if (equals(that))
			return 0;
		if (date.compareTo(that.when()) > 0 || 
		    (date.compareTo(that.when()) == 0 && name.compareTo(that.who()) > 0) ||
		    (date.compareTo(that.when()) == 0 && name.compareTo(that.who()) == 0 && money > that.amount()))
			return 1;
		return -1;
	}
	public static void main(String[] args)
	{
		Date date1 = new Date(1, 27, 1993);
		Date date2 = new Date(1, 28, 1993);
		Transaction[] a = new Transaction[4];
		a[0] = new Transaction("cai",date1, 10);
		a[1] = new Transaction("cai",date1, 11);
		a[2] = new Transaction("guo",date1, 10);
		a[3] = new Transaction("cai",date2, 10);
		Transaction temp;
	   	for (int i = 0; i < a.length; i++)
		{
			int min = i;
			for (int k = i; k < a.length; k++)
				if (a[k].compareTo(a[min]) < 0)
					min = k;
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
		for (int i = 0; i < a.length; i++)
			StdOut.println(a[i]);
	}
}
