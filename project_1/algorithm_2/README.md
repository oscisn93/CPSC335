# Algorithm 2: Matching Group Schedules

We are given two peoples schedules as well a range of availlabilties and a meeting duration and asked to output a list of availlabilties that dont clash with either of their schedules. This problem requires us to merge to sorted lists, remove duplicates and then calclulate what time ranges can be used to hold a 30 minute meeting. The trick is to convert the string data into a number format so that we can easily perform comparisons and mutations of the ranges without having to perform string concatenations.

# Instructions

You can run this program simply by running the following command in the terminal: `python3 main.py`. If you have additional input/testcases you'd like to run against the program, simply comment out the current variables that hold the inputs it is currently using: s1 and s2 are the schedules, da1 and da2 are the daily active ranges, and d is the meeting duration. name your variables accordingly to avoid reference errors.
