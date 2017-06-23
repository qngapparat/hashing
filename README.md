# hashing
Implementing a simple String-to-Integer hashing algorithm in C.

#### Structure

Two functions are provided:

    int hash(char[] string_to_hash, int string_length)

Which iterates over each character of `string_to_hash`, adds it to the initially empty hash integer (works because chars are internally represented as integers), and performs a circular left-shift by 5 digits on the whole hash.

    int compress(int hash, int N)

Which compresses the passed hash to a value between 0 and N-1, to be mapped onto a hashtable. The compressed hash is calculated by

`(((scale*hash + shift) % prime) % N);`

with scale, shift being random integers, prime being a prime number, in this case calculated by `prime = 2^(rand()%10) - 1;`. At special occasions, primes generated this way can lead to collusion patterns, so the solution is not optimal.



#### TODO's

+ Provide a hash table implementation, either using buckets or probing as collision handler.
