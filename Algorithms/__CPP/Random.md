[TOC]

# FROM

- https://codeforces.com/blog/entry/61587

## C++ rand()의 한계

- `rand()`는 $[0, RAND\_MAX]$ 사이의 값을 리턴하는데, `RANDMAX`는 컴파일러 종속적이다

  - Codeforces에서는 32767이다.

- `random_shuffle()` 또한 `rand()`를 사용하기 때문에 문제가 발생한다.

  - ```cpp
    // random_shuffle()의 구현은 컴파일러 종속적이지만, 대충 다음과 같다.
    for(int i = 1; i < n; ++i) 
        swap(perm[i], perm[rand()%(i+1)])
    ```

### Linear Congruential Generator

- [linear congruential generator](https://en.wikipedia.org/wiki/Linear_congruential_generator)

- `rand()`는 다음과 같이 구현되어 있다.

- ```cpp
  static long holdrand = 1L;
  void srand(unsigned int seed) { holdrand = (long)seed; }
  int rand() { return (((holdrand = holdrand * 214013L + 2531011L) >> 16) & 0x7fff); }
  ```

## mt19937

- `<random>` 헤더에 있는 `mt19937`을 사용한다.

-  [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister) based on prime $2^{19937}-1$

- ```cpp
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  shuffle(ALL(ar), rng);
  ```

