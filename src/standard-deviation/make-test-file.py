import random

file1 = open("test1.txt", "w")
file2 = open("test2.txt", "w")
file3 = open("test3.txt", "w")

for i in range(0, 10):
    file1.write(str((random.random()*2000.0)-1000.0) + "\n")

for i in range(0, 100):
    file2.write(str((random.random()*2000.0)-1000.0) + "\n")

for i in range(0, 1000):
    file3.write(str((random.random()*2000.0)-1000.0) + "\n")

file1.close()
file2.close()
file3.close()

print("Done")
