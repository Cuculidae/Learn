class Game {
	Game(int i) {
		System.out.println("Game contructor");
	}
}

class BoardGame extends Game {
	BoardGame(int i) {
		super(i);
		System.out.println("BoardGame constructor");
	}
}

public class Chess extends BoardGame {
	Chess() {
		super(11);
		System.out.println("Chess constructor");
	}
	public static void main(String[] args) {
		Chess x = new Chess();
	}
}
