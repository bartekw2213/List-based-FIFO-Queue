# List-based FIFO Queue :pencil:

Implementation of FIFO queue with use of cyclical double linked list

In addition to typical list methods (ADD_BEG, ADD_END, DEL_BEG, DEL_END, PRINT_FORWARD, PRINT_BACKWARD) the also implements:

- :triangular_ruler:SIZE - number of item in the list

The queue is a data structure that uses list and provides functions corresponding to the following commands:

- :inbox_tray:PUSH **N** - add element **N** to the end of the queue.
- :outbox_tray:POP - remove the first element from the queue.
- :book:PRINT_QUEUE - print the queue from the first element to the lastly added.
- :five:COUNT - the number of elements in queue ≤ SIZE.
- :heavy_exclamation_mark:GARBAGE_SOFT - change the values of all elements of the list that do not belong to the queue to 0.
- :bangbang:GARBAGE_HARD - remove all elements from the list that does not belong to the queue.

The [FIFO queue ](https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics))extends the list to the pointers to the beginning (FRONT) and the end (BACK) of the queue. After inserting an element to the queue the pointer to the end of the queue (BACK) has to be changed so it will point to the next element of the list. After removing an element from the queue (FRONT) pointer has to start pointing at the element after the previously pointer by (FRONT). Notice, that by both removing and adding the element the queue has to “follow the list”. Also it handles exceptions: inserting an element to an empty queue (no elements), adding elements to full list (the number of elements of the queue equal to the number of elements of the list), or trying to remove elements from an empty queue.

When the list is empty (no elements in it) the pointers point to nullptr. When adding an element (PUSH N) to the queue and the list is empty, then before executing the operation one element has to be added to the list. Similarly, the list extendeds when the list is not empty, but all the elements are occupied by the queue. Inserted element are inserted before the element pointed by pointer to the end of the queue (BACK).
