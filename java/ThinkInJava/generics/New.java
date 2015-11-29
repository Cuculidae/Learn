//: generics/New.java
//  Utilities to simplify generic container creation
//  by using type argument inference.

import java.util.*;

public class New {
	public static <K, V> Map<K, V> map() {
		return new HashMap<K, V>();
	}
	public static <T> List<T> list() {
		return new ArrayList<T>();
	}
	public static <T> LinkedList<T> llist() {
		return new LinkedList<T>();
	}
	public static <T> Set<T> set() {
		return new HashSet<T>();
	}
	
	public static void main(String[] args) {
		Map<String, List<String>> sls = New.map();
		List<String> ls = New.list();
		LinkedList<String> lls = New.llist();
		Set<String> ss = New.set();
	}
}
