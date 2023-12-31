rm main

g++ main.cpp constants.hpp ballClass.hpp rectClass.hpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o main

./main
