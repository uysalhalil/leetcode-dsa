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

