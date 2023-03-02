# PROG2100--Conversion
Assignment - Write a program that:

1) reads in a C++ source file (.cpp)
2) converts all < symbols to \&lt;
3) converts all > symbols to \&gt;
4) add the \<PRE> and \</PRE> tags to the front and end of the file
5) output the modified file to disk as an html file

Have a look here for escape sequences in HTML:

http://www.breakingpar.com/bkp/home.nsf/0/87256B280015193F87256C47007456E7

HTML files use tags enclosed in angle brackets to denote formatting instructions. For example, \<B>
indicates bold and \<I> indicates italics. If a web browser is displaying an HTML document that contains <
or >, it may mistake these symbols for tags. This is a common problem with C++ files, which contain many
<’s and >’s. For example, the line “#include <iostream>” may result in the browser interpreting <iostream>
as a tag.

To avoid this problem, HTML uses special symbols to denote < and >. The < symbol is created with the
string \&lt; while the > symbol is created with the string \&gt;.

Write a program that reads a C++ source file and converts all < symbols to \&lt; and all > symbols to \&gt;.
Also add the tag \<PRE> to the beginning of the file and </PRE> to the end of the file. This tag preserves
whitespace and formatting in the HTML document. Your program should output the HTML file to a disk.

As an example, given the following input file:
	
```
#include <iostream>

int main() {
	int x=4;
	if (x < 3) x++;
	  cout << x << endl;
}
```

the program should produce a text file with the following contents:
```
\<PRE>
#include &lt;iostream&gt;

int main() {
	int x=4;
	if(x &lt; 3) x++;
	cout &lt;&lt; x &lt;&lt; endl;
}
\</PRE>
```

You can test your output file by opening it with a web browser. The contents should appear identical to the
original source code.

Other notes:
* Validation must ensure that only valid Windows file names be processed (even if the demonstration
will take place on a Mac). This will require that you research the criteria for a valid Windows file
name for your validation routine.
* Be clear with the user (and validate) what information you want from them regarding the file
names (e.g. “bobFile” or “c:\bobFile” or “c:\bobFile.cpp”). It is poor UI design to make them
guess.
* The provided rubric is also considered part of this specification. Please review it as such.
* Citations - Remember that citations must be provided for any code, algorithm, text or image copied
from another source (e.g. the Web, a textbook, an online tutorial, etc.). Not attributing
appropriately (plagiarism) or using illegally copied materials (copyright breach) are serious
academic offenses. If you are in doubt as to when or how to cite, consult with your instructor and
the resources provided by the college.

David Russell

Assignment Source – Modified from Savitch Absolute C++

