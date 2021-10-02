# 1. Create a new user
adduser hammer

# 2. LIst all the currently running processes
ps -A

# 3. Display the characteristics of the CPU and the available memory
top

# 4. Redirect some eandom output into two different files
echo "random output" | tee 1.txt > 2.txt

# 5. Concatenate the two previous files
cat 1.txt 2.txt > 3.txt

# 6. Read the content of the resulting file as hexadecimal values
od -t x 3.txt

# 7. Use a single command to find all the files in /usr/src with the word semaphore in their name and containing the word ddekit_sem_down
find /usr/src -name 'semaphore | xargs grep -w 'ddekit_sem_down'
