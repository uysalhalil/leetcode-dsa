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

### [0520 — detect capital](../problems/0520-detect-capital.cpp)

**Idea:** validate whether a word follows one of three allowed capitalization patterns
**Approach:**
- Observe that a word is valid if it matches exactly one of these forms:
  - all letters uppercase
  - all letters lowercase
  - only the first letter uppercase and the rest lowercase
- Count how many uppercase letters appear in the word
- The capitalization is valid if:
  - the count equals the word length
  - the count is zero
  - the count is one and the first character is uppercase
- Use character classification (`isupper`, `islower`) instead of transforming characters
**Complexity:**
Time: O(n)
Space: O(1)

### [0482 — license key formatting](../problems/0482-license-key-formatting.cpp)

**Idea:** normalize the string by removing dashes and uppercasing, then rebuild groups of size `K`
**Approach:**
- Iterate over the input string and skip all `'-'` characters
- Convert each remaining character to uppercase and append to a temporary buffer
- Compute the size of the first group using `temp.size() % K`
- Append the first group (if non‑empty), then append subsequent groups of size `K` separated by dashes
- This forward‑construction approach keeps the logic simple and readable
**Note on `toupper`:**
- `toupper(c)` is undefined behavior when `c` is a negative `char`
- The safe form is `toupper(static_cast<unsigned char>(c))`, which ensures correct behavior for all ASCII inputs
**Complexity:**
Time: O(n)
Space: O(n)

### [0831 — masking personal information](../problems/0831-masking-personal-information.cpp)

**Idea:** classify the input as email or phone and apply the corresponding masking rules
**Approach:**
- **Email:**
  - Lowercase the entire string
  - Keep the first and last character of the name part
  - Replace the middle with exactly five asterisks
  - Append the domain unchanged (lowercased)
- **Phone:**
  - Extract digits only
  - Last four digits remain visible
  - Local number becomes `***-***-XXXX`
  - If a country code exists, prefix with `"+"` and mask its digits with `*`
**Note on `toupper` / `tolower`:**
- These functions operate on `unsigned char` values; calling them on a signed `char` may cause undefined behavior
- The safe form is `toupper(static_cast<unsigned char>(c))` and `tolower(static_cast<unsigned char>(c))`
**Complexity:**
Time: O(n)
Space: O(n)

### [0459 — repeated substring pattern](../problems/0459-repeated-substring-pattern.cpp)

**Idea:** a string repeats if it appears inside a rotation of itself
**Approach:**
- Concatenate the string with itself
- Remove the first and last character to avoid the trivial match
- If the original string appears inside this trimmed double string, it must be composed of repeated substrings
**Why it works:**
- Doubling the string generates all rotations
- A repeated pattern will always appear as a non-trivial rotation
**Complexity:**
Time: O(n) average
Space: O(n)

### [0796 — rotate string](../problems/0796-rotate-string.cpp)

**Idea:** determine whether `goal` is a rotation of `s`
**Approach (my implementation):**
- Reject immediately if lengths differ
- Identify all indices in `s` where the first character of `goal` appears
- For each candidate shift, compare characters using modular indexing
- A match means `goal` is reachable by rotating `s`
This version is explicit and readable: it checks rotation structure directly without relying on string concatenation.

**Approach (canonical):**
- A string is a rotation of itself if it appears inside a non‑trivial rotation of its double
- Concatenate `s + s` and search for `goal` inside the substring that excludes the first and last character
- If `goal` appears, it must be a rotation of `s`
This is one of those problems where the trick is obvious only after you’ve seen it; without the rotation insight, the problem feels much harder than it is.

**Complexity:**
- My implementation: O(n²) worst case
- Canonical implementation: O(n) average

### [0686 — repeated string match](../problems/0686-repeated-string-match.cpp)

**Idea:** determine the minimum number of times `a` must be repeated so that `b` becomes a substring
**Approach (explicit growth):**
- Build a repeated version of `a` until its length reaches or exceeds the length of `b`
- Check if `b` appears as a substring
- If not, append one more copy of `a` and check again
This version is straightforward and readable: it grows the candidate string just enough to cover all valid cases without arbitrary bounds.

**Approach (canonical invariant):**
- If `b` is to appear inside repeated `a`, the repeated string only needs to reach length `ceil(|b| / |a|)`
- At most one extra repetition is required to cover boundary‑crossing matches
- Therefore, only two substring checks are ever needed
This is one of those problems where knowing the invariant collapses the entire solution to a few lines; without it, the problem feels much harder than it is.

**Complexity:**
Time: O(n) average
Space: O(n)

### [0083 — remove duplicates from sorted list](../problems/0083-remove-duplicates-from-sorted-list.cpp)

**Idea:** the list is sorted, so duplicates appear in consecutive positions
**Approach:**
- Traverse the list once
- If the current node and the next node have the same value, skip the next node by rewiring the pointer
- Otherwise, move forward normally
This removes duplicates in-place without extra memory.

**Complexity:**
Time: O(n)
Space: O(1)
