To compile, use:
rw

Alternatively, you can also use - 
gcc readerwriter.c -o rw -l pthread

To run, please include the scenarios.txt file and use
./rw

You can also modify the existing scenario in scenarios.txt to test for other scenarios
Currently, the program supports 1 scenario per run

Below are some sample scenarios and outputs - 

1. rwrwrwrwrwrw 

Reader[0]  is created..
Reader[0]  is reading
Reader[0]  finished reading
Reader[1]  is created..
Reader[1]  is reading
Reader[1]  finished reading
Writer[0]  is created..
Writer[0]  is writing
Writer[0]  finished writing
Writer[3]  is created..
Writer[3]  is writing
Writer[3]  finished writing
Reader[2]  is created..
Reader[2]  is reading
Reader[2]  finished reading
Writer[4]  is created..
Writer[4]  is writing
Writer[4]  finished writing
Writer[2]  is created..
Writer[2]  is writing
Writer[2]  finished writing
Reader[3]  is created..
Reader[3]  is reading
Reader[3]  finished reading
Writer[5]  is created..
Writer[5]  is writing
Writer[5]  finished writing
Reader[5]  is created..
Reader[5]  is reading
Reader[5]  finished reading
Writer[1]  is created..
Writer[1]  is writing
Writer[1]  finished writing
Reader[4]  is created..
Reader[4]  is reading
Reader[4]  finished reading

2. rrrrrwrrrrr

Reader[2]  is created..
Reader[2]  is reading
Reader[2]  finished reading
Reader[4]  is created..
Reader[0]  is created..
Reader[5]  is created..
Reader[1]  is created..
Reader[4]  is reading
Reader[0]  is reading
Reader[3]  is created..
Reader[6]  is created..
Reader[6]  is reading
Reader[6]  finished reading
Reader[4]  finished reading
Reader[0]  finished reading
Reader[5]  is reading
Reader[5]  finished reading
Reader[3]  is reading
Reader[3]  finished reading
Reader[1]  is reading
Reader[1]  finished reading
Reader[7]  is created..
Reader[7]  is reading
Reader[7]  finished reading
Writer[0]  is created..
Writer[0]  is writing
Writer[0]  finished writing
Reader[8]  is created..
Reader[8]  is reading
Reader[8]  finished reading
Reader[9]  is created..
Reader[9]  is reading
Reader[9]  finished reading

3. wwwwwrwwwww

Writer[0]  is created..
Writer[0]  is writing
Writer[0]  finished writing
Writer[2]  is created..
Writer[2]  is writing
Writer[2]  finished writing
Writer[1]  is created..
Writer[1]  is writing
Writer[1]  finished writing
Writer[5]  is created..
Writer[5]  is writing
Writer[5]  finished writing
Writer[4]  is created..
Writer[4]  is writing
Writer[4]  finished writing
Writer[7]  is created..
Writer[7]  is writing
Writer[7]  finished writing
Writer[8]  is created..
Writer[8]  is writing
Writer[8]  finished writing
Reader[0]  is created..
Reader[0]  is reading
Reader[0]  finished reading
Writer[9]  is created..
Writer[9]  is writing
Writer[9]  finished writing
Writer[3]  is created..
Writer[3]  is writing
Writer[3]  finished writing
Writer[6]  is created..
Writer[6]  is writing
Writer[6]  finished writing

4. rwwwwwr

Reader[0]  is created..
Reader[0]  is reading
Reader[0]  finished reading
Writer[0]  is created..
Writer[0]  is writing
Writer[0]  finished writing
Writer[2]  is created..
Writer[2]  is writing
Writer[2]  finished writing
Writer[1]  is created..
Writer[1]  is writing
Writer[1]  finished writing
Writer[3]  is created..
Writer[3]  is writing
Writer[3]  finished writing
Writer[4]  is created..
Writer[4]  is writing
Writer[4]  finished writing
Reader[1]  is created..
Reader[1]  is reading
Reader[1]  finished reading

5. wrrrrrw

Writer[0]  is created..
Writer[0]  is writing
Writer[0]  finished writing
Reader[4]  is created..
Reader[4]  is reading
Reader[4]  finished reading
Reader[2]  is created..
Reader[2]  is reading
Reader[2]  finished reading
Writer[1]  is created..
Writer[1]  is writing
Writer[1]  finished writing
Reader[1]  is created..
Reader[1]  is reading
Reader[1]  finished reading
Reader[3]  is created..
Reader[3]  is reading
Reader[0]  is created..
Reader[0]  is reading
Reader[0]  finished reading
Reader[3]  finished reading

6. rwrrrrwrr

Reader[0]  is created..
Reader[0]  is reading
Reader[0]  finished reading
Writer[0]  is created..
Writer[0]  is writing
Writer[0]  finished writing
Reader[1]  is created..
Reader[1]  is reading
Reader[1]  finished reading
Reader[2]  is created..
Reader[2]  is reading
Reader[2]  finished reading
Reader[3]  is created..
Reader[3]  is reading
Reader[3]  finished reading
Reader[4]  is created..
Reader[4]  is reading
Reader[4]  finished reading
Writer[1]  is created..
Writer[1]  is writing
Writer[1]  finished writing
Reader[5]  is created..
Reader[5]  is reading
Reader[5]  finished reading
Reader[6]  is created..
Reader[6]  is reading
Reader[6]  finished reading

7. wwrrrrwr

Writer[0]  is created..
Writer[0]  is writing
Writer[0]  finished writing
Reader[1]  is created..
Reader[1]  is reading
Reader[2]  is created..
Reader[2]  is reading
Reader[2]  finished reading
Reader[1]  finished reading
Reader[0]  is created..
Reader[0]  is reading
Reader[0]  finished reading
Writer[1]  is created..
Writer[1]  is writing
Writer[1]  finished writing
Reader[4]  is created..
Reader[4]  is reading
Reader[4]  finished reading
Writer[2]  is created..
Writer[2]  is writing
Writer[2]  finished writing
Reader[3]  is created..
Reader[3]  is reading
Reader[3]  finished reading