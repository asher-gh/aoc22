# Python

- reading file in python with `open`.
- sets vs tuples vs lists
  - lists are ordered and can contain duplicates.
  - tuples are ordered and can store duplicate items but tuples are immutable.
  - sets in python are unordered and do not contain duplicates.
  - sets in python are unordered and do not contain duplicates.
  - sets in python are unordered and do not contain duplicates.
- stripping strings with `strip`
- finding max item in a list
- list comprehension
- with statement
- open
- logical and or not
- finding empty string

# C++

## Reading a file

- Steps:

  - Create a `stream` object
  - connect it to a file on disk (can be done in step 1 as shown above using the
    class constructor)
  - Read the file contents in to the stream object
  - close the file

- At various stages, the stream object may occupy different states, which can be
  checked using member functions:

  - `bad()` returns `True` if an error occurred while reading from or writing to
    a stream. If stream is "bad", no further operations involving the stream are
    possible.
  - `fail()` returns `True` if an error occurs, but we can still operate on the
    stream.
  - `eof()` returns `True` if the end of the file (EOF) is reached, with False
    returned otherwise.
  - `good()` returns `True` if each of the other three states are false, i.e.,
    the stream is neither bad nor failed, nor has it reached the end of the
    file.

- For reading, there is also `FILE` objects from the cstio library. stdin and
  stdout are expressions of type `FILE*` for handling input and output
  respectively. With C-style reading, the most important difference to the
  `fstream` class is that `FILE*` objects do not close files automatically,
  whereas the `fstream` destructor closes the file for you.

```cpp
/*
list.txt
----------
eggs
ham
eggs and spam
spam and eggs
*/

#include <iostream>
#include <fstream>
#include <string>

int main() {
// creating new stream object and connecting it to the file using constructor
std::ifstream file ("list.txt"); // similar to std::ifstream file; file.open("list.txt")

string reader; // creating a string to load contents into

if (file.is_open()) {
	file >> reader;
	std::cout << reader;
} /* prints "eggs" because the >> operator reads the string only until it
encounters a whitespace. */



}
```
