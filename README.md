# Better_Bits
A C++ library for better bit manipulation.

## Binary io Manipulators
Sudo iostream manipulator to output data in binary format.
### bb::bin
Automatically adapt the user input to decide how to format output. Data that is less than one nibble in size will be outputted as 4 bytes, anything longer will be displayed as full bytes.
### bb::bin_b
Data will be cut off after the final bit.
### bb::bin_B
Data will be cut off after the final byte.
### bb::hex
Data is outputted in stl <iomanip> format with prefix 0x infront of the hex value.
## Counters
### bb::bytesInUse(data)
Returns the number of bytes needed to maintain data integrity.
### bb::bitsInUse(data)
Returns the number of bits needed to maintain data integrity
## Nibbles
Struct used to hold first and second nibble.
### bb::split(data)
Returns a Nibbles struct holding the first and second nibbles of the data provided. Throws error if data is more than one byte.
### bb::reverse(data)
Returns the bits in reverse order.
### bb::flip(data)
Returns the data with each bit flipped.
### bb::nthByte(data, position)
Returns the targeted byte.
