## Compiling the Code

This code assumes that you have eigen library installed. If not please install it from [here](https://eigen.tuxfamily.org/dox/GettingStarted.html).

There is a precompiled binary available but if you want to compile it yourself, use the following command:

```
$ g++ -std=c++11 -I/usr/include/eigen3/ -o feedforward inference.cpp
```

Enjoy!
