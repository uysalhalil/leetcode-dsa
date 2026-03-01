# DSA Quest - Problem Index

This study set lists all problems included in LeetCode’s **DSA Quest**.
Each entry links to the canonical solution stored in the `/problems/` directory.

---

## Problem List

### [1475 — final prices with a special discount in a shop](../problems/1475-final-prices-with-a-special-discount-in-a-shop.cpp)

**Idea:** scan forward to find the first cheaper-or-equal price and subtract it
**Approach:**
- Iterate through each price and look ahead for the first valid discount
- Use a monotonic stack to track candidates efficiently
- Replace each price with price minus discount
**Complexity:**
Time: O(n)
Space: O(1)

### [0739 — daily temperatures](../problems/0739-daily-temperatures.cpp)

**Idea:** use a decreasing monotonic stack to find the next warmer day
**Approach:**
- Maintain a stack of indices with strictly decreasing temperatures
- For each new temperature, pop all cooler ones and fill their waiting days
- Push the current index as a future candidate
- Return the filled result array
**Complexity:**
Time: O(n)
Space: O(n)

### [0084 — largest rectangle in histogram](../problems/0084-largest-rectangle-in-histogram.cpp)

**Idea:** use a monotonic increasing stack to compute each bar’s maximal expansion
**Approach:**
- Iterate through all bars, treating a virtual 0-height bar at the end
- Maintain a stack of indices with strictly increasing heights
- When a lower height appears, pop and compute area using the previous index as the left boundary
- Track the maximum area across all pops
**Complexity:**
Time: O(n)
Space: O(n)

### [1700 — number of students unable to eat lunch](../problems/1700-number-of-students-unable-to-eat-lunch.cpp)

**Idea:** simulate the queue until no progress can be made
**Approach:**
- Students form a queue; sandwiches form a stack-like list
- If the front student matches the top sandwich, both are removed
- Otherwise, rotate the student to the back
- Stop when a full rotation occurs with no matches
**Complexity:**
Time: O(n)
Space: O(1) extra

### [2073 — time needed to buy tickets](../problems/2073-time-needed-to-buy-tickets.cpp)

**Idea:** simulate the circular queue until the target person finishes
**Approach:**
- Maintain an index that cycles through the queue
- Each time a person with remaining tickets is visited, decrement their count and increment time
- Stop when the target index reaches zero
**Complexity:**
Time: O(n + k)
Space: O(1)

### [0232 — implement queue using stacks](../problems/0232-implement-queue-using-stacks.cpp)

**Idea:** simulate FIFO behavior using two LIFO stacks
**Approach:**
- Maintain an input stack for pushes and an output stack for pops
- On `peek()` or `pop()`, transfer all elements from input to output only when output is empty
- This ensures amortized O(1) operations while preserving queue order
**Complexity:**
Time: amortized O(1)
Space: O(n)

### [1046 — last stone weight](../problems/1046-last-stone-weight.cpp)

**Idea:** repeatedly smash the two heaviest stones using a max‑heap
**Approach:**
- Build a max‑heap from the input stones
- Pop the two largest values, compute their difference
- Push the difference back if non‑zero
- Continue until at most one stone remains
**Complexity:**
Time: O(n log n)
Space: O(n)

### [0373 — find k pairs with smallest sums](../problems/0373-find-k-pairs-with-smallest-sums.cpp)

**Idea:** treat pair sums as a sorted matrix and extract the next smallest cell
**Approach:**
- Visualize all pairs `(nums1[i], nums2[j])` as an `m × n` matrix sorted by rows and columns
- Use a min‑heap seeded with `(0,0)` representing the smallest sum
- Repeatedly pop the smallest pair and push its neighbors `(i+1,j)` and `(i,j+1)`
- Track visited `(i,j)` pairs to avoid duplicates while exploring only the needed frontier
**Complexity:**
Time: O(k log k)
Space: O(k)

### [1354 — construct target array with multiple sums](../problems/1354-construct-target-array-with-multiple-sums.cpp)

**Idea:** reverse the construction process by undoing the last operation on the largest element
**Approach:**
- Observe that in the forward process, one element becomes the sum of the entire array
- Reverse the process by repeatedly selecting the largest element, which must have been updated last
- Let `x` be the largest value and `rest = total_sum - x`
- The previous value of `x` must be `x % rest`, since forward updates add `rest` repeatedly
- Replace `x` with `x % rest` and continue until all elements become `1`
- Use a max‑heap to efficiently track and update the largest element
**Complexity:**
Time: O(n log n)
Space: O(n)
