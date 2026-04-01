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

### [0328 — odd even linked list](../problems/0328-odd-even-linked-list.cpp)

**Idea:** group nodes by index parity while preserving internal order
**Approach (my implementation):**
- Compute the tail of the list
- Traverse from the head and repeatedly extract the next even-indexed node
- Append each extracted node to the end of the list
This works in O(n) time and O(1) space, but requires careful pointer management and size tracking.

**Complexity:**
Time: O(n)
Space: O(1)

### [0206 — reverse linked list](../problems/0206-reverse-linked-list.cpp)

**Idea:** reverse the direction of all `next` pointers in a singly linked list
**Approach:**
- Maintain three pointers: `prev`, `curr`, and `next`
- At each step, redirect `curr->next` to `prev`
- Advance all pointers forward and continue until the list is exhausted
This performs the reversal in-place with constant extra space.

**Complexity:**
Time: O(n)
Space: O(1)

### [0001 — two sum](../problems/0001-two-sum.cpp)

**Idea:** find two indices whose values sum to the target
**Approach:**
- Maintain a hash map from value to index
- For each element `nums[i]`, compute its complement `target - nums[i]`
- If the complement has been seen before, return the pair of indices
- Otherwise, store the current value and continue
This checks each element once and uses constant‑time lookups.

**Complexity:**
Time: O(n)
Space: O(n)

### [0138 — copy list with random pointer](../problems/0138-copy-list-with-random-pointer.cpp)

**Idea:** create a deep copy of a linked list where each node has both `next` and `random` pointers
**Approach (hash map):**
- First pass: allocate a clone node for each original node and store the mapping
- Second pass: wire the `next` and `random` pointers using the map
This ensures every pointer in the cloned list refers to the correct cloned target and avoids pointer aliasing issues.

**Approach (canonical O(1) space):**
- Interleave cloned nodes between original nodes
- Assign `random` pointers using the interleaving
- Detach the cloned list
This avoids extra memory but requires more pointer manipulation.

**Complexity:**
Time: O(n)
Space: O(n)

### [0041 — first missing positive](../problems/0041-first-missing-positive.cpp)

**Idea:** track all positive integers seen in the array and increment a running counter until a gap appears. The smallest positive integer not present in the set is the answer.

**Approach:**
- Maintain an `unordered_set<int>` containing all positive values encountered.
- Track a variable `minMissingPosNum`, initialized to `1`.
- For each number in the array:
  - If it is positive, insert it into the set.
  - While the current `minMissingPosNum` exists in the set, increment it.
- After processing all numbers, the value of `minMissingPosNum` is the smallest missing positive.

**Complexity:**
- Time: O(n) due to ordered set insertions and lookups.
- Space: O(n) for storing all positive integers.

### [1732 — find the highest altitude](../problems/1732-find-the-highest-altitude.cpp)

**Idea:** track the altitude after each segment using a running sum and record the maximum value reached.

**Approach (my implementation):**
- Start at altitude `0`.
- Iterate through the `gain` array, adding each value to a running `currentAltitude`.
- After each update, compare `currentAltitude` with the maximum altitude seen so far and update it if necessary.
- Return the maximum altitude reached during the traversal.

**Complexity:**
- Time: O(n)
- Space: O(1)

### [1590 — make sum divisible by p](../problems/1590-make-sum-divisible-by-p.cpp)

**Idea:** find the shortest subarray whose removal fixes the modulo mismatch between the total sum and \(p\).

**Approach:**
- Compute `total % p`; if it is `0`, no removal is needed.
- Let `target = total % p`.
- Use prefix sums modulo \(p\) and store the earliest index for each remainder in a hashmap.
- For each prefix remainder `prefix`, compute the needed previous remainder
  \((prefix - target + p) \% p\)
  and update the minimum subarray length.
- Insert or update the current prefix remainder in the hashmap.
- Return the minimum valid length, or `-1` if none exists.

**Complexity:**
Time: O(n)
Space: O(n)

### [1664 — ways to make a fair array](../problems/1664-ways-to-make-a-fair-array.cpp)

**Idea:** track odd/even prefix sums to check whether removing an index balances the two sides.

**Approach:**
- Compute prefix sums for even indices and odd indices separately.
- For each index `i`, simulate removing it by comparing:
  - even sum before `i` + odd sum after `i`
  - odd sum before `i` + even sum after `i`
- If these two totals match, removing `i` makes the array fair.
- Count all such valid indices.

**Complexity:**
Time: O(n)
Space: O(n)

### [1200 — minimum absolute difference](../problems/1200-minimum-absolute-difference.cpp)

**Idea:** sort the array so the minimum absolute difference must appear between adjacent elements.

**Approach:**
- Sort the array in non‑decreasing order.
- Scan once to compute the global minimum adjacent difference.
- Scan again and collect all adjacent pairs whose difference equals that minimum.
- Return the list of such pairs.

**Complexity:**
Time: O(n log n)
Space: O(1) extra (ignoring output)

### [1887 — reduction operations to make the array elements equal](../problems/1887-reduction-operations-to-make-the-array-elements-equal.cpp)

**Idea:** after sorting, each time we encounter a new distinct value from the right, all elements to its right must be reduced once.

**Approach:**
- Sort the array in non‑decreasing order.
- Traverse from right to left.
- Whenever `nums[i]` differs from `nums[i-1]`, all elements to the right (`n - i`) must be incremented in the operation count.
- Accumulate these increments to compute the total number of operations.
- Return the final count.

**Complexity:**
Time: O(n log n)
Space: O(1) extra

### [0056 — merge intervals](../problems/0056-merge-intervals.cpp)

**Idea:** sort intervals by start time, then merge overlapping ones in a single pass.

**Approach:**
- Sort all intervals by their starting value.
- Initialize the merged list with the first interval.
- For each next interval:
  - If it overlaps with the last merged interval, update the end to the max of both.
  - Otherwise, append it as a new disjoint interval.
- Return the merged list.

**Complexity:**
Time: O(n log n)
Space: O(1) extra (ignoring output)

### [0852 — peak index in a mountain array](../problems/0852-peak-index-in-a-mountain-array.cpp)

**Idea:** linearly scan until the slope switches from increasing to decreasing.

**Approach:**
- Start from index `0`.
- Increment `i` while `arr[i] < arr[i+1]`.
- The first position where this condition fails is the peak.
- Return that index.

**Complexity:**
Time: O(n)
Space: O(1)

### [0704 — binary search](../problems/0704-binary-search.cpp)

**Idea:** perform classic binary search by shrinking the range until the target is found or the interval collapses.

**Approach:**
- Initialize `l = 0` and `r = nums.size()`.
- While `l < r`:
  - Compute midpoint `m = (r - l) / 2 + l`.
  - If `nums[m] == target`, return `m`.
  - If `nums[m] < target`, move left bound to `m + 1`.
  - Otherwise, move right bound to `m`.
- If the loop ends with no match, return `-1`.

**Complexity:**
Time: O(log n)
Space: O(1)

### [0633 — sum of square numbers](../problems/0633-sum-of-square-numbers.cpp)

**Idea:** try all possible `a` values and check whether `c - a²` is a perfect square.

**Approach:**
- Loop `a` from `0` upward while `a² <= c`.
- For each `a`, compute `b = sqrt(c - a*a)`.
- If `b` is an integer, return `true` because `a² + b² = c`.
- If the loop finishes with no match, return `false`.

**Complexity:**
Time: O(√c)
Space: O(1)

### [0033 — search in rotated sorted array](../problems/0033-search-in-rotated-sorted-array.cpp)

**Idea:** find the rotation pivot, then perform a shifted binary search that maps virtual indices back to real ones.

**Approach:**
- First, locate the pivot (index of the smallest element) by binary searching against `nums[n‑1]`.
- Compute a shift value so that the rotated array can be treated as if pivot were at index `0`.
- Perform a binary search on this shifted index space:
  - Convert each virtual midpoint back to the real index using modular arithmetic.
  - Compare against the target and adjust bounds accordingly.
- Return the mapped index if found, otherwise `-1`.

**Complexity:**
Time: O(log n)
Space: O(1)

### [0215 — kth largest element in an array](../problems/0215-kth-largest-element-in-an-array.cpp)

**Idea:** build a max‑heap from all elements, then pop until reaching the k‑th largest.

**Approach:**
- Construct a `priority_queue<int>` (max‑heap) using all elements of `nums`.
- Repeatedly pop from the heap `k‑1` times.
- The next top element is the k‑th largest.
- Return that value.

**Complexity:**
Time: O(n + k log n)
Space: O(n)

### [0912 — sort an array](../problems/0912-sort-an-array.cpp)

**Idea:** use randomized 3‑way quicksort to partition elements into `< pivot`, `== pivot`, and `> pivot` regions, then recursively sort the outer partitions.

**Approach:**
- Call `quick_sort3(nums, 0, nums.size() - 1)`.
- The `partition3` function:
  - Chooses the first element as pivot.
  - Uses three regions:
    - elements less than pivot
    - elements equal to pivot
    - elements greater than pivot
  - Swaps elements to maintain these regions in a single linear scan.
- Recursively sort the `< pivot` and `> pivot` partitions.
- Return the fully sorted array.

**Complexity:**
Time:
- Average: O(n log n)
- Worst‑case: O(n²) (rare due to pivot behavior)

Space: O(log n) recursion depth

### [0147 — insertion sort list](../problems/0147-insertion-sort-list.cpp)

**Idea:** perform insertion sort directly on the linked list by scanning ahead and inserting out‑of‑order nodes into their correct position.

**Approach:**
- Create a `dummy_head` pointing to the original list.
- Maintain two pointers:
  - `prev` — the node before the current sorted boundary
  - `curr` — the node being checked
- For each `curr`, run an inner scan:
  - Use `prev_runner` and `runner` to search for a node whose value is smaller than `curr->val`.
  - When found:
    - Remove `runner` from its position.
    - Insert it before `curr`.
    - Update `curr` to the newly inserted node.
    - Reset `runner` to continue scanning correctly.
- After the inner loop, advance both `prev` and `curr`.
- Return `dummy_head->next` as the sorted list.

**Complexity:**
Time: O(n²)
Space: O(1)
