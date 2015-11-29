import java.util.NoSuchElementException;
public class Card
{
	private final byte n;
	public  enum Suit{ CLUB, DIAMOND, HEART, SPADE, };
	private final Suit suit;
	public Card(byte n, Suit suit)
	{
		if (n > 13 || n < 1) throw new NoSuchElementException();
		this.n = n;
		this.suit = suit;
	}
	public String toString()
	{
		String s;
		switch (n)
		{
			case 13: s = "K"; break;
			case 12: s = "Q"; break;
			case 11: s = "J"; break;
			default: s = n + ""; break;
		}
		return suit + " " + s;
	}
}
