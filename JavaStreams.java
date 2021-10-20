package com.thecodeprogram.streamexample;

/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 20.10.2021
*/

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class JavaStreams {
	
	static List<String>  strs;
	static List<Integer> ints;
	
	public static void initializeStreams()
	{
		//We can initialize List with Arrays.asList method with using an array
		strs = Arrays.asList("Burak", "Hamdi", "TUFAN");
		Integer[] nums = new Integer[] {1, 2, 3, 4, 5};
		ints = Arrays.asList(nums);
	}
	
	public static void forEachExamples() {
		//we can traverse all element in a stream with forEach function.
		//-we can call function statically, element will be parameter of that function,
		//-we can call the inline function with lambda operator
		//-we can declare the anonymous function with the element
		
		initializeStreams();
		
		strs.stream().forEach(System.out::println);
		strs.stream().forEach(s -> System.out.println(s));
		ints.stream().forEach(i -> {
			System.out.println(i);
		});
	}
	
	public static void mapExample() {
		//map function of stream creates a new list with processing all elements of given stream
		//for example we can multiply all values of an array with mapping them
		//we need to declare a new List for return stream of map function.
		//We need to collect the new values with Collectors ant convert them to a List. Collectors.toList()
		//Map function protects the source array. It does not change the source. it creates new stream
		//we can declare the function as inline or a anonymous function
		//-----------------------------------------------------------------------
		//Stringbuilder is fastest string processing class but not synchronized.
		//String buffer is slower than stringbuilder but synchronized.
		//for single thread stringbilder, for multi thread stringbuffer
		//-----------------------------------------------------------------------
		
		initializeStreams();
		
		List<Integer> mapped1 = ints.stream().map(n -> n * n).collect(Collectors.toList());
		List<String> mappedReversed = strs.stream().map(s -> { 
			StringBuilder sb = new StringBuilder(s);
			return sb.reverse().toString();
		}).collect(Collectors.toList());
		
		System.out.println(mapped1.toString());
		System.out.println(mappedReversed.toString());
	}
	
	public static void filterExample() {
		//filter function traverse all elements in iven stream and check them according to a condition
		//we can create a new stream with only obeys the specified condition
		//we can define lambda function and also create an anoniymous function
		//inner function of filter function must return boolean result.
		//also we can directly get the number of element which passes the test.
		
		initializeStreams();
		
		List<String> filtered = strs.stream().filter( s -> s.contains("u")).collect(Collectors.toList());
		List<Integer> customCondition = ints.stream().filter(i -> {
			if(i * (i-1) > 10) return true;
			else return false;
		}).toList();
		
		long evenNumbers = ints.stream().filter(n -> n % 2 == 0).count();
		
		System.out.println(filtered.toString());
		System.out.println(customCondition.toString());
		System.out.println("Even numbers : " + evenNumbers);
	}
	
	public static void sortedExample() {
		//sorted function will sort the stream as ascending order.
		//we can also use a custom comparator for ordering the elements
		Integer[] unorderedNumbers = new Integer[] {5,99,3,66,4,88,2,6,7,1,6,1,0,2,0,8,74,62,23,8,14,36,58,41,23,95};
		List<Integer> numbers = Arrays.asList(unorderedNumbers);
		List<Integer> ordered = numbers.stream().sorted().toList();
		List<Integer> descending = numbers.stream().sorted(new Comparator<Integer>() {
		    @Override
		    public int compare(Integer n1, Integer n2) {
		        return n1 > n2 ? -1 : 1;
		    }
		}).toList();
		
		System.out.println(ordered.toString());
		System.out.println(descending.toString());
	}
	
	public static void parallelStreamExample() {
		//parallel streaming is a way to use multi cores of device. operatins are performing at all cores of CPU
		//normal stream is performing on the single cores of computer so it is low performance but in parallelStream we will have high performance.
		//parallelStream does not care about order of elements but stream care about elements. 
		//if element order is not important we can use paralelStream.
		//printing order will be changed at every execution. but performance will be increased.
		//all methods of stream and parallelStream are same. so we can switch quickly.
		initializeStreams();
		ints.parallelStream().forEach(i -> System.out.println(i));
	}
	
	public static void collectorsExample() {
		//we can collect the result of the stream function. We can combine them into a string
		//or push them into a List. We can convert data to a Set or a List.
		//We can create a data stream as format as required.
		
		Integer[] nums = new Integer[] {-3, -2, -1, 0, 1, 2, 3, 4};
		List<Integer> numList = Arrays.asList(nums);
		Set<Integer> _set = Arrays.asList(nums).stream().map(n -> n*n).collect(Collectors.toSet());
		String _str = numList.stream().map(s -> s.toString()).collect(Collectors.joining(", "));
		
		System.out.println(_set.toString());
		System.out.println(_str);
	}
	
	public static void reduceExample() {
		//we can use all datas in a stream to create one single result.
		initializeStreams();
		int sum = ints.stream().reduce(0, (res, n) -> res += n).intValue();
		System.out.println(sum);
	}


	public static void main(String[] args) {
		//initializeStreams();
		//forEachExamples();
		//mapExample();
		//filterExample();
		//sortedExample();
		//parallelStreamExample();
		//collectorsExample();
		//reduceExample();
		
	}
	
	

}
