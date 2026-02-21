
---

# 📘 C++ STL Quick Reference

---

# 1️⃣ `vector`

### Header

```cpp
#include <vector>
```

### Declaration

```cpp
vector<int> v;
vector<int> v(n);
vector<int> v(n, value);
```

### Common Functions

| Function         | Description              |
| ---------------- | ------------------------ |
| `push_back(x)`   | Add element at end       |
| `pop_back()`     | Remove last element      |
| `size()`         | Number of elements       |
| `empty()`        | Check if empty           |
| `clear()`        | Remove all elements      |
| `insert(pos, x)` | Insert at position       |
| `erase(pos)`     | Erase element            |
| `front()`        | First element            |
| `back()`         | Last element             |
| `at(i)`          | Access with bounds check |
| `begin(), end()` | Iterators                |

---

# 2️⃣ `set`

### Header

```cpp
#include <set>
```

* Stores unique elements
* Sorted order (ascending by default)

### Functions

| Function         | Description      |
| ---------------- | ---------------- |
| `insert(x)`      | Insert element   |
| `erase(x)`       | Remove element   |
| `find(x)`        | Returns iterator |
| `count(x)`       | 0 or 1           |
| `lower_bound(x)` | First ≥ x        |
| `upper_bound(x)` | First > x        |
| `size()`         | Size             |

---

# 3️⃣ `multiset`

* Allows duplicates
* Sorted

Same functions as `set`

Additional:

```cpp
ms.erase(ms.find(x));  // erase single occurrence
```

---

# 4️⃣ `unordered_set`

### Header

```cpp
#include <unordered_set>
```

* Unique elements
* No order
* Average O(1)

Functions same as `set` except:

* No `lower_bound` / `upper_bound`

---

# 5️⃣ `unordered_multiset`

* Allows duplicates
* No order

Same functions as `unordered_set`

---

# 6️⃣ `map`

### Header

```cpp
#include <map>
```

* Key-value pair
* Sorted by key

### Functions

| Function           | Description     |
| ------------------ | --------------- |
| `mp[key]`          | Access / Insert |
| `insert({k,v})`    | Insert          |
| `erase(key)`       | Remove          |
| `find(key)`        | Iterator        |
| `count(key)`       | 0 or 1          |
| `lower_bound(key)` | ≥ key           |
| `upper_bound(key)` | > key           |

---

# 7️⃣ `multimap`

* Allows duplicate keys
* Sorted

Use:

```cpp
mm.insert({k, v});
```

Cannot use `mm[key]`

---

# 8️⃣ `unordered_map`

* Key-value
* No order
* Average O(1)

Functions same as `map` (except no lower/upper bound)

---

# 9️⃣ `unordered_multimap`

* Duplicate keys
* No order

---

# 🔟 `queue`

### Header

```cpp
#include <queue>
```

### Functions

| Function  | Description   |
| --------- | ------------- |
| `push(x)` | Insert        |
| `pop()`   | Remove front  |
| `front()` | First element |
| `back()`  | Last element  |
| `empty()` | Check empty   |
| `size()`  | Size          |

FIFO

---

# 1️⃣1️⃣ `stack`

### Header

```cpp
#include <stack>
```

### Functions

| Function  | Description |
| --------- | ----------- |
| `push(x)` | Insert      |
| `pop()`   | Remove top  |
| `top()`   | Top element |
| `empty()` | Check empty |
| `size()`  | Size        |

LIFO

---

# 1️⃣2️⃣ `deque`

### Header

```cpp
#include <deque>
```

### Functions

| Function        | Description  |
| --------------- | ------------ |
| `push_front(x)` | Insert front |
| `push_back(x)`  | Insert back  |
| `pop_front()`   | Remove front |
| `pop_back()`    | Remove back  |
| `front()`       | First        |
| `back()`        | Last         |

---

# 1️⃣3️⃣ `priority_queue`

### Header

```cpp
#include <queue>
```

### Max Heap (default)

```cpp
priority_queue<int> pq;
```

### Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

### Functions

| Function  | Description        |
| --------- | ------------------ |
| `push(x)` | Insert             |
| `pop()`   | Remove top         |
| `top()`   | Largest / Smallest |
| `empty()` | Check empty        |
| `size()`  | Size               |

---

# 1️⃣4️⃣ `list`

### Header

```cpp
#include <list>
```

Doubly linked list

### Functions

| Function        | Description        |
| --------------- | ------------------ |
| `push_back(x)`  | Insert end         |
| `push_front(x)` | Insert front       |
| `pop_back()`    | Remove end         |
| `pop_front()`   | Remove front       |
| `insert()`      | Insert at iterator |
| `erase()`       | Remove element     |
| `reverse()`     | Reverse list       |
| `sort()`        | Sort list          |

---

# 🔹 Algorithms & Utility Functions

---

# `sort()`

### Header

```cpp
#include <algorithm>
```

```cpp
sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>());
```

Time: O(n log n)

---

# `min_element()`

```cpp
auto it = min_element(v.begin(), v.end());
```

Returns iterator to smallest element

---

# `max_element()`

```cpp
auto it = max_element(v.begin(), v.end());
```

Returns iterator to largest element

---

# `next_permutation()`

```cpp
next_permutation(v.begin(), v.end());
```

Generates next lexicographical permutation
Returns `true` if exists

---

# `__builtin_popcount()`

Counts number of set bits.

```cpp
__builtin_popcount(x);      // int
__builtin_popcountll(x);    // long long
```

---

# ⚡ Complexity Summary

| Container      | Insert   | Search   | Order  |
| -------------- | -------- | -------- | ------ |
| vector         | O(1)*    | O(n)     | No     |
| set            | O(log n) | O(log n) | Sorted |
| unordered_set  | O(1) avg | O(1) avg | No     |
| map            | O(log n) | O(log n) | Sorted |
| unordered_map  | O(1) avg | O(1) avg | No     |
| priority_queue | O(log n) | O(1) top | Heap   |

---

# 🚀 Tip for Interviews

Remember:

* Need order → `set` / `map`
* Need fastest lookup → `unordered_*`
* Need max/min repeatedly → `priority_queue`
* Need dynamic array → `vector`
* Need sliding window from both ends → `deque`

---

If you want, I can also generate:

* 📄 Advanced STL tricks file
* 📄 Iterators + Custom Comparator guide
* 📄 Competitive programming STL cheat sheet (ultra compact)
* 📄 Time complexity master sheet

Tell me what you want next.
