/**
 * Program:      Anagram
 *
 * File:         Anagram.java
 *
 * Function:     Main (complete program listing in this file)
 *
 * Description:  Identifies anagrams for dictionary files
 *
 * Author:       Juan Antonio Sauceda (jas)
 *
 * Environment:  Javac 1.6.0_11 with KWrite 4.5.10(editor),
 *               i686 Intel Pentium M processor 1.6ghz, 512mb RAM,
 *               Slackware 12.2 Linux Kernel 2.6.27.7-smp
 *
 * Revisions:    1.00  2/17/09 (jas) First release
 */

import java.io.*;

public class Anagram {

    public static boolean areAnagrams(String string1,
                                      String string2) {

        String workingCopy1 = removeJunk(string1);
        String workingCopy2 = removeJunk(string2);

	    workingCopy1 = workingCopy1.toLowerCase();
	    workingCopy2 = workingCopy2.toLowerCase();

	    workingCopy1 = sort(workingCopy1);
	    workingCopy2 = sort(workingCopy2);

        return workingCopy1.equals(workingCopy2);
    }

    protected static String removeJunk(String string) {
        int i, len = string.length();
        StringBuilder dest = new StringBuilder(len);
  		char c;

	    for (i = (len - 1); i >= 0; i--) {
	        c = string.charAt(i);
	        if (Character.isLetter(c)) {
		        dest.append(c);
	        }
	    }

        return dest.toString();
    }

    protected static String sort(String string) {
	    char[] charArray = string.toCharArray();

	    java.util.Arrays.sort(charArray);

        return new String(charArray);
    }

    public static void main(String[] args) {

	if (args.length > 1)
            { System.out.println("\nAnagram : invalid format\nUse \" \" : Ex. java Anagram \"more word s\"\n"); return; }
	
	if (args.length == 0)
            { System.out.println("\nUsage:           Place dictionary.txt and\n                 Anagram.class in same folder.\n\nSingle words   : java Anagram word\nMultiple words : java Anagram \"more word s\"\n"); return; }

	String string1 = args[0];
	Boolean flag = false;

try{
    FileInputStream fstream = new FileInputStream("dictionary.txt");
    DataInputStream in = new DataInputStream(fstream);
    BufferedReader br = new BufferedReader(new InputStreamReader(in));
    String string2;

    //Read File Line By Line
    while ((string2 = br.readLine()) != null)   {

	//variable for dictionary word
	String word = string2;

	if (areAnagrams(string1, string2)) {
            System.out.println("\"" + args[0] + "\"" + " is an anagram of : " + word);
	    flag = true;
        } else {
	   // System.out.println("\nYou entered, " + string1);
	   // TODO:  Flow out put
        }
    }
    //Close the input stream
    in.close();

    }catch (Exception e){//Catch exception if any
      System.err.println("Error: " + e.getMessage()); return;}

	if (flag == false) {System.out.println("\"" + args[0] + "\"" + " is not an anagram");}

    }
	
}
