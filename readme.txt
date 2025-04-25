Corner Grocer Item Tracking Program
====================================

This C++ program was developed for Chada Tech to help the Corner Grocer analyze daily purchasing trends based on transactional records. It reads item data from a file and provides a menu-driven interface to display frequency data and visual histograms, allowing store management to optimize product placement in their layout.

Key Functionalities:
---------------------
1. **Item Lookup** – Allows users to input an item name and retrieve the number of times it was purchased.
2. **Frequency Listing** – Displays all items and their respective purchase counts from the input file.
3. **Histogram Display** – Graphically represents each item’s frequency using asterisks.
4. **Exit Option** – Cleanly terminates the program.

Data Handling:
---------------
- On startup, the program reads from `CS210_Project_Three_Input_File.txt`, which contains one item per line (e.g., `Potatoes`, `Onions`).
- It automatically creates a backup file called `frequency.dat`, which stores each item with its frequency count.

Design Overview:
-----------------
The program follows object-oriented design principles. It uses a class `GroceryTracker` to encapsulate core logic and maintain modularity. Internally, the program uses C++ `map` containers to store and count item frequencies efficiently.

Input validation ensures users only select valid options from the menu (1–4), and appropriate error handling is used to prevent runtime crashes due to unexpected input.

Usage Notes:
--------------
To use the program, simply compile and run it in any C++ environment. Make sure `CS210_Project_Three_Input_File.txt` is in the same directory. The menu will guide you through available options.

Developed as part of the SNHU CS210 course.
