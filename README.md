# push-swap
Greedy Algorithm with Combined Rotations and Target Position Calculation:
The algorithm iteratively finds the element in stack A that requires the fewest optimized moves (considering combined rr/rrr rotations) to push to its correct sorted position in stack B (maintaining descending order). Once stack A is reduced to three elements, they are sorted, and stack B is efficiently pushed back to A.
After trying to figure out what is the best data structure and created doublylinked list
After doing all the input parsing and error handling
After trying to divide it into chunks for better easier sorting
it turned out that with the optimized calculations it sorts with fewer moves if there is only one complete chunk.
Greedy sorting does the work better if it's not limited by the bouderies of processing chunk by chunk but has a complete picture of the stack to sort.
