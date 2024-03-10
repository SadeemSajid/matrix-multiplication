# Optimizing Code w/ Parallelization

Read the pdf for answers to questions which were there in the assignment.

## How to run codes

Just type this into your console to generate a random matrix (using int32 for now)
```
python driver.py <opcode> <datatype> <first_matrix_rows> <first_matrix_columns> <second_matrix_rows> <second_matrix_columns>
```

The data will be placed in ```input.txt```
See results in ```results.txt``` once your preffered code executes.

## Python

```
python python.py input.txt
```

## Java

```
java Main.java input.txt
```

## C

```
gcc c.c -o c
```

## C with Pthreads

```
gcc c_pthreads.c -o pthreads -lpthread
```

## C with vector instructions

```
gcc -mavx2 -march=haswell c_vector.c -o vector
```

## C with Pthreads and vector instructions

```
gcc -mavx2 -march=haswell c_vector_thread.c -o vector_thread
```

# Results

Use
```
python plot.py
```

To see a graph. It has error bars and uses averages, but will only be visible if you zoom in when the dialogue opens.